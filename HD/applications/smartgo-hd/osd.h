#ifndef OSD_H_
#define OSD_H_


struct OsdWindow;

typedef struct
{
   signed short wData_0; //0
   signed short wData_2; //2
   unsigned short width; //4
   unsigned short height; //6
   char bData_8; //8
} OsdArea;

struct OsdWindowItemXy
{
   signed short x;
   signed short y;
};

struct OsdWindowItem
{
   struct OsdWindowItemXy pos; //0
   int Data_4; //4
   int Data_8; //8
   int activated; //12
   void* Data_16; //16
   OsdArea* area; //20
   int itemId; //24
   int disabled; //28
   int (*SetHandler)(void* a, int b); //32
   int (*Draw)(void* a); //36
   int (*Data_40)(void* a); //40
   int (*Release)(void* a); //44
   //48
};


typedef struct
{
   signed short wData_0; //0
   signed short wData_2; //2
   unsigned short wData_4; //4
   unsigned short wData_6; //6
   char bData_8; //8   
   //12
} Struct_5FA0E4_Inner2;


struct OsdWindowParams
{
   Struct_5FA0E4_Inner2 Data_0; //0
   unsigned type; //12
   int Data_16; //16
   void (*SetHandler)(void* a, int b); //20
   void* Data_24; //24
   struct OsdWindow* window; //28
   //32
}; 


struct OsdWindow
{
   int fRelease; //0
   struct OsdWindowParams params; //4
   int Data_36; //36
   struct OsdView* view; //40
   char numItems; //44
   struct OsdWindowItem items[50]; //48
   int activeItem; //2448
   int Data_2452; //2452
   //2456
};


struct OsdView
{
   signed short wData_0; //0
   signed short wData_2; //2
   int Data_4; //4
   void* window; //8
   Struct_5FA0E4_Inner2* Data_12; //12
   int id; //16
   int Data_20; //20
   int Data_24; //24
   int (*SetHandler)(void* a, int b); //28
   int (*Data_32)(void* a, int b); //32
   int (*Data_36)(void* a); //36
   int (*Destroy)(void* a); //40
   void (*Data_44)(void); //44
   //48
};



#endif /*OSD_H_*/
