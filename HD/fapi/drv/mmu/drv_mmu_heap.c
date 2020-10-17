
#include <string.h>
#include <stdio.h>
#include <fapi/sys_services.h>
#include <fapi/bget.h>
#include <fapi/drv_mmu.h>
#include <fapi/drv_mmu_heap.h>
#include "drv_mmu_priv.h"



struct Struct_2152fe24_Inner1
{
   int magic; //0
   struct Struct_2152fe24_Inner1* prevPtr; //4
   struct Struct_2152fe24_Inner1* nextPtr; //8
   int allocBytes; //12
   //16
};

struct fapi_mmu_heap_handle
{
   int magic; //0
   char name[8]; //4
   int inUse; //12
   unsigned size; //16
   unsigned featureBits; //20
   char* addr; //24
   int chunkCount; //28
   int chunksAllocated; //32
   int chunksFree; //36
   int bytesAvailable; //40
   struct Struct_2152fe24_Inner1* firstChunkPtr; //44
   struct Struct_2152fe24_Inner1* lastChunkPtr; //48
   //52
}; 

FAPI_MMU_HeapParamsT heapPreinitParamsArray[] = //21efbef0
{
   {4, 1, 1, 2, 3},
   {4, 2, 1, 2, 3},
};


FAPI_SYS_HandleT FAPI_MMU_HeapHandleSys0; //21f27c88
FAPI_SYS_HandleT FAPI_MMU_HeapHandleSys1; //21f27c8c
FAPI_SYS_HandleT FAPI_MMU_HeapHandleDTcm; //21f27c90
FAPI_SYS_HandleT FAPI_MMU_HeapHandleSRam; //21f27c94
/*FAPI_SYS_SemaphoreT*/void* heapSemaphore; //21f27c98
int heapInitialized; //21f27c9c
int Data_21f27ca0; //21f27ca0
int heapBgetUseCount; //21f27ca4
int heapMemorySizeBytes; //21f27ca8
void* heapMemoryStartAddress; //21f27cac
struct fapi_mmu_heap_handle heapSegmentArray[8]; //21f27cb0
struct fapi_mmu_heap_handle* heapHandleArray[8]; //21f27e50

void fapi_mmu_heap_clear_segment(struct fapi_mmu_heap_handle* a);
void heapPrepareSegment(struct fapi_mmu_heap_handle* a);
static struct fapi_mmu_heap_handle* fapi_mmu_heap_get_handle(unsigned a);
int heapCheckSegment(struct fapi_mmu_heap_handle* a);
void* heapSegmentAllocateChunk(struct fapi_mmu_heap_handle*, unsigned);
void* heapSegmentReleaseChunk(struct fapi_mmu_heap_handle*, void*);



