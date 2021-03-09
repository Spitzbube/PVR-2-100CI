
#define DEBUG 4

#include <fapi/reg_bm.h>
//#include <fapi/reg_bm_old.h>
#include <fapi/sys_services.h>
#include <fapi/drv_intr.h>
#include <fapi/drv_bm.h>
#include <fapi/drv_bm_priv.h>


FAPI_SYS_DriverT FAPI_BM_Driver0 = //21efa524
{
      "BM0",
      FAPI_INTR_BM01,
      1,
      FAPI_BM_Init,
      FAPI_BM_Exit,
      //TODO
};

FAPI_SYS_DriverT FAPI_BM_Driver1 = //21efa548
{
      "BM1",
      FAPI_INTR_BM01,
      1,
      FAPI_BM_Init,
      FAPI_BM_Exit,
      //TODO
};

FAPI_SYS_DriverT FAPI_BM_Driver2 = //21efa56c
{
      "BM2",
      FAPI_INTR_BM23,
      1,
      FAPI_BM_Init,
      FAPI_BM_Exit,
      //TODO
};

FAPI_SYS_DriverT FAPI_BM_Driver3 = //21efa590
{
      "BM3",
      FAPI_INTR_BM23,
      1,
      FAPI_BM_Init,
      FAPI_BM_Exit,
      //TODO
};

struct fapi_bm_bufferPurpose
{
   int assigned; //0
   FAPI_BM_PurposeT bufferPurpose; //4
   uint32_t blockIndex; //8
   uint32_t address; //12
   uint32_t size; //16
   //20
} 
fapi_bm_bufferPurpose[8] = 
{
      {0, FAPI_BM_I2S0_BUFFER},
      {0, FAPI_BM_I2S1_BUFFER},
      {0, FAPI_BM_I2S2_BUFFER},
      {0, FAPI_BM_I2S3_BUFFER},
      {0, FAPI_BM_SPDIF_BUFFER},
      {0, FAPI_BM_TELETEXT_BUFFER},
      {0, FAPI_BM_VIDEO_STREAM_BUFFER},
      {0, FAPI_BM_AUDIO_STREAM_BUFFER},
};

struct fapi_bm_handle
{
   unsigned magic; //0
   unsigned inUse; //4
   uint32_t/*int*/ Data_8; //8
   FAPI_BM_OpenParamsT openParams; //12
   uint32_t/*int*/ Data_44; //44
   int readPtr; //48
   uint32_t baseAddress; //52
   void (*Data_56)(int, int, void*); //56
   void* Data_60; //60
   void (*Data_64)(unsigned, unsigned, int); //64
   int Data_68; //68
   void (*Data_72)(unsigned, unsigned, int); //72
   int Data_76; //76
#if 0
   unsigned Data_80; //80
   unsigned Data_84; //84
   unsigned Data_88; //88
   unsigned Data_92; //92
#else
   struct
   {
      unsigned fill_0[4]; //0
   } Data_80; //80
#endif
   //96
};


struct Struct_21f19b00
{
   int fill_0[3088]; //0
   //12352
};


struct fapi_bm_audData
{
   unsigned Data_0; //0
   uint32_t searchPattern; //4
   FAPI_BM_AudCallbackT callbackFunction; //8
   void* optData; //12
   //16
};

static FAPI_SYS_SemaphoreT fapi_bm_semaphore = 0; //21f19ac4
unsigned Data_21f19ac8 = 0; //21f19ac8
static int fapi_bm_initialized = 0; //21f19acc
struct  
{
   int Data_0; //0
   int Data_4; //4
} fapi_bm_baseAddress; //21f19ad0
static struct fapi_bm_handle* fapi_bm_handles = 0; //21f19ad8
static volatile struct Struct_21f19ae0
{
   int Data_0; //0
   unsigned Data_4; //4
   //8
} Data_21f19ae0[4]; //21f19ae0
static struct Struct_21f19b00* Data_21f19b00 = 0; //21f19b00
static struct fapi_bm_audData fapi_bm_audData[2][5]; //21f19b04
static int Data_21f19ba4[4][32]; //21f19ba4
static unsigned Data_21f21dbc[2]; //21f21dbc


static int fapi_bm_check_handle(struct fapi_bm_handle*);
static struct fapi_bm_handle* fapi_bm_get_handle(uint32_t);
void fapi_bm_clear_handle(struct fapi_bm_handle*);
static void func_21c140e8(int, int, void*);


