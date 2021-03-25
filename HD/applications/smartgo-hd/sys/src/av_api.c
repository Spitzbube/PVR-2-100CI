
#if 0
#include <string.h>
#include "fh_ve.h"
#include "rtos_memory.h"
#include "ghw\fd_ghw.h"
#include "osd\fd_osd.h"
#include "i2c\fd_i2c.h"
#include "fe\fd_fe.h"
#include "vo\fd_vo.h"
#include "timer\fd_timer.h"
#include "rtos_kernel.h"
#include "rtos_semaphore.h"
#include "fdrv.h"
#include "ffs_init.h"
#include "ffs.h"
#include "fsys.h"
#include "fm_debug.h"
#include "statlist.h"
#include "carrierlist.h"
#include "cfgsat.h"
#include "settings.h"
#include "slist.h"
#include "resources.h"
#include "35bf50.h"
#include "av.h"
#include "app_osd.h"
#include "input.h"
#include "mcu.h"
#include "event_queue.h"
#include "language.h"
#include "time.h"
#include "pvr_list.h"
#include "fdvr.h"
#include "pvr.h"
#include "36fcec.h"
#include "372988.h"
#include "379804.h"
#include "373b74.h"
#include "379cb8.h"
#include "app_menustack.h"
#include "app_items.h"
#include "app_servbox.h"
#include "app_confdialog.h"
#include "app_sleeptimer.h"
#include "app_main.h"
#include "app_menu_systemsetup.h"
#include "app_menu_main.h"
#include "parental_control.h"
#include "pip.h"
#endif
#include "av_api.h"



#if 0

/* 348770 - todo */
int func_348770(Struct_348770* a)
{
//   FM_Printf("av.c: func_348770()\n");

   Struct_5F8D0C* r0;
   
   if (av == 0) return 4;

   a->Data_0 = av->Data_4220;
   a->bData_4 = -1;
   
   switch (av->Data_4220)
   { 
      case 0:
      case 1:
      case 2:
         //3487f4
         r0 = func_36435c(); //->resources.c
         
         if (r0->wData_0 & 1)
         {
            a->bData_4 = r0->Data_4.bData_2;
         }          
         break;
         
      case 3:
         //348814
         a->bData_4 = -1;
         break;
   } 
   
   return 0;
}


/* 348830 - complete */
void func_348830(int a)
{
//   FM_Printf("av_api.c: func_348830\n");

   if (av == 0)
   {  
      FM_Printf("ASSERTION FAILED at %s, l.%i\n",
         "sys/src/av_api.c",
         104);
         
      rtos_halt();   
   } 
   
   av->Data_4220 = a;
}


/* 3488a0 - todo */
int av_api_tune_next_service(void)
{
//   FM_Printf("av_api.c: av_api_tune_next_service\n");

   struct slist_index fp4;
   signed short currentIndex;
   int numServices;
   int res = (104 << 16) | 0;

   if (av == 0) return 4;
   
   numServices = slist_get_element_count(av->Data_11380.Data_28.nList);
   if (numServices < 2) return 1;
   
   fp4 = av->Data_11380.Data_28;
   
   currentIndex = av->Data_11380.Data_28.nIndex; 
   
   while (1)
   {
      fp4.nIndex = (fp4.nIndex + 1) % (signed short)numServices;
   
      if (currentIndex == fp4.nIndex) break;

      res = func_348b6c(&fp4, 0);

      if (res == 0) break;
   }

   return res;
}


/* 3489b4 - todo */
int av_api_tune_previous_service(void)
{
//   FM_Printf("av_api.c: av_api_tune_previous_service\n");

   struct slist_index fp4;
   signed short currentIndex;
   int numServices;
   int res = (104 << 16) | 0;

   if (av == 0) return 4;
   
   numServices = slist_get_element_count(av->Data_11380.Data_28.nList);
   if (numServices < 2) return 1;
   
   fp4 = av->Data_11380.Data_28;
   
   currentIndex = av->Data_11380.Data_28.nIndex;
   
   while (1)
   {
      fp4.nIndex--;
      if (fp4.nIndex < 0) fp4.nIndex = numServices - 1;

      if (currentIndex == fp4.nIndex) break;

      res = func_348b6c(&fp4, 0);

      if (res == 0) break;
   }   

   return res;
}