/* 21c2d774 - complete */
int32_t FAPI_MMU_InitHeap(void)
{
   unsigned i;

   if (heapInitialized != 0)
   {
      return FAPI_MMU_MODULE_BASE+FAPI_ERR_ALREADY_INITIALIZED;
   }
      
   Data_21f27ca0 = 1;
   heapMemoryStartAddress = __heap2_start__;
   heapMemorySizeBytes = __heap2_end__ - __heap2_start__;
   heapBgetUseCount = 0;   
   
   memset(heapSegmentArray, 0, sizeof(heapSegmentArray));
   
   for (i = 0; i < 8; i++)
   {
      heapSegmentArray[i].inUse = 0;
      heapSegmentArray[i].magic = 0x68736567; //hseg
   }

   for (i = 0; i < 8; i++)
   {
      sprintf(heapSegmentArray[i].name, "user%u", i);
   }

   FAPI_MMU_HeapHandleSys0 = 0;
   FAPI_MMU_HeapHandleSys1 = 0;
   FAPI_MMU_HeapHandleDTcm = 0;
   FAPI_MMU_HeapHandleSRam = 0;   
   
   i = 7;
   
   heapSegmentArray[i].inUse = 1;
   heapSegmentArray[i].magic = 0x68736567; //hseg
   heapSegmentArray[i].featureBits = 0xd500000;
   heapSegmentArray[i].size = 0x4000;
   heapSegmentArray[i].addr = (void*) 0x0f002000;
   sprintf(heapSegmentArray[i].name, "dtcm%u", i);
   
   heapPrepareSegment(&heapSegmentArray[i]);
   
   heapHandleArray[i] = &heapSegmentArray[i];
   FAPI_MMU_HeapHandleDTcm = &heapSegmentArray[i];

   i = 6;
   
   heapSegmentArray[i].inUse = 1;
   heapSegmentArray[i].magic = 0x68736567; //hseg
   heapSegmentArray[i].featureBits = 0xd500000;
   heapSegmentArray[i].size = 0x2000;
   heapSegmentArray[i].addr = (void*) 0x02002000;
   sprintf(heapSegmentArray[i].name, "sram%u", i);
      
   heapPrepareSegment(&heapSegmentArray[i]);
   
   heapHandleArray[i] = &heapSegmentArray[i];
   FAPI_MMU_HeapHandleSRam = &heapSegmentArray[i];
   
   for (i = 0; i < 2; i++)
   {      
      if (heapPreinitParamsArray[i].sizeMBytes != 0)
      {
         heapHandleArray[i] = FAPI_MMU_CreateSegment(&heapPreinitParamsArray[i], 0);   
         if (heapHandleArray[i] == 0)
         {
            memset(heapHandleArray, 0, sizeof(heapHandleArray));
            memset(heapSegmentArray, 0, sizeof(heapSegmentArray));
            
            return FAPI_MMU_ERR_SEGMENT_CREATE;
         }

         if (i == 0)
         {
            FAPI_MMU_HeapHandleSys0 = heapHandleArray[0];
         }
         else if (i == 1)
         {
            FAPI_MMU_HeapHandleSys1 = heapHandleArray[1];
         }
      }
      
      sprintf(heapSegmentArray[i].name, "sys%u", i);
   }      

   heapSemaphore = FAPI_SYS_CREATE_SEMAPHORE(1);
   
   if (heapSemaphore == 0)
   {
      heapInitialized = 0;
      Data_21f27ca0 = 0;      
      return FAPI_MMU_MODULE_BASE+FAPI_ERR_SEMAPHORE_CREATE;
   }
   
   Data_21f27ca0 = 0;
   heapInitialized = 1;
   
   return 0;
}