/* 21c136e8 - complete */
int32_t FAPI_BM_Init(void)
{
   int i;
   
   if (fapi_bm_initialized != 0)
   {
      return 0;
   }
   
   Data_21f19b00 = FAPI_SYS_MALLOC(sizeof(struct Struct_21f19b00));
   
   fapi_bm_handles = (void*) (((unsigned)Data_21f19b00 + 32) & ~31);
         
   fapi_bm_semaphore = FAPI_SYS_CREATE_SEMAPHORE(1);
         
   if (fapi_bm_semaphore == 0)
   {
      return FAPI_BM_ERR_SEMAPHORE_CREATE;
   }
   
   fapi_bm_clear_mail_fifo(0);
   fapi_bm_clear_mail_fifo(2);
   
   memset(Data_21f21dbc, 0, sizeof(Data_21f21dbc));
   
   memset(fapi_bm_handles, 0, 4);
   
   for (i = 127; i >= 0; i--)
   {
      fapi_bm_handles[i].magic = 0x626d;
   }
   
   memset(Data_21f19ba4, 0, sizeof(Data_21f19ba4));
        
   memset(fapi_bm_audData, 0, sizeof(fapi_bm_audData)); 
   
   for (i = 4; i >= 0; i--)
   {
      fapi_bm_audData[0][i].Data_0 = -1;
      fapi_bm_audData[1][i].Data_0 = -1;
   }

   if (0 == FAPI_SYS_IsMasterCpu())
   {
      fapi_bm_initialized = 1;
      return 0;
   }
   else
   {
      if (fapi_bm_baseAddress.Data_0 & 3)
      {
         return FAPI_BM_ERR_BAD_PARAMETER; 
      }

      if (fapi_bm_baseAddress.Data_4 & 3)
      {
         return FAPI_BM_ERR_BAD_PARAMETER; 
      }
            
      FREG_BM01_SetAudCfgEn(0);
      FREG_BM01_SetClearAudIrq(0);
      
      FREG_BM23_SetAudCfgEn(0);
      FREG_BM23_SetClearAudIrq(0);
      
      FREG_BM0_SetIrqMask(-1);
      FREG_BM1_SetIrqMask(-1);            
      FREG_BM2_SetIrqMask(-1);
      FREG_BM3_SetIrqMask(-1);
      
      FREG_BM01_SetReadEnable(0);
      FREG_BM23_SetReadEnable(0);

      for (i = 31; i >= 0; i--)
      {
         FREG_BM0_SetRdPtr(i, 0);
         FREG_BM0_SetWrPtr(i, 0);
         FREG_BM0_SetBufSize(i, 0);
         FREG_BM0_SetBaseAddr(i, 0);
         
         FREG_BM1_SetRdPtr(i, 0);
         FREG_BM1_SetWrPtr(i, 0);
         FREG_BM1_SetBufSize(i, 0);
         FREG_BM1_SetBaseAddr(i, 0);
         
         FREG_BM2_SetRdPtr(i, 0);
         FREG_BM2_SetWrPtr(i, 0);
         FREG_BM2_SetBufSize(i, 0);
         FREG_BM2_SetBaseAddr(i, 0);
         
         FREG_BM3_SetRdPtr(i, 0);
         FREG_BM3_SetWrPtr(i, 0);
         FREG_BM3_SetBufSize(i, 0);
         FREG_BM3_SetBaseAddr(i, 0);
      }
      
      FREG_BM01_SetBufHighLev(0, 0);
      FREG_BM01_SetBufLowLev(0, 0);

      FREG_BM01_SetBufHighLev(1, 0);
      FREG_BM01_SetBufLowLev(1, 0);

      FREG_BM23_SetBufHighLev(2, 0);
      FREG_BM23_SetBufLowLev(2, 0);
      
      FREG_BM23_SetBufHighLev(3, 0);
      FREG_BM23_SetBufLowLev(3, 0);

      FREG_BM0_GetIrqReg();
      FREG_BM1_GetIrqReg();
      FREG_BM2_GetIrqReg();
      FREG_BM3_GetIrqReg();

      FREG_BM01_SetGlobalOffset(fapi_bm_baseAddress.Data_0);
      FREG_BM23_SetGlobalOffset(fapi_bm_baseAddress.Data_4);
      
      if ((Data_21f19ac8 == 0) || (Data_21f19ac8 == 1))
      {
         FREG_BM_SetHcbSelect(0);
      }
      else
      {
         FREG_BM_SetHcbSelect(0x7f);
      }
      
      if ((Data_21f19ac8 == 0) ||
            (Data_21f19ac8 == 2))
      {
         if ((Data_21f19ac8 == 0) || (Data_21f19ac8 == 1))
         {
            FREG_BM01_SetReadEnable_Bm01ReadSelect(0);
         }
         else
         {
            FREG_BM23_SetReadEnable_Bm23ReadSelect(0);
         }
      }
      else if ((Data_21f19ac8 == 0) || (Data_21f19ac8 == 1))
      {
         FREG_BM01_SetReadEnable_Bm01ReadSelect(1);
      }
      else
      {
         FREG_BM23_SetReadEnable_Bm23ReadSelect(1);
      }      
   }

   fapi_bm_initialized = 1;
   
   return 0;
}


