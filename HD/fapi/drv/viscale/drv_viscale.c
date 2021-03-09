
#define DEBUG 4


#include <fapi/sys_services.h>
#include <fapi/reg_ve.h>
#include <fapi/reg_vo.h>
#include <fapi/drv_intr.h>
#include <fapi/drv_timer.h>
#include <fapi/drv_vienc.h>
#include <fapi/drv_vienc_priv.h>
#include <fapi/drv_viscale.h>
#include <fapi/drv_viscale_priv.h>




FAPI_SYS_DriverT FAPI_VISCALE_Driver0 = //21efc87c 
{
      "VISCALE",
      FAPI_INTR_DISP1, //29,
      1,
      FAPI_VISCALE_Init, 
      FAPI_VISCALE_Exit,
      FAPI_VISCALE_Isr,
      FAPI_VISCALE_Bsr,
      0x1000,
      256,
};


struct Struct_21efc8a0
{
   unsigned Data_0; //0
   unsigned Data_4; //4
   unsigned Data_8; //8
   unsigned Data_12; //12
   unsigned Data_16; //16
   unsigned Data_20; //20
   unsigned Data_24; //24
   //28
};


int viscaleInitialized = 0; //21f672a8
FAPI_SYS_SemaphoreT viscaleSemaphore = 0; //21f6727c
int Data_21f67280 = 0; //21f67280
int Data_21f67284 = 0; //21f67284
int Data_21f67288 = 0; //21f67288
int Data_21f6728c = 0; //21f6728c
int Data_21f67290 = 0; //21f67290
FAPI_VISCALE_VideoScalerIsrDataT* viscaleVideoScalerIsrData = 0; //21f67294
FAPI_VISCALE_VideoScalerIsrDataT* viscaleOsd1ScalerIsrData = 0; //21f67298
FAPI_VISCALE_VideoScalerIsrDataT* viscaleOsd2ScalerIsrData = 0; //21f6729c
FAPI_VISCALE_VideoScalerIsrDataT* viscaleCpScalerIsrData = 0; //21f672a0
FAPI_VISCALE_VideoScalerIsrDataT* viscaleSdScalerIsrData = 0; //21f672a4
FAPI_VISCALE_VideoScalerHandleT viscaleHandleArray[5]; //21f672c0

struct Struct_21f672b0
{
   int Data_0; //0
   int Data_4; //4
   int Data_8; //8
   int Data_12; //12
   
} Data_21f672b0; //21f672b0

struct Struct_21f672b0* Data_21f672ac; //21f672ac


FAPI_VISCALE_VideoScalerIsrDataT viscaleIsrData[FAPI_VISCALE_MAX_NUM_SCALERS]; //2206b148



void fapi_viscale_clear_handle(FAPI_VISCALE_VideoScalerHandleT*);
void fapi_viscale_clear_isr_data(FAPI_VISCALE_VideoScalerIsrDataT*);
void func_21c53c18(struct Struct_21f672b0*);
int fapi_viscale_check_handle(FAPI_VISCALE_VideoScalerHandleT*);
void fapi_viscale_remove_handle(FAPI_VISCALE_VideoScalerHandleT*);
void func_21c53ab8(struct Struct_21f672b0*);
void func_21c539ec(struct Struct_21f672b0*);
void func_21c53b84(struct Struct_21f672b0*);



