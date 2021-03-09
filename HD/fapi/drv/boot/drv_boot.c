
#define DEBUG 0

#include <string.h>
#include <boot/rom_symbols.h>
#include <fapi/reg_sdram.h>
#include <fapi/sys_services.h>
#include <fapi/drv_flash.h>
#include "boot/21cb40c8.h"
#include <fapi/drv_boot.h>



struct fapi_boot_block
{
   int fill_0; //0
   uint32_t imageControl; //4
   int fill_8; //8
   uint32_t imageSize; //12
   uint32_t imageVersion; //16
   uint32_t loadAddress; //20
   uint32_t jumpAddress; //24
   int data[1]; //28
};


FAPI_SYS_DriverT FAPI_BOOT_Driver = //21efa674 
{
      "BOOT",
      -1,
      0,
      FAPI_BOOT_Init, 
      FAPI_BOOT_Exit,
      0,
      0,
      0,
      0,
};

FAPI_BOOT_InfoT* bootInfoPtr = 0; //21f21dc4
int bootInitialized = 0; //21f21dc8
FAPI_SYS_SemaphoreT bootSemaphore = 0; //21f21dcc
struct fapi_boot_block* Data_21f21dd0[7]; //21f21dd0
struct fapi_boot_handle
{
   int Data_0; //0
   int inUse; //4
   FAPI_BOOT_OpenParamsT openParams; //8
} bootHandleArray[1]; //21f21dec

int fapi_boot_get_block(uint32_t imageVersion, struct fapi_boot_block** b);
static int fapi_boot_copy_data(uint32_t imageVersion,uint32_t targetAddress);
static struct fapi_boot_handle* fapi_boot_get_handle(void);
static int bootCheckHandle(struct fapi_boot_handle*);



/* 21c16ca0 - complete */
int32_t FAPI_BOOT_Init(void)
{   
   int32_t res = 0;
   unsigned i = 0;
   
   if (bootInitialized != 0)
   {
      return 0;
   }
   
   bootSemaphore = FAPI_SYS_CREATE_SEMAPHORE(1);
         
   if (bootSemaphore == 0)
   {
      return FAPI_BOOT_ERR_SEMAPHORE_CREATE;
   }

   for (i = 0; i < 1; i++)
   {
      memset(&bootHandleArray[i], 0, sizeof(struct fapi_boot_handle));
      
      bootHandleArray[i].Data_0 = 0x626f6f74; //boot
      bootHandleArray[i].inUse = 0;
   }
   
   res = func_21cb40c8();
   
   if (res != 0)
   {
      FAPI_SYS_DESTROY_SEMAPHORE(bootSemaphore);      
      return res;
   }

   extern struct fapi_boot_block Data_21e080a4; //21e080a4
   extern struct fapi_boot_block Data_21e696fc; //21e696fc
   extern struct fapi_boot_block Data_21e6971c; //21e6971c
   extern struct fapi_boot_block Data_21e6e73c; //21e6e73c
   extern struct fapi_boot_block Data_21e6eb5c; //21e6eb5c
   extern struct fapi_boot_block Data_21e6f02c; //21e6f02c
   extern struct fapi_boot_block Data_21e85a24; //21e85a24

   Data_21f21dd0[0] = &Data_21e080a4;
   Data_21f21dd0[1] = &Data_21e696fc;
   Data_21f21dd0[2] = &Data_21e6971c;
   Data_21f21dd0[3] = &Data_21e6e73c;
   Data_21f21dd0[4] = &Data_21e6eb5c;
   Data_21f21dd0[5] = &Data_21e6f02c;
   Data_21f21dd0[6] = &Data_21e85a24;

   bootInfoPtr = FAPI_BOOT_INFO_PTR;
   bootInitialized = 1;

   return 0;
}


/* 21c16c34 - complete */
void FAPI_BOOT_Exit(void)
{
   unsigned i = 0;
   
   if (bootInitialized != 0)
   {
      for (i = 0; i < 1; i++)
      {
         FAPI_BOOT_Close(&bootHandleArray[i]);
      }
            
      FAPI_SYS_DESTROY_SEMAPHORE(bootSemaphore);
      
      func_21cb4058();
      
      bootInfoPtr = 0;
      bootSemaphore = 0;
      bootInitialized = 0;
   }
}