/* 21c1538c - complete */
void FAPI_BM_Exit(void)
{
   int i;
   
   if (fapi_bm_initialized != 0)
   {
      for (i = 127; i >= 0; i--)
      {
         if (fapi_bm_handles[i].inUse == 1)
         {
            FAPI_BM_Close(&fapi_bm_handles[i]);
         }
      }      
   }
   
   FAPI_SYS_GET_SEMAPHORE(fapi_bm_semaphore, FAPI_SYS_SUSPEND);
   
   FREG_BM0_SetIrqMask(-1);
   FREG_BM1_SetIrqMask(-1);
   FREG_BM2_SetIrqMask(-1);
   FREG_BM3_SetIrqMask(-1);
   
   FREG_BM01_SetReadEnable(0);
   FREG_BM23_SetReadEnable(0);

   FAPI_SYS_FREE(Data_21f19b00);
   
   fapi_bm_initialized = 0;
   
   FAPI_SYS_SET_SEMAPHORE(fapi_bm_semaphore, FAPI_SYS_NO_SUSPEND);
   
   FAPI_SYS_DESTROY_SEMAPHORE(fapi_bm_semaphore);
   
   fapi_bm_semaphore = 0;
}


/* 21c15498 - todo */
FAPI_SYS_HandleT FAPI_BM_Open(const FAPI_BM_OpenParamsT* pParams,
                                    int32_t* errorCodePtr)
{
   struct fapi_bm_handle* h;
   unsigned r16 = 0;
   int r22 = -1;
   int32_t res = 0;
   
   FAPI_SYS_PRINT_DEBUG(4, "FAPI_BM_Open\n");

   if (fapi_bm_initialized == 0)
   {
      res = -5004;      
   }
   
   if (pParams == 0)
   {
      //21c15a24
      if (errorCodePtr != 0)
      {
         *errorCodePtr = -5001;
      }
      return 0;
   }
   //21c154c0
   if (pParams->version > FAPI_BM_VERSION)
   {
      res = -5010;
   }
   
   uint32_t r13 = pParams->blockIndex;
   
   if ((r13 != 0) &&
         (r13 != 1) &&
         (r13 != 2) &&
         (r13 != 3) && 
         (r13 != -1))
   {
      res = -5001;
   }
   
   if (r13 == -1)
   {
      r13 = Data_21f19ac8;
   }
   
   if (pParams->size > 0x1000000)
   {
      res = -5001;
   }
   
   if ((pParams->channelId >= 32) || 
         (pParams->channelId < -1))
   {
      res = -5001;
   }
   
   if ((pParams->swapWrite != 0) && 
         (pParams->swapWrite != 1))
   {
      res = -5001;
   }

   if ((pParams->swapRead != 0) && 
         (pParams->swapRead != 1))
   {
      res = -5001;
   }

   if ((pParams->swapMode != 0) && 
         (pParams->swapMode != 1))
   {
      res = -5001;
   }
   
   if (pParams->channelId != -1)
   {
      if (Data_21f19ba4[r13][pParams->channelId] == 1)
      {
         res = -5001;
      }
   }
   
   if (pParams->address % 1024)
   {
      res = -5001;
   }
   
   if (pParams->address & 0xf8000000)
   {
      res = -5001;
   }
   
   if (pParams->size % 1024)
   {
      res = -5001;
   }
   
   if (0 != func_21c12478(r13, pParams->address, pParams->size))
   {
      res = -5002;
   }
   
   if (res == 0)
   {
      //21c15598
      FAPI_SYS_GET_SEMAPHORE(fapi_bm_semaphore, FAPI_SYS_SUSPEND);
      
      if (pParams->channelId == -1)
      {
         //21c156fc
         if (r13 == Data_21f19ac8)
         {
            r16 = 8;
         }
         
         for (; r16 < 32; r16++)
         {
            if (Data_21f19ba4[r13][r16] == 0)
            {
               //21c15970
               r22 = r16;
               break;
            }
         }
   
         if (r22 == -1)
         {
            res = -5002;
         }                  
      }
      //21c155c8
      FAPI_SYS_SET_SEMAPHORE(fapi_bm_semaphore, FAPI_SYS_NO_SUSPEND);
   }
   
   if (res != 0)
   {
      //->21c156e4
      if (errorCodePtr != 0)
      {
         *errorCodePtr = res;
      }
      return 0;
   }
   //21c155f0
   FAPI_SYS_GET_SEMAPHORE(fapi_bm_semaphore, FAPI_SYS_SUSPEND);
   //21c15610
   h = fapi_bm_get_handle(r13);
   //21c156a0
   if (0 != fapi_bm_check_handle(h))
   {
      //21c15748
      memcpy(&h->openParams, pParams, sizeof(FAPI_BM_OpenParamsT));
      
      Data_21f19ae0[r13].Data_0 = 1;
      
#if 1
      int r3 = pParams->channelId;
      if (r3 == -1)
      {
         r3 = r22;
      }

      h->Data_44 = r3;
               
      h->Data_8 = r13;
      
      Data_21f19ba4[r13][r3] = 1;
#else
      if (pParams->channelId != -1)
      {
         r22 = pParams->channelId;
      }

      h->Data_44 = r22;
               
      h->Data_8 = r13;
      
      Data_21f19ba4[r13][r22] = 1;
#endif

      bmSetRdPtr(r13, h->Data_44, 0);

      bmSetWrPtr(r13, h->Data_44, 0);

      bmSetBufSize(r13, h->Data_44, pParams->size);

      bmSetBaseAddr(r13, h->Data_44, pParams->address);

      if ((r13 == 0) || (r13 == 1))
      {
         //21c1592c
         h->baseAddress = fapi_bm_baseAddress.Data_0;
      }
      else
      {
         h->baseAddress = fapi_bm_baseAddress.Data_4;
      }
      
      uint32_t r0 = bmGetmEndianSwapWr(r13);

      r0 &= ~(1 << h->Data_44);
      r0 |= (pParams->swapWrite << h->Data_44);

      bmSetEndianSwapWr(r13, r0);
      //21c15818
      if ((h->Data_44 < 8) &&
            (h->Data_8 == Data_21f19ac8))
      {
         //21c158a8
         bmSetReadEnable(r13, 
               bmGetmReadEnable(r13) | (1 << h->Data_44));
         //21c158c4
         if ((r13 == 0) || (r13 == 2))
         {
            //21c158d0
            bmSetReadEnable_ReadSelect(r13, 0);
         }
         else
         {
            //21c15ae4
            bmSetReadEnable_ReadSelect(r13, 1);
         }

         uint32_t lr = bmGetmEndianSwapRd(r13);
         //21c158e8
         lr &= ~(1 << h->Data_44);
         lr |= (pParams->swapRead << h->Data_44);
         lr &= ~(1 << (h->Data_44 + 8));
         lr |= (pParams->swapMode << (h->Data_44 + 8));
         
         bmSetEndianSwapRd(r13, lr);
         //->21c15850
      }
      else
      {
         //21c15838
         if ((pParams->swapRead == 1) || 
               (pParams->swapMode == 1))
         {
            //21c159e8
            fapi_bm_clear_handle(h);
            
            if (errorCodePtr != 0)
            {
               *errorCodePtr = -5005;
            }
            
            FAPI_SYS_SET_SEMAPHORE(fapi_bm_semaphore, FAPI_SYS_NO_SUSPEND);
            
            return 0;
         }
      }
      //21c15850
      h->Data_56 = func_21c140e8;
      
      if (pParams->size != 0)
      {
         //21c15864
         bmSetIrqMask(r13,  
               bmGetmIrqMask(r13) & ~(1 << h->Data_44));
      }
      //21c15898
      FAPI_SYS_FlushDataCache((uint32_t)h, sizeof(struct fapi_bm_handle));
      //->21c156b4
   }
   else
   {
      //21c156ac
      res = -5002;
   }
   //21c156b4
   FAPI_SYS_SET_SEMAPHORE(fapi_bm_semaphore, FAPI_SYS_NO_SUSPEND);

   if (errorCodePtr != 0)
   {
      *errorCodePtr = res;
   }
   
   FAPI_SYS_PRINT_DEBUG(3, "FAPI_BM_Open: res=%d\n", res);
   
   return h;
}