/* 21c2d388 - todo */
FAPI_SYS_HandleT FAPI_MMU_CreateSegment(const FAPI_MMU_HeapParamsT* paramsPtr,int32_t* errorCodePtr)
{
   unsigned r9;
   void* mmuHandle;
   FAPI_MMU_OpenParamsT sp4;
   struct fapi_mmu_heap_handle* handle;
   int res;
   
   if ((heapInitialized == 0) &&
         (Data_21f27ca0 == 0))
   {
      res = FAPI_MMU_MODULE_BASE+FAPI_ERR_NOT_INITIALIZED;
      if (errorCodePtr != 0)
      {
         *errorCodePtr = res;
      }
      return 0;
   }

   if (paramsPtr == 0)
   {
      res = FAPI_MMU_MODULE_BASE+FAPI_ERR_BAD_PARAMETER;
      if (errorCodePtr != 0)
      {
         *errorCodePtr = res;
      }
      return 0;
   }

   if ((paramsPtr->sizeMBytes == 0) ||
         (paramsPtr->memoryMode > 2) ||
         (paramsPtr->alignmentBits > 16) ||
         (paramsPtr->functionMode > 2) ||
         (paramsPtr->strategyMode > 2))      
   {
      res = FAPI_MMU_MODULE_BASE+FAPI_ERR_BAD_PARAMETER;
      if (errorCodePtr != 0)
      {
         *errorCodePtr = res;
      }
      return 0;
   }

   if ((paramsPtr->functionMode == 2) &&
         (heapBgetUseCount != 0))      
   {
      res = FAPI_MMU_MODULE_BASE+FAPI_ERR_BAD_PARAMETER;
      if (errorCodePtr != 0)
      {
         *errorCodePtr = res;
      }
      return 0;
   }

   sp4.version = FAPI_MMU_VERSION;
   sp4.tableIndex = 0;
   
   mmuHandle = mmuInternalOpen(&sp4);
   
   if (mmuHandle == 0)
   {
      res = FAPI_MMU_MODULE_BASE+FAPI_ERR_OUT_OF_MEMORY;
      if (errorCodePtr != 0)
      {
         *errorCodePtr = res;
      }
      return 0;
   }

#if 0
   r9 = ((paramsPtr->Data_4 << 20) & 0x300000);
   r9 |= ((paramsPtr->Data_8 << 22) & 0xc00000);
   r9 |= ((paramsPtr->Data_12 << 24) & 0x3000000);
   r9 |= (paramsPtr->Data_16 << 26);
#else
   r9 = ((paramsPtr->strategyMode << 24) & 0x3000000);
   r9 |= ((paramsPtr->functionMode << 22) & 0xc00000);
   r9 |= ((paramsPtr->memoryMode << 20) & 0x300000);   
   r9 |= (paramsPtr->alignmentBits << 26);
#endif
   
   switch (paramsPtr->memoryMode)
   {
      case 2:
         r9 |= 0xDEE;  //0000 1101 1110 1110
         break;
         
      case 1:      
         r9 |= 0x1DE2; //0001 1101 1110 0010
         break;
         
      default:
         r9 |= 0x1DE2;
         break;         
   }

   if ((heapInitialized != 0) && 
         (Data_21f27ca0 == 0))
   {
      FAPI_SYS_GET_SEMAPHORE(heapSemaphore, -1);
   }
   
   res = 0;

   handle = fapi_mmu_heap_get_handle(paramsPtr->sizeMBytes << 20);

   if (0 != heapCheckSegment(handle))
   {
      handle->featureBits = r9;

      uint32_t r7 = r9 & 0xfffff;
      
      uint32_t addr = handle->addr;
      uint32_t endAddr = addr + handle->size;

      while (addr < endAddr)
      {
         int res1 = FAPI_MMU_ChangeMapEntry(mmuHandle, addr, addr, r7);
         
         addr += 0x100000;
         
         if (res1 != 0)
         {
            res = FAPI_MMU_MODULE_BASE+FAPI_ERR_FEATURE_NOT_SUPPORTED;
            
            fapi_mmu_heap_clear_segment(handle);
            
            handle = 0;

            break;
         }
      }

      if ((res == 0) && (handle != 0))
      {
         if (paramsPtr->functionMode == 2)
         {
            memset(handle->addr, 0, handle->size & 0x7FFFFFFF);
            
            heapBgetUseCount++;
            
            bpool(handle->addr, handle->size & 0x7FFFFFFF);
         }
         else if (paramsPtr->functionMode == 1)
         {
            heapPrepareSegment(handle);
         }
      }
   }
   else
   {
      res = FAPI_MMU_MODULE_BASE+FAPI_ERR_OUT_OF_MEMORY;
   }

   if ((heapInitialized == 1) || 
         (Data_21f27ca0 == 0))
   {
      FAPI_SYS_SET_SEMAPHORE(heapSemaphore, 0);
   }

   mmuInternalClose(mmuHandle);

   if (errorCodePtr != 0)
   {
      *errorCodePtr = res;
   }
   
   return handle;
}


/* 21c2d2a8 - complete */
void* FAPI_MMU_Malloc(FAPI_SYS_HandleT handle, uint32_t bytes)
{
   struct fapi_mmu_heap_handle* r4 = handle;
   void* p = 0;
   
   if ((heapInitialized != 0) &&
         (Data_21f27ca0 == 0))
   {
      FAPI_SYS_GET_SEMAPHORE(heapSemaphore, -1);
   }

   if (0 != heapCheckSegment(r4))
   {
      if (((r4->featureBits & 0xc00000) >> 22) == 2)
      {
         p = bget(bytes & 0x7FFFFFFF);
      }
      else
      {
         p = heapSegmentAllocateChunk(r4, bytes);
      }
   }

   if ((heapInitialized != 0) &&
         (Data_21f27ca0 == 0))
   {
      FAPI_SYS_SET_SEMAPHORE(heapSemaphore, 0);
   }

   return p;
}