/* 21c54640 - complete */
int32_t FAPI_VISCALE_Init(void)
{
   unsigned i = 0;
   
   if (viscaleInitialized != 0)
   {
      return -30003;
   }
   
   viscaleSemaphore = FAPI_SYS_CREATE_SEMAPHORE(1);
   
   if (viscaleSemaphore == 0)
   {
      return -30009;
   }
   
   for (i = 0; i < 5; i++)
   {
      fapi_viscale_clear_handle(&viscaleHandleArray[i]);
      
      fapi_viscale_clear_isr_data(&viscaleIsrData[i]);
   }
   
   FREG_VO_SetDispbackground_BackgroundY(0x10);
   FREG_VO_SetDispbackground_BackgroundCr(0x80);
   FREG_VO_SetDispbackground_BackgroundCb(0x80);
   
   FREG_VO_SetVohflt(0, 0xc040);
   FREG_VO_SetVohflt(1, 0xa060);
   FREG_VO_SetVohflt(2, 0x8080);
   FREG_VO_SetVohflt(3, 0x00ff);
   FREG_VO_SetVohflt(4, 0xc040);
   FREG_VO_SetVohflt(5, 0xc040);
   FREG_VO_SetVohflt(6, 0x8080);   
   FREG_VO_SetVohflt(7, 0x60a0);
   
   FREG_VO_SetVohflt(8, 0xc040);
   FREG_VO_SetVohflt(9, 0xa060);
   FREG_VO_SetVohflt(10, 0x8080);
   FREG_VO_SetVohflt(11, 0x00ff);
   FREG_VO_SetVohflt(12, 0xc040);
   FREG_VO_SetVohflt(13, 0xc040);
   FREG_VO_SetVohflt(14, 0x8080);   
   FREG_VO_SetVohflt(15, 0x60a0);
   
   FREG_VO_SetVohflt(16, 0xc040);
   FREG_VO_SetVohflt(17, 0xa060);
   FREG_VO_SetVohflt(18, 0x8080);
   FREG_VO_SetVohflt(19, 0x00ff);
   FREG_VO_SetVohflt(20, 0xc040);
   FREG_VO_SetVohflt(21, 0xc040);
   FREG_VO_SetVohflt(22, 0x8080);   
   FREG_VO_SetVohflt(23, 0x60a0);

   FREG_VO_SetVohflt(24, 0xc040);
   FREG_VO_SetVohflt(25, 0xa060);
   FREG_VO_SetVohflt(26, 0x8080);
   FREG_VO_SetVohflt(27, 0x00ff);
   FREG_VO_SetVohflt(28, 0xc040);
   FREG_VO_SetVohflt(29, 0xc040);
   FREG_VO_SetVohflt(30, 0x8080);   
   FREG_VO_SetVohflt(31, 0x60a0);

   FREG_VO_SetVohflt(32, 0x40c000);
   FREG_VO_SetVohflt(33, 0x8080);
   FREG_VO_SetVohflt(34, 0xff00);
   FREG_VO_SetVohflt(35, 0x00ff);
   FREG_VO_SetVohflt(36, 0x40c000);
   FREG_VO_SetVohflt(37, 0xff00);
   FREG_VO_SetVohflt(38, 0xff00);   
   FREG_VO_SetVohflt(39, 0xa060);

   FREG_VO_SetVohflt(40, 0x40c000);
   FREG_VO_SetVohflt(41, 0x8080);
   FREG_VO_SetVohflt(42, 0xff00);
   FREG_VO_SetVohflt(43, 0x00ff);
   FREG_VO_SetVohflt(44, 0x40c000);
   FREG_VO_SetVohflt(45, 0xff00);
   FREG_VO_SetVohflt(46, 0xff00);   
   FREG_VO_SetVohflt(47, 0xa060);

   FREG_VO_SetVohflt(48, 0x40c000);
   FREG_VO_SetVohflt(49, 0x8080);
   FREG_VO_SetVohflt(50, 0xff00);
   FREG_VO_SetVohflt(51, 0x00ff);
   FREG_VO_SetVohflt(52, 0x40c000);
   FREG_VO_SetVohflt(53, 0xff00);
   FREG_VO_SetVohflt(54, 0xff00);   
   FREG_VO_SetVohflt(55, 0xa060);

   FREG_VO_SetVohflt(56, 0x40c000);
   FREG_VO_SetVohflt(57, 0x8080);
   FREG_VO_SetVohflt(58, 0xff00);
   FREG_VO_SetVohflt(59, 0x00ff);
   FREG_VO_SetVohflt(60, 0x40c000);
   FREG_VO_SetVohflt(61, 0xff00);
   FREG_VO_SetVohflt(62, 0xff00);   
   FREG_VO_SetVohflt(63, 0xa060);

   FREG_VO_SetVohflt(64, 0xb051da43);
   FREG_VO_SetVohflt(65, 0x7125);
   FREG_VO_SetVohflt(66, 0x554621e5);
   FREG_VO_SetVohflt(67, 0xaf3e);
   
   FREG_VO_SetVohflt(68, 0xb051da43);
   FREG_VO_SetVohflt(69, 0x7125);
   FREG_VO_SetVohflt(70, 0x554621e5);
   FREG_VO_SetVohflt(71, 0xaf3e);

   FREG_VO_SetVohflt(72, 0xaf6add03);
   FREG_VO_SetVohflt(73, 0x7112);
   FREG_VO_SetVohflt(74, 0x50482505);
   FREG_VO_SetVohflt(75, 0xaf39);
   
   FREG_VO_SetVohflt(76, 0xaf6add03);
   FREG_VO_SetVohflt(77, 0x7112);
   FREG_VO_SetVohflt(78, 0x50482505);
   FREG_VO_SetVohflt(79, 0xaf39);
   
   FREG_VO_SetVohflt(80, 0xa984e4bb);
   FREG_VO_SetVohflt(81, 0x7100);
   FREG_VO_SetVohflt(82, 0x4e4a2a25);
   FREG_VO_SetVohflt(83, 0xac33);
   
   FREG_VO_SetVohflt(84, 0xa984e4bb);
   FREG_VO_SetVohflt(85, 0x7100);
   FREG_VO_SetVohflt(86, 0x4e4a2a25);
   FREG_VO_SetVohflt(87, 0xac33);
   
   FREG_VO_SetVohflt(88, 0x9b9cf08b);
   FREG_VO_SetVohflt(89, 0x71f0);
   FREG_VO_SetVohflt(90, 0x4c4d2e45);
   FREG_VO_SetVohflt(91, 0xa82e);
   
   FREG_VO_SetVohflt(92, 0x9b9cf08b);
   FREG_VO_SetVohflt(93, 0x71f0);
   FREG_VO_SetVohflt(94, 0x4c4d2e45);
   FREG_VO_SetVohflt(95, 0xa82e);
   
   FREG_VO_SetVohflt(96, 0x84a9008b);
   FREG_VO_SetVohflt(97, 0x77e4);
   FREG_VO_SetVohflt(98, 0x4a4e3365);
   FREG_VO_SetVohflt(99, 0xa42a);
   
   FREG_VO_SetVohflt(100, 0x84a9008b);
   FREG_VO_SetVohflt(101, 0x77e4);
   FREG_VO_SetVohflt(102, 0x4a4e3365);
   FREG_VO_SetVohflt(103, 0xa42a);
   
   FREG_VO_SetVohflt(104, 0x6aaf128b);
   FREG_VO_SetVohflt(105, 0x60dd);
   FREG_VO_SetVohflt(106, 0x4850397d);
   FREG_VO_SetVohflt(107, 0xa025);
   
   FREG_VO_SetVohflt(108, 0x6aaf128b);
   FREG_VO_SetVohflt(109, 0x60dd);
   FREG_VO_SetVohflt(110, 0x4850397d);
   FREG_VO_SetVohflt(111, 0xa025);
   
   FREG_VO_SetVohflt(112, 0x45af2f8b);
   FREG_VO_SetVohflt(113, 0x6bda);
   FREG_VO_SetVohflt(114, 0x4556417d);
   FREG_VO_SetVohflt(115, 0xbb1f);
   
   FREG_VO_SetVohflt(116, 0x45af2f8b);
   FREG_VO_SetVohflt(117, 0x6bda);
   FREG_VO_SetVohflt(118, 0x4556417d);
   FREG_VO_SetVohflt(119, 0xbb1f);
   
   FREG_VO_SetVohflt(120, 0x39ad398b);
   FREG_VO_SetVohflt(121, 0x6edb);
   FREG_VO_SetVohflt(122, 0x4556457d);
   FREG_VO_SetVohflt(123, 0xb91d);
   
   FREG_VO_SetVohflt(124, 0x39ad398b);
   FREG_VO_SetVohflt(125, 0x6edb);
   FREG_VO_SetVohflt(126, 0x4556457d);
   FREG_VO_SetVohflt(127, 0xb91d);
   
   FREG_VE_SetVoOsd1clut(0, 0x7a787bff);
   FREG_VE_SetVoOsd1clut(1, 0x7e7d7eff);
   FREG_VE_SetVoOsd1clut(2, 0x7c807dff);
   FREG_VE_SetVoOsd1clut(3, 0x7a837bff);
   FREG_VE_SetVoOsd1clut(4, 0x797c79ff);
   FREG_VE_SetVoOsd1clut(5, 0x77817cff);
   FREG_VE_SetVoOsd1clut(6, 0x6d9281ff);
   FREG_VE_SetVoOsd1clut(7, 0x6f8d80ff);
   FREG_VE_SetVoOsd1clut(8, 0x738683ff);
   FREG_VE_SetVoOsd1clut(9, 0x78947dff);
   FREG_VE_SetVoOsd1clut(10, 0x7b977dff);
   FREG_VE_SetVoOsd1clut(11, 0x7e867eff);
   FREG_VE_SetVoOsd1clut(12, 0x827d7dff);
   FREG_VE_SetVoOsd1clut(13, 0x7f817dff);
   FREG_VE_SetVoOsd1clut(14, 0x7a8a83ff);
   FREG_VE_SetVoOsd1clut(15, 0x7c6b7dff);
   FREG_VE_SetVoOsd1clut(16, 0x7c757dff);
   FREG_VE_SetVoOsd1clut(17, 0x7c8a7cff);
   FREG_VE_SetVoOsd1clut(18, 0x82697eff);
   FREG_VE_SetVoOsd1clut(19, 0x816c7cff);
   FREG_VE_SetVoOsd1clut(20, 0x788883ff);
   FREG_VE_SetVoOsd1clut(21, 0x81647fff);
   FREG_VE_SetVoOsd1clut(22, 0x83587fff);
   FREG_VE_SetVoOsd1clut(23, 0x83747dff);
   FREG_VE_SetVoOsd1clut(24, 0x777f7eff);
   FREG_VE_SetVoOsd1clut(25, 0x6b8080ff);
   FREG_VE_SetVoOsd1clut(26, 0x786781ff);
   FREG_VE_SetVoOsd1clut(27, 0x776a7eff);
   FREG_VE_SetVoOsd1clut(28, 0x766e84ff);
   FREG_VE_SetVoOsd1clut(29, 0x797983ff);
   FREG_VE_SetVoOsd1clut(30, 0x749184ff);
   FREG_VE_SetVoOsd1clut(31, 0x797b80ff);
   FREG_VE_SetVoOsd1clut(32, 0x767478ff);
   FREG_VE_SetVoOsd1clut(33, 0x78877aff);
   FREG_VE_SetVoOsd1clut(34, 0x79707cff);
   FREG_VE_SetVoOsd1clut(35, 0x795e7aff);
   FREG_VE_SetVoOsd1clut(36, 0x73667aff);
   FREG_VE_SetVoOsd1clut(37, 0x79647bff);
   FREG_VE_SetVoOsd1clut(38, 0x785281ff);
   FREG_VE_SetVoOsd1clut(39, 0x745d7cff);
   FREG_VE_SetVoOsd1clut(40, 0x766d7cff);
   FREG_VE_SetVoOsd1clut(41, 0x74867bff);
   FREG_VE_SetVoOsd1clut(42, 0x778d7dff);
   FREG_VE_SetVoOsd1clut(43, 0x77897fff);
   FREG_VE_SetVoOsd1clut(44, 0x767580ff);
   FREG_VE_SetVoOsd1clut(45, 0x7b8f7dff);
   FREG_VE_SetVoOsd1clut(46, 0x7c947dff);
   FREG_VE_SetVoOsd1clut(47, 0x7a7684ff);
   FREG_VE_SetVoOsd1clut(48, 0x7e727eff);
   FREG_VE_SetVoOsd1clut(49, 0x81777cff);
   FREG_VE_SetVoOsd1clut(50, 0x6b9682ff);
   FREG_VE_SetVoOsd1clut(51, 0x776b87ff);
   FREG_VE_SetVoOsd1clut(52, 0x776585ff);
   FREG_VE_SetVoOsd1clut(53, 0x74797eff);
   FREG_VE_SetVoOsd1clut(54, 0x73717bff);
   FREG_VE_SetVoOsd1clut(55, 0x7a5a7cff);
   FREG_VE_SetVoOsd1clut(56, 0x747183ff);
   FREG_VE_SetVoOsd1clut(57, 0x698a81ff);
   FREG_VE_SetVoOsd1clut(58, 0x717b8aff);
   FREG_VE_SetVoOsd1clut(59, 0x7e927eff);
   FREG_VE_SetVoOsd1clut(60, 0x7e687fff);
   FREG_VE_SetVoOsd1clut(61, 0x7f5f7cff);
   FREG_VE_SetVoOsd1clut(62, 0x717c7dff);
   FREG_VE_SetVoOsd1clut(63, 0x787383ff);
   FREG_VE_SetVoOsd1clut(64, 0x737480ff);
   FREG_VE_SetVoOsd1clut(65, 0x78617fff);
   FREG_VE_SetVoOsd1clut(66, 0x678884ff);
   FREG_VE_SetVoOsd1clut(67, 0x718981ff);
   FREG_VE_SetVoOsd1clut(68, 0x707f82ff);
   FREG_VE_SetVoOsd1clut(69, 0x79a081ff);
   FREG_VE_SetVoOsd1clut(70, 0x7a8384ff);
   FREG_VE_SetVoOsd1clut(71, 0x735f87ff);
   FREG_VE_SetVoOsd1clut(72, 0x71788dff);
   FREG_VE_SetVoOsd1clut(73, 0x7c577dff);
   FREG_VE_SetVoOsd1clut(74, 0x75637cff);
   FREG_VE_SetVoOsd1clut(75, 0x795f83ff);
   FREG_VE_SetVoOsd1clut(76, 0x7a9c82ff);
   FREG_VE_SetVoOsd1clut(77, 0x6e847fff);
   FREG_VE_SetVoOsd1clut(78, 0x749b80ff);
   FREG_VE_SetVoOsd1clut(79, 0x76a280ff);
   FREG_VE_SetVoOsd1clut(80, 0x7a6f83ff);
   FREG_VE_SetVoOsd1clut(81, 0x835f7eff);
   FREG_VE_SetVoOsd1clut(82, 0x74577bff);
   FREG_VE_SetVoOsd1clut(83, 0x727e86ff);
   FREG_VE_SetVoOsd1clut(84, 0x718997ff);
   FREG_VE_SetVoOsd1clut(85, 0x6f6e88ff);
   FREG_VE_SetVoOsd1clut(86, 0x70518aff);
   FREG_VE_SetVoOsd1clut(87, 0x735289ff);
   FREG_VE_SetVoOsd1clut(88, 0x6f5c87ff);
   FREG_VE_SetVoOsd1clut(89, 0x818c7dff);
   FREG_VE_SetVoOsd1clut(90, 0x7ca982ff);
   FREG_VE_SetVoOsd1clut(91, 0x78aa80ff);
   FREG_VE_SetVoOsd1clut(92, 0x739b8aff);
   FREG_VE_SetVoOsd1clut(93, 0x72988eff);
   FREG_VE_SetVoOsd1clut(94, 0x729580ff);
   FREG_VE_SetVoOsd1clut(95, 0x765a7dff);
   FREG_VE_SetVoOsd1clut(96, 0x72627eff);
   FREG_VE_SetVoOsd1clut(97, 0x735184ff);
   FREG_VE_SetVoOsd1clut(98, 0x669183ff);
   FREG_VE_SetVoOsd1clut(99, 0x6f9b82ff);
   FREG_VE_SetVoOsd1clut(100, 0x726886ff);
   FREG_VE_SetVoOsd1clut(101, 0x6f5a88ff);
   FREG_VE_SetVoOsd1clut(102, 0x744a86ff);
   FREG_VE_SetVoOsd1clut(103, 0x764e85ff);
   FREG_VE_SetVoOsd1clut(104, 0x715488ff);
   FREG_VE_SetVoOsd1clut(105, 0x714e86ff);
   FREG_VE_SetVoOsd1clut(106, 0x798d83ff);
   FREG_VE_SetVoOsd1clut(107, 0x71a293ff);
   FREG_VE_SetVoOsd1clut(108, 0x6ea381ff);
   FREG_VE_SetVoOsd1clut(109, 0x73a490ff);
   FREG_VE_SetVoOsd1clut(110, 0x738e8eff);
   FREG_VE_SetVoOsd1clut(111, 0x744d7bff);
   FREG_VE_SetVoOsd1clut(112, 0x77557dff);
   FREG_VE_SetVoOsd1clut(113, 0x758385ff);
   FREG_VE_SetVoOsd1clut(114, 0x764685ff);
   FREG_VE_SetVoOsd1clut(115, 0x794887ff);
   FREG_VE_SetVoOsd1clut(116, 0x755686ff);
   FREG_VE_SetVoOsd1clut(117, 0x709c97ff);
   FREG_VE_SetVoOsd1clut(118, 0x71928dff);
   FREG_VE_SetVoOsd1clut(119, 0x735f78ff);
   FREG_VE_SetVoOsd1clut(120, 0x754781ff);
   FREG_VE_SetVoOsd1clut(121, 0x784a85ff);
   FREG_VE_SetVoOsd1clut(122, 0x6e838dff);
   FREG_VE_SetVoOsd1clut(123, 0x718990ff);
   FREG_VE_SetVoOsd1clut(124, 0x7b5a83ff);
   FREG_VE_SetVoOsd1clut(125, 0x73498bff);
   FREG_VE_SetVoOsd1clut(126, 0x755a86ff);
   FREG_VE_SetVoOsd1clut(127, 0x768187ff);
   FREG_VE_SetVoOsd1clut(128, 0x739e96ff);
   FREG_VE_SetVoOsd1clut(129, 0x799283ff);
   FREG_VE_SetVoOsd1clut(130, 0x784285ff);
   FREG_VE_SetVoOsd1clut(131, 0x7b477fff);
   FREG_VE_SetVoOsd1clut(132, 0x6e7592ff);
   FREG_VE_SetVoOsd1clut(133, 0x6e9897ff);
   FREG_VE_SetVoOsd1clut(134, 0x7e547fff);
   FREG_VE_SetVoOsd1clut(135, 0x6e777fff);
   FREG_VE_SetVoOsd1clut(136, 0x704f8eff);
   FREG_VE_SetVoOsd1clut(137, 0x708092ff);
   FREG_VE_SetVoOsd1clut(138, 0x729a99ff);
   FREG_VE_SetVoOsd1clut(139, 0x76998cff);
   FREG_VE_SetVoOsd1clut(140, 0x7a4a7eff);
   FREG_VE_SetVoOsd1clut(141, 0x7a9883ff);
   FREG_VE_SetVoOsd1clut(142, 0x7b4582ff);
   FREG_VE_SetVoOsd1clut(143, 0x6e5a92ff);
   FREG_VE_SetVoOsd1clut(144, 0x6e6897ff);
   FREG_VE_SetVoOsd1clut(145, 0x734586ff);
   FREG_VE_SetVoOsd1clut(146, 0x7b6684ff);
   FREG_VE_SetVoOsd1clut(147, 0x716284ff);
   FREG_VE_SetVoOsd1clut(148, 0x6a7a7dff);
   FREG_VE_SetVoOsd1clut(149, 0x754187ff);
   FREG_VE_SetVoOsd1clut(150, 0x6e6e81ff);
   FREG_VE_SetVoOsd1clut(151, 0x717192ff);
   FREG_VE_SetVoOsd1clut(152, 0x763e83ff);
   FREG_VE_SetVoOsd1clut(153, 0x715977ff);
   FREG_VE_SetVoOsd1clut(154, 0x706a7bff);
   FREG_VE_SetVoOsd1clut(155, 0x6c7280ff);
   FREG_VE_SetVoOsd1clut(156, 0x706479ff);
   FREG_VE_SetVoOsd1clut(157, 0x779e8dff);
   FREG_VE_SetVoOsd1clut(158, 0x776288ff);
   FREG_VE_SetVoOsd1clut(159, 0x783b84ff);
   FREG_VE_SetVoOsd1clut(160, 0x7f9d7fff);
   FREG_VE_SetVoOsd1clut(161, 0x7db681ff);
   FREG_VE_SetVoOsd1clut(162, 0x7aa682ff);
   FREG_VE_SetVoOsd1clut(163, 0x7aac82ff);
   FREG_VE_SetVoOsd1clut(164, 0x76508fff);
   FREG_VE_SetVoOsd1clut(165, 0x783e8aff);
   FREG_VE_SetVoOsd1clut(166, 0x71aa80ff);
   FREG_VE_SetVoOsd1clut(167, 0x779d91ff);
   FREG_VE_SetVoOsd1clut(168, 0x7ba484ff);
   FREG_VE_SetVoOsd1clut(169, 0x7cb080ff);
   FREG_VE_SetVoOsd1clut(170, 0x73979aff);
   FREG_VE_SetVoOsd1clut(171, 0x7da181ff);
   FREG_VE_SetVoOsd1clut(172, 0x749591ff);
   FREG_VE_SetVoOsd1clut(173, 0x78a385ff);
   FREG_VE_SetVoOsd1clut(174, 0x70949aff);
   FREG_VE_SetVoOsd1clut(175, 0x743b85ff);
   FREG_VE_SetVoOsd1clut(176, 0x6f909aff);
   FREG_VE_SetVoOsd1clut(177, 0x72919bff);
   FREG_VE_SetVoOsd1clut(178, 0x6a8ba0ff);
   FREG_VE_SetVoOsd1clut(179, 0x708c9cff);
   FREG_VE_SetVoOsd1clut(180, 0x763987ff);
   FREG_VE_SetVoOsd1clut(181, 0x6f819dff);
   FREG_VE_SetVoOsd1clut(182, 0x717d95ff);
   FREG_VE_SetVoOsd1clut(183, 0x773684ff);
   FREG_VE_SetVoOsd1clut(184, 0x7b3685ff);
   FREG_VE_SetVoOsd1clut(185, 0x7d418bff);
   FREG_VE_SetVoOsd1clut(186, 0x6d84a0ff);
   FREG_VE_SetVoOsd1clut(187, 0x70889dff);
   FREG_VE_SetVoOsd1clut(188, 0x6a7da0ff);
   FREG_VE_SetVoOsd1clut(189, 0x657ea3ff);
   FREG_VE_SetVoOsd1clut(190, 0x7a398fff);
   FREG_VE_SetVoOsd1clut(191, 0x6879a2ff);
   FREG_VE_SetVoOsd1clut(192, 0x783b8eff);
   FREG_VE_SetVoOsd1clut(193, 0x6e7fa0ff);
   FREG_VE_SetVoOsd1clut(194, 0x71869aff);
   FREG_VE_SetVoOsd1clut(195, 0x6c879eff);
   FREG_VE_SetVoOsd1clut(196, 0x6874a2ff);
   FREG_VE_SetVoOsd1clut(197, 0x686ba4ff);
   FREG_VE_SetVoOsd1clut(198, 0x707a9eff);
   FREG_VE_SetVoOsd1clut(199, 0x774d90ff);
   FREG_VE_SetVoOsd1clut(200, 0x724b97ff);
   FREG_VE_SetVoOsd1clut(201, 0x6968a5ff);
   FREG_VE_SetVoOsd1clut(202, 0x6962a6ff);
   FREG_VE_SetVoOsd1clut(203, 0x6c79a0ff);
   FREG_VE_SetVoOsd1clut(204, 0x754194ff);
   FREG_VE_SetVoOsd1clut(205, 0x704e94ff);
   FREG_VE_SetVoOsd1clut(206, 0x6d759cff);
   FREG_VE_SetVoOsd1clut(207, 0x706c9eff);
   FREG_VE_SetVoOsd1clut(208, 0x707c9cff);
   FREG_VE_SetVoOsd1clut(209, 0x7a3184ff);
   FREG_VE_SetVoOsd1clut(210, 0x744595ff);
   FREG_VE_SetVoOsd1clut(211, 0x6b6d9fff);
   FREG_VE_SetVoOsd1clut(212, 0x6e6ea1ff);
   FREG_VE_SetVoOsd1clut(213, 0x695da6ff);
   FREG_VE_SetVoOsd1clut(214, 0x6f6f9bff);
   FREG_VE_SetVoOsd1clut(215, 0x753a92ff);
   FREG_VE_SetVoOsd1clut(216, 0x6f559aff);
   FREG_VE_SetVoOsd1clut(217, 0x6e73a0ff);
   FREG_VE_SetVoOsd1clut(218, 0x71489aff);
   FREG_VE_SetVoOsd1clut(219, 0x6e539cff);
   FREG_VE_SetVoOsd1clut(220, 0x6f5e97ff);
   FREG_VE_SetVoOsd1clut(221, 0x72849cff);
   FREG_VE_SetVoOsd1clut(222, 0x6b59a6ff);
   FREG_VE_SetVoOsd1clut(223, 0x70429aff);
   FREG_VE_SetVoOsd1clut(224, 0x6f4f9cff);
   FREG_VE_SetVoOsd1clut(225, 0x6e599eff);
   FREG_VE_SetVoOsd1clut(226, 0x733e99ff);
   FREG_VE_SetVoOsd1clut(227, 0x6d69a0ff);
   FREG_VE_SetVoOsd1clut(228, 0x79338eff);
   FREG_VE_SetVoOsd1clut(229, 0x743795ff);
   FREG_VE_SetVoOsd1clut(230, 0x723f94ff);
   FREG_VE_SetVoOsd1clut(231, 0x6d5d9dff);
   FREG_VE_SetVoOsd1clut(232, 0x74348aff);
   FREG_VE_SetVoOsd1clut(233, 0x6d639eff);
   FREG_VE_SetVoOsd1clut(234, 0x782e90ff);
   FREG_VE_SetVoOsd1clut(235, 0x753398ff);
   FREG_VE_SetVoOsd1clut(236, 0x6c659aff);
   FREG_VE_SetVoOsd1clut(237, 0x76328fff);
   FREG_VE_SetVoOsd1clut(238, 0x742d93ff);
   FREG_VE_SetVoOsd1clut(239, 0x70659dff);
   FREG_VE_SetVoOsd1clut(240, 0x6e61a1ff);
   FREG_VE_SetVoOsd1clut(241, 0x762993ff);
   FREG_VE_SetVoOsd1clut(242, 0x763185ff);
   FREG_VE_SetVoOsd1clut(243, 0x72539bff);
   FREG_VE_SetVoOsd1clut(244, 0x705e9dff);
   FREG_VE_SetVoOsd1clut(245, 0x792c84ff);
   FREG_VE_SetVoOsd1clut(246, 0x7c2e83ff);
   FREG_VE_SetVoOsd1clut(247, 0x7d1f86ff);
   FREG_VE_SetVoOsd1clut(248, 0x7b2888ff);
   FREG_VE_SetVoOsd1clut(249, 0x782190ff);
   FREG_VE_SetVoOsd1clut(250, 0x762b8cff);
   FREG_VE_SetVoOsd1clut(251, 0x78278dff);
   FREG_VE_SetVoOsd1clut(252, 0x7b2287ff);
   FREG_VE_SetVoOsd1clut(253, 0x79248fff);
   FREG_VE_SetVoOsd1clut(254, 0x7b1d8bff);
   FREG_VE_SetVoOsd1clut(255, 0xFF);
   
   FREG_VO_SetOsd1hflt(0, 0x00ff00ff);
   FREG_VO_SetOsd1hflt(1, 0xff);
   FREG_VO_SetOsd1hflt(2, 0x00ff00ff);
   FREG_VO_SetOsd1hflt(3, 0xff);
   FREG_VO_SetOsd1hflt(4, 0x10f010f0);
   FREG_VO_SetOsd1hflt(5, 0x000010f0);
   FREG_VO_SetOsd1hflt(6, 0x10f010f0);
   FREG_VO_SetOsd1hflt(7, 0x000010f0);
   FREG_VO_SetOsd1hflt(8, 0x20e020e0);
   FREG_VO_SetOsd1hflt(9, 0x000020e0);
   FREG_VO_SetOsd1hflt(10, 0x20e020e0);
   FREG_VO_SetOsd1hflt(11, 0x000020e0);
   FREG_VO_SetOsd1hflt(12, 0x30d030d0);
   FREG_VO_SetOsd1hflt(13, 0x000030d0);
   FREG_VO_SetOsd1hflt(14, 0x30d030d0);
   FREG_VO_SetOsd1hflt(15, 0x000030d0);
   FREG_VO_SetOsd1hflt(16, 0x40c040c0);
   FREG_VO_SetOsd1hflt(17, 0x000040c0);
   FREG_VO_SetOsd1hflt(18, 0x40c040c0);
   FREG_VO_SetOsd1hflt(19, 0x000040c0);
   FREG_VO_SetOsd1hflt(20, 0x50b050b0);
   FREG_VO_SetOsd1hflt(21, 0x000050b0);
   FREG_VO_SetOsd1hflt(22, 0x50b050b0);
   FREG_VO_SetOsd1hflt(23, 0x000050b0);
   FREG_VO_SetOsd1hflt(24, 0x60a060a0);
   FREG_VO_SetOsd1hflt(25, 0x000060a0);
   FREG_VO_SetOsd1hflt(26, 0x60a060a0);
   FREG_VO_SetOsd1hflt(27, 0x000060a0);
   FREG_VO_SetOsd1hflt(28, 0x70907090);
   FREG_VO_SetOsd1hflt(29, 0x00007090);
   FREG_VO_SetOsd1hflt(30, 0x70907090);
   FREG_VO_SetOsd1hflt(31, 0x00007090);
   FREG_VO_SetOsd1hflt(32, 0x80808080);
   FREG_VO_SetOsd1hflt(33, 0x80808080);
   FREG_VO_SetOsd1hflt(34, 0x80808080);
   FREG_VO_SetOsd1hflt(35, 0x80808080);
   FREG_VO_SetOsd1hflt(36, 0x90709070);
   FREG_VO_SetOsd1hflt(37, 0x00009070);
   FREG_VO_SetOsd1hflt(38, 0x90709070);
   FREG_VO_SetOsd1hflt(39, 0x00009070);
   FREG_VO_SetOsd1hflt(40, 0xa060a060);
   FREG_VO_SetOsd1hflt(41, 0x0000a060);
   FREG_VO_SetOsd1hflt(42, 0xa060a060);
   FREG_VO_SetOsd1hflt(43, 0x0000a060);
   FREG_VO_SetOsd1hflt(44, 0xb050b050);
   FREG_VO_SetOsd1hflt(45, 0x0000b050);
   FREG_VO_SetOsd1hflt(46, 0xb050b050);
   FREG_VO_SetOsd1hflt(47, 0x0000b050);
   FREG_VO_SetOsd1hflt(48, 0xc040c040);
   FREG_VO_SetOsd1hflt(49, 0x0000c040);
   FREG_VO_SetOsd1hflt(50, 0xc040c040);
   FREG_VO_SetOsd1hflt(51, 0x0000c040);
   FREG_VO_SetOsd1hflt(52, 0xd030d030);
   FREG_VO_SetOsd1hflt(53, 0x0000d030);
   FREG_VO_SetOsd1hflt(54, 0xd030d030);
   FREG_VO_SetOsd1hflt(55, 0x0000d030);
   FREG_VO_SetOsd1hflt(56, 0xe020e020);
   FREG_VO_SetOsd1hflt(57, 0x0000e020);
   FREG_VO_SetOsd1hflt(58, 0xe020e020);
   FREG_VO_SetOsd1hflt(59, 0x0000e020);
   FREG_VO_SetOsd1hflt(60, 0xf010f010);
   FREG_VO_SetOsd1hflt(61, 0x0000f010);
   FREG_VO_SetOsd1hflt(62, 0xf010f010);
   FREG_VO_SetOsd1hflt(63, 0x0000f010);
   FREG_VO_SetOsd1hflt(64, 0xfe020000);
   FREG_VO_SetOsd1hflt(65, 0);
   FREG_VO_SetOsd1hflt(66, 0xadaec67d);
   FREG_VO_SetOsd1hflt(67, 0x0000afc6);
   FREG_VO_SetOsd1hflt(68, 0xfe11f82d);
   FREG_VO_SetOsd1hflt(69, 0x0000a8f1);
   FREG_VO_SetOsd1hflt(70, 0x96c2c57d);
   FREG_VO_SetOsd1hflt(71, 0x0000afca);
   FREG_VO_SetOsd1hflt(72, 0xf423f05d);
   FREG_VO_SetOsd1hflt(73, 0x0000aee5);
   FREG_VO_SetOsd1hflt(74, 0x7fd3c67d);
   FREG_VO_SetOsd1hflt(75, 0x0000afcf);
   FREG_VO_SetOsd1hflt(76, 0xed37e87d);
   FREG_VO_SetOsd1hflt(77, 0x0000afdb);
   FREG_VO_SetOsd1hflt(78, 0x66dfcb7d);
   FREG_VO_SetOsd1hflt(79, 0x0000afd7);
   FREG_VO_SetOsd1hflt(80, 0xe94edf7d);
   FREG_VO_SetOsd1hflt(81, 0x0000afd1);
   FREG_VO_SetOsd1hflt(82, 0x4ee9d17d);
   FREG_VO_SetOsd1hflt(83, 0x0000afdf);
   FREG_VO_SetOsd1hflt(84, 0xdf66d77d);
   FREG_VO_SetOsd1hflt(85, 0x0000afcb);
   FREG_VO_SetOsd1hflt(86, 0x37eddb7d);
   FREG_VO_SetOsd1hflt(87, 0x0000afe8);
   FREG_VO_SetOsd1hflt(88, 0xd37fcf7d);
   FREG_VO_SetOsd1hflt(89, 0x0000afc6);
   FREG_VO_SetOsd1hflt(90, 0x23f4e575);
   FREG_VO_SetOsd1hflt(91, 0x0000abf0);
   FREG_VO_SetOsd1hflt(92, 0xc296ca7d);
   FREG_VO_SetOsd1hflt(93, 0x0000afc5);
   FREG_VO_SetOsd1hflt(94, 0x11fef145);
   FREG_VO_SetOsd1hflt(95, 0x0000a5f8);
   FREG_VO_SetOsd1hflt(96, 0xaeadc67d);
   FREG_VO_SetOsd1hflt(97, 0x0000afc6);
   FREG_VO_SetOsd1hflt(98, 0x02fe0000);
   FREG_VO_SetOsd1hflt(99, 0);
   FREG_VO_SetOsd1hflt(100, 0x97c1c57d);
   FREG_VO_SetOsd1hflt(101, 0x0000afca);
   FREG_VO_SetOsd1hflt(102, 0x00ef10c3);
   FREG_VO_SetOsd1hflt(103, 0x00007b07);
   FREG_VO_SetOsd1hflt(104, 0x7fd3c67d);
   FREG_VO_SetOsd1hflt(105, 0x0000afcf);
   FREG_VO_SetOsd1hflt(106, 0x01e3208b);
   FREG_VO_SetOsd1hflt(107, 0x0000770d);
   FREG_VO_SetOsd1hflt(108, 0x66dfcb7d);
   FREG_VO_SetOsd1hflt(109, 0x0000afd7);
   FREG_VO_SetOsd1hflt(110, 0x00d2308b);
   FREG_VO_SetOsd1hflt(111, 0x00007412);
   FREG_VO_SetOsd1hflt(112, 0x4ee9d17d);
   FREG_VO_SetOsd1hflt(113, 0x0000afdf);
   FREG_VO_SetOsd1hflt(114, 0x01c1408b);
   FREG_VO_SetOsd1hflt(115, 0x00007115);
   FREG_VO_SetOsd1hflt(116, 0x37eddb7d);
   FREG_VO_SetOsd1hflt(117, 0x0000afe8);
   FREG_VO_SetOsd1hflt(118, 0x00af508b);
   FREG_VO_SetOsd1hflt(119, 0x00007118);
   FREG_VO_SetOsd1hflt(120, 0x23f4e575);
   FREG_VO_SetOsd1hflt(121, 0x0000abf0);
   FREG_VO_SetOsd1hflt(122, 0x009f5f8b);
   FREG_VO_SetOsd1hflt(123, 0x00007119);
   FREG_VO_SetOsd1hflt(124, 0x11fef145);
   FREG_VO_SetOsd1hflt(125, 0x0000a5f8);
   FREG_VO_SetOsd1hflt(126, 0x008e6f8b);
   FREG_VO_SetOsd1hflt(127, 0x0000711a);

   FREG_VE_SetVoOsd2clut(0, 0x7a787bff);
   FREG_VE_SetVoOsd2clut(1, 0x7e7d7eff);
   FREG_VE_SetVoOsd2clut(2, 0x7c807dff);
   FREG_VE_SetVoOsd2clut(3, 0x7a837bff);
   FREG_VE_SetVoOsd2clut(4, 0x797c79ff);
   FREG_VE_SetVoOsd2clut(5, 0x77817cff);
   FREG_VE_SetVoOsd2clut(6, 0x6d9281ff);
   FREG_VE_SetVoOsd2clut(7, 0x6f8d80ff);
   FREG_VE_SetVoOsd2clut(8, 0x738683ff);
   FREG_VE_SetVoOsd2clut(9, 0x78947dff);
   FREG_VE_SetVoOsd2clut(10, 0x7b977dff);
   FREG_VE_SetVoOsd2clut(11, 0x7e867eff);
   FREG_VE_SetVoOsd2clut(12, 0x827d7dff);
   FREG_VE_SetVoOsd2clut(13, 0x7f817dff);
   FREG_VE_SetVoOsd2clut(14, 0x7a8a83ff);
   FREG_VE_SetVoOsd2clut(15, 0x7c6b7dff);
   FREG_VE_SetVoOsd2clut(16, 0x7c757dff);
   FREG_VE_SetVoOsd2clut(17, 0x7c8a7cff);
   FREG_VE_SetVoOsd2clut(18, 0x82697eff);
   FREG_VE_SetVoOsd2clut(19, 0x816c7cff);
   FREG_VE_SetVoOsd2clut(20, 0x788883ff);
   FREG_VE_SetVoOsd2clut(21, 0x81647fff);
   FREG_VE_SetVoOsd2clut(22, 0x83587fff);
   FREG_VE_SetVoOsd2clut(23, 0x83747dff);
   FREG_VE_SetVoOsd2clut(24, 0x777f7eff);
   FREG_VE_SetVoOsd2clut(25, 0x6b8080ff);
   FREG_VE_SetVoOsd2clut(26, 0x786781ff);
   FREG_VE_SetVoOsd2clut(27, 0x776a7eff);
   FREG_VE_SetVoOsd2clut(28, 0x766e84ff);
   FREG_VE_SetVoOsd2clut(29, 0x797983ff);
   FREG_VE_SetVoOsd2clut(30, 0x749184ff);
   FREG_VE_SetVoOsd2clut(31, 0x797b80ff);
   FREG_VE_SetVoOsd2clut(32, 0x767478ff);
   FREG_VE_SetVoOsd2clut(33, 0x78877aff);
   FREG_VE_SetVoOsd2clut(34, 0x79707cff);
   FREG_VE_SetVoOsd2clut(35, 0x795e7aff);
   FREG_VE_SetVoOsd2clut(36, 0x73667aff);
   FREG_VE_SetVoOsd2clut(37, 0x79647bff);
   FREG_VE_SetVoOsd2clut(38, 0x785281ff);
   FREG_VE_SetVoOsd2clut(39, 0x745d7cff);
   FREG_VE_SetVoOsd2clut(40, 0x766d7cff);
   FREG_VE_SetVoOsd2clut(41, 0x74867bff);
   FREG_VE_SetVoOsd2clut(42, 0x778d7dff);
   FREG_VE_SetVoOsd2clut(43, 0x77897fff);
   FREG_VE_SetVoOsd2clut(44, 0x767580ff);
   FREG_VE_SetVoOsd2clut(45, 0x7b8f7dff);
   FREG_VE_SetVoOsd2clut(46, 0x7c947dff);
   FREG_VE_SetVoOsd2clut(47, 0x7a7684ff);
   FREG_VE_SetVoOsd2clut(48, 0x7e727eff);
   FREG_VE_SetVoOsd2clut(49, 0x81777cff);
   FREG_VE_SetVoOsd2clut(50, 0x6b9682ff);
   FREG_VE_SetVoOsd2clut(51, 0x776b87ff);
   FREG_VE_SetVoOsd2clut(52, 0x776585ff);
   FREG_VE_SetVoOsd2clut(53, 0x74797eff);
   FREG_VE_SetVoOsd2clut(54, 0x73717bff);
   FREG_VE_SetVoOsd2clut(55, 0x7a5a7cff);
   FREG_VE_SetVoOsd2clut(56, 0x747183ff);
   FREG_VE_SetVoOsd2clut(57, 0x698a81ff);
   FREG_VE_SetVoOsd2clut(58, 0x717b8aff);
   FREG_VE_SetVoOsd2clut(59, 0x7e927eff);
   FREG_VE_SetVoOsd2clut(60, 0x7e687fff);
   FREG_VE_SetVoOsd2clut(61, 0x7f5f7cff);
   FREG_VE_SetVoOsd2clut(62, 0x717c7dff);
   FREG_VE_SetVoOsd2clut(63, 0x787383ff);
   FREG_VE_SetVoOsd2clut(64, 0x737480ff);
   FREG_VE_SetVoOsd2clut(65, 0x78617fff);
   FREG_VE_SetVoOsd2clut(66, 0x678884ff);
   FREG_VE_SetVoOsd2clut(67, 0x718981ff);
   FREG_VE_SetVoOsd2clut(68, 0x707f82ff);
   FREG_VE_SetVoOsd2clut(69, 0x79a081ff);
   FREG_VE_SetVoOsd2clut(70, 0x7a8384ff);
   FREG_VE_SetVoOsd2clut(71, 0x735f87ff);
   FREG_VE_SetVoOsd2clut(72, 0x71788dff);
   FREG_VE_SetVoOsd2clut(73, 0x7c577dff);
   FREG_VE_SetVoOsd2clut(74, 0x75637cff);
   FREG_VE_SetVoOsd2clut(75, 0x795f83ff);
   FREG_VE_SetVoOsd2clut(76, 0x7a9c82ff);
   FREG_VE_SetVoOsd2clut(77, 0x6e847fff);
   FREG_VE_SetVoOsd2clut(78, 0x749b80ff);
   FREG_VE_SetVoOsd2clut(79, 0x76a280ff);
   FREG_VE_SetVoOsd2clut(80, 0x7a6f83ff);
   FREG_VE_SetVoOsd2clut(81, 0x835f7eff);
   FREG_VE_SetVoOsd2clut(82, 0x74577bff);
   FREG_VE_SetVoOsd2clut(83, 0x727e86ff);
   FREG_VE_SetVoOsd2clut(84, 0x718997ff);
   FREG_VE_SetVoOsd2clut(85, 0x6f6e88ff);
   FREG_VE_SetVoOsd2clut(86, 0x70518aff);
   FREG_VE_SetVoOsd2clut(87, 0x735289ff);
   FREG_VE_SetVoOsd2clut(88, 0x6f5c87ff);
   FREG_VE_SetVoOsd2clut(89, 0x818c7dff);
   FREG_VE_SetVoOsd2clut(90, 0x7ca982ff);
   FREG_VE_SetVoOsd2clut(91, 0x78aa80ff);
   FREG_VE_SetVoOsd2clut(92, 0x739b8aff);
   FREG_VE_SetVoOsd2clut(93, 0x72988eff);
   FREG_VE_SetVoOsd2clut(94, 0x729580ff);
   FREG_VE_SetVoOsd2clut(95, 0x765a7dff);
   FREG_VE_SetVoOsd2clut(96, 0x72627eff);
   FREG_VE_SetVoOsd2clut(97, 0x735184ff);
   FREG_VE_SetVoOsd2clut(98, 0x669183ff);
   FREG_VE_SetVoOsd2clut(99, 0x6f9b82ff);
   FREG_VE_SetVoOsd2clut(100, 0x726886ff);
   FREG_VE_SetVoOsd2clut(101, 0x6f5a88ff);
   FREG_VE_SetVoOsd2clut(102, 0x744a86ff);
   FREG_VE_SetVoOsd2clut(103, 0x764e85ff);
   FREG_VE_SetVoOsd2clut(104, 0x715488ff);
   FREG_VE_SetVoOsd2clut(105, 0x714e86ff);
   FREG_VE_SetVoOsd2clut(106, 0x798d83ff);
   FREG_VE_SetVoOsd2clut(107, 0x71a293ff);
   FREG_VE_SetVoOsd2clut(108, 0x6ea381ff);
   FREG_VE_SetVoOsd2clut(109, 0x73a490ff);
   FREG_VE_SetVoOsd2clut(110, 0x738e8eff);
   FREG_VE_SetVoOsd2clut(111, 0x744d7bff);
   FREG_VE_SetVoOsd2clut(112, 0x77557dff);
   FREG_VE_SetVoOsd2clut(113, 0x758385ff);
   FREG_VE_SetVoOsd2clut(114, 0x764685ff);
   FREG_VE_SetVoOsd2clut(115, 0x794887ff);
   FREG_VE_SetVoOsd2clut(116, 0x755686ff);
   FREG_VE_SetVoOsd2clut(117, 0x709c97ff);
   FREG_VE_SetVoOsd2clut(118, 0x71928dff);
   FREG_VE_SetVoOsd2clut(119, 0x735f78ff);
   FREG_VE_SetVoOsd2clut(120, 0x754781ff);
   FREG_VE_SetVoOsd2clut(121, 0x784a85ff);
   FREG_VE_SetVoOsd2clut(122, 0x6e838dff);
   FREG_VE_SetVoOsd2clut(123, 0x718990ff);
   FREG_VE_SetVoOsd2clut(124, 0x7b5a83ff);
   FREG_VE_SetVoOsd2clut(125, 0x73498bff);
   FREG_VE_SetVoOsd2clut(126, 0x755a86ff);
   FREG_VE_SetVoOsd2clut(127, 0x768187ff);
   FREG_VE_SetVoOsd2clut(128, 0x739e96ff);
   FREG_VE_SetVoOsd2clut(129, 0x799283ff);
   FREG_VE_SetVoOsd2clut(130, 0x784285ff);
   FREG_VE_SetVoOsd2clut(131, 0x7b477fff);
   FREG_VE_SetVoOsd2clut(132, 0x6e7592ff);
   FREG_VE_SetVoOsd2clut(133, 0x6e9897ff);
   FREG_VE_SetVoOsd2clut(134, 0x7e547fff);
   FREG_VE_SetVoOsd2clut(135, 0x6e777fff);
   FREG_VE_SetVoOsd2clut(136, 0x704f8eff);
   FREG_VE_SetVoOsd2clut(137, 0x708092ff);
   FREG_VE_SetVoOsd2clut(138, 0x729a99ff);
   FREG_VE_SetVoOsd2clut(139, 0x76998cff);
   FREG_VE_SetVoOsd2clut(140, 0x7a4a7eff);
   FREG_VE_SetVoOsd2clut(141, 0x7a9883ff);
   FREG_VE_SetVoOsd2clut(142, 0x7b4582ff);
   FREG_VE_SetVoOsd2clut(143, 0x6e5a92ff);
   FREG_VE_SetVoOsd2clut(144, 0x6e6897ff);
   FREG_VE_SetVoOsd2clut(145, 0x734586ff);
   FREG_VE_SetVoOsd2clut(146, 0x7b6684ff);
   FREG_VE_SetVoOsd2clut(147, 0x716284ff);
   FREG_VE_SetVoOsd2clut(148, 0x6a7a7dff);
   FREG_VE_SetVoOsd2clut(149, 0x754187ff);
   FREG_VE_SetVoOsd2clut(150, 0x6e6e81ff);
   FREG_VE_SetVoOsd2clut(151, 0x717192ff);
   FREG_VE_SetVoOsd2clut(152, 0x763e83ff);
   FREG_VE_SetVoOsd2clut(153, 0x715977ff);
   FREG_VE_SetVoOsd2clut(154, 0x706a7bff);
   FREG_VE_SetVoOsd2clut(155, 0x6c7280ff);
   FREG_VE_SetVoOsd2clut(156, 0x706479ff);
   FREG_VE_SetVoOsd2clut(157, 0x779e8dff);
   FREG_VE_SetVoOsd2clut(158, 0x776288ff);
   FREG_VE_SetVoOsd2clut(159, 0x783b84ff);
   FREG_VE_SetVoOsd2clut(160, 0x7f9d7fff);
   FREG_VE_SetVoOsd2clut(161, 0x7db681ff);
   FREG_VE_SetVoOsd2clut(162, 0x7aa682ff);
   FREG_VE_SetVoOsd2clut(163, 0x7aac82ff);
   FREG_VE_SetVoOsd2clut(164, 0x76508fff);
   FREG_VE_SetVoOsd2clut(165, 0x783e8aff);
   FREG_VE_SetVoOsd2clut(166, 0x71aa80ff);
   FREG_VE_SetVoOsd2clut(167, 0x779d91ff);
   FREG_VE_SetVoOsd2clut(168, 0x7ba484ff);
   FREG_VE_SetVoOsd2clut(169, 0x7cb080ff);
   FREG_VE_SetVoOsd2clut(170, 0x73979aff);
   FREG_VE_SetVoOsd2clut(171, 0x7da181ff);
   FREG_VE_SetVoOsd2clut(172, 0x749591ff);
   FREG_VE_SetVoOsd2clut(173, 0x78a385ff);
   FREG_VE_SetVoOsd2clut(174, 0x70949aff);
   FREG_VE_SetVoOsd2clut(175, 0x743b85ff);
   FREG_VE_SetVoOsd2clut(176, 0x6f909aff);
   FREG_VE_SetVoOsd2clut(177, 0x72919bff);
   FREG_VE_SetVoOsd2clut(178, 0x6a8ba0ff);
   FREG_VE_SetVoOsd2clut(179, 0x708c9cff);
   FREG_VE_SetVoOsd2clut(180, 0x763987ff);
   FREG_VE_SetVoOsd2clut(181, 0x6f819dff);
   FREG_VE_SetVoOsd2clut(182, 0x717d95ff);
   FREG_VE_SetVoOsd2clut(183, 0x773684ff);
   FREG_VE_SetVoOsd2clut(184, 0x7b3685ff);
   FREG_VE_SetVoOsd2clut(185, 0x7d418bff);
   FREG_VE_SetVoOsd2clut(186, 0x6d84a0ff);
   FREG_VE_SetVoOsd2clut(187, 0x70889dff);
   FREG_VE_SetVoOsd2clut(188, 0x6a7da0ff);
   FREG_VE_SetVoOsd2clut(189, 0x657ea3ff);
   FREG_VE_SetVoOsd2clut(190, 0x7a398fff);
   FREG_VE_SetVoOsd2clut(191, 0x6879a2ff);
   FREG_VE_SetVoOsd2clut(192, 0x783b8eff);
   FREG_VE_SetVoOsd2clut(193, 0x6e7fa0ff);
   FREG_VE_SetVoOsd2clut(194, 0x71869aff);
   FREG_VE_SetVoOsd2clut(195, 0x6c879eff);
   FREG_VE_SetVoOsd2clut(196, 0x6874a2ff);
   FREG_VE_SetVoOsd2clut(197, 0x686ba4ff);
   FREG_VE_SetVoOsd2clut(198, 0x707a9eff);
   FREG_VE_SetVoOsd2clut(199, 0x774d90ff);
   FREG_VE_SetVoOsd2clut(200, 0x724b97ff);
   FREG_VE_SetVoOsd2clut(201, 0x6968a5ff);
   FREG_VE_SetVoOsd2clut(202, 0x6962a6ff);
   FREG_VE_SetVoOsd2clut(203, 0x6c79a0ff);
   FREG_VE_SetVoOsd2clut(204, 0x754194ff);
   FREG_VE_SetVoOsd2clut(205, 0x704e94ff);
   FREG_VE_SetVoOsd2clut(206, 0x6d759cff);
   FREG_VE_SetVoOsd2clut(207, 0x706c9eff);
   FREG_VE_SetVoOsd2clut(208, 0x707c9cff);
   FREG_VE_SetVoOsd2clut(209, 0x7a3184ff);
   FREG_VE_SetVoOsd2clut(210, 0x744595ff);
   FREG_VE_SetVoOsd2clut(211, 0x6b6d9fff);
   FREG_VE_SetVoOsd2clut(212, 0x6e6ea1ff);
   FREG_VE_SetVoOsd2clut(213, 0x695da6ff);
   FREG_VE_SetVoOsd2clut(214, 0x6f6f9bff);
   FREG_VE_SetVoOsd2clut(215, 0x753a92ff);
   FREG_VE_SetVoOsd2clut(216, 0x6f559aff);
   FREG_VE_SetVoOsd2clut(217, 0x6e73a0ff);
   FREG_VE_SetVoOsd2clut(218, 0x71489aff);
   FREG_VE_SetVoOsd2clut(219, 0x6e539cff);
   FREG_VE_SetVoOsd2clut(220, 0x6f5e97ff);
   FREG_VE_SetVoOsd2clut(221, 0x72849cff);
   FREG_VE_SetVoOsd2clut(222, 0x6b59a6ff);
   FREG_VE_SetVoOsd2clut(223, 0x70429aff);
   FREG_VE_SetVoOsd2clut(224, 0x6f4f9cff);
   FREG_VE_SetVoOsd2clut(225, 0x6e599eff);
   FREG_VE_SetVoOsd2clut(226, 0x733e99ff);
   FREG_VE_SetVoOsd2clut(227, 0x6d69a0ff);
   FREG_VE_SetVoOsd2clut(228, 0x79338eff);
   FREG_VE_SetVoOsd2clut(229, 0x743795ff);
   FREG_VE_SetVoOsd2clut(230, 0x723f94ff);
   FREG_VE_SetVoOsd2clut(231, 0x6d5d9dff);
   FREG_VE_SetVoOsd2clut(232, 0x74348aff);
   FREG_VE_SetVoOsd2clut(233, 0x6d639eff);
   FREG_VE_SetVoOsd2clut(234, 0x782e90ff);
   FREG_VE_SetVoOsd2clut(235, 0x753398ff);
   FREG_VE_SetVoOsd2clut(236, 0x6c659aff);
   FREG_VE_SetVoOsd2clut(237, 0x76328fff);
   FREG_VE_SetVoOsd2clut(238, 0x742d93ff);
   FREG_VE_SetVoOsd2clut(239, 0x70659dff);
   FREG_VE_SetVoOsd2clut(240, 0x6e61a1ff);
   FREG_VE_SetVoOsd2clut(241, 0x762993ff);
   FREG_VE_SetVoOsd2clut(242, 0x763185ff);
   FREG_VE_SetVoOsd2clut(243, 0x72539bff);
   FREG_VE_SetVoOsd2clut(244, 0x705e9dff);
   FREG_VE_SetVoOsd2clut(245, 0x792c84ff);
   FREG_VE_SetVoOsd2clut(246, 0x7c2e83ff);
   FREG_VE_SetVoOsd2clut(247, 0x7d1f86ff);
   FREG_VE_SetVoOsd2clut(248, 0x7b2888ff);
   FREG_VE_SetVoOsd2clut(249, 0x782190ff);
   FREG_VE_SetVoOsd2clut(250, 0x762b8cff);
   FREG_VE_SetVoOsd2clut(251, 0x78278dff);
   FREG_VE_SetVoOsd2clut(252, 0x7b2287ff);
   FREG_VE_SetVoOsd2clut(253, 0x79248fff);
   FREG_VE_SetVoOsd2clut(254, 0x7b1d8bff);
   FREG_VE_SetVoOsd2clut(255, 0xFF);
   
   FREG_VO_SetOsd2hflt(0, 0x00ff00ff);
   FREG_VO_SetOsd2hflt(1, 0xff);
   FREG_VO_SetOsd2hflt(2, 0x00ff00ff);
   FREG_VO_SetOsd2hflt(3, 0xff);
   FREG_VO_SetOsd2hflt(4, 0x10f010f0);
   FREG_VO_SetOsd2hflt(5, 0x000010f0);
   FREG_VO_SetOsd2hflt(6, 0x10f010f0);
   FREG_VO_SetOsd2hflt(7, 0x000010f0);
   FREG_VO_SetOsd2hflt(8, 0x20e020e0);
   FREG_VO_SetOsd2hflt(9, 0x000020e0);
   FREG_VO_SetOsd2hflt(10, 0x20e020e0);
   FREG_VO_SetOsd2hflt(11, 0x000020e0);
   FREG_VO_SetOsd2hflt(12, 0x30d030d0);
   FREG_VO_SetOsd2hflt(13, 0x000030d0);
   FREG_VO_SetOsd2hflt(14, 0x30d030d0);
   FREG_VO_SetOsd2hflt(15, 0x000030d0);
   FREG_VO_SetOsd2hflt(16, 0x40c040c0);
   FREG_VO_SetOsd2hflt(17, 0x000040c0);
   FREG_VO_SetOsd2hflt(18, 0x40c040c0);
   FREG_VO_SetOsd2hflt(19, 0x000040c0);
   FREG_VO_SetOsd2hflt(20, 0x50b050b0);
   FREG_VO_SetOsd2hflt(21, 0x000050b0);
   FREG_VO_SetOsd2hflt(22, 0x50b050b0);
   FREG_VO_SetOsd2hflt(23, 0x000050b0);
   FREG_VO_SetOsd2hflt(24, 0x60a060a0);
   FREG_VO_SetOsd2hflt(25, 0x000060a0);
   FREG_VO_SetOsd2hflt(26, 0x60a060a0);
   FREG_VO_SetOsd2hflt(27, 0x000060a0);
   FREG_VO_SetOsd2hflt(28, 0x70907090);
   FREG_VO_SetOsd2hflt(29, 0x00007090);
   FREG_VO_SetOsd2hflt(30, 0x70907090);
   FREG_VO_SetOsd2hflt(31, 0x00007090);
   FREG_VO_SetOsd2hflt(32, 0x80808080);
   FREG_VO_SetOsd2hflt(33, 0x80808080);
   FREG_VO_SetOsd2hflt(34, 0x80808080);
   FREG_VO_SetOsd2hflt(35, 0x80808080);
   FREG_VO_SetOsd2hflt(36, 0x90709070);
   FREG_VO_SetOsd2hflt(37, 0x00009070);
   FREG_VO_SetOsd2hflt(38, 0x90709070);
   FREG_VO_SetOsd2hflt(39, 0x00009070);
   FREG_VO_SetOsd2hflt(40, 0xa060a060);
   FREG_VO_SetOsd2hflt(41, 0x0000a060);
   FREG_VO_SetOsd2hflt(42, 0xa060a060);
   FREG_VO_SetOsd2hflt(43, 0x0000a060);
   FREG_VO_SetOsd2hflt(44, 0xb050b050);
   FREG_VO_SetOsd2hflt(45, 0x0000b050);
   FREG_VO_SetOsd2hflt(46, 0xb050b050);
   FREG_VO_SetOsd2hflt(47, 0x0000b050);
   FREG_VO_SetOsd2hflt(48, 0xc040c040);
   FREG_VO_SetOsd2hflt(49, 0x0000c040);
   FREG_VO_SetOsd2hflt(50, 0xc040c040);
   FREG_VO_SetOsd2hflt(51, 0x0000c040);
   FREG_VO_SetOsd2hflt(52, 0xd030d030);
   FREG_VO_SetOsd2hflt(53, 0x0000d030);
   FREG_VO_SetOsd2hflt(54, 0xd030d030);
   FREG_VO_SetOsd2hflt(55, 0x0000d030);
   FREG_VO_SetOsd2hflt(56, 0xe020e020);
   FREG_VO_SetOsd2hflt(57, 0x0000e020);
   FREG_VO_SetOsd2hflt(58, 0xe020e020);
   FREG_VO_SetOsd2hflt(59, 0x0000e020);
   FREG_VO_SetOsd2hflt(60, 0xf010f010);
   FREG_VO_SetOsd2hflt(61, 0x0000f010);
   FREG_VO_SetOsd2hflt(62, 0xf010f010);
   FREG_VO_SetOsd2hflt(63, 0x0000f010);
   FREG_VO_SetOsd2hflt(64, 0xfe020000);
   FREG_VO_SetOsd2hflt(65, 0);
   FREG_VO_SetOsd2hflt(66, 0xadaec67d);
   FREG_VO_SetOsd2hflt(67, 0x0000afc6);
   FREG_VO_SetOsd2hflt(68, 0xfe11f82d);
   FREG_VO_SetOsd2hflt(69, 0x0000a8f1);
   FREG_VO_SetOsd2hflt(70, 0x96c2c57d);
   FREG_VO_SetOsd2hflt(71, 0x0000afca);
   FREG_VO_SetOsd2hflt(72, 0xf423f05d);
   FREG_VO_SetOsd2hflt(73, 0x0000aee5);
   FREG_VO_SetOsd2hflt(74, 0x7fd3c67d);
   FREG_VO_SetOsd2hflt(75, 0x0000afcf);
   FREG_VO_SetOsd2hflt(76, 0xed37e87d);
   FREG_VO_SetOsd2hflt(77, 0x0000afdb);
   FREG_VO_SetOsd2hflt(78, 0x66dfcb7d);
   FREG_VO_SetOsd2hflt(79, 0x0000afd7);
   FREG_VO_SetOsd2hflt(80, 0xe94edf7d);
   FREG_VO_SetOsd2hflt(81, 0x0000afd1);
   FREG_VO_SetOsd2hflt(82, 0x4ee9d17d);
   FREG_VO_SetOsd2hflt(83, 0x0000afdf);
   FREG_VO_SetOsd2hflt(84, 0xdf66d77d);
   FREG_VO_SetOsd2hflt(85, 0x0000afcb);
   FREG_VO_SetOsd2hflt(86, 0x37eddb7d);
   FREG_VO_SetOsd2hflt(87, 0x0000afe8);
   FREG_VO_SetOsd2hflt(88, 0xd37fcf7d);
   FREG_VO_SetOsd2hflt(89, 0x0000afc6);
   FREG_VO_SetOsd2hflt(90, 0x23f4e575);
   FREG_VO_SetOsd2hflt(91, 0x0000abf0);
   FREG_VO_SetOsd2hflt(92, 0xc296ca7d);
   FREG_VO_SetOsd2hflt(93, 0x0000afc5);
   FREG_VO_SetOsd2hflt(94, 0x11fef145);
   FREG_VO_SetOsd2hflt(95, 0x0000a5f8);
   FREG_VO_SetOsd2hflt(96, 0xaeadc67d);
   FREG_VO_SetOsd2hflt(97, 0x0000afc6);
   FREG_VO_SetOsd2hflt(98, 0x02fe0000);
   FREG_VO_SetOsd2hflt(99, 0);
   FREG_VO_SetOsd2hflt(100, 0x97c1c57d);
   FREG_VO_SetOsd2hflt(101, 0x0000afca);
   FREG_VO_SetOsd2hflt(102, 0x00ef10c3);
   FREG_VO_SetOsd2hflt(103, 0x00007b07);
   FREG_VO_SetOsd2hflt(104, 0x7fd3c67d);
   FREG_VO_SetOsd2hflt(105, 0x0000afcf);
   FREG_VO_SetOsd2hflt(106, 0x01e3208b);
   FREG_VO_SetOsd2hflt(107, 0x0000770d);
   FREG_VO_SetOsd2hflt(108, 0x66dfcb7d);
   FREG_VO_SetOsd2hflt(109, 0x0000afd7);
   FREG_VO_SetOsd2hflt(110, 0x00d2308b);
   FREG_VO_SetOsd2hflt(111, 0x00007412);
   FREG_VO_SetOsd2hflt(112, 0x4ee9d17d);
   FREG_VO_SetOsd2hflt(113, 0x0000afdf);
   FREG_VO_SetOsd2hflt(114, 0x01c1408b);
   FREG_VO_SetOsd2hflt(115, 0x00007115);
   FREG_VO_SetOsd2hflt(116, 0x37eddb7d);
   FREG_VO_SetOsd2hflt(117, 0x0000afe8);
   FREG_VO_SetOsd2hflt(118, 0x00af508b);
   FREG_VO_SetOsd2hflt(119, 0x00007118);
   FREG_VO_SetOsd2hflt(120, 0x23f4e575);
   FREG_VO_SetOsd2hflt(121, 0x0000abf0);
   FREG_VO_SetOsd2hflt(122, 0x009f5f8b);
   FREG_VO_SetOsd2hflt(123, 0x00007119);
   FREG_VO_SetOsd2hflt(124, 0x11fef145);
   FREG_VO_SetOsd2hflt(125, 0x0000a5f8);
   FREG_VO_SetOsd2hflt(126, 0x008e6f8b);
   FREG_VO_SetOsd2hflt(127, 0x0000711a);

   FREG_VE_SetVoCursorclut(0, 0x7a787bff);
   FREG_VE_SetVoCursorclut(1, 0x7e7d7eff);
   FREG_VE_SetVoCursorclut(2, 0x7c807dff);
   FREG_VE_SetVoCursorclut(3, 0x7a837bff);
   FREG_VE_SetVoCursorclut(4, 0x797c79ff);
   FREG_VE_SetVoCursorclut(5, 0x77817cff);
   FREG_VE_SetVoCursorclut(6, 0x6d9281ff);
   FREG_VE_SetVoCursorclut(7, 0x6f8d80ff);
   FREG_VE_SetVoCursorclut(8, 0x738683ff);
   FREG_VE_SetVoCursorclut(9, 0x78947dff);
   FREG_VE_SetVoCursorclut(10, 0x7b977dff);
   FREG_VE_SetVoCursorclut(11, 0x7e867eff);
   FREG_VE_SetVoCursorclut(12, 0x827d7dff);
   FREG_VE_SetVoCursorclut(13, 0x7f817dff);
   FREG_VE_SetVoCursorclut(14, 0x7a8a83ff);
   FREG_VE_SetVoCursorclut(15, 0x7c6b7dff);
   FREG_VE_SetVoCursorclut(16, 0x7c757dff);
   FREG_VE_SetVoCursorclut(17, 0x7c8a7cff);
   FREG_VE_SetVoCursorclut(18, 0x82697eff);
   FREG_VE_SetVoCursorclut(19, 0x816c7cff);
   FREG_VE_SetVoCursorclut(20, 0x788883ff);
   FREG_VE_SetVoCursorclut(21, 0x81647fff);
   FREG_VE_SetVoCursorclut(22, 0x83587fff);
   FREG_VE_SetVoCursorclut(23, 0x83747dff);
   FREG_VE_SetVoCursorclut(24, 0x777f7eff);
   FREG_VE_SetVoCursorclut(25, 0x6b8080ff);
   FREG_VE_SetVoCursorclut(26, 0x786781ff);
   FREG_VE_SetVoCursorclut(27, 0x776a7eff);
   FREG_VE_SetVoCursorclut(28, 0x766e84ff);
   FREG_VE_SetVoCursorclut(29, 0x797983ff);
   FREG_VE_SetVoCursorclut(30, 0x749184ff);
   FREG_VE_SetVoCursorclut(31, 0x797b80ff);
   FREG_VE_SetVoCursorclut(32, 0x767478ff);
   FREG_VE_SetVoCursorclut(33, 0x78877aff);
   FREG_VE_SetVoCursorclut(34, 0x79707cff);
   FREG_VE_SetVoCursorclut(35, 0x795e7aff);
   FREG_VE_SetVoCursorclut(36, 0x73667aff);
   FREG_VE_SetVoCursorclut(37, 0x79647bff);
   FREG_VE_SetVoCursorclut(38, 0x785281ff);
   FREG_VE_SetVoCursorclut(39, 0x745d7cff);
   FREG_VE_SetVoCursorclut(40, 0x766d7cff);
   FREG_VE_SetVoCursorclut(41, 0x74867bff);
   FREG_VE_SetVoCursorclut(42, 0x778d7dff);
   FREG_VE_SetVoCursorclut(43, 0x77897fff);
   FREG_VE_SetVoCursorclut(44, 0x767580ff);
   FREG_VE_SetVoCursorclut(45, 0x7b8f7dff);
   FREG_VE_SetVoCursorclut(46, 0x7c947dff);
   FREG_VE_SetVoCursorclut(47, 0x7a7684ff);
   FREG_VE_SetVoCursorclut(48, 0x7e727eff);
   FREG_VE_SetVoCursorclut(49, 0x81777cff);
   FREG_VE_SetVoCursorclut(50, 0x6b9682ff);
   FREG_VE_SetVoCursorclut(51, 0x776b87ff);
   FREG_VE_SetVoCursorclut(52, 0x776585ff);
   FREG_VE_SetVoCursorclut(53, 0x74797eff);
   FREG_VE_SetVoCursorclut(54, 0x73717bff);
   FREG_VE_SetVoCursorclut(55, 0x7a5a7cff);
   FREG_VE_SetVoCursorclut(56, 0x747183ff);
   FREG_VE_SetVoCursorclut(57, 0x698a81ff);
   FREG_VE_SetVoCursorclut(58, 0x717b8aff);
   FREG_VE_SetVoCursorclut(59, 0x7e927eff);
   FREG_VE_SetVoCursorclut(60, 0x7e687fff);
   FREG_VE_SetVoCursorclut(61, 0x7f5f7cff);
   FREG_VE_SetVoCursorclut(62, 0x717c7dff);
   FREG_VE_SetVoCursorclut(63, 0x787383ff);
   FREG_VE_SetVoCursorclut(64, 0x737480ff);
   FREG_VE_SetVoCursorclut(65, 0x78617fff);
   FREG_VE_SetVoCursorclut(66, 0x678884ff);
   FREG_VE_SetVoCursorclut(67, 0x718981ff);
   FREG_VE_SetVoCursorclut(68, 0x707f82ff);
   FREG_VE_SetVoCursorclut(69, 0x79a081ff);
   FREG_VE_SetVoCursorclut(70, 0x7a8384ff);
   FREG_VE_SetVoCursorclut(71, 0x735f87ff);
   FREG_VE_SetVoCursorclut(72, 0x71788dff);
   FREG_VE_SetVoCursorclut(73, 0x7c577dff);
   FREG_VE_SetVoCursorclut(74, 0x75637cff);
   FREG_VE_SetVoCursorclut(75, 0x795f83ff);
   FREG_VE_SetVoCursorclut(76, 0x7a9c82ff);
   FREG_VE_SetVoCursorclut(77, 0x6e847fff);
   FREG_VE_SetVoCursorclut(78, 0x749b80ff);
   FREG_VE_SetVoCursorclut(79, 0x76a280ff);
   FREG_VE_SetVoCursorclut(80, 0x7a6f83ff);
   FREG_VE_SetVoCursorclut(81, 0x835f7eff);
   FREG_VE_SetVoCursorclut(82, 0x74577bff);
   FREG_VE_SetVoCursorclut(83, 0x727e86ff);
   FREG_VE_SetVoCursorclut(84, 0x718997ff);
   FREG_VE_SetVoCursorclut(85, 0x6f6e88ff);
   FREG_VE_SetVoCursorclut(86, 0x70518aff);
   FREG_VE_SetVoCursorclut(87, 0x735289ff);
   FREG_VE_SetVoCursorclut(88, 0x6f5c87ff);
   FREG_VE_SetVoCursorclut(89, 0x818c7dff);
   FREG_VE_SetVoCursorclut(90, 0x7ca982ff);
   FREG_VE_SetVoCursorclut(91, 0x78aa80ff);
   FREG_VE_SetVoCursorclut(92, 0x739b8aff);
   FREG_VE_SetVoCursorclut(93, 0x72988eff);
   FREG_VE_SetVoCursorclut(94, 0x729580ff);
   FREG_VE_SetVoCursorclut(95, 0x765a7dff);
   FREG_VE_SetVoCursorclut(96, 0x72627eff);
   FREG_VE_SetVoCursorclut(97, 0x735184ff);
   FREG_VE_SetVoCursorclut(98, 0x669183ff);
   FREG_VE_SetVoCursorclut(99, 0x6f9b82ff);
   FREG_VE_SetVoCursorclut(100, 0x726886ff);
   FREG_VE_SetVoCursorclut(101, 0x6f5a88ff);
   FREG_VE_SetVoCursorclut(102, 0x744a86ff);
   FREG_VE_SetVoCursorclut(103, 0x764e85ff);
   FREG_VE_SetVoCursorclut(104, 0x715488ff);
   FREG_VE_SetVoCursorclut(105, 0x714e86ff);
   FREG_VE_SetVoCursorclut(106, 0x798d83ff);
   FREG_VE_SetVoCursorclut(107, 0x71a293ff);
   FREG_VE_SetVoCursorclut(108, 0x6ea381ff);
   FREG_VE_SetVoCursorclut(109, 0x73a490ff);
   FREG_VE_SetVoCursorclut(110, 0x738e8eff);
   FREG_VE_SetVoCursorclut(111, 0x744d7bff);
   FREG_VE_SetVoCursorclut(112, 0x77557dff);
   FREG_VE_SetVoCursorclut(113, 0x758385ff);
   FREG_VE_SetVoCursorclut(114, 0x764685ff);
   FREG_VE_SetVoCursorclut(115, 0x794887ff);
   FREG_VE_SetVoCursorclut(116, 0x755686ff);
   FREG_VE_SetVoCursorclut(117, 0x709c97ff);
   FREG_VE_SetVoCursorclut(118, 0x71928dff);
   FREG_VE_SetVoCursorclut(119, 0x735f78ff);
   FREG_VE_SetVoCursorclut(120, 0x754781ff);
   FREG_VE_SetVoCursorclut(121, 0x784a85ff);
   FREG_VE_SetVoCursorclut(122, 0x6e838dff);
   FREG_VE_SetVoCursorclut(123, 0x718990ff);
   FREG_VE_SetVoCursorclut(124, 0x7b5a83ff);
   FREG_VE_SetVoCursorclut(125, 0x73498bff);
   FREG_VE_SetVoCursorclut(126, 0x755a86ff);
   FREG_VE_SetVoCursorclut(127, 0x768187ff);
   FREG_VE_SetVoCursorclut(128, 0x739e96ff);
   FREG_VE_SetVoCursorclut(129, 0x799283ff);
   FREG_VE_SetVoCursorclut(130, 0x784285ff);
   FREG_VE_SetVoCursorclut(131, 0x7b477fff);
   FREG_VE_SetVoCursorclut(132, 0x6e7592ff);
   FREG_VE_SetVoCursorclut(133, 0x6e9897ff);
   FREG_VE_SetVoCursorclut(134, 0x7e547fff);
   FREG_VE_SetVoCursorclut(135, 0x6e777fff);
   FREG_VE_SetVoCursorclut(136, 0x704f8eff);
   FREG_VE_SetVoCursorclut(137, 0x708092ff);
   FREG_VE_SetVoCursorclut(138, 0x729a99ff);
   FREG_VE_SetVoCursorclut(139, 0x76998cff);
   FREG_VE_SetVoCursorclut(140, 0x7a4a7eff);
   FREG_VE_SetVoCursorclut(141, 0x7a9883ff);
   FREG_VE_SetVoCursorclut(142, 0x7b4582ff);
   FREG_VE_SetVoCursorclut(143, 0x6e5a92ff);
   FREG_VE_SetVoCursorclut(144, 0x6e6897ff);
   FREG_VE_SetVoCursorclut(145, 0x734586ff);
   FREG_VE_SetVoCursorclut(146, 0x7b6684ff);
   FREG_VE_SetVoCursorclut(147, 0x716284ff);
   FREG_VE_SetVoCursorclut(148, 0x6a7a7dff);
   FREG_VE_SetVoCursorclut(149, 0x754187ff);
   FREG_VE_SetVoCursorclut(150, 0x6e6e81ff);
   FREG_VE_SetVoCursorclut(151, 0x717192ff);
   FREG_VE_SetVoCursorclut(152, 0x763e83ff);
   FREG_VE_SetVoCursorclut(153, 0x715977ff);
   FREG_VE_SetVoCursorclut(154, 0x706a7bff);
   FREG_VE_SetVoCursorclut(155, 0x6c7280ff);
   FREG_VE_SetVoCursorclut(156, 0x706479ff);
   FREG_VE_SetVoCursorclut(157, 0x779e8dff);
   FREG_VE_SetVoCursorclut(158, 0x776288ff);
   FREG_VE_SetVoCursorclut(159, 0x783b84ff);
   FREG_VE_SetVoCursorclut(160, 0x7f9d7fff);
   FREG_VE_SetVoCursorclut(161, 0x7db681ff);
   FREG_VE_SetVoCursorclut(162, 0x7aa682ff);
   FREG_VE_SetVoCursorclut(163, 0x7aac82ff);
   FREG_VE_SetVoCursorclut(164, 0x76508fff);
   FREG_VE_SetVoCursorclut(165, 0x783e8aff);
   FREG_VE_SetVoCursorclut(166, 0x71aa80ff);
   FREG_VE_SetVoCursorclut(167, 0x779d91ff);
   FREG_VE_SetVoCursorclut(168, 0x7ba484ff);
   FREG_VE_SetVoCursorclut(169, 0x7cb080ff);
   FREG_VE_SetVoCursorclut(170, 0x73979aff);
   FREG_VE_SetVoCursorclut(171, 0x7da181ff);
   FREG_VE_SetVoCursorclut(172, 0x749591ff);
   FREG_VE_SetVoCursorclut(173, 0x78a385ff);
   FREG_VE_SetVoCursorclut(174, 0x70949aff);
   FREG_VE_SetVoCursorclut(175, 0x743b85ff);
   FREG_VE_SetVoCursorclut(176, 0x6f909aff);
   FREG_VE_SetVoCursorclut(177, 0x72919bff);
   FREG_VE_SetVoCursorclut(178, 0x6a8ba0ff);
   FREG_VE_SetVoCursorclut(179, 0x708c9cff);
   FREG_VE_SetVoCursorclut(180, 0x763987ff);
   FREG_VE_SetVoCursorclut(181, 0x6f819dff);
   FREG_VE_SetVoCursorclut(182, 0x717d95ff);
   FREG_VE_SetVoCursorclut(183, 0x773684ff);
   FREG_VE_SetVoCursorclut(184, 0x7b3685ff);
   FREG_VE_SetVoCursorclut(185, 0x7d418bff);
   FREG_VE_SetVoCursorclut(186, 0x6d84a0ff);
   FREG_VE_SetVoCursorclut(187, 0x70889dff);
   FREG_VE_SetVoCursorclut(188, 0x6a7da0ff);
   FREG_VE_SetVoCursorclut(189, 0x657ea3ff);
   FREG_VE_SetVoCursorclut(190, 0x7a398fff);
   FREG_VE_SetVoCursorclut(191, 0x6879a2ff);
   FREG_VE_SetVoCursorclut(192, 0x783b8eff);
   FREG_VE_SetVoCursorclut(193, 0x6e7fa0ff);
   FREG_VE_SetVoCursorclut(194, 0x71869aff);
   FREG_VE_SetVoCursorclut(195, 0x6c879eff);
   FREG_VE_SetVoCursorclut(196, 0x6874a2ff);
   FREG_VE_SetVoCursorclut(197, 0x686ba4ff);
   FREG_VE_SetVoCursorclut(198, 0x707a9eff);
   FREG_VE_SetVoCursorclut(199, 0x774d90ff);
   FREG_VE_SetVoCursorclut(200, 0x724b97ff);
   FREG_VE_SetVoCursorclut(201, 0x6968a5ff);
   FREG_VE_SetVoCursorclut(202, 0x6962a6ff);
   FREG_VE_SetVoCursorclut(203, 0x6c79a0ff);
   FREG_VE_SetVoCursorclut(204, 0x754194ff);
   FREG_VE_SetVoCursorclut(205, 0x704e94ff);
   FREG_VE_SetVoCursorclut(206, 0x6d759cff);
   FREG_VE_SetVoCursorclut(207, 0x706c9eff);
   FREG_VE_SetVoCursorclut(208, 0x707c9cff);
   FREG_VE_SetVoCursorclut(209, 0x7a3184ff);
   FREG_VE_SetVoCursorclut(210, 0x744595ff);
   FREG_VE_SetVoCursorclut(211, 0x6b6d9fff);
   FREG_VE_SetVoCursorclut(212, 0x6e6ea1ff);
   FREG_VE_SetVoCursorclut(213, 0x695da6ff);
   FREG_VE_SetVoCursorclut(214, 0x6f6f9bff);
   FREG_VE_SetVoCursorclut(215, 0x753a92ff);
   FREG_VE_SetVoCursorclut(216, 0x6f559aff);
   FREG_VE_SetVoCursorclut(217, 0x6e73a0ff);
   FREG_VE_SetVoCursorclut(218, 0x71489aff);
   FREG_VE_SetVoCursorclut(219, 0x6e539cff);
   FREG_VE_SetVoCursorclut(220, 0x6f5e97ff);
   FREG_VE_SetVoCursorclut(221, 0x72849cff);
   FREG_VE_SetVoCursorclut(222, 0x6b59a6ff);
   FREG_VE_SetVoCursorclut(223, 0x70429aff);
   FREG_VE_SetVoCursorclut(224, 0x6f4f9cff);
   FREG_VE_SetVoCursorclut(225, 0x6e599eff);
   FREG_VE_SetVoCursorclut(226, 0x733e99ff);
   FREG_VE_SetVoCursorclut(227, 0x6d69a0ff);
   FREG_VE_SetVoCursorclut(228, 0x79338eff);
   FREG_VE_SetVoCursorclut(229, 0x743795ff);
   FREG_VE_SetVoCursorclut(230, 0x723f94ff);
   FREG_VE_SetVoCursorclut(231, 0x6d5d9dff);
   FREG_VE_SetVoCursorclut(232, 0x74348aff);
   FREG_VE_SetVoCursorclut(233, 0x6d639eff);
   FREG_VE_SetVoCursorclut(234, 0x782e90ff);
   FREG_VE_SetVoCursorclut(235, 0x753398ff);
   FREG_VE_SetVoCursorclut(236, 0x6c659aff);
   FREG_VE_SetVoCursorclut(237, 0x76328fff);
   FREG_VE_SetVoCursorclut(238, 0x742d93ff);
   FREG_VE_SetVoCursorclut(239, 0x70659dff);
   FREG_VE_SetVoCursorclut(240, 0x6e61a1ff);
   FREG_VE_SetVoCursorclut(241, 0x762993ff);
   FREG_VE_SetVoCursorclut(242, 0x763185ff);
   FREG_VE_SetVoCursorclut(243, 0x72539bff);
   FREG_VE_SetVoCursorclut(244, 0x705e9dff);
   FREG_VE_SetVoCursorclut(245, 0x792c84ff);
   FREG_VE_SetVoCursorclut(246, 0x7c2e83ff);
   FREG_VE_SetVoCursorclut(247, 0x7d1f86ff);
   FREG_VE_SetVoCursorclut(248, 0x7b2888ff);
   FREG_VE_SetVoCursorclut(249, 0x782190ff);
   FREG_VE_SetVoCursorclut(250, 0x762b8cff);
   FREG_VE_SetVoCursorclut(251, 0x78278dff);
   FREG_VE_SetVoCursorclut(252, 0x7b2287ff);
   FREG_VE_SetVoCursorclut(253, 0x79248fff);
   FREG_VE_SetVoCursorclut(254, 0x7b1d8bff);
   FREG_VE_SetVoCursorclut(255, 0xFF);
   
   FREG_VO_SetSdhflt_Sdhflt(0, 0xb051da43);
   FREG_VO_SetSdhflt_Sdhflt(1, 0x00007125);
   FREG_VO_SetSdhflt_Sdhflt(2, 0x554621e5);
   FREG_VO_SetSdhflt_Sdhflt(3, 0x0000af3e);
   FREG_VO_SetSdhflt_Sdhflt(4, 0xb051da43);
   FREG_VO_SetSdhflt_Sdhflt(5, 0x00007125);
   FREG_VO_SetSdhflt_Sdhflt(6, 0x554621e5);
   FREG_VO_SetSdhflt_Sdhflt(7, 0x0000af3e);
   FREG_VO_SetSdhflt_Sdhflt(8, 0xaf6add03);
   FREG_VO_SetSdhflt_Sdhflt(9, 0x00007112);
   FREG_VO_SetSdhflt_Sdhflt(10, 0x50482505);
   FREG_VO_SetSdhflt_Sdhflt(11, 0x0000af39);
   FREG_VO_SetSdhflt_Sdhflt(12, 0xaf6add03);
   FREG_VO_SetSdhflt_Sdhflt(13, 0x00007112);
   FREG_VO_SetSdhflt_Sdhflt(14, 0x50482505);
   FREG_VO_SetSdhflt_Sdhflt(15, 0x0000af39);
   FREG_VO_SetSdhflt_Sdhflt(16, 0xa984e4bb);
   FREG_VO_SetSdhflt_Sdhflt(17, 0x7100);
   FREG_VO_SetSdhflt_Sdhflt(18, 0x4e4a2a25);
   FREG_VO_SetSdhflt_Sdhflt(19, 0x0000ac33);
   FREG_VO_SetSdhflt_Sdhflt(20, 0xa984e4bb);
   FREG_VO_SetSdhflt_Sdhflt(21, 0x7100);
   FREG_VO_SetSdhflt_Sdhflt(22, 0x4e4a2a25);
   FREG_VO_SetSdhflt_Sdhflt(23, 0x0000ac33);
   FREG_VO_SetSdhflt_Sdhflt(24, 0x9b9cf08b);
   FREG_VO_SetSdhflt_Sdhflt(25, 0x000071f0);
   FREG_VO_SetSdhflt_Sdhflt(26, 0x4c4d2e45);
   FREG_VO_SetSdhflt_Sdhflt(27, 0x0000a82e);
   FREG_VO_SetSdhflt_Sdhflt(28, 0x9b9cf08b);
   FREG_VO_SetSdhflt_Sdhflt(29, 0x000071f0);
   FREG_VO_SetSdhflt_Sdhflt(30, 0x4c4d2e45);
   FREG_VO_SetSdhflt_Sdhflt(31, 0x0000a82e);
   FREG_VO_SetSdhflt_Sdhflt(32, 0x84a9008b);
   FREG_VO_SetSdhflt_Sdhflt(33, 0x000077e4);
   FREG_VO_SetSdhflt_Sdhflt(34, 0x4a4e3365);
   FREG_VO_SetSdhflt_Sdhflt(35, 0x0000a42a);
   FREG_VO_SetSdhflt_Sdhflt(36, 0x84a9008b);
   FREG_VO_SetSdhflt_Sdhflt(37, 0x000077e4);
   FREG_VO_SetSdhflt_Sdhflt(38, 0x4a4e3365);
   FREG_VO_SetSdhflt_Sdhflt(39, 0x0000a42a);
   FREG_VO_SetSdhflt_Sdhflt(40, 0x6aaf128b);
   FREG_VO_SetSdhflt_Sdhflt(41, 0x000060dd);
   FREG_VO_SetSdhflt_Sdhflt(42, 0x4850397d);
   FREG_VO_SetSdhflt_Sdhflt(43, 0x0000a025);
   FREG_VO_SetSdhflt_Sdhflt(44, 0x6aaf128b);
   FREG_VO_SetSdhflt_Sdhflt(45, 0x000060dd);
   FREG_VO_SetSdhflt_Sdhflt(46, 0x4850397d);
   FREG_VO_SetSdhflt_Sdhflt(47, 0x0000a025);
   FREG_VO_SetSdhflt_Sdhflt(48, 0x45af2f8b);
   FREG_VO_SetSdhflt_Sdhflt(49, 0x00006bda);
   FREG_VO_SetSdhflt_Sdhflt(50, 0x4556417d);
   FREG_VO_SetSdhflt_Sdhflt(51, 0x0000bb1f);
   FREG_VO_SetSdhflt_Sdhflt(52, 0x45af2f8b);
   FREG_VO_SetSdhflt_Sdhflt(53, 0x00006bda);
   FREG_VO_SetSdhflt_Sdhflt(54, 0x4556417d);
   FREG_VO_SetSdhflt_Sdhflt(55, 0x0000bb1f);
   FREG_VO_SetSdhflt_Sdhflt(56, 0x39ad398b);
   FREG_VO_SetSdhflt_Sdhflt(57, 0x00006edb);
   FREG_VO_SetSdhflt_Sdhflt(58, 0x4556457d);
   FREG_VO_SetSdhflt_Sdhflt(59, 0x0000b91d);
   FREG_VO_SetSdhflt_Sdhflt(60, 0x39ad398b);
   FREG_VO_SetSdhflt_Sdhflt(61, 0x00006edb);
   FREG_VO_SetSdhflt_Sdhflt(62, 0x4556457d);
   FREG_VO_SetSdhflt_Sdhflt(63, 0x0000b91d);

   FREG_VO_SetSdvflt_Sdvflt(0, 0x40804000);
   FREG_VO_SetSdvflt_Sdvflt(1, 0x40804000);
   FREG_VO_SetSdvflt_Sdvflt(2, 0x39794707);
   FREG_VO_SetSdvflt_Sdvflt(3, 0x39794707);
   FREG_VO_SetSdvflt_Sdvflt(4, 0x32724e0e);
   FREG_VO_SetSdvflt_Sdvflt(5, 0x32724e0e);
   FREG_VO_SetSdvflt_Sdvflt(6, 0x2b6b5515);
   FREG_VO_SetSdvflt_Sdvflt(7, 0x2b6b5515);
   FREG_VO_SetSdvflt_Sdvflt(8, 0x24645c1c);
   FREG_VO_SetSdvflt_Sdvflt(9, 0x24645c1c);
   FREG_VO_SetSdvflt_Sdvflt(10, 0x1d5d6323);
   FREG_VO_SetSdvflt_Sdvflt(11, 0x1d5d6323);
   FREG_VO_SetSdvflt_Sdvflt(12, 0x16566b2b);
   FREG_VO_SetSdvflt_Sdvflt(13, 0x16566b2b);
   FREG_VO_SetSdvflt_Sdvflt(14, 0x0f4f7131);
   FREG_VO_SetSdvflt_Sdvflt(15, 0x0f4f7131);
   FREG_VO_SetSdvflt_Sdvflt(16, 0x08487838);
   FREG_VO_SetSdvflt_Sdvflt(17, 0x08487838);
   FREG_VO_SetSdvflt_Sdvflt(18, 0x0000807f);
   FREG_VO_SetSdvflt_Sdvflt(19, 0x0000807f);
   FREG_VO_SetSdvflt_Sdvflt(20, 0x0000807f);
   FREG_VO_SetSdvflt_Sdvflt(21, 0x0000807f);
   FREG_VO_SetSdvflt_Sdvflt(22, 0x0000807f);
   FREG_VO_SetSdvflt_Sdvflt(23, 0x0000807f);
   FREG_VO_SetSdvflt_Sdvflt(24, 0x0000807f);
   FREG_VO_SetSdvflt_Sdvflt(25, 0x0000807f);
   FREG_VO_SetSdvflt_Sdvflt(26, 0x0000807f);
   FREG_VO_SetSdvflt_Sdvflt(27, 0x0000807f);
   FREG_VO_SetSdvflt_Sdvflt(28, 0x0000807f);
   FREG_VO_SetSdvflt_Sdvflt(29, 0x0000807f);
   FREG_VO_SetSdvflt_Sdvflt(30, 0x0000807f);
   FREG_VO_SetSdvflt_Sdvflt(31, 0x0000807f);
   FREG_VO_SetSdvflt_Sdvflt(32, 0x40804000);
   FREG_VO_SetSdvflt_Sdvflt(33, 0x40804000);
   FREG_VO_SetSdvflt_Sdvflt(34, 0x39794707);
   FREG_VO_SetSdvflt_Sdvflt(35, 0x39794707);
   FREG_VO_SetSdvflt_Sdvflt(36, 0x32724e0e);
   FREG_VO_SetSdvflt_Sdvflt(37, 0x32724e0e);
   FREG_VO_SetSdvflt_Sdvflt(38, 0x2b6b5515);
   FREG_VO_SetSdvflt_Sdvflt(39, 0x2b6b5515);
   FREG_VO_SetSdvflt_Sdvflt(40, 0x24645c1c);
   FREG_VO_SetSdvflt_Sdvflt(41, 0x24645c1c);
   FREG_VO_SetSdvflt_Sdvflt(42, 0x1d5d6323);
   FREG_VO_SetSdvflt_Sdvflt(43, 0x1d5d6323);
   FREG_VO_SetSdvflt_Sdvflt(44, 0x16566b2b);
   FREG_VO_SetSdvflt_Sdvflt(45, 0x16566b2b);
   FREG_VO_SetSdvflt_Sdvflt(46, 0x0f4f7131);
   FREG_VO_SetSdvflt_Sdvflt(47, 0x0f4f7131);
   FREG_VO_SetSdvflt_Sdvflt(48, 0x08487838);
   FREG_VO_SetSdvflt_Sdvflt(49, 0x08487838);
   FREG_VO_SetSdvflt_Sdvflt(50, 0x0000807f);
   FREG_VO_SetSdvflt_Sdvflt(51, 0x0000807f);
   FREG_VO_SetSdvflt_Sdvflt(52, 0x0000807f);
   FREG_VO_SetSdvflt_Sdvflt(53, 0x0000807f);
   FREG_VO_SetSdvflt_Sdvflt(54, 0x0000807f);
   FREG_VO_SetSdvflt_Sdvflt(55, 0x0000807f);
   FREG_VO_SetSdvflt_Sdvflt(56, 0x0000807f);
   FREG_VO_SetSdvflt_Sdvflt(57, 0x0000807f);
   FREG_VO_SetSdvflt_Sdvflt(58, 0x0000807f);
   FREG_VO_SetSdvflt_Sdvflt(59, 0x0000807f);
   FREG_VO_SetSdvflt_Sdvflt(60, 0x0000807f);
   FREG_VO_SetSdvflt_Sdvflt(61, 0x0000807f);
   FREG_VO_SetSdvflt_Sdvflt(62, 0x0000807f);
   FREG_VO_SetSdvflt_Sdvflt(63, 0x0000807f);
   
   FREG_VO_SetOsdrgbyuv11_Rgbyuv11(0, 0x81);
   FREG_VO_SetOsdrgbyuv12_Rgbyuv12(0, 0x42);
   FREG_VO_SetOsdrgbyuv13_Rgbyuv13(0, 0x19);
   FREG_VO_SetOsdrgbyuv14_Rgbyuv14(0, 0x10);
   FREG_VO_SetOsdrgbyuv21_Rgbyuv21(0, 0x1b6);
   FREG_VO_SetOsdrgbyuv22_Rgbyuv22(0, 0x1da);
   FREG_VO_SetOsdrgbyuv23_Rgbyuv23(0, 0x70);
   FREG_VO_SetOsdrgbyuv24_Rgbyuv24(0, 0x80);
   FREG_VO_SetOsdrgbyuv31_Rgbyuv31(0, 0x1a2);
   FREG_VO_SetOsdrgbyuv32_Rgbyuv32(0, 0x70);
   FREG_VO_SetOsdrgbyuv33_Rgbyuv33(0, 0x1ee);
   FREG_VO_SetOsdrgbyuv34_Rgbyuv34(0, 0x80);
   
   FREG_VO_SetOsdrgbyuv11_Rgbyuv11(1, 0x81);
   FREG_VO_SetOsdrgbyuv12_Rgbyuv12(1, 0x42);
   FREG_VO_SetOsdrgbyuv13_Rgbyuv13(1, 0x19);
   FREG_VO_SetOsdrgbyuv14_Rgbyuv14(1, 0x10);
   FREG_VO_SetOsdrgbyuv21_Rgbyuv21(1, 0x1b6);
   FREG_VO_SetOsdrgbyuv22_Rgbyuv22(1, 0x1da);
   FREG_VO_SetOsdrgbyuv23_Rgbyuv23(1, 0x70);
   FREG_VO_SetOsdrgbyuv24_Rgbyuv24(1, 0x80);
   FREG_VO_SetOsdrgbyuv31_Rgbyuv31(1, 0x1a2);
   FREG_VO_SetOsdrgbyuv32_Rgbyuv32(1, 0x70);
   FREG_VO_SetOsdrgbyuv33_Rgbyuv33(1, 0x1ee);
   FREG_VO_SetOsdrgbyuv34_Rgbyuv34(1, 0x80);
   
   FREG_VO_SetVobitperpixel_Bitperpixel(2);
   FREG_VO_SetVohordisppixel_Hordisppixel(704);
   FREG_VO_SetVohorreadpixel_Horreadpixel(704);
   FREG_VO_SetVofiltermode_Horfilteron(0, 0);
   FREG_VO_SetVofiltermode_Verfilteron(0, 0);   
   FREG_VO_SetVolayerenable_Layerenable(0);
   
   FREG_VO_SetOsdbitperpixel_Bitperpixel(0, 2);
   FREG_VO_SetOsdhordisppixel_Hordisppixel(0, 512);
   FREG_VO_SetOsdhorreadpixel_Horreadpixel(0, 512);
   FREG_VO_SetOsdfiltermode_Horfilteron(0, 0);
   FREG_VO_SetOsdfiltermode_Verfilteron(0, 0);
   FREG_VO_SetLayerenable_Layerenable(0, 0);
   
   FREG_VO_SetOsdbitperpixel_Bitperpixel(1, 2);
   FREG_VO_SetOsdhordisppixel_Hordisppixel(1, 512);
   FREG_VO_SetOsdhorreadpixel_Horreadpixel(1, 512);
   FREG_VO_SetOsdfiltermode_Horfilteron(1, 0);
   FREG_VO_SetOsdfiltermode_Verfilteron(1, 0);
   FREG_VO_SetLayerenable_Layerenable(1, 0);
   
   Data_21f672b0.Data_0 = 0;
   Data_21f672b0.Data_4 = 100;
   Data_21f672b0.Data_8 = 0;
   Data_21f672b0.Data_12 = 0;
   
   Data_21f672ac = &Data_21f672b0;
   
   func_21c53c18(&Data_21f672b0);
   
   viscaleInitialized = 1;
   
   return 0;
}