/* 21c14f88 - nearly complete */
int32_t FAPI_BM_Close(FAPI_SYS_HandleT handle)
{
   FAPI_SYS_PRINT_DEBUG(4, "FAPI_BM_Close\n");
   
   int r0;
   unsigned j;
   struct fapi_bm_handle* a = handle;
   int res = 0;
   unsigned i = -1;
   
   if (0 != fapi_bm_check_handle(a))
   {
      int r6;
      
      if ((a->Data_8 == 0) || (a->Data_8 == 1))
      {
         r6 = 0;
      }
      else
      {
         r6 = 1;
      }

      bmSetIrqMask(a->Data_8, 
            bmGetmIrqMask(a->Data_8) | (1 << a->Data_44));

      func_21c14e60(handle, 0, 0, 0);
      
      func_21c12d18(handle, 0, 0, 0, 0);
      
      func_21c12ae4(handle, 0, 0, 0, 0);
      
      FAPI_SYS_GET_SEMAPHORE(fapi_bm_semaphore, FAPI_SYS_SUSPEND);
      
      unsigned ip = a->Data_44;
      
      for (j = 0; j < 5; j++)
      {
         if (ip/*a->Data_44*/ == fapi_bm_audData[r6][j].Data_0)
         {
            i = j;
            break;
         }
      }

      if (i != -1)
      {         
         bmSetAudCfgEn(a->Data_8, 0);

         bmSetClearAudIrq(a->Data_8, 0);

         unsigned r8 = ~(1 << i);
         
         bmSetAudCfgEn(a->Data_8, ~fapi_bm_audData[r6][i].Data_0);
         
         bmSetClearAudIrq(a->Data_8, r8);

         bmSetAudValue(a->Data_8, i, 0);

         fapi_bm_audData[r6][i].Data_0 = -1;
         fapi_bm_audData[r6][i].searchPattern = 0;  
         
         ip = a->Data_44;
         
         fapi_bm_audData[r6][i].callbackFunction = 0;
         fapi_bm_audData[r6][i].optData = 0;         
      }

      if (ip < 8) /*(a->Data_44 < 8)*/
      {        
         r0 = bmGetmEndianSwapRd(a->Data_8);

         r0 &= ~(1 << a->Data_44);
         r0 &= ~(1 << (a->Data_44 + 8));
         
         bmSetEndianSwapRd(a->Data_8, r0);
      }

      r0 = bmGetmEndianSwapWr(a->Data_8);
      
      r0 &= ~(1 << a->Data_44);
      
      bmSetEndianSwapWr(a->Data_8, r0);

      bmSetBufSize(a->Data_8, a->Data_44, 0);

      bmSetBaseAddr(a->Data_8, a->Data_44, 0);

      Data_21f19ba4[a->Data_8][a->Data_44] = 0;
      
      fapi_bm_clear_handle(a);
      
      FAPI_SYS_SET_SEMAPHORE(fapi_bm_semaphore, FAPI_SYS_NO_SUSPEND);
   }
   else
   {
      res = FAPI_BM_ERR_INVALID_HANDLE;
   }
   
   return res;
}