/* 21c2d0b4 - complete */
void* FAPI_MMU_Calloc(FAPI_SYS_HandleT handle, uint32_t bytes)
{
   struct fapi_mmu_heap_handle* r4 = handle;
   void* p = 0;
   
   if ((heapInitialized != 0) &&
         (Data_21f27ca0 == 0))
   {
      FAPI_SYS_GET_SEMAPHORE(heapSemaphore, -1);
   }

   if (0 != heapCheckSegment(r4))
   {
      if (((r4->featureBits & 0xc00000) >> 22) == 2)
      {
         p = bgetz(bytes & 0x7FFFFFFF);
      }
      else
      {
         p = heapSegmentAllocateChunk(r4, bytes);
         
         if (p != 0)
         {
            memset(p, 0, bytes);
         }
      }
   }

   if ((heapInitialized != 0) &&
         (Data_21f27ca0 == 0))
   {
      FAPI_SYS_SET_SEMAPHORE(heapSemaphore, 0);
   }

   return p;
}


/* 21c2cd60 - complete */
void* FAPI_MMU_Realloc(FAPI_SYS_HandleT handle,void* memPtr,uint32_t bytes)
{
   struct fapi_mmu_heap_handle* r4 = handle;
   void* p = 0;
   
   if ((heapInitialized != 0) &&
         (Data_21f27ca0 == 0))
   {
      FAPI_SYS_GET_SEMAPHORE(heapSemaphore, -1);
   }

   if (0 != heapCheckSegment(r4))
   {
      if (((r4->featureBits & 0xc00000) >> 22) == 2)
      {
         p = bgetr(memPtr, bytes & 0x7FFFFFFF);
      }
      else
      {
         p = heapSegmentAllocateChunk(r4, bytes);
         
         if (p != 0)
         {
            memcpy(p, memPtr, bytes);
            
            heapSegmentReleaseChunk(r4, memPtr);
         }
      }
   }

   if ((heapInitialized != 0) &&
         (Data_21f27ca0 == 0))
   {
      FAPI_SYS_SET_SEMAPHORE(heapSemaphore, 0);
   }

   return p;
}


/* 21c2cc80 - complete */
void* FAPI_MMU_Free(void* a, void* p)
{
   struct fapi_mmu_heap_handle* r4 = a;
   void* res = 0;
   
   if ((heapInitialized != 0) &&
         (Data_21f27ca0 == 0))
   {
      FAPI_SYS_GET_SEMAPHORE(heapSemaphore, -1);
   }

   if (0 != heapCheckSegment(r4))
   {
      if (((r4->featureBits & 0xc00000) >> 22) == 2)
      {
         brel(p);
         res = p;
      }
      else
      {
         res = heapSegmentReleaseChunk(r4, p);
      }
   }

   if ((heapInitialized != 0) &&
         (Data_21f27ca0 == 0))
   {
      FAPI_SYS_SET_SEMAPHORE(heapSemaphore, 0);
   }

   return res;
}


/* 21c2cfc0 - complete */
int32_t FAPI_MMU_ReleaseSegment( FAPI_SYS_HandleT handle )
{
   int res;
   struct fapi_mmu_heap_handle* h = handle;
   
   if (heapInitialized == 0)
   {
      return -19004;
   }
   
   if ((h == FAPI_MMU_HeapHandleSys0) ||
         (h == FAPI_MMU_HeapHandleSys1) ||
         (h == FAPI_MMU_HeapHandleDTcm) ||
         (h == FAPI_MMU_HeapHandleSRam))
   {
      return -19001;
   }
      
   FAPI_SYS_GET_SEMAPHORE(heapSemaphore, -1);
   
   if (0 != heapCheckSegment(h))
   {
      fapi_mmu_heap_clear_segment(h);
      res = 0;
   }
   else
   {
      res = -19001;
   }
   
   FAPI_SYS_SET_SEMAPHORE(heapSemaphore, 0);      
   
   return res;
}


/* 21c2cf98 - complete */
void fapi_mmu_heap_clear_segment(struct fapi_mmu_heap_handle* a)
{
   heapPrepareSegment(a);
   
   memset(a->addr, 0, a->size);
   
   a->inUse = 0;
}