/* 348b6c - todo */
int func_348b6c(struct slist_index* a, void* b)
{
   struct
   {
      int tag; //0
      union
      {
         AV_Message3 s3; //4
         AV_Message7 s7; //4
         struct { int fill_4[10]; } dummy; //4
      } u; //4
      //44
   } av_msg;
   struct
   { 
      int Data_0; //0
      unsigned short wData_4; //0
      unsigned short fill_6; //6
      struct slist_index Data_8; //8
      unsigned short wData_12; //12
      int Data_16; //16
      int fill_20; //20
      //24
   } fp68; 
   int fp72;
   Struct_363c94 fp88;
   slist_tService fp288;
   int fp292;
   Struct_390630 fp316;
   
   int res = 0;
   
   if (av == 0) return 4;

   res = func_36153c(a, 0x2fe, &fp88); //->resources.c
   if (res != 0) return res;  
   
   res = func_36d088(&fp72); //->time.c
   if (res != 0) return res;  
    
   if ((av->Data_11380.Data_436 != 0) ||
      (time_get_diff(av->Data_11380.Data_432, fp72) >= 10))
   { 
      //348c2c
      av->Data_11380.Data_276 = av->Data_11380.Data_28;
      
      if ((av->Data_11380.Data_28.nList == 0xFE) ||
         (av->Data_11380.Data_28.nList == 0xFF))
      {
         //348c70
         av->Data_11380.wData_444 = app_main->Data_20024.wData_342;
         av->Data_11380.wData_446 = app_main->Data_20024.wData_344;
      }
   }
   //348cc0
   av->Data_11380.Data_432 = fp72;
   
   res = func_361a18(); //->resources.c
   
   if ((res != 0) && (res != ((104 << 16) | 23)))
   {
      return res;
   } 
   
   res = func_367568(&fp292); //->settings.c
   if (res != 0) return res;  
   
   av_msg.tag = 7;
   av_msg.u.s7.Data_8 = 0;
   av_msg.u.s7.Data_12 = 0;
   av_msg.u.s7.Data_4 = fp292;
   
   if ((SYS_GetAppData()->Data_44 != 0) &&
      (0 == slist_get_service_by_list_index(&av->Data_11380.Data_28, &fp288)) && 
      (fp288.pes_pids.video == 0) && 
      (0 == slist_get_service_by_list_index(a, &fp288)) && 
      (fp288.pes_pids.video == 0))
   {
      av_msg.u.s7.Data_16 = 1;
   }
   else
   {
      av_msg.u.s7.Data_16 = 0;
   }
   
   res = av_send_message((void*) &av_msg);
   if (res != 0) return res;  
   
   res = func_361988(&fp88); //->resources.c
   if (res != 0) return res;  
   
   av_msg.tag = 3;
   memcpy(&av_msg.u.s3.Data_4, a, 4); /////////////4  
   //memcpy(&av_msg.u.s3.Data_24, &fp88, sizeof(Struct_363c94));
   av_msg.u.s3.Data_24 = fp88; 
   
   if (b != 0)
   {
      memcpy(&av_msg.u.s3.Data_8, b, 16); /////////////16
   } 
   else
   {
      av_msg.u.s3.Data_8.Data_4 = 0;
      av_msg.u.s3.Data_8.Data_8 = 1;
      av_msg.u.s3.Data_8.audLanguage = 0xffffff;
      av_msg.u.s3.Data_8.ac3Language = 0xffffff;      
   } 
   
   memcpy(&av->Data_11380.Data_28, a, 4); ////////////4

   res = av_send_message((void*) &av_msg);
   if (res == 0) 
   {
      if ((0 == func_390630(&fp316)) && //->sys/src/pip.c
         (fp316.Data_0 != 0))
      {
         return res;
      }
      //348ec8
      fp68.Data_0 = 0;
      fp68.wData_4 = 24;   
      memcpy(&fp68.Data_8, a, 4); //fp68.Data_8 = *a; //////////4
      fp68.wData_12 = 0;
      fp68.Data_16 = 0;
   
      res = EVT_Send(&fp68, "Service select");
   } 
      
   return res;
}


/* 34c2a8 - complete */
int func_34c2a8(int a)
{
   AV_Message av_msg;
   int res = func_34d65c(a);
   
   if (res != 0) return res;
   
   res = func_365504(a); //->resources.c
   
   if ((res != 0) && (res != ((104 << 16) | 23))) return res;
   
   av_msg.tag = 18;
   av_msg.u.s18.bData_4 = a;
      
   return av_send_message(&av_msg);
}


/* 34c350 - complete */
int func_34c350(signed char* a)
{
   if (av == 0) return 4;

   switch (av->Data_4220)
   {
      case 0:
      case 3:
         *a = -1;
         break;
         
      case 1:
      case 2:
         *a = av->Data_11380.bData_256;
         break;
   } 
   
   return 0;
}


/* 34c3dc - complete */
int av_api_set_audio_stream(signed char a)
{
//   FM_Printf("av_api.c: av_api_set_audio_stream()\n");

   AV_Message msg;
   
   if (av == 0) return 4;

   if (av->Data_4220 == 3)
   {
      return ((104 << 16) | 0);
   }
   
   msg.tag = 5;
   msg.u.s5.bData_4 = a;
   
   return av_send_message(&msg);
}


/* 34c46c - complete */
int av_api_set_ac3_stream(int a, signed char b)
{
   AV_Message msg;
   
   if (av == 0) return 4;
   
   if (av->Data_4220 == 3) return (104 << 16) | 0;
   
   msg.tag = 6;
   msg.u.s6.Data_8 = a;
   msg.u.s6.bData_4 = b;
   
   return av_send_message(&msg);
}