/* 21c14da4 - complete */
int32_t FAPI_BM_SetBufferReadPointer(FAPI_SYS_HandleT handle,
                         const uint32_t readPtrPosition,
                         const uint32_t enableOutOfBounds)
{
   int32_t res = 0;
   struct fapi_bm_handle* a = handle;

   FAPI_SYS_PRINT_DEBUG(4, "FAPI_BM_SetBufferReadPointer\n");
   
   if (fapi_bm_check_handle(a))
   {
      if (enableOutOfBounds || 
            (readPtrPosition < a->openParams.size))
      {
         a->readPtr = readPtrPosition;
         
         bmSetRdPtr(a->Data_8, a->Data_44, readPtrPosition);

         FAPI_SYS_FlushDataCache((uint32_t)a, sizeof(struct fapi_bm_handle));
      }      
      else
      {
         res = FAPI_BM_ERR_PTR_OUTSIDE_BUFFER_BOUNDS;
      }
   }
   else
   {
      res = FAPI_BM_ERR_INVALID_HANDLE;
   }

   FAPI_SYS_PRINT_DEBUG(3, "FAPI_BM_SetBufferReadPointer: res=%d\n", res);
   
   return res;
}


/* 21c12c40 - complete */
uint32_t FAPI_BM_GetGlobalOffset(const uint32_t blockIndex)
{
   uint32_t res = 0;
   
   if (blockIndex < 4)
   {
      res = bmGetmGlobalOffset(blockIndex);
   }
   
   return res;
}


/* 21c125bc - complete */
void FAPI_BM_SetGlobalOffset(const uint32_t blockIndex,
                             const uint32_t globalOffset)
{
   if (fapi_bm_initialized == 0)
   {
      if ((blockIndex < 4) &&
            ((globalOffset & 0x7ffffff) == 0)) 
      {
         if ((blockIndex == 0) || (blockIndex == 1))
         {
            fapi_bm_baseAddress.Data_0 = globalOffset;
         }
         else
         {
            fapi_bm_baseAddress.Data_4 = globalOffset;
         }
      }
   }
}


/* 21c128e8 - complete */
int32_t FAPI_BM_GetInfo(FAPI_SYS_HandleT handle, FAPI_BM_InfoT* info)
{
   int32_t res = 0;
   struct fapi_bm_handle* a = handle;
   
   FAPI_SYS_PRINT_DEBUG(4, "FAPI_BM_GetInfo\n");
      
   if (0 != fapi_bm_check_handle(a))
   {
      if (info != 0)
      {
         info->blockIndex = a->Data_8;
         info->channelId = a->Data_44;
         info->globalOffset = a->baseAddress;
         info->address = a->openParams.address;
         info->size = a->openParams.size;
         info->swapWrite = a->openParams.swapWrite;
         info->swapRead = a->openParams.swapRead;
         info->swapMode = a->openParams.swapMode;
         info->privData = (uint32_t) a;
      }
      else
      {
         res = FAPI_BM_ERR_BAD_PARAMETER;
      }      
   }
   else
   {
      res = FAPI_BM_ERR_INVALID_HANDLE;
   }

   FAPI_SYS_PRINT_DEBUG(3, "FAPI_BM_GetInfo: res=%d\n", res);

   return res;
}