/* 21c2ce74 - complete (-fno-strict-aliasing) */
void heapPrepareSegment(struct fapi_mmu_heap_handle* h)
{
   int size = 0;

   if (h != 0)
   {
      h->chunkCount = 0;
      h->chunksAllocated = 0;
      h->chunksFree = 0;      
      
      h->bytesAvailable = h->size;
      h->firstChunkPtr = (void*) h->addr;
      
      h->firstChunkPtr->magic = 0x68636b31; //hck1
      h->firstChunkPtr->prevPtr = 0;
      h->firstChunkPtr->nextPtr = 0;
      h->firstChunkPtr->allocBytes = size;      
      h->chunksAllocated++;
      h->chunkCount++;
      
      h->lastChunkPtr = (struct Struct_2152fe24_Inner1*) 
         (h->addr + h->size) - 1;
      
      h->lastChunkPtr->magic = 0x68636b31; //hck1
      h->lastChunkPtr->prevPtr = 0;
      h->lastChunkPtr->nextPtr = 0;
      h->lastChunkPtr->allocBytes = size;
      h->chunksAllocated++;      
      h->chunkCount++;
      
      struct Struct_2152fe24_Inner1* ip = 
         (struct Struct_2152fe24_Inner1*) h->addr + 1;
      
      size = h->size - 48;
      
      ip->magic = 0x68636b30; //hck0
      ip->prevPtr = h->firstChunkPtr;
      ip->nextPtr = h->lastChunkPtr;
      ip->allocBytes = size;
      h->chunksFree++;
      h->chunkCount++;
      
      h->bytesAvailable = ip->allocBytes;
      h->firstChunkPtr->nextPtr = ip; 
      h->lastChunkPtr->prevPtr = ip; 
      
      memset(ip + 1, 0, ip->allocBytes);
   }
}


/* 21c2c54c - complete */
int32_t FAPI_MMU_GetSegmentInfo( FAPI_SYS_HandleT handle, FAPI_MMU_HeapSegmentInfoT* infoPtr )
{
   struct fapi_mmu_heap_handle* r4 = handle;
   int res = 0;
   bufsize curalloc = 0; 
   bufsize totfree = 0; 
   bufsize maxfree = 0; 
   long nget = 0; 
   long nrel = 0; 
   
   FAPI_SYS_GET_SEMAPHORE(heapSemaphore, -1);
   
   if (0 == heapCheckSegment(r4))
   {
      res = FAPI_MMU_MODULE_BASE+FAPI_ERR_BAD_PARAMETER;
   }
   else
   {
      infoPtr->params.sizeMBytes = r4->size >> 20; //(MB)
      infoPtr->params.strategyMode = (r4->featureBits >>24) & 3; 
      infoPtr->params.functionMode = (r4->featureBits & 0xc00000) >> 22; 
      infoPtr->params.memoryMode = (r4->featureBits & 0x300000) >> 20; 
      infoPtr->params.alignmentBits = r4->featureBits >> 26; 
      infoPtr->startAddress = r4->addr;
      
      if (infoPtr->params.functionMode != 2)
      {
         infoPtr->bytesAvailable = r4->bytesAvailable;
      }
      else
      {
         bstats(&curalloc, &totfree, &maxfree, &nget, &nrel);         
         
         infoPtr->bytesAvailable = totfree;
      }
   }

   FAPI_SYS_SET_SEMAPHORE(heapSemaphore, 0);
   
   return res;
}


/* 21c2c270 - complete (-fno-strict-aliasing) */
void* heapSegmentAllocateChunk(struct fapi_mmu_heap_handle* r0, unsigned r1)
{      
   struct Struct_2152fe24_Inner1* r9;
   void* r3 = 0;
   struct Struct_2152fe24_Inner1* r8 = 0;
   struct Struct_2152fe24_Inner1* r7 = 0;
   unsigned r6 = (r1 + 3) & ~3;
   
   if (r6 < 32)
   {
      r6 = 32;
   }
      
   unsigned r4 = (1 << ((r0->featureBits & 0xfc000000) >> 26)) - 1;   
   unsigned r5 = (r0->featureBits & 0x3000000) >> 24;

   r6 += r4;
   r6 += (r4 + 1);
   r6 &= ~r4;
      
   for (r9 = r0->firstChunkPtr; r9 != 0; r9 = r9->nextPtr)
   {
      if ((r9->magic == 0x68636b30) &&
            (r9->allocBytes >= r6))
      {
         if (r8 == 0)
         {
            r8 = r9;
            r7 = r9;
         }

         if (r5 == 1)
         {
            break;
         }
         
         if (r7 != 0)
         {            
            if ((r9->allocBytes - r6) < (r7->allocBytes - r6))
            {
               r7 = r9;
            }
         }
      }
   }

   if (r5 == 2)
   {
      r9 = r7;
   }

   if (r9 != 0)
   {
      r0->chunksAllocated++;
      r0->chunksFree--;
      r0->bytesAvailable -= r9->allocBytes;
      
      r9->magic = 0x68636b31;
      
      r3 = r9 + 1; //(void*) ((int)r9 + 16)
      r3 = (char*) r3 + r4;
      r3 = (void*) ((int)r3 & ~r4);
            
      if ((r6 + 48) < r9->allocBytes)
      {
         r4 = r6 + 16;
         
         struct Struct_2152fe24_Inner1* r2 = (void*) ((char*)r9 + r4);
         
         r2->magic = 0x68636b30;

         struct Struct_2152fe24_Inner1* ip = r9->nextPtr;
         
         r2->nextPtr = r9->nextPtr;
         r2->prevPtr = r9;
         ip->prevPtr = r2;
         r2->allocBytes = r9->allocBytes - r4;
         r9->allocBytes = r6;
         r9->nextPtr = r2;
         
         r0->chunksFree++;
         r0->chunkCount++;
         r0->bytesAvailable += r2->allocBytes;
      }
   }

   return r3;
}


