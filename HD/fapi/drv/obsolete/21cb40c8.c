
#include <string.h>
#include <fapi/sys_services.h>
#include "21cb40c8.h"



int Data_21f77d44; //21f77d44
FAPI_SYS_SemaphoreT Data_21f77d40; //21f77d40
struct Struct_21f77d48
{
   int magic; //0
   int inUse; //4
   Struct_21cb4154 openParams; //8
   //20
} Data_21f77d48[1]; //21f77d48



int func_21cb3f7c(struct Struct_21f77d48* a);


/* 21cb4aac - todo */
int func_21cb4aac(int a, int b, int c, int d)
{
   return 0;
}


/* 21cb40c8 - complete */
/* init */
int32_t func_21cb40c8(void)
{
   unsigned i;
   
   if (Data_21f77d44 != 0)
   {
      return 0;
   }
   
   for (i = 0; i < 1; i++)
   {
      Data_21f77d48[i].magic = 0x626f6f74; //boot
      Data_21f77d48[i].openParams.version = 0;
      Data_21f77d48[i].openParams.Data_4 = 0;
      Data_21f77d48[i].openParams.Data_8 = 0;
      Data_21f77d48[i].inUse = 0;
   }
   
   Data_21f77d40 = FAPI_SYS_CREATE_SEMAPHORE(1);
            
   if (Data_21f77d40 == 0)
   {
      return -5;
   }
   
   Data_21f77d44 = 1;
   
   return 0;
}


/* 21cb4058 - complete */
/* exit */
void func_21cb4058(void)
{
   unsigned i;
   
   if (Data_21f77d44 != 0)
   {
      for (i = 0; i < 1; i++)
      {
         if (Data_21f77d48[i].inUse == 1)
         {
            func_21cb3fc4(&Data_21f77d48[i]);
         }
      }
      
      FAPI_SYS_DESTROY_SEMAPHORE(Data_21f77d40);
      
      Data_21f77d40 = 0;
      Data_21f77d44 = 0;
   }
}


/* allocate handle */
static struct Struct_21f77d48* func_21cb41a4(void)
{
   unsigned i;
   struct Struct_21f77d48* handle = 0;
   
   for (i = 0; i < 1; i++)
   {
      if (Data_21f77d48[i].inUse == 0)
      {
         Data_21f77d48[i].inUse = 1;
         Data_21f77d48[i].magic = 0x626f6f74;
         
         handle = &Data_21f77d48[i];
         
         break;
      }
   }
   
   return handle;
}


/* 21cb3f14 - todo */
int func_21cb3f14(void)
{
//   FAPI_SYS_PRINT_MSG("func_21cb3f14\n");
   
   return ((unsigned*)0x2000100)[5];
}


/* 21cb4154 - complete */
/* open */
FAPI_SYS_HandleT func_21cb4154(Struct_21cb4154* paramsPtr, int32_t* b)
{
   struct Struct_21f77d48* handle;
   int res = 0;
   
   if (Data_21f77d44 == 0)
   {
      if (b != 0)
      {
         *b = -6;
      }
      return 0;
   }
   
   if (paramsPtr == 0)
   {
      if (b != 0)
      {
         *b = -1;
      }
      return 0;
   }
   
   if (paramsPtr->version > 0x20000)
   {
      if (b != 0)
      {
         *b = -7;
      }
      return 0;
   }
   
   FAPI_SYS_GET_SEMAPHORE(Data_21f77d40, FAPI_SYS_SUSPEND);

   handle = func_21cb41a4();
   
   if (0 != func_21cb3f7c(handle))
   {
      if (paramsPtr->Data_8 == 2)
      {
         int r0 = func_21cb3f14();
         
         if (r0 == 0)
         {
            paramsPtr->Data_8 = 0;
         }
         else if (r0 == 1)
         {
            paramsPtr->Data_8 = 1;
         }
         else
         {
            FAPI_SYS_SET_SEMAPHORE(Data_21f77d40, FAPI_SYS_NO_SUSPEND);
            
            return 0;
         }
      }
      else if (paramsPtr->Data_8 > 1)
      {
         if (b != 0)
         {
            *b = -1;
         }

         FAPI_SYS_SET_SEMAPHORE(Data_21f77d40, FAPI_SYS_NO_SUSPEND);
         
         return 0;
      }

      handle->openParams = *paramsPtr;
   }
   else
   {
      res = -8;
   }
   
   FAPI_SYS_SET_SEMAPHORE(Data_21f77d40, FAPI_SYS_NO_SUSPEND);

   if (b != 0)
   {
      *b = res;
   }
   
   return handle;
}


/* 21cb3fc4 - complete */
/* close */
int32_t func_21cb3fc4(FAPI_SYS_HandleT a)
{
   struct Struct_21f77d48* r4 = a;
   int32_t res = 0;
   
   if (r4 == 0)
   {
      res = -1;
   }
   else
   {
      FAPI_SYS_GET_SEMAPHORE(Data_21f77d40, FAPI_SYS_SUSPEND);
      
      if (0 != func_21cb3f7c(r4))
      {
         memset(r4, 0, sizeof(struct Struct_21f77d48));
         
         r4->magic = 0x626f6f74; //boot
      }
      else
      {
         res = -9;
      }
      
      
      FAPI_SYS_SET_SEMAPHORE(Data_21f77d40, FAPI_SYS_NO_SUSPEND);
   }

   return res;
}


/* 21cb4760 - todo */
/* Evolve: 218f4cb0 - todo */
void func_21cb4760(void)
{
   FAPI_SYS_PRINT_MSG("func_21cb4760\n");
}


/* 21cb3f7c - complete */
/* check_handle */
int func_21cb3f7c(struct Struct_21f77d48* a)
{
   if ((Data_21f77d44 != 0) &&
         (a != 0) &&
         (a->inUse != 0) &&
         (a->magic == 0x626f6f74)) //boot
   {
      return 1;
   }
   
   return 0;
}







