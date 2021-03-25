

#include <fapi/sys_services.h>
#include "api_f.h"
#include "fatfs.h"


struct Struct_2206e1dc
{
   int fill_0[567]; //0
   F_DRIVER* Data_2268; //2268
   int fill_2272[512]; //2272
   //4320
} Data_2206e1dc[10]; //2206e1dc

struct Struct_2207f2d8
{
   uint32_t taskId; //0
   int Data_4; //4
#if 0
   struct Struct_2207f2d8_8 
   {
      char bData_0; //0
      int fill_4[63]; //4
      //256
   } Data_8[10]; //8
#else
   char Data_8[10][256]; //8
#endif
   int Data_2568; //2568
   int fill_2572; //2572
   int Data_2576; //2576
   //2580
}* Data_2207f2d8[20]; //2207f2d8


struct Struct_2207f328
{
   FAPI_SYS_SemaphoreT semaphore; //0
   
} Data_2207f328; //2207f328



extern FATFS_GetTaskIdCallbackT Data_21f77178; //21f77178


/* 21ca2794 - todo */
FN_FILE *f_open(const char *filename,const char *mode)
{
   FAPI_SYS_PRINT_MSG("f_open\n");

   return 0;
}


/* 21ca2824 - todo */
int f_close(FN_FILE *filehandle)
{
   FAPI_SYS_PRINT_MSG("f_close\n");

   return 0;
}


/* 21ca2738 - todo */
long f_read(void *buf,long size,long size_st,FN_FILE *filehandle)
{
   FAPI_SYS_PRINT_MSG("f_read\n");
}


/* 21ca2128 - todo */
int func_21ca2128(void)
{
//   printf("21ca2128\n");
   
   memset(Data_2206e1dc, 0, sizeof(Data_2206e1dc));
   
   if (0 != func_21ca30f8(&Data_2207f328))
   {
      return 15;
   }
   
   return 0;
}


/* 21ca30f8 - todo */
int func_21ca30f8(F_DRIVER* driver)
{
//   printf("func_21ca30f8\n");
   
#if 0
   driver->mutex = FAPI_SYS_CREATE_SEMAPHORE(1);
   
   if (driver->mutex == 0)
   {
      return 1;
   }
      
   return 0;
#else
   unsigned mutex = FAPI_SYS_CREATE_SEMAPHORE(1);
   
   if (mutex != 0)
   {
      driver->mutex = mutex;
      return 0;
   }
   
   driver->mutex = 0;
   return 1;
#endif
}


/* 21ca313c - complete */
int func_21ca313c(F_DRIVER* driver)
{
   if (driver->mutex != 0)
   {
      FAPI_SYS_DESTROY_SEMAPHORE(driver->mutex);
      
      driver->mutex = 0;
   }   
   
   return 0;
}


/* 21ca3178 - todo */
int hcc_request_semaphore(struct Struct_2207f328* a)
{
//   printf("hcc_request_semaphore\n");
   
   if (a->semaphore != 0)
   {
      int res = FAPI_SYS_GET_SEMAPHORE(a->semaphore, -1);
      if (res == -1)
      {
         return 1;
      }
      
      return 0; //(~res >> 31) ^ 1;
   }
   
   return 1;
}


/* 21ca31bc - complete */
int hcc_release_semaphore(struct Struct_2207f328* a)
{
//   printf("hcc_release_semaphore\n");

   if (a->semaphore != 0)
   {
      FAPI_SYS_SET_SEMAPHORE(a->semaphore, 0);
      
      return 0;
   }
   
   return 1;
}


/* 21ca31f8 - complete */
uint32_t hcc_get_current_thread(void)
{
   //printf("21ca31f8\n");
   
   if (Data_21f77178 != 0)
   {
      return (Data_21f77178)();
   }
   
   return 1;
}


/* 21c9ddd0 - nearly complete */
int func_21c9ddd0(struct Struct_2207f2d8** a)
{
   unsigned i;
//   printf("func_21c9ddd0\n");
   
   uint32_t taskId = hcc_get_current_thread();
   
   for (i = 0; i < 20; i++)
   {
      if (Data_2207f2d8[i] != 0)
      {
         if (Data_2207f2d8[i]->taskId == taskId)
         {
            if (a != 0)
            {
               *a = Data_2207f2d8[i];
               
               Data_2207f2d8[i]->Data_2568 = 0;               
            }
            
            return 0;
         }
      }
   }
   
   return 1;
}


