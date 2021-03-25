

#include <fapi/sys_services.h>
#include "sys.h"
#include "stringop.h"
#include "app_main.h"




struct Struct_21f02e40
{
   struct
   {
      //void (*Data_4[16])(void); //0
      int fill_0; //0
      void (*Data_4)(void); //4
      void (*Data_8)(void); //8
      void (*Data_12)(void); //12
      int fill_16; //16
      int fill_20; //20
      int fill_24; //24
      int fill_28; //28
      int fill_32; //32
      int fill_36; //36
      int fill_40; //40
      int fill_44; //44
      int fill_48; //48
      int fill_52; //52
      int fill_56; //56
      void (*Data_60)(void); //60
      void (*Data_64)(void); //64
      void (*Data_68)(void); //68
      //72
   } Data_0[18]; //0
   struct Struct_21ba1a6c Data_1296; //1296
   char bData_1316; //1316
   void* Data_1320; //1320
   int Data_1324; //1324
   //1328   
};

struct Struct_21f02e40* Data_21f02e40; //21f02e40


/* 21b9ffe8 - todo */
void func_21b9ffe8(void)
{
   FAPI_SYS_PRINT_MSG("func_21b9ffe8\n");
}


/* 21ba0068 - todo */
void func_21ba0068(void)
{
   FAPI_SYS_PRINT_MSG("func_21ba0068\n");
}


/* 21ba05b8 - todo */
void func_21ba05b8(void)
{
   FAPI_SYS_PRINT_MSG("func_21ba05b8\n");
}


/* 21ba0820 - todo */
void func_21ba0820(void)
{
   FAPI_SYS_PRINT_MSG("func_21ba0820\n");
}


/* 21ba06f4 - todo */
void func_21ba06f4(void)
{
   FAPI_SYS_PRINT_MSG("func_21ba06f4\n");
}


/* 21ba1adc - todo */
int32_t STR_Init(struct appData* a)
{
   int r0;
   int r3;

//   printf("STR_Init\n");
   
   if (Data_21f02e40 != 0)
   {
      FAPI_SYS_PRINT_MSG("ASSERTION FAILED at %s, l.%i\n",
            "sys/src/stringop.c", 558);
      rtos_halt(-1);
   }
   
   Data_21f02e40 = SYS_MemoryAllocate(sizeof(struct Struct_21f02e40));
   if (Data_21f02e40 == NULL)
   {
      //21ba1b34
      return -2;
   }
   
   memset(Data_21f02e40, 0, sizeof(struct Struct_21f02e40));
   
   if (a->bData_72 == 0)
   {
      Data_21f02e40->Data_1324 = 1;
   }
   else
   {
      Data_21f02e40->Data_1324 = a->bData_72;
   }
   
   if (0 != STR_BufOpen(&Data_21f02e40->Data_1296, a->Data_28, 0))
   {
      //->21ba1b34
      return -2;
   }
   
   Data_21f02e40->Data_1320 = SYS_MemoryAllocate(a->Data_32);
   if (Data_21f02e40->Data_1320 == 0)
   {
      //->21ba1b34
      return -2;
   }
   
   Data_21f02e40->bData_1316 = 2;

   for (r0 = 0; r0 != 16; r0++)
   {
      for (r3 = 0; r3 != 16; r3++)
      {
//         Data_21f02e40->Data_0[r0].Data_4[r3] = func_21ba0068;
      }
   }

   Data_21f02e40->Data_0[16].Data_64 = func_21ba05b8; //1216
   Data_21f02e40->Data_0[16].Data_4 = func_21ba0820; //1156
   Data_21f02e40->Data_0[16].Data_68 = func_21ba06f4; //1220

   Data_21f02e40->Data_0[15].Data_60 = func_21b9ffe8; //1140

   Data_21f02e40->Data_0[1].Data_4 = func_21b9ffe8; //76
   Data_21f02e40->Data_0[2].Data_8 = func_21b9ffe8; //152
   Data_21f02e40->Data_0[3].Data_12 = func_21b9ffe8; //228

   return 0;
}


/* 21ba1a6c - complete */
int32_t STR_BufOpen(struct Struct_21ba1a6c* a, int size, void* data)
{   
   if ((a == 0) || (size == 0))
   {
      return -10000001;
   }
   
   if (data != 0)
   {
      a->data = data;
      a->memAllocated = 0;
   }
   else
   {
      a->data = SYS_MemoryAllocate(size);
      if (a->data == 0)
      {
         return -2;
      }
      
      a->memAllocated = 1;
   }

   a->size = size;
   
   STR_BufClear(a);

   return 0;
}


/* 21ba1a18 - complete */
int32_t func_21ba1a18(struct Struct_21ba1a6c* a)
{
   if (a == 0)
   {
      return -10000001;
   }
   
   if ((a->memAllocated != 0) && (a->data != 0))
   {
      SYS_MemoryFree(a->data);
      
      a->data = 0;
      a->memAllocated = 0;
   }
   
   a->size = 0;
   
   STR_Clear(a);
   
   return 0;
}


/* 21b9f76c - complete */
int32_t STR_BufClear(struct Struct_21ba1a6c* a)
{
   if (a == 0)
   {
      a = &Data_21f02e40->Data_1296;
   }

   STR_Clear(a);

   STR_Terminate(a->data, a->size);

   return 0;
}


//* 21b9ef70 - complete */
void STR_Terminate(void* data, uint32_t size)
{
//   FAPI_SYS_PRINT_MSG("STR_Terminate\n");

   if ((data != NULL) && (size != 0))
   {
      ((uint8_t*)data)[0] = 0;

      if (size > 1)
      {
         ((uint8_t*)data)[1] = 0;
      }
   }
}


/* 21b9ef60 - complete */
void STR_Clear(struct Struct_21ba1a6c* a)
{
//   FAPI_SYS_PRINT_MSG("STR_Clear\n");

   a->bData_0 = 0;
   a->Data_4 = 0;
}


/* 21b9ef54 - complete */
void func_21b9ef54(struct Struct_21ba1a6c* a, uint8_t b, uint32_t c)
{
   a->Data_4 = c;
   a->bData_0 = b;
}