/* 21c16b14 - complete */
FAPI_SYS_HandleT FAPI_BOOT_Open(const FAPI_BOOT_OpenParamsT* paramsPtr,int32_t* errorCodePtr)
{
//   FAPI_SYS_PRINT_MSG("FAPI_BOOT_Open\n");
   
   int32_t err_code = FAPI_OK;
   struct fapi_boot_handle* handle;
   
   if (bootInitialized == 0)
   {
      if (errorCodePtr != 0)
      {
         *errorCodePtr = FAPI_BOOT_ERR_NOT_INITIALIZED;
      }
      return 0;
   }

   if (paramsPtr == 0)
   {
      if (errorCodePtr != 0)
      {
         *errorCodePtr = FAPI_BOOT_ERR_UNSUPPORTED_VERSION;
            //FAPI_BOOT_ERR_BAD_PARAMETER;
      }
      return 0;
   }

   if (paramsPtr->version > FAPI_BOOT_VERSION)
   {
      if (errorCodePtr != 0)
      {
         *errorCodePtr = FAPI_BOOT_ERR_UNSUPPORTED_VERSION;
      }
      return 0;
   }

   FAPI_SYS_GET_SEMAPHORE(bootSemaphore, FAPI_SYS_SUSPEND);

   handle = fapi_boot_get_handle();   

   if (0 != bootCheckHandle(handle))
   {
      memcpy(&handle->openParams, paramsPtr, 
            sizeof(FAPI_BOOT_OpenParamsT));
   }
   else
   {
      err_code = FAPI_BOOT_ERR_OUT_OF_MEMORY;
   }
   
   FAPI_SYS_SET_SEMAPHORE(bootSemaphore, FAPI_SYS_NO_SUSPEND);
  
   if (errorCodePtr != 0)
   {
      *errorCodePtr = err_code;
   }
   
   FAPI_SYS_PRINT_DEBUG(3, "[BOOT] FAPI_BOOT_Open: %i\n", err_code);
   
   return handle;
}


/* 21c165c4 - complete */
int32_t FAPI_BOOT_Close(FAPI_SYS_HandleT handle)
{   
   struct fapi_boot_handle* a = handle;   
   int32_t err_code = FAPI_OK;
   
   FAPI_SYS_GET_SEMAPHORE(bootSemaphore, FAPI_SYS_SUSPEND);
   
   if (0 != bootCheckHandle(a))
   {
      memset(a, 0, sizeof(struct fapi_boot_handle));
      
      if (a != 0)
      {
         a->Data_0 = 0x626f6f74; //boot
         a->inUse = 0;
      }
   }
   else
   {
      err_code = FAPI_BOOT_ERR_INVALID_HANDLE;
   }
   
   FAPI_SYS_SET_SEMAPHORE(bootSemaphore, FAPI_SYS_NO_SUSPEND);
   
   FAPI_SYS_PRINT_DEBUG(3, "[BOOT] FAPI_BOOT_Close: %i\n", err_code);
   
   return err_code;
}


/* 21c16abc - complete */
int32_t FAPI_BOOT_GetInfo(FAPI_SYS_HandleT handle,FAPI_BOOT_InfoT* resultBuffer)
{
   if (0 == bootCheckHandle(handle))
   {
      return FAPI_BOOT_ERR_BAD_PARAMETER; 
   }

   if (resultBuffer == 0)
   {
      return FAPI_BOOT_ERR_BAD_PARAMETER;
   }
   
   if (bootInfoPtr == 0)
   {
      return FAPI_BOOT_ERR_BAD_PARAMETER;
   }
   
   *resultBuffer = *bootInfoPtr;
   
   return 0;
}


/* 21c1652c - complete */
int32_t FAPI_BOOT_GetBootMode(FAPI_SYS_HandleT handle,uint32_t* modeBuffer)
{
   int32_t err_code = FAPI_OK;

   if (0 != bootCheckHandle(handle))
   {
      if (bootInfoPtr->bootMode > 3)
      {
         *modeBuffer = 0;
      }
      else
      {
         *modeBuffer = bootInfoPtr->bootMode;
      }      
   }
   else
   {
      err_code = FAPI_BOOT_ERR_BAD_PARAMETER;
   }
   
   return err_code;
}


/* 21c164e8 - complete */
int32_t FAPI_BOOT_GetBootDevice(FAPI_SYS_HandleT handle,uint32_t* deviceBuffer)
{
   int32_t err_code = FAPI_OK;
   
   if (0 != bootCheckHandle(handle))
   {
      if (bootInfoPtr->bootDevice > 2)
      {
         *deviceBuffer = 0;
      }
      else
      {
         *deviceBuffer = bootInfoPtr->bootDevice;
      }
   }
   else
   {
      err_code = FAPI_BOOT_ERR_BAD_PARAMETER;
   }
      
   return err_code;
}