/* 21c126a0 - complete */
int32_t FAPI_BM_SetBufferPurpose(const FAPI_BM_PurposeT bufferPurpose,
                                 const uint32_t blockIndex,
                                 const uint32_t address,
                                 const uint32_t size)
{
   unsigned i;
   struct fapi_bm_bufferPurpose* r1;
   
   if (fapi_bm_initialized != 0)
   {
      return FAPI_BM_ERR_ALREADY_INITIALIZED;
   }
   
   if (bufferPurpose > 7)
   {
      return FAPI_BM_ERR_BAD_PARAMETER;
   }
   
   for (i = 0; i < 8; i++)
   {
      if (fapi_bm_bufferPurpose[i].bufferPurpose == bufferPurpose)
      {
         if (fapi_bm_bufferPurpose[i].assigned != 0)
         {
            return FAPI_BM_ERR_PURPOSE_ALREADY_ASSIGNED;
         }
         
         r1 = &fapi_bm_bufferPurpose[i];
         
         r1->assigned = 1;
         r1->blockIndex = blockIndex;
         r1->address = address;
         r1->size = size;
         
         if (i == 128)
         {
            return FAPI_BM_ERR_INVALID_PURPOSE;
         }
                  
         break;
      }
   }
   
   return 0;
}


/* 21c12760 - complete */
uint32_t FAPI_BM_GetAddressByBufferPurpose(const FAPI_BM_PurposeT bufferPurpose)
{
   unsigned i;
   uint32_t res = 0;
   
   if (bufferPurpose < 8)
   {
      for (i = 0; i < 8; i++)
      {
         if (fapi_bm_bufferPurpose[i].bufferPurpose == bufferPurpose)
         {
            if (fapi_bm_bufferPurpose[i].assigned == 1)
            {
               res = fapi_bm_bufferPurpose[i].address;
            }
            
            break;
         }
      }      
   }
   
   return res;
}


/* 21c127c4 - complete */
int32_t FAPI_BM_GetBlockIndexByBufferPurpose(const FAPI_BM_PurposeT bufferPurpose)
{
   unsigned i;
   int32_t res = -1;
   
   if (bufferPurpose < 8)
   {
      for (i = 0; i < 8; i++)
      {
         if (fapi_bm_bufferPurpose[i].bufferPurpose == bufferPurpose)
         {
            if (fapi_bm_bufferPurpose[i].assigned == 1)
            {
               res = fapi_bm_bufferPurpose[i].blockIndex;
            }
            
            break;
         }
      }      
   }
   
   return res;
}


/* 21c12828 - complete */
uint32_t FAPI_BM_GetSizeByBufferPurpose(const FAPI_BM_PurposeT bufferPurpose)
{
   unsigned i;
   uint32_t res = 0;
   
   if (bufferPurpose < 8)
   {
      for (i = 0; i < 8; i++)
      {
         if (fapi_bm_bufferPurpose[i].bufferPurpose == bufferPurpose)
         {
            if (fapi_bm_bufferPurpose[i].assigned == 1)
            {
               res = fapi_bm_bufferPurpose[i].size;
            }
            
            break;
         }
      }      
   }
   
   return res;
}


/* 21c129f0 - complete */
int32_t FAPI_BM_SetBufferWritePointer(const FAPI_SYS_HandleT handle,
                       const uint32_t writePtrPosition,
                       const uint32_t enableOutOfBounds)
{
   int32_t res = 0;
   struct fapi_bm_handle* a = handle;

   FAPI_SYS_PRINT_DEBUG(4, "FAPI_BM_SetBufferWritePointer\n");
   
   if (fapi_bm_check_handle(a))
   {
      if (enableOutOfBounds ||
            (writePtrPosition < a->openParams.size))
      {
         bmSetWrPtr(a->Data_8, a->Data_44, writePtrPosition);
      }
      else
      {
         res = FAPI_BM_ERR_PTR_OUTSIDE_BUFFER_BOUNDS;
      }
   }
   else
   {
      res = FAPI_BM_ERR_INVALID_HANDLE;
   }
   
   FAPI_SYS_PRINT_DEBUG(3, "FAPI_BM_SetBufferWritePointer: res=%d\n", res);
   
   return res;
}


