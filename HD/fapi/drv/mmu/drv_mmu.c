

#include <stdint.h>
#include <string.h>
#include <fapi/sys_services.h>
#include <fapi/drv_mmu_heap.h>
#include <fapi/drv_mmu.h>
#include "drv_mmu_priv.h"


struct fapi_mmu_handle;

static struct fapi_mmu_handle* fapi_mmu_get_handle(void);
static int fapi_mmu_check_handle(struct fapi_mmu_handle*);
static void fapi_mmu_clear_handle(struct fapi_mmu_handle*);

FAPI_SYS_DriverT FAPI_MMU_Driver = //21efbec4 
{
      "MMU",
      -1,
      0,
      FAPI_MMU_Init, 
      FAPI_MMU_Exit,
      0,
      0,
      0,
      0,
};

static int mmuInitialized = 0; //21f23c5c
int Data_21f23c60; //21f23c60
static /*FAPI_SYS_SemaphoreT*/void* mmuSemaphore = 0; //21f23c64
static unsigned* mmuTable1BaseAddr = (void*) 0x02004000; //21efbee8
static void* mmuTable2BaseAddr = (void*) 0x02008000; //21efbeec

static int mmuTmpTable1MB[0x1000]; //21f23c68
static struct fapi_mmu_handle
{
   int magic; //0
   int inUse; //4
   FAPI_MMU_OpenParamsT params; //8
   //16
} mmuHandleArray[2]; //21f27c68 size??




/* 21c2c00c - complete (-fno-tree-vrp) */
int32_t FAPI_MMU_Init(void) 
{
   unsigned i = 0;
   
   if (mmuInitialized != 0)
   {
      return 0;
   }

   Data_21f23c60 = 1;
   
   for (i = 0; i < 2; i++)
   {  
      mmuHandleArray[i].inUse = 0;      
      mmuHandleArray[i].magic = 0x69697530; //iiu0
      memset(&mmuHandleArray[i].params, 0, 8);
   }
   
   if (0 != FAPI_SYS_IsMasterCpu())
   {
      int res = FAPI_MMU_InitHeap();
      
      if (res != 0)
      {
         FAPI_MMU_Exit();
         
         return res;
      }
   }

   Data_21f23c60 = 0;
   
   mmuSemaphore = FAPI_SYS_CREATE_SEMAPHORE(1);
         
   if (mmuSemaphore == 0)
   {
      return FAPI_MMU_MODULE_BASE+FAPI_ERR_SEMAPHORE_CREATE;
   }

   mmuInitialized = 1;

   return 0;
}


/* 21c2bcf0 - complete */
void FAPI_MMU_Exit(void)
{
   if (mmuInitialized != 0)
   {
      unsigned i;
      
      for (i = 0; i < 2; i++)
      {
         FAPI_MMU_Close(&mmuHandleArray[i]);
      }
      
      FAPI_SYS_DESTROY_SEMAPHORE(mmuSemaphore);
      
      mmuSemaphore = 0;
      mmuInitialized = 0;
   }
}


/* 21b05718 - complete */
void FAPI_MMU_SetTlb1BaseAddr(uint32_t a)
{
   mmuTable1BaseAddr = (void*) a;
}


/* 21b05724 - complete */
void FAPI_MMU_SetTlb2BaseAddr(uint32_t a)
{
   mmuTable2BaseAddr = (void*) a;
}


/* 21c2bf08 - complete */
FAPI_SYS_HandleT FAPI_MMU_Open( FAPI_MMU_OpenParamsT* openParamsPtr, int32_t* errorCodePtr )
{
   int res = 0;
   struct fapi_mmu_handle* h;
   
   if (mmuInitialized == 0)
   {
      res = FAPI_MMU_MODULE_BASE+FAPI_ERR_NOT_INITIALIZED;
      if (errorCodePtr != 0)
      {
         *errorCodePtr = res;
      }      
      return 0;
   }

   if (openParamsPtr == 0)
   {
      res = FAPI_MMU_MODULE_BASE+FAPI_ERR_BAD_PARAMETER;
      if (errorCodePtr != 0)
      {
         *errorCodePtr = res;
      }
      return 0;
   }

   if (openParamsPtr->version > FAPI_MMU_VERSION)
   {
      res = FAPI_MMU_ERR_UNSUPPORTED_VERSION;
      if (errorCodePtr != 0)
      {
         *errorCodePtr = res;
      }
      return 0;
   }

   FAPI_SYS_GET_SEMAPHORE(mmuSemaphore, -1);
   
   h = fapi_mmu_get_handle();
   
   if (0 != fapi_mmu_check_handle(h))
   {
      memcpy(&h->params, openParamsPtr, 8);
   }
   else
   {
      res = FAPI_MMU_MODULE_BASE+FAPI_ERR_OUT_OF_MEMORY;
   }
   
   FAPI_SYS_SET_SEMAPHORE(mmuSemaphore, 0);
   
   if (errorCodePtr != 0)
   {
      *errorCodePtr = res;
   }
   
   return h;
}