/* 21c16864 - complete */
int32_t FAPI_BOOT_GetImageInfoByVersion(FAPI_SYS_HandleT handle,
      uint32_t imageVersion,FAPI_BOOT_ImageHeaderT* infoBuffer)
{
   int32_t err_code;
   FAPI_FLASH_OpenParamsT flashParams;
   BOOT_FLASH_ImageT sp0x28;
   Struct_21cb4154 sp0x1c;
   struct
   {
      uint32_t Data_0; //0
      uint32_t Data_4; //4
      uint32_t Data_8; //8
      uint32_t Data_12; //12
      uint32_t Data_16; //16
      uint32_t Data_20; //20
   } sp4;

   FAPI_SYS_HandleT flashHandle;
   struct fapi_boot_block* r12;

   if (0 == bootCheckHandle(handle))
   {
      return FAPI_BOOT_ERR_BAD_PARAMETER; 
   }

   if (bootInfoPtr == 0)
   {
      return FAPI_BOOT_ERR_BAD_PARAMETER; 
   }

   if (infoBuffer == 0)
   {
      return FAPI_BOOT_ERR_BAD_PARAMETER; 
   }

   err_code = FAPI_BOOT_ERR_MODE_UNKNOWN; 

   FAPI_SYS_GET_SEMAPHORE(bootSemaphore, FAPI_SYS_SUSPEND);

   memset(infoBuffer, 0, sizeof(FAPI_BOOT_ImageHeaderT));

   err_code = FAPI_BOOT_ERR_MODE_UNKNOWN; 

   memset(&flashParams, 0, sizeof(FAPI_FLASH_OpenParamsT));

   flashParams.version = FAPI_FLASH_VERSION;
   flashParams.deviceType = 0;
   flashParams.firstSector = 0;
   flashParams.sectorCount = 0;
   flashParams.fsysFlag = 0;
   flashParams.forceFlush = 0;

   flashHandle = 0;

   if (bootInfoPtr->bootDevice == 1)
   {
      flashParams.deviceType = 0; //FAPI_PARALLEL_FLASH;
      flashHandle = FAPI_FLASH_Open(&flashParams, 0);
   }
   else if (bootInfoPtr->bootDevice == 2)
   {
      flashParams.deviceType = 1; //FAPI_SERIAL_FLASH;
      flashHandle = FAPI_FLASH_Open(&flashParams, 0);
   }

   err_code = fapi_boot_get_block(imageVersion, &r12);

   if (err_code == 0)
   {
      infoBuffer->imageVersion = r12->imageVersion;
      infoBuffer->imageControl = r12->imageControl;
      infoBuffer->imageSize = r12->imageSize;
      infoBuffer->loadAddress = r12->loadAddress;
      infoBuffer->jumpAddress = r12->jumpAddress;
   }
   
   if (err_code != 0)
   {
      FAPI_SYS_HandleT r7;

      memset(&sp0x1c, 0, sizeof(sp0x1c));

      sp0x1c.version = 0x20000;
      sp0x1c.Data_4 = flashHandle;
      sp0x1c.Data_8 = bootInfoPtr->slotIndex;

      r7 = func_21cb4154(&sp0x1c, &err_code);

      if ((r7 != 0) && (err_code == 0))
      {
         err_code = func_21cb4760(r7,
               imageVersion, &sp4);

         if (err_code == 0)
         {
            infoBuffer->imageVersion = sp4.Data_0;
            infoBuffer->imageControl = sp4.Data_4;
            infoBuffer->imageSize = sp4.Data_12;
            infoBuffer->loadAddress = sp4.Data_16;
            infoBuffer->jumpAddress = sp4.Data_20;

            func_21cb3fc4(r7);
         }
      }
   }

   if (err_code != 0)
   {
      if (flashHandle != 0)
      {
         err_code = FAPI_FLASH_GetBootImageInfoByVersion(flashHandle,
               imageVersion, &sp0x28);

         if (err_code == 0)
         {
            infoBuffer->imageVersion = sp0x28.imageVersion;
            infoBuffer->imageControl = sp0x28.imageControl;
            infoBuffer->imageSize = sp0x28.imageSize;
            infoBuffer->loadAddress = sp0x28.loadAddress;
            infoBuffer->jumpAddress = sp0x28.jumpAddress;
         }
      }
   }

   if (flashHandle != 0)
   {
      FAPI_FLASH_Close(flashHandle);
   }

   FAPI_SYS_SET_SEMAPHORE(bootSemaphore, FAPI_SYS_NO_SUSPEND);

   FAPI_SYS_PRINT_DEBUG(3, "[BOOT] FAPI_BOOT_GetImageInfoByVersion: %i\n", err_code);
   
   return err_code;
}