/* 21c53958 - complete */
void FAPI_VISCALE_Exit(void)
{
   unsigned i = 0;
   
   if (viscaleInitialized != 0)
   {
      viscale_lock();
      
      viscaleInitialized = 0;
      
      for (i = 0; i < 5; i++)
      {
         if (0 != fapi_viscale_check_handle(&viscaleHandleArray[i]))
         {
            FAPI_VISCALE_Close(&viscaleHandleArray[i]);
         }         
      }
      
      viscale_unlock();

      FAPI_SYS_DESTROY_SEMAPHORE(viscaleSemaphore);

      viscaleSemaphore = 0;
   }
}


static FAPI_VISCALE_VideoScalerIsrDataT* fapi_viscale_get_isr_data_ptr(
      FAPI_VISCALE_OpenParamsT* paramsPtr, int32_t* res)
{
   int32_t r3 = 0;
   unsigned j = 0;
   FAPI_VISCALE_VideoScalerIsrDataT* r6 = 0;
   
   for (j = 0; j < 5; j++)
   {
      //21c54430 / 0x218d2294
      if (viscaleIsrData[j].inUse == 0)
      {
         //21c54498 / 0x218d22a8
         FAPI_SYS_PRINT_DEBUG(4, "fapi_viscale_get_handle (21c54498): paramsPtr->scalerType=%d\n",
               paramsPtr->scalerType);
         
         viscaleIsrData[j].inUse = 1;
         viscaleIsrData[j].scalerType = paramsPtr->scalerType;
         
         r6 = &viscaleIsrData[j];
         
         if (paramsPtr->scalerType == FAPI_VISCALE_SCALER_VIDEO) //0)
         {
            viscaleVideoScalerIsrData = r6;
         }
         else if (paramsPtr->scalerType == FAPI_VISCALE_SCALER_OSD1) //1)
         {
            viscaleOsd1ScalerIsrData = r6;
         }
         else if (paramsPtr->scalerType == FAPI_VISCALE_SCALER_OSD2) //2)
         {
            viscaleOsd2ScalerIsrData = r6;
         }
         else if (paramsPtr->scalerType == FAPI_VISCALE_SCALER_CURSOR_PLANE) //4)
         {
            viscaleCpScalerIsrData = r6;
         }
         else if (paramsPtr->scalerType == FAPI_VISCALE_SCALER_SD) //3)
         {
            viscaleSdScalerIsrData = r6;
         }
         //  / ->0x218d230c
         break;
      } //if (viscaleIsrData[j].inUse == 0)
      //  / 0x218d2300
   } //for (j = 0; j < 5; j++)
   
   if (res != 0)
   {
      *res = r3;
   }
   
   return r6;
}


