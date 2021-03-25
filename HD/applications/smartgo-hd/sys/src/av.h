#ifndef AV_H_
#define AV_H_

#include "val/val.h"

typedef struct
{
  int tag; //0
  union
  {
     struct { int fill_4[17]; } dummy; //4
  } u; //4
  //72
} AV_Message;

typedef struct av_72740
{
   void/*VAL_DataT*/* valDataPtr; //72740
   void/*VAL_OpenT*/* valOpenPtr; //72744
   int Data_72748; //72748
   int Data_72752; //72752
   int Data_72756; //72756
   int Data_72760; //72760
   int Data_72764; //72764
   int bootScreenActive; //72768
   int Data_72772; //72772
#if 0
   int Data_72776; //72776
   int Data_72780; //72780
#else
   VAL_DecoderTypeT    freezeDecoder; //72776
#endif
   int fill_72784[2]; //72784
   int Data_72792; //72792
   int fill_72796[5]; //72796
   //76
} AV_VIDEO_S;

struct av
{
   Struct_35e444 Data_0; //0
   int fill_28[1048]; //28
   int Data_4220; //4220
   int Data_4224; //4224
   int sleepMode; //4228
   int Data_4232; //4232
   int fill_4236[3866]; //4236
   int videoOutCurr; //19700
   int fill_19704; //19704
   int fill_19708; //19708
   int Data_19712; //19712
   int Data_19716; //19716
   struct Struct_19720
   {
      signed char bData_0; //0
      int Data_4; //4
      void* hFrontend; //8
      int Data_12; //12
      int Data_16; //16
      int Data_20; //20
      int fill_24[4]; //24
      int Data_40; //40
      int fill_44; //44
      struct Struct_48
      {
         int Data_48; //48
         unsigned short wData_52; //52
         int Data_56; //56
         int fill_60[9]; //60
         unsigned short wData_96; //96
         //52
      } Data_48; //48
      struct Struct_48 Data_100; //100
      int Data_152; //152
      int Data_156; //156
      int fill_160[4424]; //160
      //17856
   } Data_19720[2]; //19720 +35712
   int fill_55432[17]; //55432
   unsigned short wData_55500; //55500
   unsigned short wData_55502; //55502
   unsigned short wData_55504; //55504
   unsigned short wData_55506; //55506
   int fill_55508[2]; //55508
   unsigned short wData_55516; //55516
   int Data_55520; //55520
   signed char bData_55524; //55524
   unsigned short wData_55526; //55526
   int Data_55528; //55528
   signed char bData_55532; //55532
   unsigned short wData_55534; //55534
   int Data_55536; //55536
   int fill_55540[4300]; //55540
#if 0
   void/*VAL_DataT*/* valDataPtr; //72740
   int valOpenPtr; //72744
   int Data_72748; //72748
   int Data_72752; //72752   
   int Data_72756; //72756
   int Data_72760; //72760
   int Data_72764; //72764
   int bootScreenActive; //72768
   int Data_72772; //72772
   int Data_72776; //72776
   int Data_72780; //72780
   int fill_72784[2]; //72784
   int Data_72792; //72792
   int fill_72796[5]; //72796
#else
#if 0
   struct av_72740
   {
      void/*VAL_DataT*/* valDataPtr; //72740
      void/*VAL_OpenT*/* valOpenPtr; //72744
      int Data_72748; //72748
      int Data_72752; //72752   
      int Data_72756; //72756
      int Data_72760; //72760
      int Data_72764; //72764
      int bootScreenActive; //72768
      int Data_72772; //72772
#if 0
      int Data_72776; //72776
      int Data_72780; //72780
#else
      VAL_DecoderTypeT    freezeDecoder; //72776
#endif
      int fill_72784[2]; //72784
      int Data_72792; //72792
      int fill_72796[5]; //72796
      //76
   } AV_VIDEO_S;
#endif
   AV_VIDEO_S video; //72740
#endif
   int Data_72816; //72816
   unsigned long long Data_72820; //72820
   int fill_72828[2]; //72828
   int Data_72836; //72836
   int Data_72840; //72840
   int fill_72844[16]; //72844
   //72908
};


extern struct av* av; //21f029e4

extern int av_init(void);
extern int av_send_message(AV_Message*);
extern int av_send_null_message(void);
extern int av_send_start_message(void);
extern int av_send_stop_message(void);
extern FAPI_SYS_HandleT av_get_vienc_hd(void);
extern void av_int_set_colour_component_sd(int a);


#endif /* AV_H_ */