/* 34c514 - todo */
int func_34c514(int* a, signed char* b)
{
//   FM_Printf("av_api.c: func_34c514()\n");

   if (av == 0) return 4;

   switch (av->Data_4220)
   {
      case 0:
      case 3:
         *a = -1;
         *b = -1;
         break;
         
      case 1:
      case 2:
         if (av->Data_11380.bData_258 < 0)
         {
            if (av->Data_11380.bData_256 < 0)
            { 
               *a = -1;
               *b = -1;
            } 
            else
            {
               *a = 0;
               *b = av->Data_11380.bData_256;
            }          
         } 
         else
         {
            *a = 1;
            *b = av->Data_11380.bData_258;
         }          
         break;
   } 

   return 0;   
}


/* 349710 - todo */
int func_349710(void)
{
//   FM_Printf("av_api.c: func_349710()\n");

   int res;
   AV_Message msg;

   if (av == 0) return 4;

   res = func_361a18(); //->resources.c
   
   if ((res != 0) && (res != ((104 << 16) | 23)))
   {
      return res;
   } 
   
   msg.tag = 7;
   msg.u.s7.Data_4 = 1;
   msg.u.s7.Data_8 = 1;
   msg.u.s7.Data_12 = 0;
   msg.u.s7.Data_16 = 0;
   
   return av_send_message(&msg);
}


/* 3497b4 - todo */
int func_3497b4(void)
{
   int res;
   AV_Message msg;
   
   if (av == 0) return 4;
   
   res = func_361a18(); //->resources.c
   
   if ((res != 0) && (res != ((104 << 16) | 23)))
   {
      return res;
   } 

   msg.tag = 7;
   msg.u.s7.Data_4 = 0;
   msg.u.s7.Data_8 = 1;
   msg.u.s7.Data_12 = 0;
   msg.u.s7.Data_16 = 0;
   
   return av_send_message(&msg);
}


/* 349930 - todo */
int func_34cb34(void)
{
//   FM_Printf("av_api.c: func_34cb34()\n");

   int res;
   AV_Message msg;
   struct Event_serviceSelect ev;
   Struct_363c94 fp84;
   
   if (av == 0) return 4;

   res = func_36153c( //->resources.c
            &av->Data_11380.Data_28,
            0x2FE, &fp84);   
   if (res != 0) return res;
   
   res = func_361988(&fp84); //->resources.c
   if (res != 0) return res;
   
   msg.tag = 4;
   msg.u.s4.Data_4 = av->Data_11380.Data_28;
   msg.u.s4.Data_12 = 0;
   msg.u.s4.Data_16 = 1;
   msg.u.s4.Data_8 = 0;
   msg.u.s4.Data_20 = 0;
   msg.u.s4.Data_24 = fp84;
   
   res = av_send_message(&msg);
   
   if (res == 0)
   {
      ev.header.tag = 0;
      ev.header.size = sizeof(struct Event_serviceSelect);
      ev.Data_8 = av->Data_11380.Data_28;
      ev.audioStream = 0;
      ev.mode = 0;
      
      res = EVT_Send(&ev, "Service select");
   } 
   
   return res;
}


/* 349a98 - todo */
int func_349a98(void)
{
   struct slist_index fp4;
   
   fp4.nList = 0x100;
   fp4.nIndex = 0;
   
   if (0 == func_348b6c(&av->Data_11380.Data_28, 0))
   {
      return 0;
   } 
   
   if (0 == func_348b6c(&fp4, 0))
   {
      return 0;
   } 
   
   fp4.nList = 0x101;
   
   return func_348b6c(&fp4, 0);
}


/* 34cd5c - complete */
int av_api_get_tv_system(int* a)
{
   if (av == 0) return 4;
   
   *a = av->tvSystem;
   
   return 0;
}


/* 349ba8 - todo */
int func_349ba8(int* a)
{
   if (av == 0) return 4;

   *a = av->Data_7480;
   
   return 0;
}

#endif

/* 21b7c6c8 - todo */
/* v3.8: 34cf94 - todo */
int func_21b7c6c8(signed char a, Struct_349d90* b)
{
#if 0
   Struct_5F8D0C* r15;
   
   if (av == 0) return 4;

   if ((a < 0) || (a >= SYS_GetAppData()->bData_0)) return 1;

   r15 = func_36435c(); //->sys/src/resources.c
   
   if ((r15->Data_144.arData_2[a].a & 1) == 0)
   {
      b->a = 0;
   } 
   else if (r15->Data_144.arData_2[a].a == 1)
   {
      b->a = 1;
   } 
   else
   {
      b->a = 2;
   } 
   
   b->b = av->Data_7500[a].Data_20;
#endif
   
   return 0;      
}

#if 0

/* 349ed4 - complete */
int av_api_set_lnb_power(int a, int b)
{
   AV_Message av_msg;
   
   int res = func_34d65c(a);
   if (res != 0) return res;
   
   av_msg.tag = 31;
   av_msg.u.s31.bData_4 = a;
   av_msg.u.s31.Data_8 = b;
   
   return av_send_message(&av_msg);
}


/* 349f44 - complete */
int av_api_get_service_list_index(struct slist_index* a)
{
   if (av == 0) return 4;
   
   *a = av->Data_11380.Data_28;
   
   return 0;
}

#endif