static FAPI_VISCALE_VideoScalerHandleT* fapi_viscale_get_handle(
      const FAPI_VISCALE_OpenParamsT* paramsPtr, int32_t* res)
{
   int32_t r3 = 0;
   uint32_t i = 0;
   FAPI_VISCALE_VideoScalerHandleT* r11 = 0;
   
   switch (paramsPtr->scalerType)
   {
   case FAPI_VISCALE_SCALER_VIDEO: //0:
      //21c53fb0
      if (Data_21f67280 == 0)
      {
         //->21c53f10
         Data_21f67280 = 1;
      }
      else
      {
         //->21c53f78
         r3 = 0xffff8a66;
      }
      break;
      
   case FAPI_VISCALE_SCALER_OSD1: //1:
      //21c53f9c
      if (Data_21f67284 == 0)
      {
         //->21c53f10
         Data_21f67284 = 1;
      }
      else
      {
         //->21c53f78
         r3 = 0xffff8a66;
      }
      break;
      
   case FAPI_VISCALE_SCALER_OSD2: //2:
      //21c53f88
      if (Data_21f67288 == 0)
      {
         //->21c53f10
         Data_21f67288 = 1;
      }
      else
      {
         //->21c53f78
         r3 = 0xffff8a66;
      }
      break;
      
   case FAPI_VISCALE_SCALER_CURSOR_PLANE: //4:
      //21c53f00
      if (Data_21f67290 == 0)
      {
         //21c53f10
         Data_21f67290 = 1;
      }
      else
      {
         //21c53f78
         r3 = 0xffff8a66;
      }
      break;
      
   case FAPI_VISCALE_SCALER_SD: //3:
      //21c53f68
      if (Data_21f6728c == 0)
      {
         //->21c53f10
         Data_21f6728c = 1;
      }
      else
      {
         //21c53f78
         r3 = 0xffff8a66;
      }
      break;
      
   default:
      //21c53ee0
      r3 = 0xffff8a69;
      break;
   }
   
   if (r3 == 0)
   {
      //  / 0x218d2244
      for (i = 0; i < 5; i++)
      {
         //  / 0x218d2270
         if (viscaleHandleArray[i].inUse == 0)
         {
            //21c54428 / 0x218d2284
#if 0
            unsigned j = 0;
            FAPI_VISCALE_VideoScalerIsrDataT* r6 = 0;
            r3 = 0; 
            
            for (j = 0; j < 5; j++)
            {
               //21c54430 / 0x218d2294
               if (viscaleIsrData[j].inUse == 0)
               {
                  //21c54498 / 0x218d22a8
                  FAPI_SYS_PRINT_DEBUG(4, "fapi_viscale_get_handle (21c54498): paramsPtr->scalerType=%d\n",
                        paramsPtr->scalerType);
                  
                  viscaleIsrData[j].inUse = 1;
                  viscaleIsrData[j].scalerType = paramsPtr->scalerType;
                  
                  r6 = &viscaleIsrData[j];
                  
                  if (paramsPtr->scalerType == FAPI_VISCALE_SCALER_VIDEO) //0)
                  {
                     viscaleVideoScalerIsrData = r6;
                  }
                  else if (paramsPtr->scalerType == FAPI_VISCALE_SCALER_OSD1) //1)
                  {
                     viscaleOsd1ScalerIsrData = r6;
                  }
                  else if (paramsPtr->scalerType == FAPI_VISCALE_SCALER_OSD2) //2)
                  {
                     viscaleOsd2ScalerIsrData = r6;
                  }
                  else if (paramsPtr->scalerType == FAPI_VISCALE_SCALER_CURSOR_PLANE) //4)
                  {
                     viscaleCpScalerIsrData = r6;
                  }
                  else if (paramsPtr->scalerType == FAPI_VISCALE_SCALER_SD) //3)
                  {
                     viscaleSdScalerIsrData = r6;
                  }
                  //  / ->0x218d230c
                  break;
               } //if (viscaleIsrData[j].inUse == 0)
               //  / 0x218d2300
            } //for (j = 0; j < 5; j++)
            //21c54458 / 0x218d230c
            viscaleHandleArray[i].isrDataPtr = r6;
#else
            viscaleHandleArray[i].isrDataPtr = 
               fapi_viscale_get_isr_data_ptr(paramsPtr, &r3);
#endif
            
            if (r3 == 0)
            {
               viscaleHandleArray[i].inUse = 1;            
               r11 = &viscaleHandleArray[i];            
            }
            else
            {
               r3 = 0xffff8a5f;
            }
            //->21c53fcc  / ->0x218d2378
            break;
         }
      } //for (i = 0; i < 5; i++)
      //  / 0x218d2378
   }
   else
   {
      //  / 0x218d2250
      switch (paramsPtr->scalerType)
      {
      case FAPI_VISCALE_SCALER_VIDEO: //0:
         //  / 218d2340
         Data_21f67280--;
         break;
         
      case FAPI_VISCALE_SCALER_OSD1: //1:
         //  / 218d234c
         Data_21f67284--;
         break;
         
      case FAPI_VISCALE_SCALER_OSD2: //2:
         //  / 218d2358
         Data_21f67288--;
         break;
         
      case FAPI_VISCALE_SCALER_SD: //3:
         //  / 218d2364
         Data_21f6728c--;
         break;
         
      case FAPI_VISCALE_SCALER_CURSOR_PLANE: //4:
         //  / 218d2370
         Data_21f67290--;
         break;
         
      default:
         //  / 218d2378
         break;
      }
   }
   //  / 0x218d2378
   if (res != 0)
   {
      *res = r3;
   }

   return r11;
}


/* 21c5313c - todo */
void func_21c5313c(FAPI_VISCALE_VideoScalerHandleT* a)
{
//   printf("func_21c5313c\n");
   
   FAPI_VISCALE_VideoScalerIsrDataT* r3 = a->isrDataPtr;
   
   r3->iFadeCurrValue = a->scalerParams.globalAlpha; //16
   r3->iFadeStepSize = 10; //20
   r3->iFadeState = 5; //8
   r3->iFadeLimitValue = a->scalerParams.globalAlpha; //12
   r3->iEnableState = 0; //24
   r3->iUserScalerReqState = 0; //28
   r3->iAutoScalerReqState = 1; //32
   r3->iFilterState = 0; //36
   
   r3->iFilter.hSize = 0; //40
   r3->iFilter.initalShift = 4; //44
   r3->iFilter.horDispPixel = 0; //48
   r3->iFilter.horReadPixel = 0; //52
   r3->iFilter.hStartPos = 0; //56
   r3->iFilter.horFilterOn = 0; //64
   r3->iFilter.horFilterUp = 0; //68
   r3->iFilter.horD = 0x10000; //72
   r3->iFilter.horN = 0x10000; //76
   r3->iFilter.verFilterOn = 0; //92
   r3->iFilter.verFilterUp = 0; //96
   r3->iFilter.verD = 0x10000; //100
   r3->iFilter.verN = 0x10000; //104
   r3->iFilter.horStart = 0; //108
   r3->iFilter.horStop = 0; //112
   r3->iFilter.verStart = 0; //116
   r3->iFilter.verStop = 0; //120
   r3->iFilter.sdScalerReq.inputHorStart = 0; //124
   r3->iFilter.sdScalerReq.inputHorStop = 0; //128
   r3->iFilter.sdScalerReq.inputVerStart = 0; //132
   r3->iFilter.sdScalerReq.inputVerStop = 0; //136
   r3->iFilter.sdScalerReq.outputHorStart = 0; //140
   r3->iFilter.sdScalerReq.outputHorStop = 0; //144
   r3->iFilter.sdScalerReq.outputVerStart = 0; //148
   r3->iFilter.sdScalerReq.outputVerStop = 0; //152
   r3->iFilter.sdScalerReq.sdHorWriteStart = 0; //156
   r3->iFilter.sdScalerReq.sdHorWriteStop = 0; //160
   r3->iFilter.sdScalerReq.sdDispcvbshorstartstop = 0; //164
}


/* 21c53e3c - todo */
FAPI_SYS_HandleT FAPI_VISCALE_Open(
                      const FAPI_VISCALE_OpenParamsT* paramsPtr,
                            int32_t* errorCodePtr)
{
   int32_t res;
   FAPI_VISCALE_VideoScalerHandleT* r4;
   FAPI_VISCALE_VideoScalerHandleT* h = 0;
   
   if (viscaleInitialized == 0)
   {
      *errorCodePtr = -30004;
      return 0;
   }
   
   if (paramsPtr == 0)
   {
      *errorCodePtr = -30001;
      return 0;
   }
   
   if (paramsPtr->version > FAPI_VISCALE_VERSION)
   {      
      *errorCodePtr = -30101;
      return 0;
   }
   
   if ((paramsPtr->scalerType == FAPI_VISCALE_UNKNOWN_SCALER) || 
         (paramsPtr->encoderType == FAPI_VISCALE_UNKNOWN_ENCODER))
   {
      *errorCodePtr = -29102;
      return 0;
   }
   
   viscale_lock();
   
   h = fapi_viscale_get_handle(paramsPtr, &res);
   //21c53fcc
   viscale_unlock();
   
   if (h == 0)
   {
      //->21c53f58
      *errorCodePtr = -30106; //0xffff8a66;
      return 0;
   }
//   else
   {
      //21c53fd8
      viscale_lock();
      
      switch (paramsPtr->scalerType)
      {
      case FAPI_VISCALE_SCALER_VIDEO: //0:
         //21c54360
         h->inUse = 1;
         strncpy(h->coreName, "Viscaler", 32);
         h->coreID = FAPI_VISCALE_ID;
         h->baseAddress = FAPI_VISCALE_BASE_ADDRESS_VIDEO_SCALER_0;
         h->opParams = *paramsPtr;
         
         h->Start = fapi_viscale_vostart;
         h->Stop = fapi_viscale_vostop;
         h->EnableDisable = 0; //fapi_viscale_voenabledisable;
         h->Alpha = fapi_viscale_voalpha;
         h->Resize = fapi_viscale_voresize;
         h->Hilight = 0;
         h->AutoPlaneFading = fapi_viscale_voautoplanefading; 
         h->AutoPlaneFadingStepSize = fapi_viscale_voautoplanefadingstepsize;
         h->UpdateClut = 0; 
         h->UpdateSingleClut = 0;
         h->AutoScale = fapi_viscale_voautoscaler;
         h->SetScalerToHdEncoder = fapi_viscale_setvoscalertohdencoder;
         h->SetScalingMethod = fapi_viscale_setvoscalingmethod;
         h->SetDisplayAspectRatio = fapi_viscale_setvodisplayaspectratio;
         h->SetWssState = fapi_viscale_setvowssstate;
         h->SetParamChangeCallback = fapi_viscale_vosetparamchangecallback;
         h->GetWssSignal = fapi_viscale_getvowsssignal;
         
         func_21c5313c(h);
         
//         res = 0;
         //->21c540ac
         break;
         
      case FAPI_VISCALE_SCALER_OSD1: //1:
         //21c542d0
         h->inUse = 1;
         strncpy(h->coreName, "Viscaler", 32);
         h->coreID = FAPI_VISCALE_ID;
         h->baseAddress = FAPI_VISCALE_BASE_ADDRESS_OSD_SCALER_1;
         h->opParams = *paramsPtr;
         
         h->Start = fapi_viscale_osd1start;
         h->Stop = fapi_viscale_osd1stop;
         h->EnableDisable = fapi_viscale_osd1enabledisable;
         h->Alpha = fapi_viscale_osd1alpha;
         h->Resize = fapi_viscale_osd1resize;
         h->Hilight = 0;
         h->AutoPlaneFading = fapi_viscale_osd1autoplanefading; 
         h->AutoPlaneFadingStepSize = fapi_viscale_osd1autoplanefadingstepsize;
         h->UpdateClut = fapi_viscale_osd1updateclut; 
         h->UpdateSingleClut = fapi_viscale_osd1updatesingleclut;
         h->AutoScale = 0;
         h->SetScalerToHdEncoder = fapi_viscale_setosd1scalertohdencoder;
         h->SetScalingMethod = 0;
         h->SetDisplayAspectRatio = 0;
         h->SetWssState = 0;
         h->SetParamChangeCallback = 0;
         h->GetWssSignal = 0;

         func_21c5313c(h);
         
//         res = 0;
         //->21c540ac
         break;
         
      case FAPI_VISCALE_SCALER_OSD2: //2:
         //21c5422c
         h->inUse = 1;
         strncpy(h->coreName, "Viscaler", 32);
         h->coreID = FAPI_VISCALE_ID;
         h->baseAddress = FAPI_VISCALE_BASE_ADDRESS_OSD_SCALER_2;
         h->opParams = *paramsPtr;
         
         h->Start = fapi_viscale_osd2start;
         h->Stop = fapi_viscale_osd2stop;
         h->EnableDisable = fapi_viscale_osd2enabledisable;
         h->Alpha = fapi_viscale_osd2alpha;
         h->Resize = fapi_viscale_osd2resize;
         h->Hilight = 0;
         h->AutoPlaneFading = fapi_viscale_osd2autoplanefading; 
         h->AutoPlaneFadingStepSize = fapi_viscale_osd2autoplanefadingstepsize;
         h->UpdateClut = fapi_viscale_osd2updateclut; 
         h->UpdateSingleClut = fapi_viscale_osd2updatesingleclut;
         h->AutoScale = 0;
         h->SetScalerToHdEncoder = fapi_viscale_setosd2scalertohdencoder;
         h->SetScalingMethod = 0;
         h->SetDisplayAspectRatio = 0;
         h->SetWssState = 0;
         h->SetParamChangeCallback = 0;
         h->GetWssSignal = 0;

         func_21c5313c(h);
         
//         res = 0;
         //->21c540ac
         break;
         
      case FAPI_VISCALE_SCALER_SD: //3:
         //21c54194
         h->inUse = 1;
         strncpy(h->coreName, "Viscaler", 32);
         h->coreID = FAPI_VISCALE_ID;
         h->baseAddress = FAPI_VISCALE_BASE_ADDRESS_SD_SCALER_3;
         h->opParams = *paramsPtr;
         
         h->Start = fapi_viscale_sdstart;
         h->Stop = fapi_viscale_sdstop;
         h->EnableDisable = fapi_viscale_sdenabledisable;
         h->Alpha = 0;
         h->Resize = fapi_viscale_sdresize;
         h->Hilight = 0;
         h->AutoPlaneFading = 0; 
         h->AutoPlaneFadingStepSize = 0;
         h->UpdateClut = 0; 
         h->UpdateSingleClut = 0;
         h->AutoScale = fapi_viscale_sdautoscaler;
         h->SetScalerToHdEncoder = fapi_viscale_setsdscalertohdencoder;
         h->SetScalingMethod = 0;
         h->SetDisplayAspectRatio = fapi_viscale_setsddisplayaspectratio;
         h->SetWssState = 0;
         h->SetParamChangeCallback = 0;
         h->GetWssSignal = 0;

         func_21c5313c(h);
         
//         res = 0;
         //->21c540ac
         break;
         
      case FAPI_VISCALE_SCALER_CURSOR_PLANE: //4:
         //21c540d4
         h->inUse = 1;
         strncpy(h->coreName, "Viscaler", 32);
         h->coreID = FAPI_VISCALE_ID;
         h->baseAddress = FAPI_VISCALE_BASE_ADDRESS_CP_SCALER_4;
         h->opParams = *paramsPtr;
         
         h->Start = fapi_viscale_cpstart;
         h->Stop = fapi_viscale_cpstop;
         h->EnableDisable = fapi_viscale_cpenabledisable;
         h->Alpha = fapi_viscale_cpalpha;
         h->Resize = fapi_viscale_cpreposition;
         h->Hilight = fapi_viscale_cphilight;
         h->AutoPlaneFading = fapi_viscale_cpautoplanefading; 
         h->AutoPlaneFadingStepSize = fapi_viscale_cpautoplanefadingstepsize;
         h->UpdateClut = fapi_viscale_cpupdateclut; 
         h->UpdateSingleClut = fapi_viscale_cpupdatesingleclut;
         h->AutoScale = 0;
         h->SetScalerToHdEncoder = fapi_viscale_setcptohdencoder;
         h->SetScalingMethod = 0;
         h->SetDisplayAspectRatio = 0;
         h->SetWssState = 0;
         h->SetParamChangeCallback = 0;
         h->GetWssSignal = 0;

         func_21c5313c(h);
         
//         res = 0;
         //->21c540ac
         break;
         
      default:
         //21c54028
         h->inUse = 0;
         strncpy(h->coreName, "Unknown Scaler", 32);
         h->coreID = 0;
         h->baseAddress = 0;
         h->opParams.scalerType = -1;
         h->opParams.encoderType = -1;
         h->isrDataPtr = 0; 
         h->Start = 0; //2568
         h->Stop = 0; //2572
         h->EnableDisable = 0; //2576
         h->Alpha = 0; //2580
         h->Resize = 0; //2584
         h->Hilight = 0; //2588
         h->AutoPlaneFading = 0; //2592
         h->AutoPlaneFadingStepSize = 0; //2596
         h->UpdateClut = 0; //2600
         h->UpdateSingleClut = 0; //2604
         h->AutoScale = 0; //2608
         h->SetScalerToHdEncoder = 0; //2612
         h->SetScalingMethod = 0; //2616
         h->SetDisplayAspectRatio = 0; //2620
         h->SetWssState = 0; //2624
         h->SetParamChangeCallback = 0; //2628
         h->GetWssSignal = 0; //2632
         
         res = 0xffff8e52;
         //21c540ac
         break;
      }
      //21c540ac
      if (errorCodePtr) *errorCodePtr = res;
      
      if (res != 0)
      {
         //21c540bc
         fapi_viscale_remove_handle(h);
         r4 = 0;
      }
      else
      {
         //21c54488
         func_21c53c18(&Data_21f672b0);
         r4 = h;
         //->21c540c8
      }
      //21c540c8
      viscale_unlock();
   }
   
   return r4;
}


/* 21c53900 - complete */
int32_t FAPI_VISCALE_Close(FAPI_SYS_HandleT handle)
{
   int res = 0;
   FAPI_VISCALE_VideoScalerHandleT* a = handle;
   
   viscale_lock();
   
   if (0 != fapi_viscale_check_handle(a))
   {
      if (a->Stop != 0)
      {
         res = (a->Stop)(a);
      }
      else
      {
         res = -30107;
      }
      
      fapi_viscale_remove_handle(a);
   }
   else
   {
      res = -30108;
   }
   
   viscale_unlock();
   
   return res;
}


/* 21c530e0 - complete */
int32_t FAPI_VISCALE_Start(FAPI_SYS_HandleT handle,
                            FAPI_VISCALE_ScalerParamsT*
                            scaleParamsPtr)
{
   int32_t res = 0;
   FAPI_VISCALE_VideoScalerHandleT* a = handle;
   
   viscale_lock();
   
   if (0 != fapi_viscale_check_handle(a))
   {
      if (a->Start != 0)
      {
         res = (a->Start)(a, scaleParamsPtr);
      }
      else
      {
         res = -30107;
      }
   }
   else
   {
      res = -30108;
   }
   
   viscale_unlock();
   
   return res;
}


/* 21c5308c - complete */
int32_t FAPI_VISCALE_Stop(FAPI_SYS_HandleT handle)
{
   int32_t res = 0;
   FAPI_VISCALE_VideoScalerHandleT* a = handle;
   
   viscale_lock();
   
   if (0 != fapi_viscale_check_handle(a))
   {
      if (a->Stop != 0)
      {
         res = (a->Stop)(a);
      }
      else
      {
         res = -30107;
      }
   }
   else
   {
      res = -30108;
   }
   
   viscale_unlock();
   
   return res;
}


/* 21c53030 - complete */
int32_t FAPI_VISCALE_EnableDisable(FAPI_SYS_HandleT handle,
                            FAPI_VISCALE_ParameterModeEnumT mode)
{
   int32_t res = 0;
   FAPI_VISCALE_VideoScalerHandleT* a = handle;
   
   viscale_lock();
   
   if (0 != fapi_viscale_check_handle(a))
   {
      if (a->EnableDisable != 0)
      {
         res = (a->EnableDisable)(a, mode);
      }
      else
      {
         res = -30107;
      }
   }
   else
   {
      res = -30108;
   }
   
   viscale_unlock();
   
   return res;
}


/* 21c52fd0 - complete */
uint32_t FAPI_VISCALE_Alpha(FAPI_SYS_HandleT handle,
                            FAPI_VISCALE_ParameterModeEnumT mode,
                            uint32_t level)
{
   int32_t res = 0;
   FAPI_VISCALE_VideoScalerHandleT* a = handle;
   
   viscale_lock();
   
   if (0 != fapi_viscale_check_handle(a))
   {
      if (a->Alpha != 0)
      {
         res = (a->Alpha)(a, mode, level);
      }
      else
      {
         //res = -30107;
      }
   }
   else
   {
      //res = -30108;
   }
   
   viscale_unlock();
   
   return res;
}


/* 21c52f74 - complete */
int32_t FAPI_VISCALE_Resize(FAPI_SYS_HandleT handle ,
                            FAPI_VISCALE_ScalerParamsT*
                            scaleParamsPtr)
{
   int32_t res = 0;
   FAPI_VISCALE_VideoScalerHandleT* a = handle;
   
   FAPI_SYS_PRINT_DEBUG(4, "FAPI_VISCALE_Resize\n");

   viscale_lock();
   
   if (0 != fapi_viscale_check_handle(a))
   {
      if (a->Resize != 0)
      {
         res = (a->Resize)(a, scaleParamsPtr);
      }
      else
      {
         res = -30107;
      }
   }
   else
   {
      res = -30108;
   }
   
   viscale_unlock();
   
   FAPI_SYS_PRINT_DEBUG(3, "FAPI_VISCALE_Resize: %i\n", res);

   return res;
}


/* 21c52f18 - complete */
int32_t FAPI_VISCALE_Hilight(FAPI_SYS_HandleT handle,
                            FAPI_VISCALE_ParameterModeEnumT mode)
{
   int32_t res = 0;
   FAPI_VISCALE_VideoScalerHandleT* a = handle;
   
   viscale_lock();
   
   if (0 != fapi_viscale_check_handle(a))
   {
      if (a->Hilight != 0)
      {
         res = (a->Hilight)(a, mode);
      }
      else
      {
         res = -30107;
      }
   }
   else
   {
      res = -30108;
   }
   
   viscale_unlock();
   
   return res;
}


/* 21c52ebc - complete */
int32_t FAPI_VISCALE_AutoPlaneFading(FAPI_SYS_HandleT handle,
                            FAPI_VISCALE_VideoFadingModeEnumT fadingMode)
{
   int32_t res = 0;
   FAPI_VISCALE_VideoScalerHandleT* a = handle;
   
   viscale_lock();
   
   if (0 != fapi_viscale_check_handle(a))
   {
      if (a->AutoPlaneFading != 0)
      {
         res = (a->AutoPlaneFading)(a, fadingMode);
      }
      else
      {
         res = -30107;
      }
   }
   else
   {
      res = -30108;
   }
   
   viscale_unlock();
   
   return res;
}


/* 21c52e58 - complete */
int32_t FAPI_VISCALE_AutoPlaneFadingStepSize(FAPI_SYS_HandleT handle,
                    FAPI_VISCALE_ParameterModeEnumT mode,
                                  uint32_t* stepSizePtr)
{
   int32_t res = 0;
   FAPI_VISCALE_VideoScalerHandleT* a = handle;
   
   viscale_lock();
   
   if (0 != fapi_viscale_check_handle(a))
   {
      if (a->AutoPlaneFadingStepSize != 0)
      {
         res = (a->AutoPlaneFadingStepSize)(a, mode, stepSizePtr);
      }
      else
      {
         res = -30107;
      }
   }
   else
   {
      res = -30108;
   }
   
   viscale_unlock();
   
   return res;
}


/* 21c52dfc - complete */
int32_t FAPI_VISCALE_UpdateClut(FAPI_SYS_HandleT handle,
                            uint32_t* colour)
{
   int32_t res = 0;
   FAPI_VISCALE_VideoScalerHandleT* a = handle;
   
   viscale_lock();
   
   if (0 != fapi_viscale_check_handle(a))
   {
      if (a->UpdateClut != 0)
      {
         res = (a->UpdateClut)(a, colour);
      }
      else
      {
         res = -30107;
      }
   }
   else
   {
      res = -30108;
   }
   
   viscale_unlock();
   
   return res;
}


/* 21c52d98 - complete */
int32_t FAPI_VISCALE_UpdateSingleClut(FAPI_SYS_HandleT handle,
             uint32_t entryNumber, uint32_t entryColour)
{
   int32_t res = 0;
   FAPI_VISCALE_VideoScalerHandleT* a = handle;
   
   viscale_lock();
   
   if (0 != fapi_viscale_check_handle(a))
   {
      if (a->UpdateSingleClut != 0)
      {
         res = (a->UpdateSingleClut)(a, entryNumber, entryColour);
      }
      else
      {
         res = -30107;
      }
   }
   else
   {
      res = -30108;
   }
   
   viscale_unlock();
   
   return res;
}


/* 21c527ac - complete */
void FAPI_VISCALE_AutoScaler(void* frameCropPtr,
      FAPI_SYS_HandleT scalerHandle, uint32_t suspendType)
{
   FAPI_SYS_PRINT_DEBUG(4, "FAPI_VISCALE_AutoScaler\n");

   if ((frameCropPtr != 0) && (scalerHandle != 0))
   {
      FAPI_VISCALE_VideoScalerHandleT* h = scalerHandle;

      if (h->AutoScale != 0)
      {
         (h->AutoScale)(frameCropPtr, scalerHandle, suspendType);
      }
   }
}


/* 21c52d14 - complete */
int32_t FAPI_VISCALE_SetScalerToHdEncoder(FAPI_SYS_HandleT handle,
                            FAPI_SYS_HandleT viencHdHandle)
{
   int32_t res = 0;
   FAPI_VISCALE_VideoScalerHandleT* a = handle;
   FAPI_VISCALE_VideoScalerHandleT* b = viencHdHandle;
   
   if (b == 0)
   {
      a->hdMode = 0;
      
      res = -30110;
   }
   else if (b->sdMode == -1)
   {
      a->hdMode = 0;
      
      res = -30110;
   }
   else
   {
      viscale_lock();
      
      if (0 != fapi_viscale_check_handle(a))
      {
         if (a->SetScalerToHdEncoder != 0)
         {
            res = (a->SetScalerToHdEncoder)(a, viencHdHandle);
         }
         else
         {
            res = -30107;
         }
      }
      else
      {
         res = -30108;
      }
      
      viscale_unlock();
   }
   
   return res;
}


/* 21c52cb8 - complete */
int32_t FAPI_VISCALE_SetScalingMethod(FAPI_SYS_HandleT handle,
                            FAPI_VISCALE_ScalingMethodEnumT scalingMethod)
{
   int32_t res = 0;
   FAPI_VISCALE_VideoScalerHandleT* a = handle;
   
   viscale_lock();
   
   if (0 != fapi_viscale_check_handle(a))
   {
      if (a->SetScalingMethod != 0)
      {
         res = (a->SetScalingMethod)(a, scalingMethod);
      }
      else
      {
         res = -30107;
      }
   }
   else
   {
      res = -30108;
   }
   
   viscale_unlock();
   
   return res;
}


/* 21c52c34 - complete */
int32_t FAPI_VISCALE_SetDisplayAspectRatio(FAPI_SYS_HandleT handle,
                            FAPI_VISCALE_AspectRatioEnumT displayAr)
{
   int32_t res = 0;
   FAPI_VISCALE_VideoScalerHandleT* a = handle;
   
   FAPI_SYS_PRINT_DEBUG(4, "FAPI_VISCALE_SetDisplayAspectRatio\n");

   viscale_lock();
   
   if (0 != fapi_viscale_check_handle(a))
   {
      if (a->opParams.scalerType == 1)
      {
         res = -30110;
      }
      else if (a->opParams.scalerType == 2)
      {
         res = -30110;
      }
      else if (a->opParams.scalerType == 4)
      {
         res = -30110;
      }
      else   
      {
         if (a->SetDisplayAspectRatio != 0)
         {
            res = (a->SetDisplayAspectRatio)(a, displayAr);
         }
         else
         {
            res = -30107;
         }
      }
   }
   else
   {
      res = -30108;
   }
   
   viscale_unlock();
   
   FAPI_SYS_PRINT_DEBUG(3, "FAPI_VISCALE_SetDisplayAspectRatio: %i\n", res);

   return res;
}


/* 21c52bc4 - complete */
int32_t FAPI_VISCALE_SetWssState(FAPI_SYS_HandleT handle,
                                 FAPI_VISCALE_WssStateEnumT wssState)
{
   int32_t res = 0;
   FAPI_VISCALE_VideoScalerHandleT* a = handle;
   
   viscale_lock();
   
   if (0 != fapi_viscale_check_handle(a))
   {
      if (a->opParams.scalerType == 0)
      {
         if (a->SetWssState != 0)
         {
            res = (a->SetWssState)(a, wssState);
         }
         else
         {
            res = -30107;
         }
      }
      else
      {
         res = -30110;
      }
   }
   else
   {
      res = -30108;
   }
   
   viscale_unlock();
   
   return res;
}


/* 21c52b60 - complete */
int32_t FAPI_VISCALE_SetParamChangeCallback(FAPI_SYS_HandleT handle,
                            FAPI_VISCALE_ParamChangeCallbackT
                                                 paramChangeCallbackFunction,
                            void* paramChangeOptData)
{
   int32_t res = 0;
   FAPI_VISCALE_VideoScalerHandleT* a = handle;
   
   viscale_lock();
   
   if (0 != fapi_viscale_check_handle(a))
   {
      if (a->SetParamChangeCallback != 0)
      {
         res = (a->SetParamChangeCallback)(a, 
               paramChangeCallbackFunction, paramChangeOptData);
      }
      else
      {
         res = -30107;
      }
   }
   else
   {
      res = -30108;
   }
   
   viscale_unlock();
   
   return res;
}


/* 21c52b08 - complete */
int32_t FAPI_VISCALE_ClearScalerToHdEncoder(FAPI_SYS_HandleT handle)
{
   int32_t res = 0;
   FAPI_VISCALE_VideoScalerHandleT* a = handle;
   
   viscale_lock();
   
   if (0 != fapi_viscale_check_handle(a))
   {
      if (a->SetScalerToHdEncoder != 0)
      {
         res = (a->SetScalerToHdEncoder)(a, 0);
      }
      else
      {
         res = -30107;
      }
   }
   else
   {
      res = -30108;
   }
   
   viscale_unlock();
   
   return res;
}


/* 21c52ab0 - complete */
int32_t FAPI_VISCALE_ClearScalingMethod(FAPI_SYS_HandleT handle)
{
   int32_t res = 0;
   FAPI_VISCALE_VideoScalerHandleT* a = handle;
   
   viscale_lock();
   
   if (0 != fapi_viscale_check_handle(a))
   {
      if (a->SetScalingMethod != 0)
      {
         res = (a->SetScalingMethod)(a, 2);
      }
      else
      {
         res = -30107;
      }
   }
   else
   {
      res = -30108;
   }
   
   viscale_unlock();
   
   return res;
}


/* 21c52a58 - complete */
int32_t FAPI_VISCALE_ClearDisplayAspectRatio(FAPI_SYS_HandleT handle)
{
   int32_t res = 0;
   FAPI_VISCALE_VideoScalerHandleT* a = handle;
   
   viscale_lock();
   
   if (0 != fapi_viscale_check_handle(a))
   {
      if (a->SetDisplayAspectRatio != 0)
      {
         res = (a->SetDisplayAspectRatio)(a, 0);
      }
      else
      {
         res = -30107;
      }
   }
   else
   {
      res = -30108;
   }
   
   viscale_unlock();
   
   return res;
}


/* 21c529fc - complete */
int32_t FAPI_VISCALE_ClearParamChangeCallback(FAPI_SYS_HandleT handle)
{
   int32_t res = 0;
   FAPI_VISCALE_VideoScalerHandleT* a = handle;
   
   viscale_lock();
   
   if (0 != fapi_viscale_check_handle(a))
   {
      if (a->SetParamChangeCallback != 0)
      {
         res = (a->SetParamChangeCallback)(a, 0, 0);
      }
      else
      {
         res = -30107;
      }
   }
   else
   {
      res = -30108;
   }
   
   viscale_unlock();
   
   return res;
}