/* 21c2bd84 - complete */
int32_t FAPI_MMU_ChangeMapEntry( FAPI_SYS_HandleT handle, uint32_t virtAddr,
                                          uint32_t physAddr, uint32_t accessFlags )
{
   struct fapi_mmu_handle* a = handle;
   void* r5 = mmuTable1BaseAddr;
   
   if (Data_21f23c60 == 0)
   {
      FAPI_SYS_GET_SEMAPHORE(mmuSemaphore, -1);
   }

   if (0 == fapi_mmu_check_handle(a))
   {
      if (Data_21f23c60 == 0)
      {
         FAPI_SYS_SET_SEMAPHORE(mmuSemaphore, 0);
      }
      
      return FAPI_MMU_MODULE_BASE+FAPI_ERR_BAD_PARAMETER;
   }

   if (a->params.tableIndex != 0)
   {
      r5 = mmuTable2BaseAddr;
   }   
   
   if ((accessFlags & 3) != 2)
   {
      if (Data_21f23c60 == 0)
      {
         FAPI_SYS_SET_SEMAPHORE(mmuSemaphore, 0);
      }

      return FAPI_MMU_MODULE_BASE+FAPI_ERR_FEATURE_NOT_SUPPORTED;
   }

   if (0 != memcpy(mmuTmpTable1MB, r5, 0x4000))
   {
      mmuTmpTable1MB[virtAddr >> 20] = physAddr & 0xFFF00000; 
      mmuTmpTable1MB[virtAddr >> 20] |= accessFlags; 
      
      memcpy(r5, mmuTmpTable1MB, 0x4000);
   }

   if (Data_21f23c60 == 0)
   {
      FAPI_SYS_SET_SEMAPHORE(mmuSemaphore, 0);
   }

   return 0;
}


/* 21c2bd60 - complete */
FAPI_SYS_HandleT mmuInternalOpen( FAPI_MMU_OpenParamsT* paramsPtr )
{
   struct fapi_mmu_handle* h;
   
   h = fapi_mmu_get_handle(); 
   
   if (h != 0)
   {
      memcpy(&h->params, paramsPtr, sizeof(FAPI_MMU_OpenParamsT));
   }
   
   return h;
}


/* 21c2bc74 - complete */
int32_t FAPI_MMU_Close( FAPI_SYS_HandleT handle )
{
   int res;
   
   FAPI_SYS_GET_SEMAPHORE(mmuSemaphore, -1);
   
   if (0 == fapi_mmu_check_handle(handle))
   {
      res = FAPI_MMU_MODULE_BASE+FAPI_ERR_INVALID_HANDLE;
   }
   else
   {
      fapi_mmu_clear_handle(handle);
      
      res = 0;
   }

   FAPI_SYS_SET_SEMAPHORE(mmuSemaphore, 0);
   
   return res;
}


/* 21c2bc70 - complete */
void mmuInternalClose(FAPI_SYS_HandleT handle)
{
   fapi_mmu_clear_handle(handle);
}


/* 21c2bc28 - complete */
void fapi_mmu_clear_handle(struct fapi_mmu_handle* a)
{
   if (0 != fapi_mmu_check_handle(a))
   {      
      if (0 != memset(a, 0, sizeof(struct fapi_mmu_handle)))
      {
         a->magic = 0x69697530; //iiu0
         a->inUse = 0;
      }
   }
}


/* 21c2bbe4 - complete */
struct fapi_mmu_handle* fapi_mmu_get_handle(void)
{
   int i;
   
   for (i = 0; i < 2; i++)
   {
      if (mmuHandleArray[i].inUse == 0)
      {
         mmuHandleArray[i].inUse = 1;
         return &mmuHandleArray[i];
      }
   }
      
   return 0;
}


/* 21c2bb84 - complete */
int fapi_mmu_check_handle(struct fapi_mmu_handle* a)
{
   int res = 0;
   
   if (((mmuInitialized != 0) ||
         (Data_21f23c60 != 0)) &&
         (a != 0) &&
         (a->inUse != 0) &&
         (a->magic == 0x69697530)) //iiu0
   {
      res = 1;
   }
   
   return res;
}


/* 21c2bad4 - complete */
uint32_t FAPI_MMU_GetPhysAddr( uint32_t virtAddr )
{
   int reg;
   
   asm("mrc 15, 0, %0, cr1, cr0, 0": "=r" (reg));
   
   if ((reg & 1) == 0)
   {
      return virtAddr;
   }
   else
   {
      unsigned res = -1;
      unsigned r2 = mmuTable1BaseAddr[virtAddr >> 20];
      
      if ((r2 & 0x03) == 2)
      {
         res = (r2 & 0xFFF00000) | (virtAddr & 0xFFFFF);
      }
      
      return res;
   }   
}


/* 21c2bb18 - nearly complete */
uint32_t FAPI_MMU_GetVirtAddr( uint32_t physAddr )
{
   unsigned i, ip;
   int reg;
   
   asm("mrc 15, 0, %0, cr1, cr0, 0": "=r" (reg));
   
   if ((reg & 1) == 0)
   {
      return physAddr;
   }
   else
   {
      unsigned res = -1;
      
      ip = (physAddr & 0xFFF00000); 
      
      for (i = 0; i < 0x1000; i++)
      {                  
         if ((mmuTable1BaseAddr[i] & 0xFFF00000) == ip)
         {
            if ((mmuTable1BaseAddr[i] & 0x03) == 2)
            {
               res = (physAddr & 0xFFFFF) | (i << 20);
            }
            
            break;
         }
      }
      return res;
   }   
}