/* 21c12964 - complete */
int32_t FAPI_BM_SetAudCallback(FAPI_SYS_HandleT handle,
                   const uint32_t audIndex,
                   const uint32_t searchPattern,
                   FAPI_BM_AudCallbackT callbackFunction,
                   void* optData)
{
   int32_t res = 0;
   struct fapi_bm_handle* a = handle;

   FAPI_SYS_PRINT_DEBUG(4, "FAPI_BM_SetAudCallback\n");
   
   if (fapi_bm_check_handle(a))
   {
      if (audIndex < 5)
      {
         if (callbackFunction != 0)
         {
            unsigned r2;
            
            if ((a->Data_8 == 0) || (a->Data_8 == 1))
            {
               r2 = 0;
            }
            else
            {
               r2 = 1;
            }
                        
            fapi_bm_audData[r2][audIndex].Data_0 = a->Data_44;
            fapi_bm_audData[r2][audIndex].searchPattern = searchPattern;
            fapi_bm_audData[r2][audIndex].callbackFunction = callbackFunction;
            fapi_bm_audData[r2][audIndex].optData = optData;
         }
         else
         {
            res = FAPI_BM_ERR_BAD_PARAMETER;
         }
      }
      else
      {
         res = FAPI_BM_ERR_BAD_PARAMETER;
      }
   }
   else
   {
      res = FAPI_BM_ERR_INVALID_HANDLE;
   }
   
   FAPI_SYS_PRINT_DEBUG(3, "FAPI_BM_SetAudCallback: res=%d\n", res);
   
   return res;
}


/* 21c13d7c - complete */
uint8_t* FAPI_BM_GetBufferReadPointer(const FAPI_SYS_HandleT handle)
{
   int readPtr;
   void* p = 0;   
   struct fapi_bm_handle* a = handle;
   
   if (fapi_bm_check_handle(a))
   {
      if ((a->Data_8 == Data_21f19ac8) && 
            (a->Data_44 < 8))
      {
         readPtr = bmGetRdPtr(a->Data_8, a->Data_44);
      }
      else
      {
         readPtr = a->readPtr;
      }
      
      readPtr += a->openParams.address + a->baseAddress;
         
      p = (void*) FAPI_SYS_GET_VIRTUAL_ADDRESS(readPtr);
   }
   
   return p;
}


/* 21c13d04 - complete */
uint32_t FAPI_BM_GetBufferReadPointerPosition(const FAPI_SYS_HandleT handle)
{
   uint32_t res = 0;
   
   struct fapi_bm_handle* a = handle;
   
   if (fapi_bm_check_handle(a))
   {
      if ((a->Data_8 == Data_21f19ac8) && 
            (a->Data_44 < 8))
      {
         res = bmGetRdPtr(a->Data_8, a->Data_44);
      }
      else
      {
         res = a->readPtr;
      }
   }
   
   return res;
}


/* 21c1406c - complete */
uint8_t* FAPI_BM_GetBufferWritePointer(const FAPI_SYS_HandleT handle)
{
   void* p = 0;
   struct fapi_bm_handle* a = handle;
   
   if (fapi_bm_check_handle(a))
   {
      int writePtr = bmGetWrPtr(a->Data_8, a->Data_44);
      
      writePtr += a->openParams.address + a->baseAddress;
         
      p = (void*) FAPI_SYS_GET_VIRTUAL_ADDRESS(writePtr);
   }
      
   return p;
}


/* 21c14018 - complete */
uint32_t FAPI_BM_GetBufferWritePointerPosition(const FAPI_SYS_HandleT handle)
{
   uint32_t res = 0;
   struct fapi_bm_handle* a = handle;
   
   if (fapi_bm_check_handle(a))
   {
      res = bmGetWrPtr(a->Data_8, a->Data_44);    
   }

   return res;
}


/* 21c13e1c - complete */
int32_t FAPI_BM_SetWriteSwap(const FAPI_SYS_HandleT handle, uint32_t swap)
{
   int32_t res = 0;
   struct fapi_bm_handle* a = handle;

   FAPI_SYS_PRINT_DEBUG(4, "FAPI_BM_SetWriteSwap\n");
   
   if (fapi_bm_check_handle(a))
   {
      if ((swap == 0) || (swap == 1))
      {
         uint32_t r0 = bmGetmEndianSwapWr(a->Data_8);
         
         r0 &= ~(1 << a->Data_44);
         r0 |= (swap << a->Data_44);
         
         bmSetEndianSwapWr(a->Data_8, r0);
      }
      else
      {
         res = FAPI_BM_ERR_BAD_PARAMETER;
      }
   }
   else
   {
      res = FAPI_BM_ERR_INVALID_HANDLE;
   }
   
   FAPI_SYS_PRINT_DEBUG(3, "FAPI_BM_SetWriteSwap: res=%d\n", res);
   
   return res;
}