/* 21c5290c - complete */
FAPI_VISCALE_SystemModeEnumT
                 FAPI_VISCALE_GetSystemType(FAPI_SYS_HandleT handle)
{
   FAPI_VISCALE_SystemModeEnumT res;
   FAPI_VISCALE_VideoScalerHandleT* a = handle;
   
   viscale_lock();
   
   if (0 != fapi_viscale_check_handle(a))
   {
      if (a->hdMode == 1)
      {
         res = FAPI_VISCALE_SYSTEM_MODE_1920x1080x2397P; 
      }
      else if (a->hdMode == 2)
      {
         res = FAPI_VISCALE_SYSTEM_MODE_1920x1080x24P; 
      }
      else if (a->hdMode == 3)
      {
         res = FAPI_VISCALE_SYSTEM_MODE_1920x1080x25P; 
      }
      else if (a->hdMode == 4)
      {
         res = FAPI_VISCALE_SYSTEM_MODE_1920x1080x2997P; 
      }
      else if (a->hdMode == 5)
      {
         res = FAPI_VISCALE_SYSTEM_MODE_1920x1080x30P; 
      }
      else if (a->hdMode == 6)
      {
         res = FAPI_VISCALE_SYSTEM_MODE_1920x1080x50I; 
      }
      else if (a->hdMode == 7)
      {
         res = FAPI_VISCALE_SYSTEM_MODE_1920x1080x5994I; 
      }
      else if (a->hdMode == 8)
      {
         res = FAPI_VISCALE_SYSTEM_MODE_1920x1080x60I; 
      }
      else if (a->hdMode == 9)
      {
         res = FAPI_VISCALE_SYSTEM_MODE_1280x720x2397P; 
      }
      else if (a->hdMode == 10)
      {
         res = FAPI_VISCALE_SYSTEM_MODE_1280x720x24P; 
      }
      else if (a->hdMode == 11)
      {
         res = FAPI_VISCALE_SYSTEM_MODE_1280x720x25P; 
      }
      else if (a->hdMode == 12)
      {
         res = FAPI_VISCALE_SYSTEM_MODE_1280x720x2997P; 
      }
      else if (a->hdMode == 13)
      {
         res = FAPI_VISCALE_SYSTEM_MODE_1280x720x30P; 
      }
      else if (a->hdMode == 14)
      {
         res = FAPI_VISCALE_SYSTEM_MODE_1280x720x50P; 
      }
      else if (a->hdMode == 15)
      {
         res = FAPI_VISCALE_SYSTEM_MODE_1280x720x5994P; 
      }
      else if (a->hdMode == 16)
      {
         res = FAPI_VISCALE_SYSTEM_MODE_1280x720x60P; 
      }
      else if (a->hdMode == 17)
      {
         res = FAPI_VISCALE_SYSTEM_MODE_720x576x50I; 
      }
      else if (a->hdMode == 18)
      {
         res = FAPI_VISCALE_SYSTEM_MODE_720x576x50P; 
      }
      else if (a->hdMode == 19)
      {
         res = FAPI_VISCALE_SYSTEM_MODE_720x480x5994I; 
      }
      else if (a->hdMode == 20)
      {
         res = FAPI_VISCALE_SYSTEM_MODE_720x480x5994P; 
      }
      else if (a->hdMode == 21)
      {
         res = FAPI_VISCALE_SYSTEM_MODE_LCD_640x480x50P_LQ080V3DG01; 
      }
      else if (a->hdMode == 22)
      {
         res = FAPI_VISCALE_SYSTEM_MODE_LCD_1024x768x50P_SVA150XG10TB; 
      }
      else
      {
         res = FAPI_VISCALE_UNKNOWN_SYSTEM_MODE;
      }
   }
   else
   {
      res = FAPI_VISCALE_UNKNOWN_SYSTEM_MODE;
   }
   
   viscale_unlock();
   
   return res;
}


/* 21c5289c - complete */
int32_t FAPI_VISCALE_GetWssSignal(FAPI_SYS_HandleT handle,
                                             uint32_t* wssSignalPtr)
{
   int32_t res = 0;
   FAPI_VISCALE_VideoScalerHandleT* a = handle;
   
   viscale_lock();
   
   if (0 != fapi_viscale_check_handle(a))
   {
      if (a->opParams.scalerType == 0)
      {
         if (a->GetWssSignal != 0)
         {
            res = (a->GetWssSignal)(a, wssSignalPtr);
         }
         else
         {
            res = -30107;
         }
      }
      else
      {
         res = -30110;
      }
   }
   else
   {
      res = -30108;
   }
   
   viscale_unlock();
   
   return res;
}


/* 21c537a8 - complete */
void fapi_viscale_remove_handle(FAPI_VISCALE_VideoScalerHandleT* a)
{
//   printf("21c537a8\n");
   
   switch (a->opParams.scalerType)
   {
   case 0:
      //21c53838
      Data_21f67280--;
      break;
      
   case 1:
      //21c5384c
      Data_21f67284--;
      break;
      
   case 2:
      //21c53860
      Data_21f67288--;
      break;
      
   case 3:
      //21c53874
      Data_21f6728c--;
      break;
      
   case 4:
      //21c537d4
      Data_21f67290--;
      break;
      
   default:
      break;
   }

   if (a->isrDataPtr != 0)
   {
      if (a->isrDataPtr->scalerType == 0)
      {
         //21c53828
         fapi_viscale_clear_isr_data(a->isrDataPtr);
         viscaleVideoScalerIsrData = 0;
      }
      else if (a->isrDataPtr->scalerType == 1)
      {
         //21c538b0
         fapi_viscale_clear_isr_data(a->isrDataPtr);
         viscaleOsd1ScalerIsrData = 0;
      }
      else if (a->isrDataPtr->scalerType == 2)
      {
         //21c5389c
         fapi_viscale_clear_isr_data(a->isrDataPtr);
         viscaleOsd2ScalerIsrData = 0;
      }
      else if (a->isrDataPtr->scalerType == 4)
      {
         //21c538c4
         fapi_viscale_clear_isr_data(a->isrDataPtr);
         viscaleCpScalerIsrData = 0;
      }
      else if (a->isrDataPtr->scalerType == 3)
      {
         //21c53888
         fapi_viscale_clear_isr_data(a->isrDataPtr);
         viscaleSdScalerIsrData = 0;
      }
   }

   fapi_viscale_clear_handle(a);
}


/* 21c527d0 - complete */
void viscale_lock(void)
{
   FAPI_SYS_GET_SEMAPHORE(viscaleSemaphore, FAPI_SYS_SUSPEND);
}


/* 21c52800 - complete */
void viscale_unlock(void)
{
   FAPI_SYS_SET_SEMAPHORE(viscaleSemaphore, FAPI_SYS_NO_SUSPEND);
}


/* 21c52830 - complete */
int fapi_viscale_check_handle(FAPI_VISCALE_VideoScalerHandleT* a)
{
   int res = 0; 
   
   if ((a != 0) &&
         (a->inUse == 1) &&
         (a->coreID == FAPI_VISCALE_ID) && 
         (a->baseAddress != 0) &&
         (a->opParams.scalerType != -1) &&
         (a->opParams.encoderType != -1))
   {
      res = 1;
   }
   
   return res;
}


/* 21c59260 - complete */
uint32_t FAPI_VISCALE_Isr(void)
{
   unsigned i;
   uint32_t r8;
   
   FAPI_SYS_PRINT_DEBUG(5, "FAPI_VISCALE_Isr\n");
   
   FREG_VO_SetDispirqctrl_Dispirq1(0);
   
   r8 = FREG_VO_GetDisppicpos_Currentfield();
      
   if ((viscaleVideoScalerIsrData != 0) && !r8)
   {
      if ((viscaleVideoScalerIsrData->iFadeState == FAPI_VISCALE_INTERNAL_REQUEST_TO_FADE_IN) ||
            (viscaleVideoScalerIsrData->iFadeState == FAPI_VISCALE_INTERNAL_FADING_IN))
      {
         viscaleVideoScalerIsrData->iFadeCurrValue =
               viscaleVideoScalerIsrData->iFadeStepSize +
               viscaleVideoScalerIsrData->iFadeCurrValue;
         
         if (viscaleVideoScalerIsrData->iFadeCurrValue >= viscaleVideoScalerIsrData->iFadeLimitValue)
         {
            viscaleVideoScalerIsrData->iFadeState = FAPI_VISCALE_INTERNAL_FADE_IN_DONE;
            viscaleVideoScalerIsrData->iFadeCurrValue = viscaleVideoScalerIsrData->iFadeLimitValue;
         }
         else
         {
            viscaleVideoScalerIsrData->iFadeState = FAPI_VISCALE_INTERNAL_FADING_IN;
         }
         
         FREG_VO_SetDispmixconf_Dispmixvoa(viscaleVideoScalerIsrData->iFadeCurrValue);
      }
      else if ((viscaleVideoScalerIsrData->iFadeState == FAPI_VISCALE_INTERNAL_REQUEST_TO_FADE_OUT) ||
            (viscaleVideoScalerIsrData->iFadeState == FAPI_VISCALE_INTERNAL_FADING_OUT))
      {
         viscaleVideoScalerIsrData->iFadeCurrValue -= viscaleVideoScalerIsrData->iFadeStepSize;
         
         if (viscaleVideoScalerIsrData->iFadeCurrValue <= viscaleVideoScalerIsrData->iFadeLimitValue)
         {
            viscaleVideoScalerIsrData->iFadeState = FAPI_VISCALE_INTERNAL_FADE_OUT_DONE;
            viscaleVideoScalerIsrData->iFadeCurrValue = 0;
         }
         else
         {
            viscaleVideoScalerIsrData->iFadeState = FAPI_VISCALE_INTERNAL_FADING_OUT;
         }
         
         FREG_VO_SetDispmixconf_Dispmixvoa(viscaleVideoScalerIsrData->iFadeCurrValue);
      }

      if (viscaleVideoScalerIsrData->iFilterState == FAPI_VISCALE_REQUEST_TO_UPDATE_FILTERS)
      {
         FREG_VO_SetVohsize_Hsize(viscaleVideoScalerIsrData->iFilter.hSize);
         FREG_VO_SetVoinitialshift_Initialshiftlum(viscaleVideoScalerIsrData->iFilter.initalShift);
         FREG_VO_SetVohordisppixel_Hordisppixel(viscaleVideoScalerIsrData->iFilter.horDispPixel);
         FREG_VO_SetVohorreadpixel_Horreadpixel(viscaleVideoScalerIsrData->iFilter.horReadPixel);
         FREG_VO_SetVohstartpos_Hstartpos(viscaleVideoScalerIsrData->iFilter.hStartPos);
         FREG_VO_SetVohordenum_Hordenum(viscaleVideoScalerIsrData->iFilter.horD);
         FREG_VO_SetVohornum_Hornum(viscaleVideoScalerIsrData->iFilter.horN);
         FREG_VO_SetVofiltermode_Horfilteron(0, viscaleVideoScalerIsrData->iFilter.horFilterOn);
         FREG_VO_SetVofiltermode_Horfilterup(0, viscaleVideoScalerIsrData->iFilter.horFilterUp);
         FREG_VO_SetVofiltermode_Horaddphase(0, viscaleVideoScalerIsrData->iFilter.horAddPhase);
         FREG_VO_SetDispvohorstartstop_Vohorstart(viscaleVideoScalerIsrData->iFilter.horStart);
         FREG_VO_SetDispvohorstartstop_Vohorstop(viscaleVideoScalerIsrData->iFilter.horStop);
         FREG_VO_SetVovstartpos_Vstartpos(viscaleVideoScalerIsrData->iFilter.vStartPos);
         FREG_VO_SetVoverdenum_Verdenum(viscaleVideoScalerIsrData->iFilter.verD);
         FREG_VO_SetVovernum_Vernum(viscaleVideoScalerIsrData->iFilter.verN);
         FREG_VO_SetVofiltermode_Verfilteron(0, viscaleVideoScalerIsrData->iFilter.verFilterOn);
         FREG_VO_SetVofiltermode_Verfilterup(0, viscaleVideoScalerIsrData->iFilter.verFilterUp);
         FREG_VO_SetVofiltermode_Veraddphase(0, viscaleVideoScalerIsrData->iFilter.verAddPhase);
         FREG_VO_SetDispvoverstartstop_Voverstart(viscaleVideoScalerIsrData->iFilter.verStart);
         FREG_VO_SetDispvoverstartstop_Voverstop(viscaleVideoScalerIsrData->iFilter.verStop);
         
         for (i = 0; i < 128; i++)
         {
            FREG_VO_SetVohflt(i, viscaleVideoScalerIsrData->iFilter.coefficients[i]);
         }

         FAPI_VISCALE_VideoScalerIsrDataT* r1 = viscaleVideoScalerIsrData;

         if (r1->iAutoScalerReqState == FAPI_VISCALE_AUTO_SCALER_REQUEST)
         {
            r1->iAutoScalerReqState = FAPI_VISCALE_AUTO_SCALER_REQUEST_DONE;
         }
         
         if (r1->iUserScalerReqState == FAPI_VISCALE_USER_SCALER_REQUEST)
         {
            r1->iUserScalerReqState = FAPI_VISCALE_USER_SCALER_REQUEST_DONE;
         }

         r1->iFilterState = FAPI_VISCALE_FILTERS_UPDATED;
      }
   }

   if (viscaleVideoScalerIsrData != 0)
   {
      if (viscaleVideoScalerIsrData->iFilter.fieldInversion == 1)
      {
         if (r8 == 1)
         {
            FREG_VO_SetVovstartpos_Vstartpos(viscaleVideoScalerIsrData->iFilter.vStartPos + 1);
         }
         else
         {
            FREG_VO_SetVovstartpos_Vstartpos(viscaleVideoScalerIsrData->iFilter.vStartPos);
         }
      }
   }

   if ((viscaleOsd1ScalerIsrData != 0) && !r8)
   {
      if ((viscaleOsd1ScalerIsrData->iFadeState == FAPI_VISCALE_INTERNAL_REQUEST_TO_FADE_IN) ||
            (viscaleOsd1ScalerIsrData->iFadeState == FAPI_VISCALE_INTERNAL_FADING_IN))
      {
         viscaleOsd1ScalerIsrData->iFadeCurrValue =
               viscaleOsd1ScalerIsrData->iFadeStepSize +
               viscaleOsd1ScalerIsrData->iFadeCurrValue;
         
         if (viscaleOsd1ScalerIsrData->iFadeCurrValue >= viscaleOsd1ScalerIsrData->iFadeLimitValue)
         {
            viscaleOsd1ScalerIsrData->iFadeState = FAPI_VISCALE_INTERNAL_FADE_IN_DONE;
            viscaleOsd1ScalerIsrData->iFadeCurrValue = viscaleOsd1ScalerIsrData->iFadeLimitValue;
         }
         else
         {
            viscaleOsd1ScalerIsrData->iFadeState = FAPI_VISCALE_INTERNAL_FADING_IN;
         }
         
         FREG_VO_SetOsdalpha1_Osdalpha1(0, viscaleOsd1ScalerIsrData->iFadeCurrValue);
      }
      else if ((viscaleOsd1ScalerIsrData->iFadeState == FAPI_VISCALE_INTERNAL_REQUEST_TO_FADE_OUT) ||
            (viscaleOsd1ScalerIsrData->iFadeState == FAPI_VISCALE_INTERNAL_FADING_OUT))
      {
         viscaleOsd1ScalerIsrData->iFadeCurrValue -= viscaleOsd1ScalerIsrData->iFadeStepSize;
         
         if (viscaleOsd1ScalerIsrData->iFadeCurrValue <= viscaleOsd1ScalerIsrData->iFadeLimitValue)
         {
            viscaleOsd1ScalerIsrData->iFadeState = FAPI_VISCALE_INTERNAL_FADE_OUT_DONE;
            viscaleOsd1ScalerIsrData->iFadeCurrValue = 0;
         }
         else
         {
            viscaleOsd1ScalerIsrData->iFadeState = FAPI_VISCALE_INTERNAL_FADING_OUT;
         }

         FREG_VO_SetOsdalpha1_Osdalpha1(0, viscaleOsd1ScalerIsrData->iFadeCurrValue);
      }

      if (viscaleOsd1ScalerIsrData->iEnableState == FAPI_VISCALE_REQUEST_TO_FORCE_ENABLE)
      {
         FREG_VO_SetLayerenable_Layerenable(0, 1);
         
         viscaleOsd1ScalerIsrData->iEnableState = FAPI_VISCALE_FORCE_ENABLED;
      }
      else if (viscaleOsd1ScalerIsrData->iEnableState == FAPI_VISCALE_REQUEST_TO_FORCE_DISABLE)
      {
         FREG_VO_SetLayerenable_Layerenable(0, 0);
         
         viscaleOsd1ScalerIsrData->iEnableState = FAPI_VISCALE_FORCE_DISABLED;
      }

      if (viscaleOsd1ScalerIsrData->iFilterState == FAPI_VISCALE_REQUEST_TO_UPDATE_FILTERS)
      {
         FREG_VO_SetOsdhsize_Hsize(0, viscaleOsd1ScalerIsrData->iFilter.hSize);
         FREG_VO_SetOsdinitialshift_Initialshift(0, viscaleOsd1ScalerIsrData->iFilter.initalShift);
         FREG_VO_SetOsdhordenum_Hordenum(0, viscaleOsd1ScalerIsrData->iFilter.horD);
         FREG_VO_SetOsdhornum_Hornum(0, viscaleOsd1ScalerIsrData->iFilter.horN);
         FREG_VO_SetOsdfiltermode_Horfilteron(0, viscaleOsd1ScalerIsrData->iFilter.horFilterOn);
         FREG_VO_SetOsdfiltermode_Horfilterup(0, viscaleOsd1ScalerIsrData->iFilter.horFilterUp);
         FREG_VO_SetOsdhordisppixel_Hordisppixel(0, viscaleOsd1ScalerIsrData->iFilter.horDispPixel);
         FREG_VO_SetOsdhorreadpixel_Horreadpixel(0, viscaleOsd1ScalerIsrData->iFilter.horReadPixel);
         FREG_VO_SetOsdverdenum_Verdenum(0, viscaleOsd1ScalerIsrData->iFilter.verD);
         FREG_VO_SetOsdvernum_Vernum(0, viscaleOsd1ScalerIsrData->iFilter.verN);
         FREG_VO_SetOsdfiltermode_Verfilteron(0, viscaleOsd1ScalerIsrData->iFilter.verFilterOn);
         FREG_VO_SetOsdfiltermode_Verfilterup(0, viscaleOsd1ScalerIsrData->iFilter.verFilterUp);
         FREG_VO_SetDisposd1horstartstop_Osd1horstart(viscaleOsd1ScalerIsrData->iFilter.horStart);
         FREG_VO_SetDisposd1horstartstop_Osd1horstop(viscaleOsd1ScalerIsrData->iFilter.horStop);
         FREG_VO_SetDisposd1verstartstop_Osd1verstart(viscaleOsd1ScalerIsrData->iFilter.verStart);
         FREG_VO_SetDisposd1verstartstop_Osd1verstop(viscaleOsd1ScalerIsrData->iFilter.verStop - 1);
         
         for (i = 0; i < 128; i++)
         {
            FREG_VO_SetOsd1hflt(i, viscaleOsd1ScalerIsrData->iFilter.coefficients[i]);
         }

         viscaleOsd1ScalerIsrData->iFilterState = FAPI_VISCALE_FILTERS_UPDATED;
      }
   }

   if ((viscaleOsd2ScalerIsrData != 0) && !r8)
   {
      if ((viscaleOsd2ScalerIsrData->iFadeState == FAPI_VISCALE_INTERNAL_REQUEST_TO_FADE_IN) ||
            (viscaleOsd2ScalerIsrData->iFadeState == FAPI_VISCALE_INTERNAL_FADING_IN))
      {
         viscaleOsd2ScalerIsrData->iFadeCurrValue =
            viscaleOsd2ScalerIsrData->iFadeStepSize +
            viscaleOsd2ScalerIsrData->iFadeCurrValue;
         
         if (viscaleOsd2ScalerIsrData->iFadeCurrValue >= viscaleOsd2ScalerIsrData->iFadeLimitValue)
         {
            viscaleOsd2ScalerIsrData->iFadeState = FAPI_VISCALE_INTERNAL_FADE_IN_DONE;
            viscaleOsd2ScalerIsrData->iFadeCurrValue = viscaleOsd2ScalerIsrData->iFadeLimitValue;
         }
         else
         {
            viscaleOsd2ScalerIsrData->iFadeState = FAPI_VISCALE_INTERNAL_FADING_IN;
         }
         
         FREG_VO_SetOsdalpha1_Osdalpha1(1, viscaleOsd2ScalerIsrData->iFadeCurrValue);
      }
      else if ((viscaleOsd2ScalerIsrData->iFadeState == FAPI_VISCALE_INTERNAL_REQUEST_TO_FADE_OUT) ||
            (viscaleOsd2ScalerIsrData->iFadeState == FAPI_VISCALE_INTERNAL_FADING_OUT))
      {
         viscaleOsd2ScalerIsrData->iFadeCurrValue -= viscaleOsd2ScalerIsrData->iFadeStepSize;
         
         if (viscaleOsd2ScalerIsrData->iFadeCurrValue <= viscaleOsd2ScalerIsrData->iFadeLimitValue)
         {
            viscaleOsd2ScalerIsrData->iFadeState = FAPI_VISCALE_INTERNAL_FADE_OUT_DONE;
            viscaleOsd2ScalerIsrData->iFadeCurrValue = 0;
         }
         else
         {
            viscaleOsd2ScalerIsrData->iFadeState = FAPI_VISCALE_INTERNAL_FADING_OUT;
         }

         FREG_VO_SetOsdalpha1_Osdalpha1(1, viscaleOsd2ScalerIsrData->iFadeCurrValue);
      }

      if (viscaleOsd2ScalerIsrData->iEnableState == FAPI_VISCALE_REQUEST_TO_FORCE_ENABLE)
      {
         FREG_VO_SetLayerenable_Layerenable(1, 1);
         
         viscaleOsd2ScalerIsrData->iEnableState = FAPI_VISCALE_FORCE_ENABLED;
      }
      else if (viscaleOsd2ScalerIsrData->iEnableState == FAPI_VISCALE_REQUEST_TO_FORCE_DISABLE)
      {
         FREG_VO_SetLayerenable_Layerenable(1, 0);
         
         viscaleOsd2ScalerIsrData->iEnableState = FAPI_VISCALE_FORCE_DISABLED;
      }

      if (viscaleOsd2ScalerIsrData->iFilterState == FAPI_VISCALE_REQUEST_TO_UPDATE_FILTERS)
      {
         FREG_VO_SetOsdhsize_Hsize(1, viscaleOsd2ScalerIsrData->iFilter.hSize);
         FREG_VO_SetOsdinitialshift_Initialshift(1, viscaleOsd2ScalerIsrData->iFilter.initalShift);
         FREG_VO_SetOsdhordenum_Hordenum(1, viscaleOsd2ScalerIsrData->iFilter.horD);
         FREG_VO_SetOsdhornum_Hornum(1, viscaleOsd2ScalerIsrData->iFilter.horN);
         FREG_VO_SetOsdfiltermode_Horfilteron(1, viscaleOsd2ScalerIsrData->iFilter.horFilterOn);
         FREG_VO_SetOsdfiltermode_Horfilterup(1, viscaleOsd2ScalerIsrData->iFilter.horFilterUp);
         FREG_VO_SetOsdhordisppixel_Hordisppixel(1, viscaleOsd2ScalerIsrData->iFilter.horDispPixel);
         FREG_VO_SetOsdhorreadpixel_Horreadpixel(1, viscaleOsd2ScalerIsrData->iFilter.horReadPixel);
         FREG_VO_SetOsdverdenum_Verdenum(1, viscaleOsd2ScalerIsrData->iFilter.verD);
         FREG_VO_SetOsdvernum_Vernum(1, viscaleOsd2ScalerIsrData->iFilter.verN);
         FREG_VO_SetOsdfiltermode_Verfilteron(1, viscaleOsd2ScalerIsrData->iFilter.verFilterOn);
         FREG_VO_SetOsdfiltermode_Verfilterup(1, viscaleOsd2ScalerIsrData->iFilter.verFilterUp);
         FREG_VO_SetDisposd2horstartstop_Osd2horstart(viscaleOsd2ScalerIsrData->iFilter.horStart);
         FREG_VO_SetDisposd2horstartstop_Osd2horstop(viscaleOsd2ScalerIsrData->iFilter.horStop);
         FREG_VO_SetDisposd2verstartstop_Osd2verstart(viscaleOsd2ScalerIsrData->iFilter.verStart);
         FREG_VO_SetDisposd2verstartstop_Osd2verstop(viscaleOsd2ScalerIsrData->iFilter.verStop - 1);
         
         for (i = 0; i < 128; i++)
         {
            FREG_VO_SetOsd2hflt(i, viscaleOsd2ScalerIsrData->iFilter.coefficients[i]);
         }

         viscaleOsd2ScalerIsrData->iFilterState = FAPI_VISCALE_FILTERS_UPDATED;
      }
   }

   if ((viscaleCpScalerIsrData != 0) && !r8)
   {
      if ((viscaleCpScalerIsrData->iFadeState == FAPI_VISCALE_INTERNAL_REQUEST_TO_FADE_IN) ||
            (viscaleCpScalerIsrData->iFadeState == FAPI_VISCALE_INTERNAL_FADING_IN))
      {
         viscaleCpScalerIsrData->iFadeCurrValue =
            viscaleCpScalerIsrData->iFadeStepSize +
            viscaleCpScalerIsrData->iFadeCurrValue;
         
         if (viscaleCpScalerIsrData->iFadeCurrValue >= viscaleCpScalerIsrData->iFadeLimitValue)
         {
            viscaleCpScalerIsrData->iFadeCurrValue = viscaleCpScalerIsrData->iFadeLimitValue;
            viscaleCpScalerIsrData->iFadeState = FAPI_VISCALE_INTERNAL_FADE_IN_DONE;
         }
         else
         {
            viscaleCpScalerIsrData->iFadeState = FAPI_VISCALE_INTERNAL_FADING_IN;
         }
         
         for (i = 0; i < 256; i++)
         {
            FREG_VO_SetCursorclut_ClutAlpha(i, viscaleCpScalerIsrData->iFadeCurrValue);
         }
      }
      else if ((viscaleCpScalerIsrData->iFadeState == FAPI_VISCALE_INTERNAL_REQUEST_TO_FADE_OUT) ||
            (viscaleCpScalerIsrData->iFadeState == FAPI_VISCALE_INTERNAL_FADING_OUT))
      {
         viscaleCpScalerIsrData->iFadeCurrValue -= viscaleCpScalerIsrData->iFadeStepSize;
         
         if (viscaleCpScalerIsrData->iFadeCurrValue <= viscaleCpScalerIsrData->iFadeLimitValue)
         {
            viscaleCpScalerIsrData->iFadeCurrValue = 0;
            viscaleCpScalerIsrData->iFadeState = FAPI_VISCALE_INTERNAL_FADE_OUT_DONE;
         }
         else
         {
            viscaleCpScalerIsrData->iFadeState = FAPI_VISCALE_INTERNAL_FADING_OUT;
         }
         
         for (i = 0; i < 256; i++)
         {
            FREG_VO_SetCursorclut_ClutAlpha(i, viscaleCpScalerIsrData->iFadeCurrValue);
         }
      }

      if (viscaleCpScalerIsrData->iEnableState == FAPI_VISCALE_REQUEST_TO_FORCE_ENABLE)
      {
         FREG_VO_SetCursormode_Enable(1);
         
         viscaleCpScalerIsrData->iEnableState = FAPI_VISCALE_FORCE_ENABLED;
      }
      else if (viscaleCpScalerIsrData->iEnableState == FAPI_VISCALE_REQUEST_TO_FORCE_DISABLE)
      {
         FREG_VO_SetCursormode_Enable(0);
         
         viscaleCpScalerIsrData->iEnableState = FAPI_VISCALE_FORCE_DISABLED;
      }

      if (viscaleCpScalerIsrData->iFilterState == FAPI_VISCALE_REQUEST_TO_UPDATE_FILTERS)
      {
         FREG_VO_SetDisposd3horstartstop_Osd3horstart(viscaleCpScalerIsrData->iFilter.horStart);
         FREG_VO_SetDisposd3horstartstop_Osd3horstop(viscaleCpScalerIsrData->iFilter.horStop);
         FREG_VO_SetDisposd3verstartstop_Osd3verstart(viscaleCpScalerIsrData->iFilter.verStart);
         FREG_VO_SetDisposd3verstartstop_Osd3verstop(viscaleCpScalerIsrData->iFilter.verStop);

         viscaleCpScalerIsrData->iFilterState = FAPI_VISCALE_FILTERS_UPDATED;
      }
   }

   if ((viscaleSdScalerIsrData != 0) && !r8)
   {
      if (viscaleSdScalerIsrData->iEnableState == FAPI_VISCALE_REQUEST_TO_FORCE_ENABLE)
      {
         FREG_VO_SetSdenable_Sdenable(1);
         
         viscaleSdScalerIsrData->iEnableState = FAPI_VISCALE_FORCE_ENABLED;
      }
      else if (viscaleSdScalerIsrData->iEnableState == FAPI_VISCALE_REQUEST_TO_FORCE_DISABLE)
      {
         FREG_VO_SetSdenable_Sdenable(0);
         
         viscaleSdScalerIsrData->iEnableState = FAPI_VISCALE_FORCE_DISABLED;
      }

      if (viscaleSdScalerIsrData->iFilterState == FAPI_VISCALE_REQUEST_TO_UPDATE_FILTERS)
      {
         FREG_VO_SetSdhordenum_Hordenum(viscaleSdScalerIsrData->iFilter.horD);
         FREG_VO_SetSdhornum_Hornum(viscaleSdScalerIsrData->iFilter.horN);
         FREG_VO_SetSdfiltermode_Horfilteron(viscaleSdScalerIsrData->iFilter.horFilterOn);
         FREG_VO_SetSdfiltermode_Horfilterup(viscaleSdScalerIsrData->iFilter.horFilterUp);
         FREG_VO_SetSdverdenum_Verdenum(viscaleSdScalerIsrData->iFilter.verD);
         FREG_VO_SetSdvernum_Vernum(viscaleSdScalerIsrData->iFilter.verN);
         FREG_VO_SetSdfiltermode_Verfilteron(viscaleSdScalerIsrData->iFilter.verFilterOn);
         FREG_VO_SetSdfiltermode_Verfilterup(viscaleSdScalerIsrData->iFilter.verFilterUp);
         FREG_VE_SetSdVohorstart_VoHorStart(viscaleSdScalerIsrData->iFilter.sdScalerReq.outputHorStart * 4);
         FREG_VE_SetSdVohorstop_VoHorStop(viscaleSdScalerIsrData->iFilter.sdScalerReq.outputHorStop * 4);
         FREG_VE_SetSdVoverstart_VoVerStart(viscaleSdScalerIsrData->iFilter.sdScalerReq.outputVerStart);
         FREG_VE_SetSdVoverstop_VoVerStop(viscaleSdScalerIsrData->iFilter.sdScalerReq.outputVerStop);
         FREG_VO_SetSdhorwritestart_Horwritestart(viscaleSdScalerIsrData->iFilter.sdScalerReq.sdHorWriteStart);
         FREG_VO_SetSdhorwritestop_Horwritestop(viscaleSdScalerIsrData->iFilter.sdScalerReq.sdHorWriteStop);
         FREG_VO_SetDispcvbshorstartstop_Cvbshorstart(viscaleSdScalerIsrData->iFilter.sdScalerReq.sdDispcvbshorstartstop);
         FREG_VO_SetDispcvbsverstartstop_Cvbsverstart(viscaleSdScalerIsrData->iFilter.sdScalerReq.inputVerStart);
         FREG_VO_SetDispcvbsverstartstop_Cvbsverstop(viscaleSdScalerIsrData->iFilter.sdScalerReq.inputVerStop + 5);
         
         for (i = 0; i < 64; i++)
         {
            FREG_VO_SetSdvflt_Sdvflt(i, viscaleSdScalerIsrData->iFilter.coefficients[i]);
            FREG_VO_SetSdhflt_Sdhflt(i, viscaleSdScalerIsrData->iFilter.coefficients[64+i]);
         }

         FAPI_VISCALE_VideoScalerIsrDataT* r1 = viscaleSdScalerIsrData;

         if (r1->iAutoScalerReqState == FAPI_VISCALE_AUTO_SCALER_REQUEST)
         {
            r1->iAutoScalerReqState = FAPI_VISCALE_AUTO_SCALER_REQUEST_DONE;
         }

         if (r1->iUserScalerReqState == FAPI_VISCALE_USER_SCALER_REQUEST)
         {
            r1->iUserScalerReqState = FAPI_VISCALE_USER_SCALER_REQUEST_DONE;
         }

         r1->iFilterState = FAPI_VISCALE_FILTERS_UPDATED;
      }
   }

   if ((Data_21f672ac != 0) && (r8 == 1))
   {
      if (Data_21f672ac->Data_12 == 1)
      {
         func_21c53ab8(Data_21f672ac);
         
         Data_21f672ac->Data_12 = 0;
      }
      else if (Data_21f672ac->Data_12 == 2)
      {
         func_21c539ec(Data_21f672ac);
         
         Data_21f672ac->Data_12 = 0;
      }
      else if (Data_21f672ac->Data_12 == 3)
      {
         func_21c53b84(Data_21f672ac);
         
         Data_21f672ac->Data_12 = 0;
      }
   }

   if ((viscaleSdScalerIsrData != 0) && (r8 == 1))
   {
      if (55 == FREG_VE_GetmSdhsyncoffset_Sdhsyncoffset())
      {
         FREG_VE_SetSdhsyncoffset_Sdhsyncoffset(48);
      }
      else if (48 == FREG_VE_GetmSdhsyncoffset_Sdhsyncoffset())
      {
         FREG_VE_SetSdhsyncoffset_Sdhsyncoffset(55);
      }
      else
      {
         FREG_VE_SetSdhsyncoffset_Sdhsyncoffset(52);
      }      
   }

   return 1;
}


/* 21c526f8 - complete */
void FAPI_VISCALE_Bsr(uint32_t arg)
{
   /* empty */
}