/* 21c2c400 - complete (-fno-strict-aliasing) */
void* heapSegmentReleaseChunk(struct fapi_mmu_heap_handle* a, void* b)
{
   struct Struct_2152fe24_Inner1* r4;
   struct Struct_2152fe24_Inner1* r3 = 0;
   
   if (b == 0)
   {
      return 0;
   }
   
   r3 = (struct Struct_2152fe24_Inner1*) b - 1;
   
   if (r3->magic != 0x68636b31)
   {
      for (r3 = a->firstChunkPtr; r3 != 0; r3 = r3->nextPtr)
      {
         if (r3->magic == 0x68636b31)
         {
            r4 = r3 + 1;
            
            if ((b >= (void*) r4) &&
                  (b < (void*) ((char*) r4 + r3->allocBytes)))
            {
               break;
            }
         }
      }
   }

   if ((r3 == 0) || 
         (r3->magic != 0x68636b31))
   {
      return 0;
   }

   r3->magic = 0x68636b30;
   
   a->chunksAllocated--;
   a->chunksFree++;
   a->bytesAvailable += r3->allocBytes;
      
   while (((r4 = r3->prevPtr) != 0) && (r4->magic == 0x68636b30))
   {
      r3 = r4;
   }
   
   while (((r4 = r3->nextPtr) != 0) && (r4->magic == 0x68636b30))
   {
      int r2 = r4->allocBytes;
      r2 += 16;
      
      r4 = r4->nextPtr;
      
      r3->nextPtr = r4;
      r4->prevPtr = r3;
      
      r3->allocBytes += r2;
      
      a->chunksFree--;
      a->chunkCount--;
      a->bytesAvailable += 16;      
   }

   return b;
}


/* 21c2c210 - complete */
int heapCheckSegment(struct fapi_mmu_heap_handle* a)
{
   int res = 0;
   
   if ((heapInitialized != 0) ||
         (Data_21f27ca0 != 0))
   {
      if ((a != 0) &&
            (a->inUse != 0) &&
            (a->magic == 0x68736567))
      {
         res = 1;
      }
   }
      
   return res;
}


struct fapi_mmu_heap_handle* fapi_mmu_heap_get_handle(unsigned a)
{
   unsigned i;
   struct fapi_mmu_heap_handle* h = 0;
   unsigned remaining = heapMemorySizeBytes;
   
   for (i = 0; i < 8; i++)
   {
      if (heapSegmentArray[i].inUse != 0)
      {
         remaining -= heapSegmentArray[i].size;
      }
   }
   
   if ((a >> 20) == 0xFFF)
   {
      a = remaining;
   }
   else if (a > remaining)
   {
      return 0;
   }

   for (i = 0; i < 8; i++)
   {
      if (heapSegmentArray[i].inUse == 0)
      {
         h = &heapSegmentArray[i];
         
         h->inUse = 1;
         h->magic = 0x68736567; //hseg
         h->size = a;
                  
         if (i == 0)
         {
            h->addr = heapMemoryStartAddress;
         }
         else
         {
            h->addr = heapSegmentArray[i - 1].addr + 
               heapSegmentArray[i - 1].size;
         }
         
         break;
      }
   }   
   
