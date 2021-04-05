
#include <fapi/sys_services.h>
#include "smartgo_types.h"
#include "sys_api.h"
#include "stringop.h"
#include "fgs.h"
#include "fgs_box.h"
#include "fgs_navilist.h"
#include "app_osd.h"
#include "app_menu_items.h"
#include "menustack.h"

struct appData
{
   char bData_0; //0
   char bData_1; //1
   char bData_2; //2
   int Data_4; //4
   int Data_8; //8
   int Data_12; //12
   int Data_16; //16
   char bData_20; //20
   char bData_21; //21
   int Data_24; //24
   int Data_28; //28
   int Data_32; //32
   void* bootScreen; //Data_36; //36
   int bootScreenSize; //Data_40; //40
   void* Data_44; //44
   int Data_48; //48
   int fill_52[3]; //52
   char bData_64; //64
   int Data_68; //68
   char altDefaultSiCharSet; //72
   unsigned short fill_74; //74
   char bData_76; //76
   signed char bData_77; //77
   unsigned short fill_78; //78
   char bData_80; //80
   signed char bData_81; //81
   char bData_82; //82
   char fill_83; //83
   char bData_84; //84
   unsigned short fill_86; //86
   unsigned short wData_88; //88
   unsigned short wData_90; //90
   unsigned short wData_92; //92
   unsigned short wData_94; //94
   unsigned short wData_96; //96
   int fill_100[3]; //100
   void (*setStartupDefaults)(void); //112
   void (*Func_116)(void); //116
   void (*Func_120)(void); //120
   void (*Func_124)(void); //124
   void (*Func_128)(void); //128
   void (*Func_132)(void); //132
   void (*Func_136)(void); //136
   void (*Func_140)(void); //140
   void (*Func_144)(void); //144
   int (*init)(void); //148
   void (*handleEvent)(int, void*); //152
   void (*appGetStartupOperationMode)(void); //156
   //160
};


struct Struct_21f02400
{
   int fill_0[614]; //0
   int Data_2456; //2456
   int fill_2460[3055]; //2460
   int Data_14680/*helpNaviInst*/; //14680
   int fill_14684[267]; //14684
   FGS_POS_S rootPos; //15752
   FGS_MEMBER_S* pStartupMem; //15764
   FGS_MEMBER_S* pRootMem; //15768
   int Data_15772/*selectLstInst*/; //15772
   int fill_15776[874]; //15776
   int Data_19272; //19272
   int fill_19276[1283]; //19276
   int Data_24408; //24408
   int fill_24412[616]; //24412
   int Data_26876; //26876
   int fill_26880[6965]; //26880
   struct appData* Data_54740; //54740
   int fill_54744[3]; //54744
   int osdLayerStarted; //54756
   char schemeData[4][9]; //54760
   MENUSTACK_INST_S menuStack; //54796 +604
   int Data_55400; //55400
   int Data_55404; //55404
   void (*osdUpdateCb)(void); //55408
   void (*menuTimerHandler)(void*); //55412
   void* menuTimerArg; //55416
   int Data_55420; //55420
   int fill_55424[11]; //55424
   int Data_55468; //55468
   int Data_55472; //55472
   int Data_55476; //55476
   int Data_55480; //55480
   int fill_55484; //55484
   int Data_55488; //55488
   int fill_55492[99]; //55492
   char bData_55888; //55888
   char bData_55889; //55889
   char bData_55890; //55890
   char bData_55891; //55891
   char bData_55892; //55892
   int Data_55896; //55896
   int Data_55900; //55900
   struct Struct_21ba1a6c osdStringBuf; //55904
   struct Struct_21ba1a6c osdCutStrBuf; //55924
   struct Struct_21ba1a6c Data_55944; //55944
   struct Struct_21ba1a6c Data_55964; //55964
   int Data_55984; //55984
   FAPI_SYS_HandleT fontserverHandle; //55988
   void* Data_55992; //55992
   int Data_55996; //55996
   //56000
};

extern struct Struct_21f02400* appDat; //21f02400