/* 21c53540 - nearly complete */
void fapi_viscale_clear_handle(FAPI_VISCALE_VideoScalerHandleT* a)
{
//   printf("fapi_viscale_clear_handle\n");
   
   a->inUse = 0;
   strncpy(a->coreName, "Unknown Scaler", 32);
   a->coreID = 0;
   a->baseAddress = 0; 
   a->opParams.version = 0x30002; //48
   a->opParams.scalerType = -1; //52
   a->opParams.encoderType = -1; //56
   a->sdMode = 0; //60
   a->hdMode = 0; //64
   a->pixPerBurst = 0; //68
   a->bitsPerPix = 0; //72
   
   a->scalerParams.layerEnable = 0; //76
   a->scalerParams.osdMode = 15; //84
   a->scalerParams.cpMode = 4; //88
   a->scalerParams.cpTileNumX = 0; //92
   a->scalerParams.cpTileNumY = 0; //96
   a->scalerParams.picBase = 0; //100
   a->scalerParams.frameField = 0; //104
   a->scalerParams.useGlobalAlpha = 0; //108
   a->scalerParams.globalAlpha = 0; //112
   a->scalerParams.hilightOnOff = 0; //116   
   a->scalerParams.diMode = 0; //1144
   a->scalerParams.fieldInversion = 0; //1148
   a->scalerParams.inputPicWidth = 0; //1152
   a->scalerParams.inputPicHeight = 0; //1156
   a->scalerParams.inputWindowX0 = 0; //1160
   a->scalerParams.inputWindowY0 = 0; //1164
   a->scalerParams.inputWindowWidth = 0; //1168
   a->scalerParams.inputWindowHeight = 0; //1172
   a->scalerParams.outputWindowX0 = 0; //1176
   a->scalerParams.outputWindowY0 = 0; //1180
   a->scalerParams.outputWindowWidth = 0; //1184
   a->scalerParams.outputWindowHeight = 0; //1188
   
   a->userRawScalerReq.layerEnable = 0; //1192
   a->userRawScalerReq.osdMode = 15; //1200
   a->userRawScalerReq.cpMode = 4; //1204
   a->userRawScalerReq.cpTileNumX = 0; //1208
   a->userRawScalerReq.cpTileNumY = 0; //1212
   a->userRawScalerReq.picBase = 0; //1216
   a->userRawScalerReq.frameField = 0; //1220
   a->userRawScalerReq.useGlobalAlpha = 0; //1224
   a->userRawScalerReq.globalAlpha = 0; //1228
   a->userRawScalerReq.hilightOnOff = 0; //1232      
   a->userRawScalerReq.diMode = 0; //2260
   a->userRawScalerReq.fieldInversion = 0; //2264
   a->userRawScalerReq.inputPicWidth = 0; //2268
   a->userRawScalerReq.inputPicHeight = 0; //2272
   a->userRawScalerReq.inputWindowX0 = 0; //2276
   a->userRawScalerReq.inputWindowY0 = 0; //2280
   a->userRawScalerReq.inputWindowWidth = 0; //2284
   a->userRawScalerReq.inputWindowHeight = 0; //2288
   a->userRawScalerReq.outputWindowX0 = 0; //2292
   a->userRawScalerReq.outputWindowY0 = 0; //2296
   a->userRawScalerReq.outputWindowWidth = 0; //2300
   a->userRawScalerReq.outputWindowHeight = 0; //2304
   
   a->inputAspectRatio = 0; //2308
   a->inputActiveAspectRatioL0 = 0; //2312
   a->inputActiveAspectRatioL1 = 0; //2316
   a->userDisplayAspectRatio = 0; //2320
   a->displayAspectRatioL0 = 0; //2324
   a->displayAspectRatioL1 = 0; //2328
   a->userScalingMethod = 0; //2332
   a->scalingMethod = 1; //2336
   
   a->afdScalerReq.diMode = 1; //2340
   a->afdScalerReq.fieldInversion = 0; //2344
   a->afdScalerReq.frameField = 0; //2348
   a->afdScalerReq.inputPicWidth = 0; //2352
   a->afdScalerReq.inputPicHeight = 0; //2356
   a->afdScalerReq.inputWindowX0 = 0; //2360
   a->afdScalerReq.inputWindowY0 = 0; //2364
   a->afdScalerReq.inputWindowWidth = 0; //2368
   a->afdScalerReq.inputWindowHeight = 0; //2372
   a->afdScalerReq.outputWindowX0 = 0; //2376
   a->afdScalerReq.outputWindowY0 = 0; //2380
   a->afdScalerReq.outputWindowWidth = 0; //2384
   a->afdScalerReq.outputWindowHeight = 0; //2388
   
   a->userScalerReq.diMode = 0; //2392
   a->userScalerReq.fieldInversion = 0; //2396
   a->userScalerReq.frameField = 0; //2400
   a->userScalerReq.inputPicWidth = 0; //2404
   a->userScalerReq.inputPicHeight = 0; //2408
   a->userScalerReq.inputWindowX0 = 0; //2412
   a->userScalerReq.inputWindowY0 = 0; //2416
   a->userScalerReq.inputWindowWidth = 0; //2420
   a->userScalerReq.inputWindowHeight = 0; //2424
   a->userScalerReq.outputWindowX0 = 0; //2428
   a->userScalerReq.outputWindowY0 = 0; //2432
   a->userScalerReq.outputWindowWidth = 0; //2436
   a->userScalerReq.outputWindowHeight = 0; //2440
   
   a->smScalerReq.diMode = 0; //2444
   a->smScalerReq.fieldInversion = 0; //2448
   a->smScalerReq.frameField = 0; //2452
   a->smScalerReq.inputPicWidth = 0; //2456
   a->smScalerReq.inputPicHeight = 0; //2460
   a->smScalerReq.inputWindowX0 = 0; //2464
   a->smScalerReq.inputWindowY0 = 0; //2468
   a->smScalerReq.inputWindowWidth = 0; //2472
   a->smScalerReq.inputWindowHeight = 0; //2476
   a->smScalerReq.outputWindowX0 = 0; //2480
   a->smScalerReq.outputWindowY0 = 0; //2484
   a->smScalerReq.outputWindowWidth = 0; //2488
   a->smScalerReq.outputWindowHeight = 0; //2492
   
   a->autoScalerReq.diMode = 0; //2496
   a->autoScalerReq.fieldInversion = 0; //2500
   a->autoScalerReq.frameField = 0; //2504
   a->autoScalerReq.inputPicWidth = 0; //2508
   a->autoScalerReq.inputPicHeight = 0; //2512
   a->autoScalerReq.inputWindowX0 = 0; //2516
   a->autoScalerReq.inputWindowY0 = 0; //2520
   a->autoScalerReq.inputWindowWidth = 0; //2524
   a->autoScalerReq.inputWindowHeight = 0; //2528
   a->autoScalerReq.outputWindowX0 = 0; //2532
   a->autoScalerReq.outputWindowY0 = 0; //2536
   a->autoScalerReq.outputWindowWidth = 0; //2540
   a->autoScalerReq.outputWindowHeight = 0; //2544
   
   a->currAfd = 0; //2548
   a->userWssState = 0; //2552
   a->wssState = -1; //2556
   a->currWss = -1; //2560   
   a->isrDataPtr = 0; //2564
   
   //a->fill = 0; //2636
   
   a->Start = 0; //2568
   a->Stop = 0; //2572
   a->EnableDisable = 0; //2576
   a->Alpha = 0; //2580
   a->Resize = 0; //2584
   a->Hilight = 0; //2588
   a->AutoPlaneFading = 0; //2592
   a->AutoPlaneFadingStepSize = 0; //2596
   a->UpdateClut = 0; //2600
   a->UpdateSingleClut = 0; //2604
   a->AutoScale = 0; //2608
   a->SetScalerToHdEncoder = 0; //2612
   a->SetScalingMethod = 0; //2616
   a->SetDisplayAspectRatio = 0; //2620
   a->SetWssState = 0; //2624
   a->SetParamChangeCallback = 0; //2628
   a->GetWssSignal = 0; //2632
}


/* 21c531f8 - complete */
void fapi_viscale_clear_isr_data(FAPI_VISCALE_VideoScalerIsrDataT* a)
{
//   printf("fapi_viscale_clear_isr_data\n");   

   a->inUse = 0;
   a->scalerType = FAPI_VISCALE_UNKNOWN_SCALER;
   a->iFadeState = FAPI_VISCALE_INTERNAL_FADE_OUT_DONE;
   a->iFadeCurrValue = 0; //16
   a->iFadeLimitValue = 0; //12
   a->iFadeStepSize = 10; //20
   a->iEnableState = 0; //24
   a->iUserScalerReqState = 0; 
   a->iAutoScalerReqState = 1; //32
   a->iFilterState = 0;
   
   a->iFilter.hStartPos = 0; //56
   a->iFilter.hSize = 0; //40
   a->iFilter.horDispPixel = 0; //48
   a->iFilter.initalShift = 4; //44
   a->iFilter.horReadPixel = 0; //52
   a->iFilter.horFilterOn = 0; //64
   a->iFilter.horFilterUp = 0; //68
   a->iFilter.horN = 0x10000; //76
   a->iFilter.horD = 0x10000; //72
   a->iFilter.fieldInversion = 0; //80
   a->iFilter.vStartPos = 0; //84
   a->iFilter.verAddPhase = 0; //88
   a->iFilter.verFilterOn = 0; //92
   a->iFilter.verFilterUp = 0; //96
   a->iFilter.verN = 0x10000; //104
   a->iFilter.verD = 0x10000; //100
   a->iFilter.horStart = 0; //108
   a->iFilter.horStop = 0; //112
   a->iFilter.verStart = 0; //116
   a->iFilter.verStop = 0; //120
   
   a->iFilter.sdScalerReq.inputHorStart = 0; //124
   a->iFilter.sdScalerReq.inputHorStop = 0; //128
   a->iFilter.sdScalerReq.inputVerStart = 0; //132
   a->iFilter.sdScalerReq.inputVerStop = 0; //136
   a->iFilter.sdScalerReq.outputHorStart = 0; //140
   a->iFilter.sdScalerReq.outputHorStop = 0; //144
   a->iFilter.sdScalerReq.outputVerStart = 0; //148
   a->iFilter.sdScalerReq.outputVerStop = 0; //152
   a->iFilter.sdScalerReq.sdDispcvbshorstartstop = 0; //164
   a->iFilter.sdScalerReq.sdHorWriteStart = 0; //156
   a->iFilter.sdScalerReq.sdHorWriteStop = 0; //160
   
   a->paramChangeInfo.codedAspectRatio = 0; //680
   a->paramChangeInfo.displayAspectRatio = 0; //684
   a->paramChangeInfo.scalingMethod = 0; //688
   a->paramChangeInfo.currAfd = 0; //692
   a->paramChangeInfo.currWss = 0; //696
   
   a->paramChangeCbk = 0; //700
   a->paramChangeOptData = 0; //704
}


/* 21c539ec - complete */
void func_21c539ec(struct Struct_21f672b0* a)
{
//   printf("21c539ec\n");
   
   unsigned i = 0;    
   int r6 = 0;
   
   if (a->Data_4 > 100)
   {
      r6 = a->Data_4 - 100;
      r6 = r6 * -64 / 100;
   }
   
   FREG_VO_SetDispmixconfenable_Enableyuvlut(0);
   FREG_VO_SetDispmixconfenable_Enablergblut(0);
   
   for (i = 0; i < 1024; i++)
   {
      int r1 = a->Data_4 * 100;
      r1 = i * r1;
      r1 = r1 / 10000 + a->Data_0 + r6;
      
      if (r1 < 64) r1 = 64;
      else if (r1 > 960) r1 = 960;

      FREG_VO_SetBLut_Value(i, r1);
   }

   FREG_VO_SetDispmixconfenable_Enableyuvlut(1);
   FREG_VO_SetDispmixconfenable_Enablergblut(1);
}


/* 21c53ab8 - complete */
void func_21c53ab8(struct Struct_21f672b0* a)
{
//   printf("21c53ab8\n");
   
   unsigned i = 0;    
   int r6 = 0;
   
   if (a->Data_4 > 100)
   {
      r6 = a->Data_4 - 100;
      r6 = r6 * -64 / 100;
   }
   
   FREG_VO_SetDispmixconfenable_Enableyuvlut(0);
   FREG_VO_SetDispmixconfenable_Enablergblut(0);
   
   for (i = 0; i < 1024; i++)
   {
      int r1 = a->Data_4 * 100;
      r1 = i * r1;
      r1 = r1 / 10000 + a->Data_0 + r6;
      
      if (r1 < 64) r1 = 64;
      else if (r1 > 960) r1 = 960;

      FREG_VO_SetBLut_Value(i, r1);
   }

   FREG_VO_SetDispmixconfenable_Enableyuvlut(1);
   FREG_VO_SetDispmixconfenable_Enablergblut(1);
}


/* 21c53b84 - complete */
void func_21c53b84(struct Struct_21f672b0* a)
{
//   printf("21c53b84\n");
   
   unsigned i = 0;
   
   FREG_VO_SetDispmixconfenable_Enableyuvlut(0);
   FREG_VO_SetDispmixconfenable_Enablergblut(0);
   
   for (i = 0; i < 1024; i++)
   {
      int r1 = (a->Data_8 + 100) * (i - 504);
      r1 = (r1 / 100) + 512;
      
      if (r1 < 64) r1 = 64;
      else if (r1 > 960) r1 = 960;

      FREG_VO_SetGLut_Value(i, r1);
      FREG_VO_SetRLut_Value(i, r1);
   }

   FREG_VO_SetDispmixconfenable_Enableyuvlut(1);
   FREG_VO_SetDispmixconfenable_Enablergblut(1);
}


/* 21c53c18 - complete */
void func_21c53c18(struct Struct_21f672b0* a)
{
//   printf("func_21c53c18\n");
   
   unsigned i = 0;
   
   if (a != 0)
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
         int r1 = i*4;
         if (r1 < 0) r1 = 0;
         else if (r1 >= 1024) r1 = 1023;
         
         FREG_VO_SetYLut_Value(i, r1);
      }
      
      for (i = 0; i < 256; i++)
      {
         int r1 = i*4;
         if (r1 < 0) r1 = 0;
         else if (r1 >= 1024) r1 = 1023;
         
         FREG_VO_SetCrLut_Value(i, r1);
      }
      
      for (i = 0; i < 256; i++)
      {
         int r1 = i*4;
         if (r1 < 0) r1 = 0;
         else if (r1 >= 1024) r1 = 1023;

         FREG_VO_SetCbLut_Value(i, r1);
      }
      
      func_21c53ab8(a);
      func_21c539ec(a);
      func_21c53b84(a);
      
      FREG_VO_SetMixrgbyuv_Data(2, 0x42);
      FREG_VO_SetMixrgbyuv_Data(1, 0x81);
      FREG_VO_SetMixrgbyuv_Data(0, 0x19);
      FREG_VO_SetMixrgbyuv_Data(3, 0x10);
      FREG_VO_SetMixrgbyuv_Data(6, -0x26);
      FREG_VO_SetMixrgbyuv_Data(5, -0x4a);
      FREG_VO_SetMixrgbyuv_Data(4, 0x70);
      FREG_VO_SetMixrgbyuv_Data(7, 0x80);
      FREG_VO_SetMixrgbyuv_Data(10, 0x70);
      FREG_VO_SetMixrgbyuv_Data(9, -0x5e);
      FREG_VO_SetMixrgbyuv_Data(8, -0x12);
      FREG_VO_SetMixrgbyuv_Data(11, 0x80);
      
      FREG_VO_SetDispmixconfenable_Enablergblut(1);
      FREG_VO_SetDispmixconfenable_Enablergbconv(0);
      FREG_VO_SetDispmixconfenable_Enableyuvlut(1);
      FREG_VO_SetDispmixconfenable_Enableyuvconv(0);
   }
}


int32_t fapi_viscale_voenabledisable(FAPI_SYS_HandleT handle,
                                   FAPI_VISCALE_ParameterModeEnumT mode)
{
   FAPI_SYS_PRINT_MSG("fapi_viscale_voenabledisable\n");
   return 0;
}


unsigned Data_21e01bb0[66] = //21e01bb0
{
0x8800051d, 0x0000717f, 
0x95000615, 0x00007172, 0xa7000715, 0x0000715f, 
0xb9000715, 0x0000514e, 0xcb00070d, 0x0000513d, 
0xd900060e, 0x0000352c, 0xe6000507, 0x0000191d, 
0xf3000307, 0x00001d0e, 0xff000000, 0x00000000, 
0xfe0efc01, 0x000003f4, 0xf81ff802, 0x000005ea, 
0xed31f40a, 0x000027e3, 0xe044ef13, 0x000028df, 
0xd159ea1b, 0x000048dc, 0xc06ee623, 0x000048db, 
0xad84e12b, 0x000067dc, 0x9999de33, 0x000066de, 
0x84addc3b, 0x000065e1, 0x6ec0db42, 0x000064e6, 
0x59d1dc42, 0x000063ea, 0x44e0df41, 0x000062ef, 
0x31ede339, 0x000041f4, 0x1ff8ea28, 0x000040f8, 
0x0efef418, 0x000020fc, 0x00ff0000, 0x00000000, 
0x00f30ee8, 0x0000e003, 0x00e61dc8, 0x0000e005, 
0x00d92ca9, 0x0000c106, 0x00cb3d8a, 0x0000a107, 
0x00b94e8a, 0x0000a207, 0x00a75f8b, 0x0000a207, 
0x0095728b, 0x0000a206, 0x00887f8b, 0x0000a305,
};
unsigned Data_21e01cb8[66] = //21e01cb8
{
0x9200e378, 0x0000a07f, 0x9107e27a, 0x0000b97f, 
0x950fe07b, 0x0000b37a, 0x9a17de73, 0x0000b172, 
0x9d20dd63, 0x0000b169, 0xa129dc4b, 0x0000b160, 
0xa332dc3b, 0x0000b157, 0xa73bdc1b, 0x0000b14e, 
0xa644de03, 0x00001144, 0xa44de0eb, 0x0000713b, 
0xa458e2cb, 0x00007132, 0xa462e5ab, 0x00007129, 
0xa26de98b, 0x00007120, 0x9d75ee8b, 0x00007118, 
0x997df38b, 0x0000710f, 0x9385f98b, 0x00007107, 
0x8c8c008b, 0x00007100, 0x8593078b, 0x000071f9, 
0x7d990f8b, 0x000071f3, 0x759d188b, 0x000071ee, 
0x6ca3208b, 0x000071e9, 0x62a4298b, 0x000075e5, 
0x58a4328b, 0x000079e2, 0x4da43b8b, 0x00007de0, 
0x44a64488, 0x000060de, 0x3ca64e8d, 0x000063dc, 
0x32a3578d, 0x000067dc, 0x29a1608d, 0x000069dc, 
0x209d698d, 0x00006cdd, 0x179a728d, 0x00006ede, 
0x0f957a9d, 0x00006fe0, 0x07917fcd, 0x00004fe2, 
0x00927f05, 0x00000fe3,
};
unsigned Data_21e01dc0[66] = //21e01dc0
{
0x5f3a088d, 0x00006f5f, 
0x5f3b0a8d, 0x00006f5c, 0x5e3d0d8d, 0x00006f58, 
0x5e3f108d, 0x00000f56, 0x5e41128d, 0x0000cf54, 
0x5d431595, 0x0000af50, 0x5b4417a5, 0x0000af4d, 
0x5a4519b5, 0x0000af49, 0x58461cbd, 0x0000af46, 
0x57471ecd, 0x0000af42, 0x554820dd, 0x0000af3f, 
0x544822ed, 0x0000af3c, 0x524925f5, 0x0000af39, 
0x514b2705, 0x0000ad36, 0x504c2915, 0x0000ab34, 
0x4f4d2c25, 0x0000a931, 0x4e4e2e3d, 0x0000a72e, 
0x4d4f314d, 0x0000a42c, 0x4c50345d, 0x0000a229, 
0x4b51366d, 0x0000a027, 0x4952397d, 0x0000be25, 
0x48543c7d, 0x0000bd22, 0x48553f7d, 0x0000bb20, 
0x4757427d, 0x0000b91e, 0x4658467d, 0x0000b71c, 
0x455a497d, 0x0000b619, 0x445b4d7d, 0x0000b417, 
0x435d507d, 0x0000b215, 0x415e547e, 0x0000b112, 
0x3f5e5678, 0x0000b110, 0x3d5e587b, 0x0000b10d, 
0x3b5f5c7b, 0x0000b10a, 0x3a5f5f7b, 0x0000b108,
};


/* 21c6d0d8 - complete */
void HSCALE(FAPI_VISCALE_VideoScalerHandleT* h, 
            uint32_t layer, uint32_t doubling_factor)
{
   int r1;
   uint32_t r2;
   unsigned i;
   int r9 = 0;
   unsigned r8 = 0;
   uint32_t r0 = 0x10000;
   
//   FAPI_SYS_PRINT_MSG("HSCALE\n");
   
   if (h->scalerParams.inputWindowWidth == //1168
      h->scalerParams.outputWindowWidth) //1184
   {
      //21c6d2fc
      h->isrDataPtr->iFilter.horFilterOn = 0;
      h->isrDataPtr->iFilter.horFilterUp = 0;
      h->isrDataPtr->iFilter.horAddPhase = 0;
      
      r0 = ((h->scalerParams.outputWindowWidth << 16) / 
            h->scalerParams.inputWindowWidth) + 1;
   }
   //21c6d100
   if (h->scalerParams.inputWindowWidth > 
      h->scalerParams.outputWindowWidth)
   {
      //21c6d108
      h->isrDataPtr->iFilter.horFilterOn = 1; //64
      h->isrDataPtr->iFilter.horFilterUp = 0; //68
      h->isrDataPtr->iFilter.horAddPhase = 0; //60
      
      r0 = ((h->scalerParams.outputWindowWidth << 16) / 
            h->scalerParams.inputWindowWidth) + 1;
   }
   //21c6d134
   if (h->scalerParams.inputWindowWidth < 
      h->scalerParams.outputWindowWidth)
   {
      //21c6d13c
      h->isrDataPtr->iFilter.horFilterOn = 1; //64
      h->isrDataPtr->iFilter.horFilterUp = 1; //68
      h->isrDataPtr->iFilter.horAddPhase = 0; //60
      
      r0 = ((h->scalerParams.inputWindowWidth << 16) / 
            h->scalerParams.outputWindowWidth) + 1;
   }
   //21c6d164
   switch (layer)
   {
   case 0:
      r1 = 64;
      h->isrDataPtr->iFilter.horD = 0x10000;
      h->isrDataPtr->iFilter.horN = r0;
      r9 = 8;
      break;
      
   case 1:
      //->21c6d344
      r1 = 64;
      h->isrDataPtr->iFilter.horD = 0x10000;
      h->isrDataPtr->iFilter.horN = r0;

      r2 = r0;
      
      while (r2 & 0xf000)
      {
         r2 += r0;
      }
      
      //21c6d36c
      r8 = ((0x20000 - (r0 << 1) - r2) & 0xFFFF) >> 12;
      //->21c6d184
      break;
      
   case 2:
      //21c6d32c
      r1 = 64;
      h->isrDataPtr->iFilter.horD = 0x10000;
      h->isrDataPtr->iFilter.horN = r0;
      //->21c6d184
      break;
      
   default:
      //21c6d280
      r1 = 64;
      h->isrDataPtr->iFilter.horD = 0x10000;
      h->isrDataPtr->iFilter.horN = r0;
      break;
   }
   //21c6d184
   unsigned r5 = h->scalerParams.inputWindowWidth * doubling_factor;
   
   if (h->scalerParams.outputWindowWidth == r5)
   {
      //->21c6d2a8
      for (i = 0; i < 16; i++)
      {
         //21c6d2c0         
         h->isrDataPtr->iFilter.coefficients[i*4 + r1] = 0xff000000;
         h->isrDataPtr->iFilter.coefficients[i*4 + r1+1] = 0;
         h->isrDataPtr->iFilter.coefficients[i*4 + r1+2] = Data_21e01bb0[r9*2]; 
         h->isrDataPtr->iFilter.coefficients[i*4 + r1+3] = Data_21e01bb0[r9*2+1]; 
      }
      return;
   }
   //21c6d198
   else if (r5 < h->scalerParams.outputWindowWidth)
   {
      //21c6d1a0
      for (i = 0; i < 16; i++)
      {
         //21c6d1b0         
         h->isrDataPtr->iFilter.coefficients[i*4 + r1] = Data_21e01bb0[i*2 + 16];
         h->isrDataPtr->iFilter.coefficients[i*4 + r1+1] = Data_21e01bb0[i*2 + 16+1];
         h->isrDataPtr->iFilter.coefficients[i*4 + r1+2] = Data_21e01bb0[(i+r9)*2];
         h->isrDataPtr->iFilter.coefficients[i*4 + r1+3] = Data_21e01bb0[(i+r9)*2 + 1];
      }
      return;
   }
   //21c6d1fc
   r0 = r0 / doubling_factor;
   
   if (r5 <= h->scalerParams.outputWindowWidth * doubling_factor)
   {
      //21c6d210
      if (r0 > 54613)
      {
         //21c6d21c
         for (i = 0; i < 16; i++)
         {
            //21c6d22c         
            h->isrDataPtr->iFilter.coefficients[i*4 + r1] = Data_21e01bb0[i*2 + 16];
            h->isrDataPtr->iFilter.coefficients[i*4 + r1+1] = Data_21e01bb0[i*2 + 16+1];
            h->isrDataPtr->iFilter.coefficients[i*4 + r1+2] = Data_21e01bb0[(i+r9)*2];
            h->isrDataPtr->iFilter.coefficients[i*4 + r1+3] = Data_21e01bb0[(i+r9)*2+1];
         }
         return;
      }
      //21c6d4e8
      else if (r0 > 39442)
      {
         //21c6d504
         for (i = 0; i < 16; i++)
         {
            //21c6d514
            h->isrDataPtr->iFilter.coefficients[i*4 + r1] = Data_21e01cb8[i*2 + 16];
            h->isrDataPtr->iFilter.coefficients[i*4 + r1+1] = Data_21e01cb8[i*2 + 16+1];
            h->isrDataPtr->iFilter.coefficients[i*4 + r1+2] = Data_21e01cb8[(i+r9)*2];
            h->isrDataPtr->iFilter.coefficients[i*4 + r1+3] = Data_21e01cb8[(i+r9)*2+1];
         }
         return;
      }
      else
      {
         //21c6d4f0
         for (i = 0; i < 16; i++)
         {
            //21c6d560
            h->isrDataPtr->iFilter.coefficients[i*4 + r1] = Data_21e01dc0[i*2 + 16];
            h->isrDataPtr->iFilter.coefficients[i*4 + r1+1] = Data_21e01dc0[i*2 + 16+1];
            h->isrDataPtr->iFilter.coefficients[i*4 + r1+2] = Data_21e01dc0[(i+r9)*2];
            h->isrDataPtr->iFilter.coefficients[i*4 + r1+3] = Data_21e01dc0[(i+r9)*2+1];
         }
         return;
      }
   }
   else
   {
      //21c6d38c
      if (r0 > 54613)
      {
         //21c6d398
         for (i = 0; i < 16; i++)
         {
            //21c6d3ac
            unsigned r3 = (i + r8) % 16; 
            
            h->isrDataPtr->iFilter.coefficients[r3*4 + r1] = Data_21e01bb0[(24-i)*2];
            h->isrDataPtr->iFilter.coefficients[r3*4 + r1+1] = Data_21e01bb0[(24-i)*2+1];
            h->isrDataPtr->iFilter.coefficients[r3*4 + r1+2] = Data_21e01bb0[16 + (16-i+r9)*2];
            h->isrDataPtr->iFilter.coefficients[r3*4 + r1+3] = Data_21e01bb0[16 + (16-i+r9)*2+1];
         }
         return;
      }
      //21c6d404
      else if (r0 > 39442)
      {
         //21c6d424
         for (i = 0; i < 16; i++)
         {
            //21c6d3ac         
            unsigned r3 = (i + r8) % 16; 

            h->isrDataPtr->iFilter.coefficients[r3*4 + r1] = Data_21e01cb8[(24-i)*2];
            h->isrDataPtr->iFilter.coefficients[r3*4 + r1+1] = Data_21e01cb8[(24-i)*2+1];
            h->isrDataPtr->iFilter.coefficients[r3*4 + r1+2] = Data_21e01cb8[16 + (16-i+r9)*2];
            h->isrDataPtr->iFilter.coefficients[r3*4 + r1+3] = Data_21e01cb8[16 + (16-i+r9)*2+1];
         }
         return;
      }
      else
      {
         //21c6d40c
         for (i = 0; i < 16; i++)
         {
            //21c6d3ac         
            unsigned r3 = (i + r8) % 16; 

            h->isrDataPtr->iFilter.coefficients[r3*4 + r1] = Data_21e01dc0[(24-i)*2];
            h->isrDataPtr->iFilter.coefficients[r3*4 + r1+1] = Data_21e01dc0[(24-i)*2+1];
            h->isrDataPtr->iFilter.coefficients[r3*4 + r1+2] = Data_21e01dc0[16 + (16-i+r9)*2];
            h->isrDataPtr->iFilter.coefficients[r3*4 + r1+3] = Data_21e01dc0[16 + (16-i+r9)*2+1];
         }
         return;
      }
   }
}