   return h;
}


/* 21c2c0f8 - complete */
void FAPI_MMU_SetSegmentSizeMBytes(uint32_t index,uint32_t sizeMBytes)
{
   if ((index < 2) && (sizeMBytes > 0) && (sizeMBytes < 0x1000))
   {
      heapPreinitParamsArray[index].sizeMBytes = sizeMBytes;
   }
}


/* 21c2c138 - complete */
void FAPI_MMU_SetSegmentStragegyMode(uint32_t index,uint32_t strategyMode)
{
   if ((index < 2) && (strategyMode > 0) && (strategyMode <= 2))
   {
      heapPreinitParamsArray[index].strategyMode = strategyMode;
   }
}


/* 21c2c17c - complete */
void FAPI_MMU_SetSegmentAlignmentBits(uint32_t index,uint32_t alignmentBits)
{
   if ((index < 2) && (alignmentBits >= 3) && (alignmentBits <= 16))
   {
      heapPreinitParamsArray[index].alignmentBits = alignmentBits;
   }
}


/* 21c2c1c0 - todo */
void* FAPI_MMU_GetSegment(void* addr)
{
   unsigned i;
   
   for (i = 0; i < 8; i++)
   {      
      if (heapSegmentArray[i].inUse != 0)
      {
         struct fapi_mmu_heap_handle* h = &heapSegmentArray[i];
         void* endAddr = h->addr + h->size;
         
         if ((addr >= (void*)h->addr) && (addr <= endAddr))
         {
            return h;               
         }
      }
   }   
   
   return 0;
}