/* 21c16664 - nearly complete */
int32_t FAPI_BOOT_LoadImageByVersion(FAPI_SYS_HandleT handle,
      uint32_t imageVersion,uint32_t targetAddress)
{
   int32_t err_code;
   FAPI_FLASH_OpenParamsT flashParams;

   Struct_21cb4154 sp24;

   FAPI_SYS_HandleT flashHandle;
   
   if (0 == bootCheckHandle(handle))
   {
      return FAPI_BOOT_ERR_BAD_PARAMETER;
   }
   
   if (bootInfoPtr == 0)
   {
      return FAPI_BOOT_ERR_BAD_PARAMETER;
   }
   
   FAPI_SYS_GET_SEMAPHORE(bootSemaphore, FAPI_SYS_SUSPEND);
      
   err_code = FAPI_BOOT_ERR_MODE_UNKNOWN;

   memset(&flashParams, 0, sizeof(FAPI_FLASH_OpenParamsT));

   flashParams.version = FAPI_FLASH_VERSION;
   flashParams.deviceType = 0;
   flashParams.firstSector = 0;
   flashParams.sectorCount = 0;
   flashParams.fsysFlag = 0;
   flashParams.forceFlush = 0;

   flashHandle = 0;

   if (bootInfoPtr->bootDevice == 1)
   {
      flashParams.deviceType = 0; //FAPI_PARALLEL_FLASH;
      flashHandle = FAPI_FLASH_Open(&flashParams, 0);
   }
   else if (bootInfoPtr->bootDevice == 2)
   {
      flashParams.deviceType = 1; //FAPI_SERIAL_FLASH;
      flashHandle = FAPI_FLASH_Open(&flashParams, 0);
   }
   
   err_code = fapi_boot_copy_data(imageVersion, targetAddress);
   
   if (err_code != 0)
   {      
      FAPI_SYS_HandleT r7;

      memset(&sp24, 0, sizeof(sp24));

      sp24.version = 0x20000;
      sp24.Data_4 = flashHandle;
      sp24.Data_8 = bootInfoPtr->slotIndex;      
      
      r7 = func_21cb4154(&sp24, &err_code);
      
      if ((r7 != 0) && (err_code == 0))
      {
         err_code = func_21cb4aac(r7,
               0, imageVersion, targetAddress);
         
         func_21cb3fc4(r7);
      }      
   }   
   
   if (err_code != 0)
   {
      if (flashHandle != 0)
      {
         err_code = FAPI_FLASH_LoadBootImageByVersion(flashHandle,
               imageVersion, targetAddress);
      }
   }

   if (flashHandle != 0)
   {
      FAPI_FLASH_Close(flashHandle);
   }

   FAPI_SYS_SET_SEMAPHORE(bootSemaphore, FAPI_SYS_NO_SUSPEND);

   FAPI_SYS_PRINT_DEBUG(3, "[BOOT] FAPI_BOOT_LoadImageByVersion: %i\n", err_code);
   
   return err_code;
}


/* 21c16570 - complete */
int fapi_boot_get_block(uint32_t imageVersion, struct fapi_boot_block** b)
{
   unsigned i;
   int count = 7;
   
   for (i = 0; i < count; i++)
   {
      struct fapi_boot_block* r4 = Data_21f21dd0[i];

      if ((r4 != 0) &&
            (r4->imageVersion == imageVersion))
      {
         *b = r4;
         return 0;
      }
   }
   
   *b = 0;   
   return FAPI_BOOT_ERR_FEATURE_NOT_SUPPORTED;
}


int fapi_boot_copy_data(uint32_t imageVersion,uint32_t targetAddress)
{
   int* src;
   int* end;
   struct fapi_boot_block* sp = 0;
   int* dest = (void*) targetAddress;
   
   if (0 == fapi_boot_get_block(imageVersion, &sp))
   {
      if (dest == 0)
      {
         dest = (void*) sp->loadAddress;
      }
      
      src = (void*) sp;
      src += 7;
      end = src + sp->imageSize;
      
      while (src < end)
      {
         *dest++ = *src++;
      }
      
      return 0;
   }
   else
   {
      return -4005;
   }
}


struct fapi_boot_handle* fapi_boot_get_handle(void)
{   
   int i;
   for (i = 0; i < 1; i++)
   {
      if (bootHandleArray[i].inUse == 0)
      {
         bootHandleArray[i].inUse = 1;
         return &bootHandleArray[i];
      }      
   }

   return 0;
}


/* 21c164a0 - complete */
int bootCheckHandle(struct fapi_boot_handle* a)
{
   if ((bootInitialized != 0) &&
         (a != 0) &&
         (a->inUse != 0) &&
         (a->Data_0 == 0x626f6f74)) //boot
   {
      return 1;
   }
   
   return 0;
}