/* 21c6c520 - todo */
void func_2196c62c(FAPI_VISCALE_VideoScalerHandleT* h,
      unsigned sp16, int sp12, int sp8,
      int sp248, uint32_t sp252, unsigned sp256)
{
   int r8         = 0;
   int r6         = 0;
   int r7         = 0;
   int r5         = 0;
   int fp         = 0;
   int r4        = 0;
   int i          = 0;
//   int sp20     = 0;
//   int sp24     = 0;
   int sp28 = 0;
   int sp32     = 0;
   int sp36     = 0;
   int ip     = 0;
   int sp40     = 0;
   int sp44        = 0;
   int sp48 = 0;
   int sp52 = 0;
   unsigned sp56 = 0;
   unsigned sp80 = 0;
   int r9     = 0;

   int sp0x44[16];
   int sp4[16];

   sp32 = (sp12 + 0x800) >> 12;

   if (sp248 < 0)
   {
      sp48 = -sp248;
   }
   else
   {
      sp52 = sp248;
   }

   if (sp16 == 0)
   {
      //21c6c570
      if ((sp252 == 0) || (sp252 == 1))
      {
         //21c6d020
         if (sp48 < 0x4000)
         {
            //21c6d02c
            sp52 = (sp52 + 0x4000) - sp48; //sp52 = (sp52 - sp48) + 0x4000;
            sp48 = 0x4000;
         }
         //21c6d044
         if (sp52 < 0xc000)
         {
            //21c6d050
            sp48 = (sp48 + 0xc000) - sp52; //sp48 = (sp48 - sp52) + 0xc000;
            sp52 = 0xc000;
         }
         //->21c6c5b4
      }
      else
      {
         //21c6c57c
         if (sp48 < 0x8000)
         {
            //21c6c58c
            //sp52 = (sp52 + 0x8000) - sp48;
            //sp52 = (sp52 - sp48) + 0x8000;
            sp52 += (0x8000 - sp48);
            sp48 = 0x8000;
         }
         //21c6c5a8
         if (sp52 < 0x8000)
         {
            //2196c6fc
            sp48 = (sp48 + 0x8000) - sp52; //sp48 = (sp48 - sp52) + 0x8000;
            sp52 = 0x8000;
         }
         //2196c718
      }
      //2196c718
      if ((sp48 >= 0x8000) && (sp48 <= 0x14000) && (sp52 <= 0x14000))
      {
         //2196c734
         sp52 = (sp52 + 0x10000) - sp48; //sp52 = (sp52 - sp48) + 0x10000;
         sp48 = 0x10000;
         //->2196c784
      }
      //2196c750
      else if ((sp52 >= 0x8000) && (sp52 <= 0x14000) && (sp48 <= 0x14000))
      {
         sp48 = (sp48 + 0x10000) - sp52; //sp48 = (sp48 - sp52) + 0x10000;
         sp52 = 0x10000;
      }
      //2196c784
   }
   //21c6c5f4
   //sp20 = sp8 * 10;

   for (sp28 = 0; sp28 < 16; sp28++)
   {
      //->21c6c934
      int r3;
      int r0;

      if ((sp256 == 1)/*sp68*/ && (sp16 == 0)/*sp60*/) //sp4
      {
         //21c6c650
         int r0_ = ((sp28 & 0xfc) << 16) / sp32;
         r0 = (sp48 + r0_) / 256;
         r3 = (sp52 + r0_) / 256;
      }
      else
      {
         //21c6c940
         int r0_ = (sp28 << 16) / sp32;
         r0 = (sp48 + r0_) / 256;
         r3 = (sp52 + r0_) / 256;
      }
      //21c6c674
      r8 = 0;
      r6 = 0;
      ip = 0;
      sp40 = 0;

      if (r0 < 0)
      {
         r8 = 0x100;
         //->21c6c70c
      }
      else if (r0 < 0x100)
      {
         r6 = r0;
         r8 = 0x100 - r0;
         //->21c6c70c
      }
      else if (r0 < 0x200)
      {
         ip = r0 - 0x100;
         r6 = 0x100 - ip;
         //->21c6c70c
      }
      else if (r0 < 0x300)
      {
         sp40 = r0 - 0x200;
         ip = 0x100 - sp40;
      }
      else
      {
         sp40 = 0x100;
      }
      //21c6c70c
      r7 = 0;
      r5 = 0;
      fp = 0;
      sp44 = 0;

      if (r3 < 0)
      {
         r7 = 0x100;
         //->21c6c784
      }
      else if (r3 < 0x100)
      {
         r5 = r3;
         r7 = 0x100 - r3;
         //->21c6c784
      }
      else if (r3 < 0x200)
      {
         fp = r3 - 0x100;
         r5 = 0x100 - fp;
         //->21c6c784
      }
      else if (r3 < 0x300)
      {
         sp44 = r3 - 0x200;
         fp = 0x100 - sp44;
      }
      else
      {
         sp44 = 0x100;
      }
      //21c6c784
      if (sp16 > 1) //r2
      {
         //2196c8d4
         if (r0 >= 0x100)
         {
            //2196c8dc
            r6 = 0x100;
            ip = 0;
            sp40 = 0;
         }
         //2196c8ec
         if (r3 >= 0x100)
         {
            fp = 0;
            r5 = 0x100;
            sp44 = 0; //fp
         }
      }
      //21c6c7c0
      if (r8 >= 0xff)
      {
         r8 = 0xfe;
         r6 = 2;
         ip = 0;
         sp40 = 0;
         //->21c6c810
      }
      /*else*/ if (r6 >= 0xff)
      {
         r8 = 2;
         r6 = 0xfe;
         ip = 0;
         sp40 = 0;
         //->21c6c810
      }
      /*else*/ if (ip >= 0xff)
      {
         r8 = 0;
         r6 = 2;
         ip = 0xfe;
         sp40 = 0;
         //->21c6c810
      }
      /*else*/ if (sp40 >= 0xff)
      {
         r8 = 0;
         r6 = 0;
         ip = 2;
         sp40 = 0xfe;
      }
      //21c6c810
      if (r7 >= 0xff)
      {
         sp44 = 0;
         r7 = 0xfe;
         r5 = 2;
         fp = 0; //sp44
         //->21c6c860
      }
      /*else*/ if (r5 >= 0xff)
      {
         sp44 = 0;
         r7 = 2;
         r5 = 0xfe;
         fp = 0; //sp44
         //->21c6c860
      }
      /*else*/ if (fp >= 0xff)
      {
         r7 = 0;
         r5 = 2;
         fp = 0xfe;
         sp44 = 0; //r7
      }
      /*else*/ if (sp44 >= 0xff)
      {
         r7 = 0;
         sp44 = 0xfe;
         fp = 2;
         r5 = 0; //r7
      }
      //21c6c860
      switch (sp16)
      {
      case 0:
         //21c6c884
         r4 = sp28 * 4;
         r9 = 2;
         break;

      case 1:
         //21c6c868
         r4 = sp28 * 2;
         r9 = 32;
         break;

      case 2:
         //21c6c9c0
         r4 = sp28 * 4;
         r9 = 2;
         break;

      default:
         //21c6c884
         r4 = sp28 * 4;
         r9 = 2;
         break;
      }
      //21c6c88c
      if (sp12 >= sp8)
      {
         //21c6c89c
         //if (sp16 < 2)
         if ((sp16 == 0) || (sp16 == 1))
         {
            //21c6c9cc
            if (sp16 != 0)
            {
               //21c6cec8
               h->isrDataPtr->iFilter.coefficients[r4 + 1] =
                  (((((sp40 << 8) + ip) << 8) + r6) << 8) + r8;
                  //(sp40 << 24) + (ip << 16) + (r6 << 8) + (r8 << 0);

               h->isrDataPtr->iFilter.coefficients[r4 + r9 + 1] =
                  (((((sp44 << 8) + fp) << 8) + r5) << 8) + r7;
                  //(sp44 << 24) + (fp << 16) + (r5 << 8) + (r7 << 0);
            }
            //21c6c9d4
            h->isrDataPtr->iFilter.coefficients[r4] =
               (((((sp40 << 8) + ip) << 8) + r6) << 8) + r8;
               //(sp40 << 24) + (ip << 16) + (r6 << 8) + (r8 << 0);

            h->isrDataPtr->iFilter.coefficients[r4 + r9] =
               (((((sp44 << 8) + fp) << 8) + r5) << 8) + r7;
               //(sp44 << 24) + (fp << 16) + (r5 << 8) + (r7 << 0);
         }
         else
         {
            //21c6c8a8
            h->isrDataPtr->iFilter.coefficients[r4] =
               (((((r6 << 8) + r8) << 8) + r6) << 8) + r8;
               //(r6 << 24) + (r8 << 16) + (r6 << 8) + (r8 << 0);

            h->isrDataPtr->iFilter.coefficients[r4 + r9] =
               (((((r5 << 8) + r7) << 8) + r5) << 8) + r7;
               //(r5 << 24) + (r7 << 16) + (r5 << 8) + (r7 << 0);

            h->isrDataPtr->iFilter.coefficients[r4 + 1] =
               (((((r6 << 8) + r8) << 8) + r6) << 8) + r8;
               //(r6 << 24) + (r8 << 16) + (r6 << 8) + (r8 << 0);

            h->isrDataPtr->iFilter.coefficients[r4 + r9 + 1] =
               (((((r5 << 8) + r7) << 8) + r5) << 8) + r7;
               //(r5 << 24) + (r7 << 16) + (r5 << 8) + (r7 << 0);
         }
      }
      else
      {
         //21c6c964
         //if (sp16 < 2)
         if ((sp16 == 0) || (sp16 == 1))
         {
            //21c6cdd4
            int r0 = sp8 * 10 / sp12; //sp20 / sp12;

            if (r0 > 0x23)
            {
               //21c6cde8
               sp44 = 0x40;
               fp = 0x40;
               r5 = 0x40;
               r7 = 0x40;
               //->21c6ce1c
            }
            else if (r0 > 0x19)
            {
               //2196cb80
               fp = 0x55;
               sp44 = 1;
               r5 = 0x55;
               r7 = 0x55;
            }
            //21c6ce1c
            if (sp16 != 0)
            {
               //21c6cf28
               if ((sp48 < 0x30000) && (sp52 < 0x30000))
               {
                  //21c6cf3c
                  sp40 = ip;
                  sp44 = fp;
                  ip = r6;
                  r6 = r8;
                  fp = r5;
                  r8 = 0;
                  r5 = r7;
                  r7 = 0; //r8
               }
               //21c6cf5c
               h->isrDataPtr->iFilter.coefficients[r4 + 1] =
                  (((((r7 << 8) + r5) << 8) + fp) << 8) + sp44;
                  //(r7 << 24) + (r5 << 16) + (fp << 8) + (sp44 << 0);

               h->isrDataPtr->iFilter.coefficients[r4 + r9 + 1] =
                  (((((r8 << 8) + r6) << 8) + ip) << 8) + sp40;
                  //(r8 << 24) + (r6 << 16) + (ip << 8) + (sp40 << 0);
            }
            //21c6ce28
            h->isrDataPtr->iFilter.coefficients[r4] =
               (((((r7 << 8) + r5) << 8) + fp) << 8) + sp44;
               //(r7 << 24) + (r5 << 16) + (fp << 8) + (sp44 << 0);

            h->isrDataPtr->iFilter.coefficients[r4 + r9] =
               (((((r8 << 8) + r6) << 8) + ip) << 8) + sp40;
               //(r8 << 24) + (r6 << 16) + (ip << 8) + (sp40 << 0);
         }
         else
         {
            //21c6c970
            h->isrDataPtr->iFilter.coefficients[r4] =
               (((((r7 << 8) + r5) << 8) + r7) << 8) + r5;
               //(r7 << 24) + (r5 << 16) + (r7 << 8) + (r5 << 0);

            h->isrDataPtr->iFilter.coefficients[r4 + r9] =
               (((((r8 << 8) + r6) << 8) + r8) << 8) + r6;
               //(r8 << 24) + (r6 << 16) + (r8 << 8) + (r6 << 0);

            h->isrDataPtr->iFilter.coefficients[r4 + 1] =
               (((((r7 << 8) + r5) << 8) + r7) << 8) + r5;
               //(r7 << 24) + (r5 << 16) + (r7 << 8) + (r5 << 0);

            h->isrDataPtr->iFilter.coefficients[r4 + r9 + 1] =
               (((((r8 << 8) + r6) << 8) + r8) << 8) + r6;
               //(r8 << 24) + (r6 << 16) + (r8 << 8) + (r6 << 0);
         }
      }
   }
   //21c6ca48
   i = 0;
   r6 = 0; //r7
   r7 = 0; //r6
   sp56 = 0;
   sp80 = 0;
   sp36 = 0;

   if (sp16 == 0) //sp60
   {
      //21c6ca54
      for (i = 0; i < 16; i++)
      {
         //21c6ca5c
         sp0x44[i] = 0;
         sp4[i] = 0;
      }
      //21c6ca78
      if (sp252 < 2)
      {
         //21c6d074
         sp48 -= 0x4000; //->sp76
         sp52 -= 0xc000; //->sp72
      }
      else
      {
         //21c6ca84
         sp48 -= 0x8000;
         sp52 -= 0x8000;
      }
      //21c6ca9c
      //sp24 = sp12 * 2;

      for (/*r8*/i = 0; i < 16; i++) //r9 = r8*4
      {
         //21c6cb9c
         int r1;
         int r0;
         int r3;
         int r2;

         int r0_ = (r6 << 16) / sp32;
         int r2_ = (r0_ + sp48) / 256;
         int r12 = (r0_ + sp52) / 256;

         r1 = 0; //r5
         r0 = 0; //r4

         if (r2_ < 0)
         {
            r1 = 0x100; //r5
            //->21c6cbfc
         }
         else if (r2_ < 0x200)
         {
            r0 = r2_ / 2; //r4
            r1 = 0x100 - r0; //r5
         }
         else
         {
            r0 = 0x100; //r4
         }
         //21c6cbfc
         r3 = 0; //lr
         r2 = 0; //r0

         if (r12 < 0)
         {
            r3 = 0x100; //lr
            //->21c6cc24
         }
         else if (r12 < 0x200)
         {
            r2 = r12 / 2; //r0
            r3 = 0x100 - r2; //lr
         }
         else
         {
            r2 = 0x100; //r0
         }
         //21c6cc24
         if (r1 >= 0xff)
         {
            r1 = 0xfe;
            r0 = 2;
            //->21c6cc40
         }
         else if (r0 >= 0xff)
         {
            r0 = 0xfe;
            r1 = 2;
         }
         //21c6cc40
         if (r3 >= 0xff)
         {
            r3 = 0xfe;
            r2 = 2;
            //->21c6cc5c
         }
         else if (r2 >= 0xff)
         {
            r2 = 0xfe;
            r3 = 2;
         }
         //21c6cc5c
         if ((sp256 == 1)/*sp68*/ && (sp16 == 0) &&
               ((r6 == 0) || (r6 == sp32)) && (i != 0))
         {
            sp56 = (sp56 + 1) & 3;
         }
         //21c6cc8c
         if (sp12 >= sp8)
         {
            //21c6cac8
            if (r6 < sp32)
            {
               sp80 = sp56 + r6;
            }
            else
            {
               sp80 = sp56 + r6 - sp32;
            }
            //21c6caf0
            if ((sp0x44[sp80] != 0) &&
                  (sp0x44[sp80] != (r1 + (r0 << 8))))
            {
               sp0x44[i] = 0x8080;
            }
            else
            {
               //21c6ce78
               sp0x44[sp80] = r1 + (r0 << 8);
            }
            //21c6cb30
            if ((sp4[sp80] != 0) &&
                  (sp4[sp80] != (r3 + (r2 << 8))))
            {
               sp4[i] = 0x8080;
            }
            else
            {
               //21c6ce68
               sp4[sp80] = r3 + (r2 << 8);
            }
            //21c6cb64
            r7 = (r7 + sp8) % (sp12 * 2); //sp24;
            r6 = r7 / 4096;
            //->2196cf8c
         }
         else
         {
            //21c6cc9c
            if ((sp0x44[sp80] != 0) &&
                  (sp0x44[sp80] != (r2 + (r3 << 8))))
            {
               sp0x44[i] = 0x8080;
            }
            else
            {
               sp0x44[sp80] = r2 + (r3 << 8);
            }

            if ((sp4[sp80] != 0) &&
                  (sp4[sp80] != (r0 + (r1 << 8))))
            {
               sp4[i] = 0x8080;
            }
            else
            {
               sp4[sp80] = r0 + (r1 << 8);
            }
            //21c6cd10
            r7 += sp12;

            sp36 = !sp36; //1 & ~sp36;

            if (r7 >= sp8)
            {
               //21c6cd30
               r7 -= sp8;

               if (sp36 == 0)
               {
                  //21c6cd3c
                  r6 = r7 / 4096;
               }
               else
               {
                  //21c6cea8
                  r6 = r7 / 4096 - sp32;
               }
               //21c6cd54
               sp80 = r7 / 4096 + sp56;
            }
            //21c6cb8c
         }
      } //for (i = 0; i < 16; i++)
      //21c6cd70
      for (i = 0; i < 16; i++)
      {
         //21c6cd74
         if (sp0x44[i] == 0)
         {
            sp0x44[i] = 0x8080;
         }

         if (sp4[i] == 0)
         {
            sp4[i] = 0x8080;
         }

         h->isrDataPtr->iFilter.coefficients[1 + i*4] = sp0x44[i];
         h->isrDataPtr->iFilter.coefficients[3 + i*4] = sp4[i];
      }
   }
   //21c6cdcc
}


/* 21c6d5c0 - complete */
void VSCALE(FAPI_VISCALE_VideoScalerHandleT* h, uint32_t layer)
{
//   FAPI_SYS_PRINT_MSG("VSCALE\n");

   unsigned r0 = 0;
   unsigned r5 = 0;
   unsigned r6 = 0;
   int r11 = 0;
   unsigned sp0x10 = 0;
   int r10 = 0xf;
   int r9 = 0xf;

   switch (h->scalerParams.diMode)
   {
   case 0:
      //21c6d740
      r11 = (int)((h->scalerParams.inputWindowHeight - h->scalerParams.outputWindowHeight) << 16) /
            (int)h->scalerParams.outputWindowHeight / 2;
      break;

   case 1:
      //21c6d804
      r11 = 0xffff8000;
      break;

   case 2:
      //21c6d818
      r11 = (((int)h->scalerParams.inputWindowHeight << 16) / (int)h->scalerParams.outputWindowHeight) / 2;
      break;

   default:
      break;
   }
   //21c6d5f8
   r0 = 0x10000;
   r5 = 0x10000;

   if (h->scalerParams.inputWindowHeight == h->scalerParams.outputWindowHeight)
   {
      //21c6d76c
      r9 = r0; //0x10000;
      r10 = r5; //0x10000;
   }

   if (h->scalerParams.inputWindowHeight > h->scalerParams.outputWindowHeight)
   {
      r6 = 0x10;

      //unsigned r5_ = (h->scalerParams.outputWindowHeight * 256 / h->scalerParams.inputWindowHeight) & 0x0f;
      //unsigned r0_ = (h->scalerParams.outputWindowHeight * 240 / h->scalerParams.inputWindowHeight) & 0x0f;

      if (/*r5_*/((h->scalerParams.outputWindowHeight * 256 / h->scalerParams.inputWindowHeight) & 0x0f) <=
         /*r0_*/((h->scalerParams.outputWindowHeight * 240 / h->scalerParams.inputWindowHeight) & 0x0f))
      {
         r5 = 0x10000;
      }
      else
      {
         r5 = 0xf000;
      }

      r0 = (h->scalerParams.outputWindowHeight * r5) / h->scalerParams.inputWindowHeight;
      r9 = r0;
      r10 = r5;
   }

   if (h->scalerParams.inputWindowHeight < h->scalerParams.outputWindowHeight)
   {
      r6 = 0x30;

      //unsigned r5_ = (h->scalerParams.inputWindowHeight * 256 / h->scalerParams.outputWindowHeight) & 0x0f;
      //unsigned r0_ = (h->scalerParams.inputWindowHeight * 240 / h->scalerParams.outputWindowHeight) & 0x0f;

      if (/*r5_*/((h->scalerParams.inputWindowHeight * 256 / h->scalerParams.outputWindowHeight) & 0x0f) <=
         /*r0_*/((h->scalerParams.inputWindowHeight * 240 / h->scalerParams.outputWindowHeight) & 0x0f))
      {
         r5 = 0x10000;
      }
      else
      {
         r5 = 0xf000;
      }

      r0 = (h->scalerParams.inputWindowHeight * r5) / h->scalerParams.outputWindowHeight;
      r9 = r5;
      r10 = r0;
   }

   if (r0 == 0x10000)
   {
      r0 = 0x8000;
      r5 = 0x8000;
      r9 = 0x8000;
      r10 = 0x8000;
   }

   switch (layer)
   {
   case 0:
      //21c6d6d0
      h->isrDataPtr->iFilter.verN = r0;
      h->isrDataPtr->iFilter.verD = r5;

      if (h->scalerParams.inputWindowHeight <=
            h->scalerParams.outputWindowHeight)
      {
         if (((r0 & 0x3000) == 0) &&
               ((r5 & 0x3000) == 0))
         {
            r6 = (r6 & 0xf) + 0x230;
            sp0x10 = 1;
         }
      }

      func_2196c62c(h, layer, r9, r10, r11, h->scalerParams.diMode, sp0x10);
      break;

   case 1:
      //21c6d788
      h->isrDataPtr->iFilter.verN = r0;
      h->isrDataPtr->iFilter.verD = r5;

      func_2196c62c(h, layer, r9, r10, r11, h->scalerParams.diMode, 0);
      break;

   case 2:
      //21c6d7cc
      h->isrDataPtr->iFilter.verN = r0;
      h->isrDataPtr->iFilter.verD = r5;

      func_2196c62c(h, layer, r9, r10, r11, h->scalerParams.diMode, 0);
      break;

   default:
      //21c6d788
      h->isrDataPtr->iFilter.verN = r0;
      h->isrDataPtr->iFilter.verD = r5;

      func_2196c62c(h, layer, r9, r10, r11, h->scalerParams.diMode, 0);
      break;
   }

   h->isrDataPtr->iFilter.verFilterOn = (r6 & 0x10) >> 4;
   h->isrDataPtr->iFilter.verFilterUp = (r6 & 0x20) >> 5;
   h->isrDataPtr->iFilter.verAddPhase = (r6 & 0x200) >> 9;
}


/* 21c5a0ac - complete */
void func_21c5a0ac(FAPI_VISCALE_VideoScalerHandleT* a)
{
//   FAPI_SYS_PRINT_MSG("func_21c5a0ac\n");
   
   if (a->scalerParams.outputWindowX0 < 5)
   {
      a->scalerParams.outputWindowX0 = 5;
   }
   
   a->isrDataPtr->iFilter.hStartPos = 
      a->scalerParams.inputWindowX0 / 128;
   a->isrDataPtr->iFilter.initalShift = 
      a->scalerParams.inputWindowX0 + 4 - 
      (a->isrDataPtr->iFilter.hStartPos) * 128;
   a->isrDataPtr->iFilter.horDispPixel = 
      a->scalerParams.outputWindowWidth;
   a->isrDataPtr->iFilter.horReadPixel =
      (a->scalerParams.inputWindowX0 % 128) +
      a->scalerParams.inputWindowWidth;
   a->isrDataPtr->iFilter.hSize = 
      ((a->scalerParams.inputWindowWidth + 127) + 
      (a->scalerParams.inputWindowX0 % 128)) / 128 - 1;      
   if (a->isrDataPtr->iFilter.hSize == 0)
   {
      a->isrDataPtr->iFilter.hSize++;
   }
   
   a->isrDataPtr->iFilter.horStart = 
      a->scalerParams.outputWindowX0;
   a->isrDataPtr->iFilter.horStop = 
      a->scalerParams.outputWindowX0 + 
      a->isrDataPtr->iFilter.horDispPixel;
   
   HSCALE(a, 0, 1);
   
   if (a->scalerParams.outputWindowY0 < 5)
   {
      a->scalerParams.outputWindowY0 = 5;
   }
   
   a->isrDataPtr->iFilter.fieldInversion = 
      a->scalerParams.fieldInversion;
   a->isrDataPtr->iFilter.vStartPos = 
      a->scalerParams.inputWindowY0;
   a->isrDataPtr->iFilter.verStart =
      a->scalerParams.outputWindowY0;
   
   if (a->scalerParams.inputWindowHeight != 
      a->scalerParams.outputWindowHeight)
   {
      a->isrDataPtr->iFilter.verStop = 
         a->scalerParams.outputWindowY0 +
         a->scalerParams.outputWindowHeight - 4;
   }
   else
   {
      a->isrDataPtr->iFilter.verStop = 
         a->scalerParams.outputWindowY0 +
         a->scalerParams.inputWindowHeight - 1;
   }
   
   VSCALE(a, 0);
   
   FREG_VO_SetVohsize_Hsize(a->isrDataPtr->iFilter.hSize);
   FREG_VO_SetVoinitialshift_Initialshiftlum(a->isrDataPtr->iFilter.initalShift);
   FREG_VO_SetVohordisppixel_Hordisppixel(a->isrDataPtr->iFilter.horDispPixel);
   FREG_VO_SetVohorreadpixel_Horreadpixel(a->isrDataPtr->iFilter.horReadPixel);
   FREG_VO_SetVohstartpos_Hstartpos(a->isrDataPtr->iFilter.hStartPos);
   FREG_VO_SetVohordenum_Hordenum(a->isrDataPtr->iFilter.horD);
   FREG_VO_SetVohornum_Hornum(a->isrDataPtr->iFilter.horN);
   FREG_VO_SetVofiltermode_Horfilteron(0, a->isrDataPtr->iFilter.horFilterOn);
   FREG_VO_SetVofiltermode_Horfilterup(0, a->isrDataPtr->iFilter.horFilterUp);
   FREG_VO_SetVofiltermode_Horaddphase(0, a->isrDataPtr->iFilter.horAddPhase);
   FREG_VO_SetDispvohorstartstop_Vohorstart(a->isrDataPtr->iFilter.horStart);
   FREG_VO_SetDispvohorstartstop_Vohorstop(a->isrDataPtr->iFilter.horStop);
   FREG_VO_SetVovstartpos_Vstartpos(a->isrDataPtr->iFilter.vStartPos);
   FREG_VO_SetVoverdenum_Verdenum(a->isrDataPtr->iFilter.verD);
   FREG_VO_SetVovernum_Vernum(a->isrDataPtr->iFilter.verN);
   FREG_VO_SetVofiltermode_Verfilteron(0, a->isrDataPtr->iFilter.verFilterOn);
   FREG_VO_SetVofiltermode_Verfilterup(0, a->isrDataPtr->iFilter.verFilterUp);
   FREG_VO_SetVofiltermode_Veraddphase(0, a->isrDataPtr->iFilter.verAddPhase);
   FREG_VO_SetDispvoverstartstop_Voverstart(a->isrDataPtr->iFilter.verStart);
   FREG_VO_SetDispvoverstartstop_Voverstop(a->isrDataPtr->iFilter.verStop);
   
   a->isrDataPtr->iFilterState = FAPI_VISCALE_REQUEST_TO_UPDATE_FILTERS;
}


/* 21c60a58 - todo */
int32_t fapi_viscale_sdstop(FAPI_SYS_HandleT handle)
{
   FAPI_SYS_PRINT_MSG("fapi_viscale_sdstop\n");
   return 0;
}


FAPI_VISCALE_ActiveRegionDataT Data_21efd02c[23] = //21efd02c
{
      {0x00000000, 0x00000000, 0x00000000, 
         0x00000000, 0x00000000, 0x00000000, 0x00000000,},
      {0x000000c0, 0x00000029, 0x00000780, 0x00000438, 
            0x00000019, 0x000002df, 0x00000078, },
      {0x000000c0, 
            0x00000029, 0x00000780, 0x00000438, 0x00000019, 
            0x000002df, 0x00000078, },
      {0x000000c0, 0x00000029, 
            0x00000780, 0x00000438, 0x00000019, 0x000002d7, 
            0x00000078, },
      {0x000000c0, 0x00000029, 0x00000780, 
            0x00000438, 0x00000019, 0x000002df, 0x00000078,},
      {0x000000c0, 0x00000029, 0x00000780, 0x00000438, 
            0x00000019, 0x000002df, 0x00000078, },
      {0x000000c0, 
            0x00000014, 0x00000780, 0x0000021c, 0x00000019, 
            0x000002d7, 0x00000080, },
      {0x000000c0, 0x00000014, 
            0x00000780, 0x0000021c, 0x00000019, 0x000002df, 
            0x00000078, },
      {0x000000c0, 0x00000014, 0x00000780, 
            0x0000021c, 0x00000019, 0x000002df, 0x00000078,},
      {0x00000104, 0x00000019, 0x00000500, 0x000002d0, 
            0x00000018, 0x000002de, 0x000000d8, },
      {0x00000104, 
            0x00000019, 0x00000500, 0x000002d0, 0x00000018, 
            0x000002de, 0x000000d8,},
      { 0x00000104, 0x00000019, 
            0x00000500, 0x000002d0, 0x00000018, 0x000002d6, 
            0x000000ee, },
      {0x00000104, 0x00000019, 0x00000500, 
            0x000002d0, 0x00000018, 0x000002de, 0x000000d8,},
      {0x00000104, 0x00000019, 0x00000500, 0x000002d0, 
            0x00000018, 0x000002de, 0x000000d8, },
      {0x00000104, 
            0x00000019, 0x00000500, 0x000002d0, 0x00000018, 
            0x000002d6, 0x000000dc, },
      {0x00000104, 0x00000019, 
            0x00000500, 0x000002d0, 0x00000018, 0x000002de, 
            0x000000d8, },
      {0x00000104, 0x00000019, 0x00000500, 
            0x000002d0, 0x00000018, 0x000002de, 0x000000d8,},
      {0x00000108, 0x00000016, 0x000005a0, 0x00000120, 
            0x00000019, 0x000002d7, 0x000000d0, },
      {0x00000084, 
            0x0000002c, 0x000002be, 0x00000240, 0x00000019, 
            0x000002d7, 0x0000006c, },
      {0x000000ee, 0x00000015, 
            0x000005a0, 0x000000f0, 0x00000019, 0x000002df, 
            0x000000b4, },
      {0x0000007a, 0x00000024, 0x000002c6, 
            0x000001e0, 0x00000019, 0x000002df, 0x00000064, },
      {0x00000000, 0x00000000, 0x00000000, 0x00000000, 
            0x00000000, 0x00000000, 0x00000000,},
      { 0x00000000, 
            0x00000000, 0x00000000, 0x00000000, 0x00000000, 
            0x00000000, 0x00000000, },
};
FAPI_VISCALE_ActiveRegionDataT Data_21efd2b0[23] = //21efd2b0
{
      {0x00000000, 0x00000000, 
         0x00000000, 0x00000000, 0x00000000, 0x00000000, 
         0x00000000, },
      {0x000001b0, 0x00000029, 0x000005a0, 
            0x00000438, 0x00000019, 0x000002df, 0x00000097, },
      {0x000001b0, 0x00000029, 0x000005a0, 0x00000438, 
            0x00000019, 0x000002df, 0x00000097, },
      {0x000001b0, 
            0x00000029, 0x000005a0, 0x00000438, 0x00000019, 
            0x000002d7, 0x00000198, },
      {0x000001b0, 0x00000029, 
            0x000005a0, 0x00000438, 0x00000019, 0x000002df, 
            0x00000097, },
      {0x000001b0, 0x00000029, 0x000005a0, 
            0x00000438, 0x00000019, 0x000002df, 0x00000097,},
      {0x000001b0, 0x00000014, 0x0000057c, 0x0000021c, 
            0x00000019, 0x000002d7, 0x00000190, },
      {0x000001b0, 
            0x00000014, 0x000005a0, 0x0000021c, 0x00000018, 
            0x000002de, 0x00000180, },
      {0x000001b0, 0x00000014, 
            0x000005a0, 0x0000021c, 0x00000019, 0x000002df, 
            0x00000097, },
      {0x000001a4, 0x00000019, 0x000003c0, 
            0x000002d0, 0x00000019, 0x000002df, 0x00000180, },
      {0x000001a4, 0x00000019, 0x000003c0, 0x000002d0, 
            0x00000019, 0x000002df, 0x00000180, },
      {0x000001a4, 
            0x00000019, 0x000003c0, 0x000002d0, 0x00000018, 
            0x000002d6, 0x00000194, },
      {0x000001a4, 0x00000019, 
            0x000003c0, 0x000002d0, 0x00000019, 0x000002df, 
            0x00000180, },
      {0x000001a4, 0x00000019, 0x000003c0, 
            0x000002d0, 0x00000019, 0x000002df, 0x00000180,},
      {0x000001a4, 0x00000019, 0x000003c0, 0x000002d0, 
            0x00000018, 0x000002d6, 0x00000188, },
      {0x000001a4, 
            0x00000019, 0x000003c0, 0x000002d0, 0x00000019, 
            0x000002df, 0x00000180, },
      {0x000001a4, 0x00000019, 
            0x000003c0, 0x000002d0, 0x00000019, 0x000002df, 
            0x00000180, },
      {0x00000108, 0x00000016, 0x000005a0, 
            0x00000120, 0x00000019, 0x000002d7, 0x000000d0, },
      {0x00000084, 0x0000002c, 0x000002be, 0x00000240, 
            0x00000019, 0x000002d7, 0x0000006c, },
      {0x000000ee, 
            0x00000015, 0x000005a0, 0x000000f0, 0x00000019, 
            0x000002df, 0x000000b4, },
      {0x0000007a, 0x00000024, 
            0x000002c6, 0x000001e0, 0x00000019, 0x000002df, 
            0x00000064, },
      {0x00000000, 0x00000000, 0x00000000, 
            0x00000000, 0x00000000, 0x00000000, 0x00000000,},
      {0x00000000, 0x00000000, 0x00000000, 0x00000000, 
            0x00000000, 0x00000000, 0x00000000, },
};
FAPI_VISCALE_ActiveRegionDataT Data_21efd534[23] = //21efd534
{
      {0x00000000, 
         0x00000000, 0x00000000, 0x00000000, 0x00000000, 
         0x00000000, 0x00000000, },
      {0x000000c0, 0x00000029, 
            0x00000780, 0x00000438, 0x00000019, 0x000002df, 
            0x00000078, },
      {0x000000c0, 0x00000029, 0x00000780, 
            0x00000438, 0x00000019, 0x000002df, 0x00000078,},
      {0x000000c0, 0x00000029, 0x00000780, 0x00000438, 
            0x00000019, 0x000002d7, 0x00000078, },
      {0x000000c0, 
            0x00000029, 0x00000780, 0x00000438, 0x00000019, 
            0x000002df, 0x00000078, },
      {0x000000c0, 0x00000029, 
            0x00000780, 0x00000438, 0x00000019, 0x000002df, 
            0x00000078, },
      {0x000000c0, 0x00000014, 0x00000780, 
            0x0000021c, 0x00000019, 0x000002d7, 0x00000080,},
      {0x000000c0, 0x00000014, 0x00000780, 0x0000021c, 
            0x00000019, 0x000002df, 0x00000078, },
      {0x000000c0, 
            0x00000014, 0x00000780, 0x0000021c, 0x00000019, 
            0x000002df, 0x00000078, },
      {0x00000104, 0x00000019, 
            0x00000500, 0x000002d0, 0x00000018, 0x000002de, 
            0x000000d8, },
      {0x00000104, 0x00000019, 0x00000500, 
            0x000002d0, 0x00000018, 0x000002de, 0x000000d8,},
      {0x00000104, 0x00000019, 0x00000500, 0x000002d0, 
            0x00000018, 0x000002d6, 0x000000ee, },
      {0x00000104, 
            0x00000019, 0x00000500, 0x000002d0, 0x00000018, 
            0x000002de, 0x000000d8, },
      {0x00000104, 0x00000019, 
            0x00000500, 0x000002d0, 0x00000018, 0x000002de, 
            0x000000d8, },
      {0x00000104, 0x00000019, 0x00000500, 
            0x000002d0, 0x00000018, 0x000002d6, 0x000000dc,},
      {0x00000104, 0x00000019, 0x00000500, 0x000002d0, 
            0x00000018, 0x000002de, 0x000000d8, },
      {0x00000104, 
            0x00000019, 0x00000500, 0x000002d0, 0x00000018, 
            0x000002de, 0x000000d8, },
      {0x00000108, 0x00000016, 
            0x000005a0, 0x00000120, 0x00000019, 0x000002d7, 
            0x000000d0, },
      {0x00000084, 0x0000002c, 0x000002be, 
            0x00000240, 0x00000019, 0x000002d7, 0x0000006c,},
      {0x000000ee, 0x00000015, 0x000005a0, 0x000000f0, 
            0x00000019, 0x000002df, 0x000000b4, },
      {0x0000007a, 
            0x00000024, 0x000002c6, 0x000001e0, 0x00000019, 
            0x000002df, 0x00000064, },
      {0x00000000, 0x00000000, 
            0x00000000, 0x00000000, 0x00000000, 0x00000000, 
            0x00000000, },
      {0x00000000, 0x00000000, 0x00000000, 
            0x00000000, 0x00000000, 0x00000000, 0x00000000,}, 
};
FAPI_VISCALE_ActiveRegionDataT Data_21efd7b8[23] = //21efd7b8
{
      {0x00000000, 0x00000000, 0x00000000, 0x00000000, 
         0x00000000, 0x00000000, 0x00000000, },
      {0x000000c0, 
            0x00000029, 0x00000780, 0x00000438, 0x00000019, 
            0x000002df, 0x00000078, },
      {0x000000c0, 0x00000029, 
            0x00000780, 0x00000438, 0x00000019, 0x000002df, 
            0x00000078, },
      {0x000000c0, 0x00000029, 0x00000780, 
            0x00000438, 0x00000019, 0x000002d7, 0x00000078,},
      {0x000000c0, 0x00000029, 0x00000780, 0x00000438, 
            0x00000019, 0x000002df, 0x00000078, },
      {0x000000c0, 
            0x00000029, 0x00000780, 0x00000438, 0x00000019, 
            0x000002df, 0x00000078, },
      {0x000000c0, 0x00000014, 
            0x00000780, 0x0000021c, 0x00000019, 0x000002d7, 
            0x00000080, },
      {0x000000c0, 0x00000014, 0x00000780, 
            0x0000021c, 0x00000019, 0x000002df, 0x00000078,},
      {0x000000c0, 0x00000014, 0x00000780, 0x0000021c, 
            0x00000019, 0x000002df, 0x00000078, },
      {0x00000104, 
            0x00000019, 0x00000500, 0x000002d0, 0x00000018, 
            0x000002de, 0x000000d8, },
      {0x00000104, 0x00000019, 
            0x00000500, 0x000002d0, 0x00000018, 0x000002de, 
            0x000000d8, },
      {0x00000104, 0x00000019, 0x00000500, 
            0x000002d0, 0x00000018, 0x000002d6, 0x000000ee,},
      {0x00000104, 0x00000019, 0x00000500, 0x000002d0, 
            0x00000018, 0x000002de, 0x000000d8, },
      {0x00000104, 
            0x00000019, 0x00000500, 0x000002d0, 0x00000018, 
            0x000002de, 0x000000d8, },
      {0x00000104, 0x00000019, 
            0x00000500, 0x000002d0, 0x00000018, 0x000002d6, 
            0x000000dc, },
      {0x00000104, 0x00000019, 0x00000500, 
            0x000002d0, 0x00000018, 0x000002de, 0x000000d8,},
      {0x00000104, 0x00000019, 0x00000500, 0x000002d0, 
            0x00000018, 0x000002de, 0x000000d8, },
      {0x00000108, 
            0x00000016, 0x000005a0, 0x00000120, 0x00000019, 
            0x000002d7, 0x000000d0, },
      {0x00000084, 0x0000002c, 
            0x000002be, 0x00000240, 0x00000019, 0x000002d7, 
            0x0000006c, },
      {0x000000ee, 0x00000015, 0x000005a0, 
            0x000000f0, 0x00000019, 0x000002df, 0x000000b4,},
      {0x0000007a, 0x00000024, 0x000002c6, 0x000001e0, 
            0x00000019, 0x000002df, 0x00000064, },
      {0x00000000, 
            0x00000000, 0x00000000, 0x00000000, 0x00000000, 
            0x00000000, 0x00000000, },
      {0x00000000, 0x00000000, 
            0x00000000, 0x00000000, 0x00000000, 0x00000000, 
            0x00000000,}, 
};
FAPI_VISCALE_ActiveRegionDataT Data_21efda3c[23] = //21efda3c
{
      {0x00000000, 0x00000000, 0x00000000, 
         0x00000000, 0x00000000, 0x00000000, 0x00000000,},
      {0x000000c0, 0x00000029, 0x00000780, 0x00000438, 
            0x00000019, 0x000002df, 0x00000078, },
      {0x000000c0, 
            0x00000029, 0x00000780, 0x00000438, 0x00000019, 
            0x000002df, 0x00000078, },
      {0x000000c0, 0x00000029, 
            0x00000780, 0x00000438, 0x00000019, 0x000002d7, 
            0x00000078, },
      {0x000000c0, 0x00000029, 0x00000780, 
            0x00000438, 0x00000019, 0x000002df, 0x00000078,},
      {0x000000c0, 0x00000029, 0x00000780, 0x00000438, 
            0x00000019, 0x000002df, 0x00000078, },
      {0x000000c0, 
            0x00000014, 0x00000780, 0x0000021c, 0x00000019, 
            0x000002d7, 0x00000080, },
      {0x000000c0, 0x00000014, 
            0x00000780, 0x0000021c, 0x00000019, 0x000002df, 
            0x00000078, },
      {0x000000c0, 0x00000014, 0x00000780, 
            0x0000021c, 0x00000019, 0x000002df, 0x00000078,},
      {0x00000104, 0x00000019, 0x00000500, 0x000002d0, 
            0x00000018, 0x000002de, 0x000000d8, },
      {0x00000104, 
            0x00000019, 0x00000500, 0x000002d0, 0x00000018, 
            0x000002de, 0x000000d8, },
      {0x00000104, 0x00000019, 
            0x00000500, 0x000002d0, 0x00000018, 0x000002d6, 
            0x000000ee, },
      {0x00000104, 0x00000019, 0x00000500, 
            0x000002d0, 0x00000018, 0x000002de, 0x000000d8,},
      {0x00000104, 0x00000019, 0x00000500, 0x000002d0, 
            0x00000018, 0x000002de, 0x000000d8, },
      {0x00000104, 
            0x00000019, 0x00000500, 0x000002d0, 0x00000018, 
            0x000002d6, 0x000000dc, },
      {0x00000104, 0x00000019, 
            0x00000500, 0x000002d0, 0x00000018, 0x000002de, 
            0x000000d8, },
      {0x00000104, 0x00000019, 0x00000500, 
            0x000002d0, 0x00000018, 0x000002de, 0x000000d8,},
      {0x00000108, 0x00000016, 0x000005a0, 0x00000120, 
            0x00000019, 0x000002d7, 0x000000d0, },
      {0x00000084, 
            0x0000002c, 0x000002be, 0x00000240, 0x00000019, 
            0x000002d7, 0x0000006c, },
      {0x000000ee, 0x00000015, 
            0x000005a0, 0x000000f0, 0x00000019, 0x000002df, 
            0x000000b4, },
      {0x0000007a, 0x00000024, 0x000002c6, 
            0x000001e0, 0x00000019, 0x000002df, 0x00000064,},
      {0x00000000, 0x00000000, 0x00000000, 0x00000000, 
            0x00000000, 0x00000000, 0x00000000, },
      {0x00000000, 
            0x00000000, 0x00000000, 0x00000000, 0x00000000, 
            0x00000000, 0x00000000,}, 
};
FAPI_VISCALE_ActiveRegionDataT Data_21efdcc0[23] = //21efdcc0
{
   {0x00000000, 0x00000000, 
      0x00000000, 0x00000000, 0x00000000, 0x00000000, 
      0x00000000, },
   {0x000000c0, 0x00000029, 0x00000780, 
         0x00000438, 0x00000019, 0x000002df, 0x00000078,},
   {0x000000c0, 0x00000029, 0x00000780, 0x00000438, 
         0x00000019, 0x000002df, 0x00000078, },
   {0x000000c0, 
         0x00000029, 0x00000780, 0x00000438, 0x00000019, 
         0x000002d7, 0x00000078, },
   {0x000000c0, 0x00000029, 
         0x00000780, 0x00000438, 0x00000019, 0x000002df, 
         0x00000078, },
   {0x000000c0, 0x00000029, 0x00000780, 
         0x00000438, 0x00000019, 0x000002df, 0x00000078,},
   {0x000000c0, 0x00000014, 0x00000780, 0x0000021c, 
         0x00000019, 0x000002d7, 0x00000080, },
   {0x000000c0, 
         0x00000014, 0x00000780, 0x0000021c, 0x00000019, 
         0x000002df, 0x00000078, },
   {0x000000c0, 0x00000014, 
         0x00000780, 0x0000021c, 0x00000019, 0x000002df, 
         0x00000078, },
   {0x00000104, 0x00000019, 0x00000500, 
         0x000002d0, 0x00000018, 0x000002de, 0x000000d8,},
   {0x00000104, 0x00000019, 0x00000500, 0x000002d0, 
         0x00000018, 0x000002de, 0x000000d8, },
   {0x00000104, 
         0x00000019, 0x00000500, 0x000002d0, 0x00000018, 
         0x000002d6, 0x000000ee, },
   {0x00000104, 0x00000019, 
         0x00000500, 0x000002d0, 0x00000018, 0x000002de, 
         0x000000d8, },
   {0x00000104, 0x00000019, 0x00000500, 
         0x000002d0, 0x00000018, 0x000002de, 0x000000d8,},
   {0x00000104, 0x00000019, 0x00000500, 0x000002d0, 
         0x00000018, 0x000002d6, 0x000000dc, },
   {0x00000104, 
         0x00000019, 0x00000500, 0x000002d0, 0x00000018, 
         0x000002de, 0x000000d8, },
   {0x00000104, 0x00000019, 
         0x00000500, 0x000002d0, 0x00000018, 0x000002de, 
         0x000000d8, },
   {0x00000108, 0x00000016, 0x000005a0, 
         0x00000120, 0x00000019, 0x000002d7, 0x000000d0,},
   {0x00000084, 0x0000002c, 0x000002be, 0x00000240, 
         0x00000019, 0x000002d7, 0x0000006c, },
   {0x000000ee, 
         0x00000015, 0x000005a0, 0x000000f0, 0x00000019, 
         0x000002df, 0x000000b4, },
   {0x0000007a, 0x00000024, 
         0x000002c6, 0x000001e0, 0x00000019, 0x000002df, 
         0x00000064, },
   {0x00000000, 0x00000000, 0x00000000, 
         0x00000000, 0x00000000, 0x00000000, 0x00000000,},
   {0x00000000, 0x00000000, 0x00000000, 0x00000000, 
         0x00000000, 0x00000000, 0x00000000,}, 
};
FAPI_VISCALE_ActiveRegionDataT Data_21efdf44[23] = //21efdf44
{
      {0x00000000, 
         0x00000000, 0x00000000, 0x00000000, 0x00000000, 
         0x00000000, 0x00000000, },
      {0x00000078, 0x00000013, 
            0x000002c6, 0x000000f0, 0x00000000, 0x00000000, 
            0x00000000, },
      {0x00000078, 0x00000013, 0x000002c6, 
            0x000000f0, 0x00000000, 0x00000000, 0x00000000,},
      {0x00000088, 0x00000017, 0x000002be, 0x00000120, 
            0x00000000, 0x00000000, 0x00000000, },
      {0x00000078, 
            0x00000013, 0x000002c6, 0x000000f0, 0x00000000, 
            0x00000000, 0x00000000, },
      {0x00000078, 0x00000013, 
            0x000002c6, 0x000000f0, 0x00000000, 0x00000000, 
            0x00000000, },
      {0x00000088, 0x00000017, 0x000002be, 
            0x00000120, 0x00000000, 0x00000000, 0x00000000,},
      {0x00000078, 0x00000013, 0x000002c6, 0x000000f0, 
            0x00000000, 0x00000000, 0x00000000, },
      {0x00000078, 
            0x00000013, 0x000002c6, 0x000000f0, 0x00000000, 
            0x00000000, 0x00000000, },
      {0x00000078, 0x00000013, 
            0x000002c6, 0x000000f0, 0x00000000, 0x00000000, 
            0x00000000, },
      {0x00000078, 0x00000013, 0x000002c6, 
            0x000000f0, 0x00000000, 0x00000000, 0x00000000,},
      {0x00000088, 0x00000017, 0x000002be, 0x00000120, 
            0x00000000, 0x00000000, 0x00000000, },
      {0x00000078, 
            0x00000013, 0x000002c6, 0x000000f0, 0x00000000, 
            0x00000000, 0x00000000, },
      {0x00000078, 0x00000013, 
            0x000002c6, 0x000000f0, 0x00000000, 0x00000000, 
            0x00000000, },
      {0x00000088, 0x00000017, 0x000002be, 
            0x00000120, 0x00000000, 0x00000000, 0x00000000,},
      {0x00000078, 0x00000013, 0x000002c6, 0x000000f0, 
            0x00000000, 0x00000000, 0x00000000, },
      {0x00000078, 
            0x00000013, 0x000002c6, 0x000000f0, 0x00000000, 
            0x00000000, 0x00000000, },
      {0x00000088, 0x00000017, 
            0x000002be, 0x00000120, 0x00000000, 0x00000000, 
            0x00000000, },
      {0x00000088, 0x00000017, 0x000002be, 
            0x00000120, 0x00000000, 0x00000000, 0x00000000,},
      {0x00000078, 0x00000013, 0x000002c6, 0x000000f0, 
            0x00000000, 0x00000000, 0x00000000, },
      {0x00000078, 
            0x00000013, 0x000002c6, 0x000000f0, 0x00000000, 
            0x00000000, 0x00000000, },
      {0x00000000, 0x00000000, 
            0x00000000, 0x00000000, 0x00000000, 0x00000000, 
            0x00000000, },
      {0x00000000, 0x00000000, 0x00000000, 
            0x00000000, 0x00000000, 0x00000000, 0x00000000,},  
};