/* 21c9dd54 - todo */
void func_21c9dd54(struct Struct_2207f2d8* a)
{
   printf("21c9dd54\n");
}


/* 21ca1fe4 - todo */
int func_21ca1fe4(struct Struct_2207f2d8* a, 
      F_DRIVER **driver, 
      F_DRIVERINIT driver_init,
      unsigned long driver_param)
{
//   printf("21ca1fe4\n");
      
   if ((driver_init != 0) &&
         ((*driver = (driver_init)(driver_param)) != 0))
   {
      int i;
      for (i = 0; i < 10; i++)
      {
         if (Data_2206e1dc[i].Data_2268 == *driver)
         {
            //21ca2068
            a->Data_2576 = F_ERR_DUPLICATED;
            return a->Data_2576; //F_ERR_DUPLICATED;
         }
      }
      //21ca2038
      if (0 == func_21ca30f8(*driver))
      {
         //21ca2054
         (*driver)->separated = 1;
         
         a->Data_2576 = F_NO_ERROR;
         return a->Data_2576; //F_NO_ERROR;
      }
#if 0
      else
      {
         a->Data_2576 = F_ERR_INITFUNC;
         return a->Data_2576; //F_ERR_INITFUNC;
      }
#endif
   }
//   else
   {
      //21ca2044
      a->Data_2576 = F_ERR_INITFUNC;
      return a->Data_2576;
   }
}


/* 21ca2eec - complete */
int fm_createdriver(F_DRIVER **driver, 
      F_DRIVERINIT driver_init,
      unsigned long driver_param)
{
#if 1
   int res;
   struct Struct_2207f2d8* sp;
   
   //printf("f_createdriver");
   
   if (0 != func_21c9ddd0(&sp))
   {
      return F_ERR_TASKNOTFOUND; 
   }
   
   res = func_21ca1fe4(sp, driver, driver_init, driver_param);
   
   func_21c9dd54(sp);
   
   return res;
#else
   return 0;
#endif
}


/* 21c9de38 - todo */
int func_21c9de38(void)
{
//   printf("func_21c9de38\n");
   
#if 1
   unsigned i, j;
   struct Struct_2207f2d8* p = 0;
   uint32_t taskId = hcc_get_current_thread();
   
   if (0 == func_21c9ddd0(0))
   {
      return 0;
   }
   
   while (1)
   {
      if (0 == hcc_request_semaphore(&Data_2207f328))
      {
         break;
      }
   }
   
   for (i = 0; i < 20; i++)
   {
      if (Data_2207f2d8[i] == 0)
      {
         p = FAPI_SYS_MALLOC(sizeof(struct Struct_2207f2d8));
         
         if (p == 0)
         {
            hcc_release_semaphore(&Data_2207f328);

            return 33;
         }         
         break;
#if 0
         else
         {
            //p->taskId = taskId;
            
            Data_2207f2d8[i] = p;
            
            //p->Data_4 = 0;
            //p->Data_2576 = 0;
            
            Data_2207f2d8[i]->taskId = taskId;
            Data_2207f2d8[i]->Data_4 = 0;
            Data_2207f2d8[i]->Data_2576 = 0;
            
            for (j = 0; j < 10; j++)
            {
               //Data_2207f2d8[i]->Data_8[j].bData_0 = 0;
               Data_2207f2d8[i]->Data_8[j][0] = 0;
            }
            
            Data_2207f2d8[i]->Data_2568 = 0;
            
            hcc_release_semaphore(&Data_2207f328);

            return 0;
         }
#endif
      }
   }
   
   if (p == 0)
   {
      hcc_release_semaphore(&Data_2207f328);
      
      return 7;
   }
   
   Data_2207f2d8[i] = p;
   
   //p->Data_4 = 0;
   //p->Data_2576 = 0;
   
   Data_2207f2d8[i]->taskId = taskId;
   Data_2207f2d8[i]->Data_4 = 0;
   Data_2207f2d8[i]->Data_2576 = 0;
   
   for (j = 0; j < 10; j++)
   {
      //Data_2207f2d8[i]->Data_8[j].bData_0 = 0;
      Data_2207f2d8[i]->Data_8[j][0] = 0;
   }
   
   Data_2207f2d8[i]->Data_2568 = 0;
   
   hcc_release_semaphore(&Data_2207f328);
#endif

   return 0;
}