/* 21c13b9c - complete */
int32_t FAPI_BM_StartAudFiltering(const FAPI_SYS_HandleT handle)
{
   unsigned r4;
   unsigned i;
   unsigned r2 = -1;
   int32_t res = 0;
   struct fapi_bm_handle* a = handle;

   FAPI_SYS_PRINT_DEBUG(4, "FAPI_BM_StartAudFiltering\n");

   if (fapi_bm_check_handle(a))
   {
      if ((a->Data_8 == 0) || (a->Data_8 == 1))
      {
         r4 = 0;
      }
      else
      {
         r4 = 1;
      }

      bmSetAudCfgEn(a->Data_8, 0);
      
      bmSetClearAudIrq(a->Data_8, 0);
      
      for (i = 0; i < 5; i++)
      {      
         if (fapi_bm_audData[r4][i].Data_0 == a->Data_44)
         {
            uint32_t r7 = ~(1 << i);
            
            if ((a->Data_8 == 1) || (a->Data_8 == 3))
            {
               bmSetAudCfgEn(a->Data_8, 
                     fapi_bm_audData[r4][i].Data_0 | 0x120);
            }
            else
            {
               bmSetAudCfgEn(a->Data_8, 
                     fapi_bm_audData[r4][i].Data_0 | 0x100);            
            }

            bmSetClearAudIrq(a->Data_8, r7);
            
            bmSetAudValue(a->Data_8, i, 
                  fapi_bm_audData[r4][i].searchPattern | 0x100);

            r2 = i;
         }
      }

      if (r2 == -1)
      {
         res = FAPI_BM_ERR_AUD_NOT_ASSIGNED;
      }
   }
   else
   {
      res = FAPI_BM_ERR_INVALID_HANDLE;
   }
   
   FAPI_SYS_PRINT_DEBUG(3, "FAPI_BM_StartAudFiltering: res=%d\n", res);
   
   return res;
}


/* 21c13a84 - complete */
int32_t FAPI_BM_StopAudFiltering(const FAPI_SYS_HandleT handle,
                                 const uint32_t audIndex)
{
   int r4;
   uint32_t r6;
   int32_t res = 0;
   struct fapi_bm_handle* a = handle;

   FAPI_SYS_PRINT_DEBUG(4, "FAPI_BM_StopAudFiltering\n");

   if (audIndex < 5)
   {
      if (fapi_bm_check_handle(a))
      {
         bmSetAudCfgEn(a->Data_8, 0);
         
         bmSetClearAudIrq(a->Data_8, 0);

         if ((a->Data_8 == 0) || (a->Data_8 == 1))
         {
            r4 = 0;
         }
         else
         {
            r4 = 1;
         }

         r6 = ~(1 << audIndex);
         
         bmSetAudCfgEn(a->Data_8, ~fapi_bm_audData[r4][audIndex].Data_0);
         
         bmSetClearAudIrq(a->Data_8, r6);

         bmSetAudValue(a->Data_8, audIndex, 0);
      }
      else
      {
         res = FAPI_BM_ERR_INVALID_HANDLE;
      }
   }
   else
   {
      res = FAPI_BM_ERR_BAD_PARAMETER;
   }      

   FAPI_SYS_PRINT_DEBUG(3, "FAPI_BM_StopAudFiltering: res=%d\n", res);
   
   return res;
}


struct fapi_bm_handle* fapi_bm_get_handle(uint32_t a)
{
   int i;
   struct fapi_bm_handle* h = 0;
   
   if (Data_21f19ae0[a].Data_4 != 32)
   {
      for (i = 127; i >= 0; i--)
      {
         if (!fapi_bm_handles[i].inUse)
         {
            fapi_bm_handles[i].inUse = 1;
            fapi_bm_handles[i].magic = 0x626d;
            fapi_bm_handles[i].Data_8 = a;

            Data_21f19ae0[a].Data_4++;

#if 1
            memset(&fapi_bm_handles[i].Data_80, 0, 16);
#else
            fapi_bm_handles[i].Data_80 = 0;
            fapi_bm_handles[i].Data_84 = 0;
            fapi_bm_handles[i].Data_88 = 0;
            fapi_bm_handles[i].Data_92 = 0;
#endif
            
            h = &fapi_bm_handles[i];
            break;
         }
      }
      
      FAPI_SYS_FlushDataCache((uint32_t)h, sizeof(struct fapi_bm_handle));
   }
      
   return h;
}


/* 21c1288c - complete */
int fapi_bm_check_handle(struct fapi_bm_handle* a)
{    
   if (a == 0)
   {
      return 0;
   }
   
   FAPI_SYS_InvalidateDataCache((int)a, sizeof(struct fapi_bm_handle));
   
   int res = 1;
   
   if ((fapi_bm_initialized == 0) ||
         (a->inUse == 0) ||
         (a->magic != 0x626d))
   {
      res = 0;
   }
   
   return res;
}