/* 21c2c668 - complete */
void FAPI_MMU_ReportMemory(FAPI_SYS_HandleT handle,uint32_t dumpChunks)
{
   struct Struct_2152fe24_Inner1* loopChunkPtr;
   char* r5_;
   void* r7_;
   int memoryMode;
   int strategyMode;
   int functionMode;
   int alignmentBits;
   char* r10;
   void* sp28;
   
   struct fapi_mmu_heap_handle* r4 = handle;
   
   bufsize curalloc = 0; 
   bufsize totfree = 0; 
   bufsize maxfree = 0; 
   long nget = 0; 
   long nrel = 0; 
   
   FAPI_SYS_GET_SEMAPHORE(heapSemaphore, -1);
   
   if (0 != heapCheckSegment(r4))
   {
      strategyMode = (r4->featureBits & 0x3000000) >> 24;
      functionMode = (r4->featureBits & 0xc00000) >> 22;
      memoryMode = (r4->featureBits & 0x300000) >> 20;
      alignmentBits = r4->featureBits >> 26; 
      r10 = r4->addr;
      sp28 = r10 + r4->size - 1;
      
      if (functionMode == 2)
      {
         FAPI_SYS_PRINT_MSG("\n");
         FAPI_SYS_PRINT_MSG("############################################################\n");
         FAPI_SYS_PRINT_MSG("# BGET controlled segment\n");         
         FAPI_SYS_PRINT_MSG("############################################################\n");
      }
      else
      {
         FAPI_SYS_PRINT_MSG("\n");
         FAPI_SYS_PRINT_MSG("############################################################\n");
         FAPI_SYS_PRINT_MSG("# FME controlled segment\n");         
         FAPI_SYS_PRINT_MSG("############################################################\n");
      }
      
      FAPI_SYS_PRINT_MSG("\n");
      FAPI_SYS_PRINT_MSG("Heap segment                   = 0x%08x\n", r4);
      FAPI_SYS_PRINT_MSG("->magicId                      = 0x%08x\n", r4->magic);
      FAPI_SYS_PRINT_MSG("->inUse                        = 0x%08x\n", 
            (r4->inUse != 0)? "yes": "no");
      FAPI_SYS_PRINT_MSG("->sizeBytes                    = 0x%08x\n", r4->size);
      FAPI_SYS_PRINT_MSG("->featureBits                  = 0x%08x\n", r4->featureBits);
      FAPI_SYS_PRINT_MSG("  .memoryMode                  = %s\n", 
            (memoryMode == 2)? "cached": "uncached");
      FAPI_SYS_PRINT_MSG("  .functionMode                = %s\n", 
            (functionMode == 1)? "fme": "bget");
      FAPI_SYS_PRINT_MSG("  .strategyMode                = %s\n", 
            (strategyMode == 1)? "firstfit": "bestfit");
      FAPI_SYS_PRINT_MSG("  .alignmentBits               = %d\n", alignmentBits);
      FAPI_SYS_PRINT_MSG("->startAddress                 = 0x%08x\n", r4->addr);
      FAPI_SYS_PRINT_MSG("  [memoryArea]                 = 0x%08x..0x%08x\n", r10, sp28);
      
      if (functionMode == 2)
      {
         bstats(&curalloc, &totfree, &maxfree, &nget, &nrel);         
         
         FAPI_SYS_PRINT_MSG("->funcInfo.bget.curalloc       = 0x%08x\n", curalloc);
         FAPI_SYS_PRINT_MSG("->funcInfo.bget.totfree        = 0x%08x\n", totfree);
         FAPI_SYS_PRINT_MSG("->funcInfo.bget.maxfree        = 0x%08x\n", maxfree);
         FAPI_SYS_PRINT_MSG("->funcInfo.bget.nget           = 0x%08x\n", nget);
         FAPI_SYS_PRINT_MSG("->funcInfo.bget.nrel           = 0x%08x\n", nrel);
         
         if (dumpChunks != 0)
         {
            bpoold(r4->addr, 1, 1);
         }
      }
      else
      {
         FAPI_SYS_PRINT_MSG("->funcInfo.fme.chunkCount      = 0x%08x\n", r4->chunkCount);
         FAPI_SYS_PRINT_MSG("->funcInfo.fme.chunksAllocated = 0x%08x\n", r4->chunksAllocated);
         FAPI_SYS_PRINT_MSG("->funcInfo.fme.chunksFree      = 0x%08x\n", r4->chunksFree);
         FAPI_SYS_PRINT_MSG("->funcInfo.fme.bytesAvailable  = 0x%08x\n", r4->bytesAvailable);
         FAPI_SYS_PRINT_MSG("->funcInfo.fme.firstChunkPtr   = 0x%08x\n", r4->firstChunkPtr);
         FAPI_SYS_PRINT_MSG("->funcInfo.fme.lastChunkPtr    = 0x%08x\n", r4->lastChunkPtr);
         
         if (dumpChunks != 0)
         {            
            for (loopChunkPtr = r4->firstChunkPtr; 
               loopChunkPtr != 0; 
               loopChunkPtr = loopChunkPtr->nextPtr)
            {
               r5_ = (char*)loopChunkPtr + 16;
               r7_ = r5_ + loopChunkPtr->allocBytes - 1;
               
               FAPI_SYS_PRINT_MSG("\n");
               FAPI_SYS_PRINT_MSG("->loopChunkPtr                 = 0x%08x\n", loopChunkPtr);
               FAPI_SYS_PRINT_MSG("  ->magicId                    = 0x%08x (%s)\n", 
                     loopChunkPtr->magic, 
                     (loopChunkPtr->magic == 0x68636b31)? "used": "free");
               FAPI_SYS_PRINT_MSG("  ->prevPtr                    = 0x%08x\n", loopChunkPtr->prevPtr);
               FAPI_SYS_PRINT_MSG("  ->nextPtr                    = 0x%08x\n", loopChunkPtr->nextPtr);
               FAPI_SYS_PRINT_MSG("  ->allocBytes                 = %d\n", loopChunkPtr->allocBytes);
            
               if (loopChunkPtr->allocBytes != 0)
               {
                  FAPI_SYS_PRINT_MSG("  [memoryArea]                 = 0x%08x..0x%08x\n", r5_, r7_);                  
               }
               else
               {
                  FAPI_SYS_PRINT_MSG("  [memoryArea]                 = none (dummy chunk)\n");                  
               }               
            }
         }
         FAPI_SYS_PRINT_MSG("\n");
      }
   }
   else
   {      
      FAPI_SYS_PRINT_MSG("Heap segment      = 0x%08x IS INVALID!\n", r4);
   }

   FAPI_SYS_SET_SEMAPHORE(heapSemaphore, 0);
}