/* 21939ed0 - todo */
int32_t func_21c604e8(FAPI_VISCALE_VideoScalerHandleT* r4)
{
   int32_t res = 0;
   uint32_t sdHorWriteStop = 0;
   uint32_t sdHorWriteStart = 0;
   uint32_t sdDispcvbshorstartstop = 0;
   uint32_t inputWindowHeight = 0;
   uint32_t inputWindowWidth = 0;
   uint32_t inputWindowY0 = 0;
   uint32_t inputWindowX0 = 0;
   uint32_t outputWindowHeight = 0;
   uint32_t outputWindowWidth = 0;
   uint32_t outputWindowY0 = 0;
   uint32_t outputWindowX0 = 0;
   FAPI_VISCALE_ActiveRegionDataT* r3 = 0;

   FAPI_SYS_PRINT_DEBUG(4, "func_21c604e8: sdMode=%d, hdMode=%d\n",
         r4->sdMode, r4->hdMode);
   
   if (r4->sdMode == FAPI_VISCALE_UNKNOWN_SD_SCALER_MODE)
   {
      return FAPI_VISCALE_ERR_INVALID_INITIALIZATION_PARAMS;
   }

   if (r4->sdMode == FAPI_VISCALE_UNSUPPORTED_SD_SCALER_MODE)
   {
      r4->sdMode = FAPI_VISCALE_UNSUPPORTED_SD_SCALER_MODE;

      return FAPI_VISCALE_ERR_UNSUPPORTED_FUNCTIONALITY;
   }

   if (r4->hdMode != FAPI_VISCALE_UNKNOWN_HD_SCALER_MODE)
   {
      //21c60754
      if (r4->displayAspectRatioL1 == FAPI_VISCALE_AR_NONE)
      {
         r3 = &Data_21efd02c[r4->hdMode];
      }
      else if (r4->displayAspectRatioL1 == FAPI_VISCALE_AR_4_3)
      {
         r3 = &Data_21efd2b0[r4->hdMode];
      }
      else if (r4->displayAspectRatioL1 == FAPI_VISCALE_AR_14_9)
      {
         r3 = &Data_21efd534[r4->hdMode];
      }
      else if (r4->displayAspectRatioL1 == FAPI_VISCALE_AR_16_9)
      {
         r3 = &Data_21efd7b8[r4->hdMode];
      }
      else if (r4->displayAspectRatioL1 == FAPI_VISCALE_AR_221_100)
      {
         r3 = &Data_21efda3c[r4->hdMode];
      }
      else if (r4->displayAspectRatioL1 == FAPI_VISCALE_AR_235_100)
      {
         r3 = &Data_21efdcc0[r4->hdMode];
      }
   }

   if (r3 != 0)
   {
      //21c607f0
      inputWindowX0 = r3->startX0;
      inputWindowY0 = r3->startY0;
      inputWindowWidth = r3->horSize;
      inputWindowHeight = r3->verSize;
      sdHorWriteStart = r3->sdHorWriteStart;
      sdHorWriteStop = r3->sdHorWriteStop;
      sdDispcvbshorstartstop = r3->sdDispcvbshorstartstop;
   }
   //21c60538
   r4->scalerParams.inputWindowX0 = inputWindowX0; //1160
   r4->scalerParams.inputWindowY0 = inputWindowY0; //1164
   r4->scalerParams.inputWindowWidth = inputWindowWidth; //1168
   r4->scalerParams.inputWindowHeight = inputWindowHeight; //1172

   FAPI_SYS_PRINT_DEBUG(4, "func_21c604e8: inputWindowX0=%d\n",
         r4->scalerParams.inputWindowX0);
   FAPI_SYS_PRINT_DEBUG(4, "func_21c604e8: inputWindowY0=%d\n",
         r4->scalerParams.inputWindowY0);
   FAPI_SYS_PRINT_DEBUG(4, "func_21c604e8: inputWindowWidth=%d\n",
         r4->scalerParams.inputWindowWidth);
   FAPI_SYS_PRINT_DEBUG(4, "func_21c604e8: inputWindowHeight=%d\n",
         r4->scalerParams.inputWindowHeight);

   r4->isrDataPtr->iFilter.sdScalerReq.sdHorWriteStart = sdHorWriteStart; //156
   r4->isrDataPtr->iFilter.sdScalerReq.sdHorWriteStop = sdHorWriteStop; //160
   r4->isrDataPtr->iFilter.sdScalerReq.sdDispcvbshorstartstop = sdDispcvbshorstartstop; //164

   FAPI_SYS_PRINT_DEBUG(4, "func_21c604e8: sdHorWriteStart=%d\n",
         r4->isrDataPtr->iFilter.sdScalerReq.sdHorWriteStart);
   FAPI_SYS_PRINT_DEBUG(4, "func_21c604e8: sdHorWriteStop=%d\n",
         r4->isrDataPtr->iFilter.sdScalerReq.sdHorWriteStop);
   FAPI_SYS_PRINT_DEBUG(4, "func_21c604e8: sdDispcvbshorstartstop=%d\n",
         r4->isrDataPtr->iFilter.sdScalerReq.sdDispcvbshorstartstop);

   r4->isrDataPtr->iFilter.hSize = 0; //40 = sl
   r4->isrDataPtr->iFilter.initalShift = 4; //44 = r3
   r4->isrDataPtr->iFilter.horReadPixel = sdHorWriteStart; //52
   r4->isrDataPtr->iFilter.horDispPixel = sdHorWriteStop; //48

   if (r4->sdMode != FAPI_VISCALE_UNKNOWN_SD_SCALER_MODE)
   {
      //21c60804
      r3 = &Data_21efdf44[r4->sdMode];

      outputWindowX0 = r3->startX0;
      outputWindowY0 = r3->startY0;
      outputWindowWidth = r3->horSize;
      outputWindowHeight = r3->verSize;
      //->21c6058c
   }
   else
   {
      //21c60578
      res = FAPI_VISCALE_ERR_INVALID_INITIALIZATION_PARAMS;
   }
   //21c6058c
   r4->scalerParams.outputWindowX0 = outputWindowX0; //1176
   r4->scalerParams.outputWindowY0 = outputWindowY0; //1180
   r4->scalerParams.outputWindowWidth = outputWindowWidth; //1184
   r4->scalerParams.outputWindowHeight = outputWindowHeight; //1188

   FAPI_SYS_PRINT_DEBUG(4, "func_21c604e8: outputWindowX0=%d\n",
         r4->scalerParams.outputWindowX0);
   FAPI_SYS_PRINT_DEBUG(4, "func_21c604e8: outputWindowY0=%d\n",
         r4->scalerParams.outputWindowY0);
   FAPI_SYS_PRINT_DEBUG(4, "func_21c604e8: outputWindowWidth=%d\n",
         r4->scalerParams.outputWindowWidth);
   FAPI_SYS_PRINT_DEBUG(4, "func_21c604e8: outputWindowHeight=%d\n",
         r4->scalerParams.outputWindowHeight);

   if (r4->sdMode == FAPI_VISCALE_SD_SCALER_MODE_1920x1080x2397P_TO_5994I)
   {
      r4->scalerParams.frameField = 1;
   }
   else if (r4->sdMode == FAPI_VISCALE_SD_SCALER_MODE_1920x1080x24P_TO_5994I)
   {
      //21c6065c
      r4->scalerParams.frameField = 1;
   }
   else if (r4->sdMode == FAPI_VISCALE_SD_SCALER_MODE_1920x1080x25P_TO_50I)
   {
      //21c6065c
      r4->scalerParams.frameField = 1;
   }
   else if (r4->sdMode == FAPI_VISCALE_SD_SCALER_MODE_1920x1080x2997P_TO_5994I)
   {
      //21c6065c
      r4->scalerParams.frameField = 1;
   }
   else if (r4->sdMode == FAPI_VISCALE_SD_SCALER_MODE_1920x1080x30P_TO_5994I)
   {
      //21c6065c
      r4->scalerParams.frameField = 1;
   }
   else if (r4->sdMode == FAPI_VISCALE_SD_SCALER_MODE_1920x1080x50I_TO_50I)
   {
      //21c60650
      r4->scalerParams.frameField = 0;
   }
   else if (r4->sdMode == FAPI_VISCALE_SD_SCALER_MODE_1920x1080x5994I_TO_5994I)
   {
      //21c60650
      r4->scalerParams.frameField = 0;
   }
   else if (r4->sdMode == FAPI_VISCALE_SD_SCALER_MODE_1920x1080x60I_TO_5994I)
   {
      //21c60650
      r4->scalerParams.frameField = 0;
   }
   else if (r4->sdMode == FAPI_VISCALE_SD_SCALER_MODE_1280x720x2397P_TO_5994I)
   {
      //21c6065c
      r4->scalerParams.frameField = 1;
   }
   else if (r4->sdMode == FAPI_VISCALE_SD_SCALER_MODE_1280x720x24P_TO_5994I)
   {
      //21c6065c
      r4->scalerParams.frameField = 1;
   }
   else if (r4->sdMode == FAPI_VISCALE_SD_SCALER_MODE_1280x720x25P_TO_50I)
   {
      //21c6065c
      r4->scalerParams.frameField = 1;
   }
   else if (r4->sdMode == FAPI_VISCALE_SD_SCALER_MODE_1280x720x2997P_TO_5994I)
   {
      //21c6065c
      r4->scalerParams.frameField = 1;
   }
   else if (r4->sdMode == FAPI_VISCALE_SD_SCALER_MODE_1280x720x30P_TO_5994I)
   {
      //21c6065c
      r4->scalerParams.frameField = 1;
   }
   else if (r4->sdMode == FAPI_VISCALE_SD_SCALER_MODE_1280x720x50P_TO_50I)
   {
      //21c6065c
      r4->scalerParams.frameField = 1;
   }
   else if (r4->sdMode == FAPI_VISCALE_SD_SCALER_MODE_1280x720x5994P_TO_5994I)
   {
      //21c6065c
      r4->scalerParams.frameField = 1;
   }
   else if (r4->sdMode == FAPI_VISCALE_SD_SCALER_MODE_1280x720x60P_TO_5994I)
   {
      //21c6065c
      r4->scalerParams.frameField = 1;
   }
   else if (r4->sdMode == FAPI_VISCALE_SD_SCALER_MODE_720x576x50I_TO_50I)
   {
      //21c60650
      r4->scalerParams.frameField = 0;
   }
   else if (r4->sdMode == FAPI_VISCALE_SD_SCALER_MODE_720x576x50P_TO_50I)
   {
      //21c6065c
      r4->scalerParams.frameField = 1;
   }
   else if (r4->sdMode == FAPI_VISCALE_SD_SCALER_MODE_720x480x5994I_TO_5994I)
   {
      //21c60650
      r4->scalerParams.frameField = 0;
   }
   else if (r4->sdMode == FAPI_VISCALE_SD_SCALER_MODE_720x480x5994P_TO_5994I)
   {
      //21c6065c
      r4->scalerParams.frameField = 1;
   }
   else if (r4->sdMode == FAPI_VISCALE_SD_SCALER_MODE_LCD_640x480x50P_LQ080V3DG01_TO_50I)
   {
      //21c6065c
      r4->scalerParams.frameField = 1;
   }
   else if (r4->sdMode == FAPI_VISCALE_SD_SCALER_MODE_LCD_1024x768x50P_SVA150XG10TB_TO_50I)
   {
      //21c6065c
      r4->scalerParams.frameField = 1;
   }
   else
   {
      //21c60650
      r4->scalerParams.frameField = 0;
   }
   //21c60664
   r4->scalerParams.diMode/*1144*/ = r4->scalerParams.frameField << 1;
   r4->isrDataPtr->iFilter.horStart = r4->scalerParams.outputWindowX0;
   r4->isrDataPtr->iFilter.horStop = r4->scalerParams.outputWindowX0 +
      r4->scalerParams.outputWindowWidth;
   r4->isrDataPtr->iFilter.verStart = r4->scalerParams.outputWindowY0;
   r4->isrDataPtr->iFilter.verStop = r4->scalerParams.outputWindowY0 +
      r4->scalerParams.outputWindowHeight;
   r4->isrDataPtr->iFilter.sdScalerReq.inputHorStart = r4->scalerParams.inputWindowX0;
   r4->isrDataPtr->iFilter.sdScalerReq.inputHorStop = r4->scalerParams.inputWindowX0 +
      r4->scalerParams.inputWindowWidth;
   r4->isrDataPtr->iFilter.sdScalerReq.inputVerStart = r4->scalerParams.inputWindowY0;
   r4->isrDataPtr->iFilter.sdScalerReq.inputVerStop = r4->scalerParams.inputWindowY0 +
      r4->scalerParams.inputWindowHeight;
   r4->isrDataPtr->iFilter.sdScalerReq.outputHorStart = r4->scalerParams.outputWindowX0;
   r4->isrDataPtr->iFilter.sdScalerReq.outputHorStop = r4->scalerParams.outputWindowX0 +
      r4->scalerParams.outputWindowWidth;
   r4->isrDataPtr->iFilter.sdScalerReq.outputVerStart = r4->scalerParams.outputWindowY0;
   r4->isrDataPtr->iFilter.sdScalerReq.outputVerStop = r4->scalerParams.outputWindowY0 +
      r4->scalerParams.outputWindowHeight;
   
   HSCALE(r4, 1, 1);

   if (r4->sdMode == FAPI_VISCALE_SD_SCALER_MODE_720x576x50P_TO_50I)
   {
      //21c6082c
      r4->isrDataPtr->iFilter.horN = 0xffa6;
      r4->isrDataPtr->iFilter.horFilterOn = 1;
   }
   else if (r4->sdMode == FAPI_VISCALE_SD_SCALER_MODE_720x480x5994P_TO_5994I)
   {
      //21c60720
      r4->isrDataPtr->iFilter.horN = 0xffa7;
      r4->isrDataPtr->iFilter.horFilterOn = 1;
   }
   //21c60734
   VSCALE(r4, 1);

   r4->isrDataPtr->iFilterState = FAPI_VISCALE_REQUEST_TO_UPDATE_FILTERS;
   
   return res;
}


/* 21c60870 - todo */
void fapi_viscale_sdautoscaler(void* frameCropPtr,
                          FAPI_SYS_HandleT handle, uint32_t suspendType)
{
   FAPI_SYS_PRINT_MSG("fapi_viscale_sdautoscaler\n");
}


/* 21c60260 - complete */
int32_t fapi_viscale_setsdscalertohdencoder(FAPI_SYS_HandleT handle,
                                         FAPI_SYS_HandleT viencHdHandle)
{
//   FAPI_SYS_PRINT_MSG("fapi_viscale_setsdscalertohdencoder\n");

   int32_t res = 0;
   FAPI_VISCALE_VideoScalerHandleT* r0 = handle;
   FAPI_VIENC_VideoEncoderHandleT* r1 = viencHdHandle;
   
   if (r1 == 0)
   {
      r0->hdMode = 0;
      r0->sdMode = 0;
      
      return 0;
   }
   
   switch (r1->opParams.interlaceProgressive)
   {
   case FAPI_VIENC_IP_MODE_1920x1080x2397P:
      r0->hdMode = 1;
      r0->sdMode = 1;
      break;
      
   default:
      r0->hdMode = 0;
      r0->sdMode = 0;
      res = -30102;
      break;
      
   case FAPI_VIENC_IP_MODE_1920x1080x24P:
      r0->hdMode = 2;
      r0->sdMode = 2;
      break;
      
   case FAPI_VIENC_IP_MODE_1920x1080x25P:
      r0->hdMode = 3;
      r0->sdMode = 3;
      break;
      
   case FAPI_VIENC_IP_MODE_1920x1080x2997P:
      r0->hdMode = 4;
      r0->sdMode = 4;
      break;
      
   case FAPI_VIENC_IP_MODE_1920x1080x30P:
      r0->hdMode = 5;
      r0->sdMode = 5;
      break;
      
   case FAPI_VIENC_IP_MODE_1920x1080x50I:
      r0->hdMode = 6;
      r0->sdMode = 6;
      break;
      
   case FAPI_VIENC_IP_MODE_1920x1080x5994I:
      r0->hdMode = 7;
      r0->sdMode = 7;
      break;
      
   case FAPI_VIENC_IP_MODE_1920x1080x60I:
      r0->hdMode = 8;
      r0->sdMode = 8;
      break;
      
   case FAPI_VIENC_IP_MODE_1280x720x2397P:
      r0->hdMode = 9;
      r0->sdMode = 9;
      break;
      
   case FAPI_VIENC_IP_MODE_1280x720x24P:
      r0->hdMode = 10;
      r0->sdMode = 10;
      break;
      
   case FAPI_VIENC_IP_MODE_1280x720x25P:
      r0->hdMode = 11;
      r0->sdMode = 11;
      break;
      
   case FAPI_VIENC_IP_MODE_1280x720x2997P:
      r0->hdMode = 12;
      r0->sdMode = 12;
      break;
      
   case FAPI_VIENC_IP_MODE_1280x720x30P:
      r0->hdMode = 13;
      r0->sdMode = 13;
      break;
      
   case FAPI_VIENC_IP_MODE_1280x720x50P:
      r0->hdMode = 14;
      r0->sdMode = 14;
      break;
      
   case FAPI_VIENC_IP_MODE_1280x720x5994P:
      r0->hdMode = 15;
      r0->sdMode = 15;
      break;
      
   case FAPI_VIENC_IP_MODE_1280x720x60P:
      r0->hdMode = 16;
      r0->sdMode = 16;
      break;
      
   case FAPI_VIENC_IP_MODE_720x576x50I:
      r0->hdMode = 17;
      r0->sdMode = 17;
      break;
      
   case FAPI_VIENC_IP_MODE_720x576x50P:
      r0->hdMode = 18;
      r0->sdMode = 18;
      break;
      
   case FAPI_VIENC_IP_MODE_720x480x5994I:
      r0->hdMode = 19;
      r0->sdMode = 19;
      break;
      
   case FAPI_VIENC_IP_MODE_720x480x5994P:
      r0->hdMode = 20;
      r0->sdMode = 20;
      break;
      
   case FAPI_VIENC_IP_MODE_LCD_640x480x50P_LQ080V3DG01:
      r0->hdMode = 21;
      r0->sdMode = 21;
      break;
      
   case FAPI_VIENC_IP_MODE_LCD_1024x768x50P_SVA150XG10TB:
      r0->hdMode = 22;
      r0->sdMode = 22;
      break;
   }
   
   return res;
}


/* 21c604b4 - complete */
int32_t fapi_viscale_setsddisplayaspectratio(FAPI_SYS_HandleT handle,
                                FAPI_VISCALE_AspectRatioEnumT displayAr)
{
//   FAPI_SYS_PRINT_MSG("fapi_viscale_setsddisplayaspectratio\n");

   int res = 0;
   FAPI_VISCALE_VideoScalerHandleT* r0 = handle;

   if (r0->sdMode == 0)
   {
      res = -30102;      
   }
   else if (r0->sdMode == 0xFF)
   {
      r0->sdMode = 0xFF;
      res = -30107;
   }
   else
   {
      r0->userDisplayAspectRatio = displayAr;
   }
   
   return res;
}


/* 21c53334 - complete */
uint32_t FAPI_VISCALE_PlaneOrder(
                             FAPI_VISCALE_ParameterModeEnumT mode,
                             FAPI_VISCALE_PlaneDataSelectorEnumT plane3,
                             FAPI_VISCALE_PlaneDataSelectorEnumT plane2,
                             FAPI_VISCALE_PlaneDataSelectorEnumT plane1,
                             FAPI_VISCALE_PlaneDataSelectorEnumT plane0)
{
   int res = 0;
   
   viscale_lock();
   
   switch (mode)
   {
   case FAPI_VISCALE_PARAMETER_GET:
      res = FREG_VO_GetDispmixconf() & 0xFFFF;
      break;
      
   case FAPI_VISCALE_PARAMETER_SET:
      if ((plane0 != plane1) &&
            (plane0 != plane2) &&
            (plane0 != plane3) &&
            (plane1 != plane2) &&
            (plane1 != plane3) &&
            (plane2 != plane3))
      {
         FREG_VO_SetDispmixconf_Mix0inselect(plane0 & 3);
         FREG_VO_SetDispmixconf_Mix1inselect(plane1 & 3);
         FREG_VO_SetDispmixconf_Mix2inselect(plane2 & 3);
         FREG_VO_SetDispmixconf_Mix3inselect(plane3 & 3);
      }
      res = FREG_VO_GetDispmixconf() & 0xFFFF;
      break;
      
   default:
      res = 0;
      break;
   }
   
   viscale_unlock();

   return res;
}


/* 21c533c8 - todo */
uint32_t FAPI_VISCALE_BackgroundColour(
                            FAPI_VISCALE_ParameterModeEnumT mode,
                            uint8_t Y, uint8_t Cr, uint8_t Cb)
{
   unsigned r5;
   unsigned r4;
   unsigned r0;
   unsigned ip;
   unsigned r3;
   unsigned r2;
   unsigned r6;
   unsigned r1;
   
//   printf("FAPI_VISCALE_BackgroundColour\n");
   
   viscale_lock();
   
   FREG_VE_SetSdBackground_BackGroundY(0x10);
   FREG_VE_SetSdBackground_BackGroundCr(0x80);
   FREG_VE_SetSdBackground_BackGroundCb(0x80);
   
   switch (mode)
   {
   case 0:
      //21c5350c
      r5 = FREG_VO_GetDispbackground_BackgroundY();
      r4 = FREG_VO_GetDispbackground_BackgroundCr();
      r0 = FREG_VO_GetDispbackground_BackgroundCb();
      
      r4 = r4 << 8;
      r4 |= (r5 << 16);
      r4 |= r0;
      
      break;
      
   case 1:
      //21c5347c
      if (Y < 16)
      {
         r0 = 0x10;
         ip = 0x100000;
      }
      else 
      {
#if 0
         if (Y > 240)
         {
            r3 = Y;
         }
         else
         {
            r3 = 240;
         }
#else
//         r3 = (Y > 240)? Y: 240;
#endif
         
         r0 = (Y >= 240)? Y: 240; //r3;
         ip = r0 << 16; //r3 << 16;
      }
      //21c534a0
      if (Cr < 16)
      {
         r2 = 0x1000;
         r6 = 0x10;
      }
      else
      {
         if (Cr > 235)
         {
            r3 = Cr;
         }
         else
         {
            r3 = 235;
         }
         
         r6 = r3;
         r2 = r3 << 8;
      }
      //21c534c4
      if (Cb < 16)
      {
         r5 = 0x10;
         r1 = 0x10;
      }
      else
      {
         if (Cb > 235)
         {
            r5 = Cb;
         }
         else
         {
            r5 = 235;
         }
         r1 = r5;
      }
      //21c534e4
      //r3 = r2 | ip;
      //r4 = r3 | r1;
      r4 = ip | r2 | r1;
      
      FREG_VO_SetDispbackground_BackgroundY(r0);
      FREG_VO_SetDispbackground_BackgroundCr(r6);
      FREG_VO_SetDispbackground_BackgroundCb(r5);
      
      break;
   
   case 5:
      //21c5342c
      FREG_VO_SetDispbackground_BackgroundY(0x10);
      FREG_VO_SetDispbackground_BackgroundCr(0x80);
      FREG_VO_SetDispbackground_BackgroundCb(0x80);
      
      r4 = 0x00108080;
      break;
   }
   
   viscale_unlock();
   
   return r4;
}





