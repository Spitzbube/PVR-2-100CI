
#define DEBUG 0


#include <fapi/sys_services.h>
#include <fapi/drv_gpio.h>
#include <fapi/drv_upi.h>
#include <fapi/drv_flash.h>
#include <fapi/drv_flash_priv.h>



FAPI_SYS_DriverT FAPI_FLASH_Driver = //21efa6ec
{
      "FLASH",
      -1,
      FAPI_SYS_BSR_EXEC_UNDEFINED,
      FAPI_FLASH_Init,
      FAPI_FLASH_Exit,
      0,
      0,
      0,
      0,
};



static FAPI_SYS_SemaphoreT flashSemaphore = 0; //21f21efc
static uint32_t flashInitialized = 0; //21f21ef8
static int Data_21efa6e0 = 0x80000000; //21efa6e0
static int Data_21efa6e4 = 0x80000000; //21efa6e4
static int Data_21efa6e8 = 0x80000000; //21efa6e8
static FAPI_SYS_HandleT flashNFlashUpiHandle; //21f21f34
static FAPI_SYS_HandleT flashPFlashUpiHandle; //21f21f30

static flashBlockT flashBlockArray[3] = //21b6a3e8
{
   {0, FAPI_FLASH_DEVICE_PFLASH, 0, 0,
    /*{func_21c1c75c, //pflashDetectChip
     * d8c6c121 //pflashEraseChip
     * dcc5c121 //pflashEraseSector
     * b0bdc121 //pflashReadSector
     * b0c3c121 //pflashWriteSector
     * ccbcc121 //pflashReadDirect
     * f8c1c121}*/}, //pflashWriteDirect

   {0, FAPI_FLASH_DEVICE_SFLASH, 0, 0,
   sflashDetectChip,
   sflashEraseChip,
   sflashEraseSector,
   sflashReadSector,
   sflashWriteSector,
   sflashReadDirect,
   sflashWriteDirect,
   },

   {0, FAPI_FLASH_DEVICE_NFLASH, 0, 0,
    /*{d0e1c121 //nflashDetectChip
     * 28dcc121 //nflashEraseChip
     * 7cdbc121 //nflashEraseSector
     * 0cd8c121 //nflashReadSector
     * 24dfc121 //nflashWriteSector
     * 5cd6c121 //nflashReadDirect
     * 44ddc121}*/}, //nflashWriteDirect
};

static FAPI_GPIO_OpenParamsT flashGpioParams[9] = //21efa794
{
   {FAPI_GPIO_VERSION, FAPI_GPIO_PIN_AUTODETECT, FAPI_GPIO_IN_SFLASH_DATA, 0},
   {FAPI_GPIO_VERSION, FAPI_GPIO_PIN_AUTODETECT, FAPI_GPIO_OUT_SFLASH_HOLD, 0},
   {FAPI_GPIO_VERSION, FAPI_GPIO_PIN_AUTODETECT, FAPI_GPIO_OUT_SFLASH_CS, 0},
   {FAPI_GPIO_VERSION, FAPI_GPIO_PIN_AUTODETECT, FAPI_GPIO_OUT_SFLASH_CLK, 0},
   {FAPI_GPIO_VERSION, FAPI_GPIO_PIN_AUTODETECT, FAPI_GPIO_OUT_SFLASH_DATA, 0},
   {FAPI_GPIO_VERSION, FAPI_GPIO_PIN_AUTODETECT, FAPI_GPIO_OUT_UPI_ADDRX0, 0},
   {FAPI_GPIO_VERSION, FAPI_GPIO_PIN_AUTODETECT, FAPI_GPIO_OUT_UPI_ADDRX1, 0},
   {FAPI_GPIO_VERSION, FAPI_GPIO_PIN_AUTODETECT, FAPI_GPIO_OUT_UPI_ADDRX2, 0},
   {FAPI_GPIO_VERSION, FAPI_GPIO_PIN_AUTODETECT, FAPI_GPIO_OUT_UPI_ADDRX3, 0},
};


struct Struct_21efa710;

struct fapi_flash_handle
{
   int magic; //0
   int inUse; //4
   FAPI_FLASH_OpenParamsT Data_8; //8
   struct Struct_21efa710* Data_32; //32
   int Data_36; //36
   int Data_40; //40
   uint32_t Data_44; //44
   uint32_t Data_48; //48
   //52
};


struct Struct_21efa9bc
{
   char* name; //0
   unsigned numPartitions; //4
   struct fapi_flash_partition
   {
      unsigned sectorCount; //0
      unsigned sectorSize; //4
      //8
   } partitions[5]; //8
   int manufacturerId; //48
   int Data_52; //52
   int fill_56; //56
   int fill_60; //60
   int fill_64; //64
   //68
};


struct Struct_21efa710_Inner_12
{
   int Data_0; //0
   unsigned totalSize; //4
   unsigned totalSectors; //8
   int Data_12; //12
   int Data_16; //16
   struct Struct_21efa9bc* chip; //20
   unsigned* sectorStart; //24
   unsigned* sectorBytes; //28
   char* sectorProtect; //32
   unsigned* buffer; //36
   int currSectorIndex; //40
   int currSectorStart; //44
   unsigned currSectorBytes; //48
   int Data_52; //52
   //56
};


struct Struct_21efa710
{
   int Data_0; //0
   int Data_4; //4
   FAPI_SYS_SemaphoreT semaphore; //8
   struct Struct_21efa710_Inner_12* Data_12; //12
   int (*detectChip)(struct Struct_21efa710_Inner_12**, int); //16
   int32_t (*eraseChip)(struct Struct_21efa710_Inner_12*, int); //20
   int32_t (*eraseSector)(struct Struct_21efa710_Inner_12*, int); //24
   int32_t (*readSector)(struct Struct_21efa710_Inner_12*, int); //28
   int (*writeSector)(struct Struct_21efa710_Inner_12*, int); //32
   int (*readDirect)(struct Struct_21efa710_Inner_12*,
         int, int, int, void*, int); //36
   int32_t (*writeDirect)(struct Struct_21efa710_Inner_12*,
         int, int, int, const void*, int); //40
   //44
};


int fapi_flash_enables[3]; //21f21f00
int fapi_flash_upi_index[3]; //21f21eec
void* fapi_flash_gpio_handles[9]; //21f21f0c
flashHandleT flashHandleArray[16]; //21f21f38


static void func_21c1a4bc(void);
static int fapi_flash_open_gpio(void);
static void fapi_flash_close_gpio(void);
static void func_214e2338(void);
/*static*/ int32_t flashFlushBuffer(struct Struct_21efa710*, int);
static void fapi_flash_release_handle(struct fapi_flash_handle*);
static struct fapi_flash_handle* fapi_flash_get_handle(struct Struct_21efa710*);
static int flashAllocateExtGpioAddressPins(unsigned a);
static int func_214e2168(struct fapi_flash_handle*);
int32_t fapi_flash_read_sector(struct Struct_21efa710*);



/* 21c19ee8 - complete */
void FAPI_FLASH_SetEnable(uint32_t deviceType, uint32_t enableFlag)
{
   if (deviceType <= 2)
   {
      if (enableFlag != 0)
      {
         fapi_flash_enables[deviceType] = 1;
      }
      else
      {
         fapi_flash_enables[deviceType] = 0;
      }
   }
}


/* 21c19f10 - complete */
void FAPI_FLASH_SetUpiIndex( uint32_t deviceType, uint32_t upiIndex )
{
   if ((deviceType == FAPI_FLASH_DEVICE_PFLASH) || 
         (deviceType == FAPI_FLASH_DEVICE_NFLASH))
   {
      if (upiIndex <= 2)
      {
         fapi_flash_upi_index[deviceType] = upiIndex;
      }
   }
}


/* 21c1b2f4 - complete */
int32_t FAPI_FLASH_Init(void)
{
   FAPI_UPI_OpenParamsT sp;
   uint32_t i;

   if (flashInitialized != 0)
   {
      return FAPI_FLASH_ERR_ALREADY_INITIALIZED;
   }

   flashSemaphore = FAPI_SYS_CREATE_SEMAPHORE(1);

   if (flashSemaphore == 0)
   {
      return FAPI_FLASH_ERR_SEMAPHORE_CREATE;
   }

   for (i = 0; i < 3; i++)
   {
      flashBlockArray[i].inUse = 0;
      flashBlockArray[i].devicePtr = 0;
      flashBlockArray[i].semaphore = FAPI_SYS_CREATE_SEMAPHORE(1);

      if (flashBlockArray[i].semaphore == 0)
      {
         func_21c1a4bc();

         FAPI_SYS_DESTROY_SEMAPHORE(flashSemaphore);

         flashSemaphore = 0;

         return FAPI_FLASH_ERR_SEMAPHORE_CREATE;
      }
   }

   for (i = 0; i < 16; i++)
   {
      memset(&flashHandleArray[i], 0, sizeof(flashHandleT));

      flashHandleArray[i].id = 0x666c7368; //flsh
   }

   if (fapi_flash_enables[FAPI_FLASH_DEVICE_SFLASH] == 1)
   {
      if (0 == fapi_flash_open_gpio())
      {
         fapi_flash_close_gpio();

         return 0;
      }
   } //if (fapi_flash_enables[FAPI_FLASH_DEVICE_SFLASH] == 1)

   if (fapi_flash_enables[FAPI_FLASH_DEVICE_PFLASH] == 1)
   {
      Data_21efa6e0 = (fapi_flash_upi_index[FAPI_FLASH_DEVICE_PFLASH] << 27)
         + 0x80000000;

      sp.version = FAPI_UPI_VERSION;
      sp.index = fapi_flash_upi_index[FAPI_FLASH_DEVICE_PFLASH];

      flashPFlashUpiHandle = FAPI_UPI_Open(&sp, 0);

      if (flashPFlashUpiHandle == 0)
      {
         return 0;
      }

      if (0 != FAPI_UPI_SetDefaults(flashPFlashUpiHandle, FAPI_UPI_DEFAULTS_FLASH))
      {
         return 0;
      }
   } //if (fapi_flash_enables[FAPI_FLASH_DEVICE_PFLASH] == 1)

   if (fapi_flash_enables[FAPI_FLASH_DEVICE_NFLASH] == 1)
   {
      Data_21efa6e4 = (fapi_flash_upi_index[FAPI_FLASH_DEVICE_NFLASH] << 27)
         + 0x80000000;

      sp.version = FAPI_UPI_VERSION;
      sp.index = fapi_flash_upi_index[FAPI_FLASH_DEVICE_NFLASH];

      flashNFlashUpiHandle = FAPI_UPI_Open(&sp, 0);

      if (flashNFlashUpiHandle == 0)
      {
         return 0;
      }

      Data_21efa6e8 = Data_21efa6e4;

      if (0 != FAPI_UPI_SetDefaults(flashNFlashUpiHandle, FAPI_UPI_DEFAULTS_NFLASH))
      {
         return 0;
      }
   } //if (fapi_flash_enables[FAPI_FLASH_DEVICE_NFLASH] == 1)

   flashInitialized = 1;

   return 0;
}


/* 21c1b190 - complete */
void FAPI_FLASH_Exit(void)
{
   if (flashInitialized != 0)
   {
      uint32_t i;

      for (i = 0; i < 16; i++)
      {
         FAPI_FLASH_Close(&flashHandleArray[i]);
      }

      FAPI_SYS_GET_SEMAPHORE(flashSemaphore, FAPI_SYS_SUSPEND);

      func_214e2338();
      fapi_flash_close_gpio();
      func_21c1a4bc();

      FAPI_UPI_Close(flashPFlashUpiHandle);
      FAPI_UPI_Close(flashNFlashUpiHandle);

      FAPI_SYS_SET_SEMAPHORE(flashSemaphore, FAPI_SYS_NO_SUSPEND);

      FAPI_SYS_DESTROY_SEMAPHORE(flashSemaphore);

      flashSemaphore = 0;
      flashInitialized = 0;
   }
}


/* 218add24 - todo */
FAPI_SYS_HandleT FAPI_FLASH_Open(const FAPI_FLASH_OpenParamsT* paramsPtr, int32_t* errorCodePtr )
{   
   struct Struct_21efa710* r6;
   uint32_t i;
   unsigned r3; // = 0;   
   int sp3;
   int (*detectChip)(struct Struct_21efa710_Inner_12**, int);
   struct fapi_flash_handle* h;
   int32_t res = 0;
   
   FAPI_SYS_PRINT_DEBUG(4, "FAPI_FLASH_Open()\n");
   
   if (flashInitialized == 0)
   {
      res = FAPI_FLASH_ERR_NOT_INITIALIZED;
      if (errorCodePtr != 0)
      {
         *errorCodePtr = res;
      }
      return 0;
   }

   FAPI_SYS_PRINT_DEBUG(5, "FAPI_FLASH_Open(): 1\n");

   if (paramsPtr == 0)
   {
      res = FAPI_FLASH_ERR_BAD_PARAMETER;
      if (errorCodePtr != 0)
      {
         *errorCodePtr = res;
      }
      return 0;
   }
   
   FAPI_SYS_PRINT_DEBUG(5, "FAPI_FLASH_Open(): 2\n");

   if ((paramsPtr->deviceType != FAPI_FLASH_DEVICE_PFLASH) &&
         (paramsPtr->deviceType != FAPI_FLASH_DEVICE_SFLASH) &&
         (paramsPtr->deviceType != FAPI_FLASH_DEVICE_NFLASH))
   {
      res = FAPI_FLASH_ERR_BAD_PARAMETER;
      if (errorCodePtr != 0)
      {
         *errorCodePtr = res;
      }
      return 0;
   }
   
   FAPI_SYS_PRINT_DEBUG(5, "FAPI_FLASH_Open(): 3\n");

   if (paramsPtr->version > FAPI_FLASH_VERSION)
   {
      res = FAPI_FLASH_ERR_UNSUPPORTED_VERSION;
      if (errorCodePtr != 0)
      {
         *errorCodePtr = res;
      }
      return 0;
   }
   
   FAPI_SYS_PRINT_DEBUG(5, "FAPI_FLASH_Open(): 4\n");
   
   FAPI_SYS_GET_SEMAPHORE(flashSemaphore, FAPI_SYS_SUSPEND);
      
   if (fapi_flash_enables[paramsPtr->deviceType] != 1)
   {
      FAPI_SYS_SET_SEMAPHORE(flashSemaphore, FAPI_SYS_NO_SUSPEND);
      
      res = FAPI_FLASH_ERR_DEVICE_NOT_SUPPORTED;
      if (errorCodePtr != 0)
      {
         *errorCodePtr = res;
      }
      return 0;
   }

   FAPI_SYS_PRINT_DEBUG(5, "FAPI_FLASH_Open(): 5\n");

   r6 = &flashBlockArray[paramsPtr->deviceType];
      
   if ((r6->detectChip == 0) ||
         (r6->eraseChip == 0) ||
         (r6->eraseSector == 0) ||
         (r6->readSector == 0) ||
         (r6->writeSector == 0))
   {
      FAPI_SYS_SET_SEMAPHORE(flashSemaphore, FAPI_SYS_NO_SUSPEND);
      
      res = FAPI_FLASH_ERR_INVALID_FUNCTION;
      if (errorCodePtr != 0)
      {
         *errorCodePtr = res;
      }
      return 0;
   }
   
   FAPI_SYS_PRINT_DEBUG(5, "FAPI_FLASH_Open(): 6\n");

   if (r6->Data_12 == 0)
   {
      detectChip = r6->detectChip;
      
      //if (paramsPtr->deviceType == FAPI_FLASH_DEVICE_PFLASH)
      {
         FAPI_UPI_Lock();
      }
      
      res = (detectChip)(&r6->Data_12, 2000);
      
      //if (paramsPtr->deviceType == FAPI_FLASH_DEVICE_PFLASH)
      {
         FAPI_UPI_Unlock();
      }
      
      if (res != 0)
      {
         FAPI_SYS_SET_SEMAPHORE(flashSemaphore, FAPI_SYS_NO_SUSPEND);
         
         if (errorCodePtr != 0)
         {
            *errorCodePtr = res;
         }
         return 0;
      }
      
      if (paramsPtr->deviceType == FAPI_FLASH_DEVICE_PFLASH)
      {
         if (0 == flashAllocateExtGpioAddressPins(r6->Data_12->totalSize))
         {
            FAPI_SYS_SET_SEMAPHORE(flashSemaphore, FAPI_SYS_NO_SUSPEND);

            res = FAPI_FLASH_ERR_EXT_ADDRESS_FAILED;
            if (errorCodePtr != 0)
            {
               *errorCodePtr = res;
            }
            return 0;
         }
      }

      if (r6->Data_12 == 0)
      {
         FAPI_SYS_SET_SEMAPHORE(flashSemaphore, FAPI_SYS_NO_SUSPEND);

         res = FAPI_FLASH_ERR_INVALID_DEVICE;
         if (errorCodePtr != 0)
         {
            *errorCodePtr = res;
         }
         return 0;
      }
   } //if (r6->Data_12 == 0)

   FAPI_SYS_PRINT_DEBUG(5, "FAPI_FLASH_Open(): 7\n");

   h = fapi_flash_get_handle(r6);
   
   if (0 == flashCheckHandle(h))
   {
      FAPI_SYS_SET_SEMAPHORE(flashSemaphore, FAPI_SYS_NO_SUSPEND);

      res = FAPI_FLASH_ERR_INVALID_HANDLE;
      if (errorCodePtr != 0)
      {
         *errorCodePtr = res;
      }
      return 0;
   }
   
   FAPI_SYS_PRINT_DEBUG(5, "FAPI_FLASH_Open(): 8\n");

   memcpy(&h->Data_8, paramsPtr, sizeof(FAPI_FLASH_OpenParamsT));
   
   if (0 == func_214e2168(h))
   {
      fapi_flash_release_handle(h);
      
      FAPI_SYS_SET_SEMAPHORE(flashSemaphore, FAPI_SYS_NO_SUSPEND);

      res = FAPI_FLASH_ERR_OVERLAP_DETECTED;
      if (errorCodePtr != 0)
      {
         *errorCodePtr = res;
      }
      return 0;      
   }
   
   FAPI_SYS_PRINT_DEBUG(5, "FAPI_FLASH_Open(): 9\n");

   FAPI_SYS_SET_SEMAPHORE(flashSemaphore, FAPI_SYS_NO_SUSPEND);
   
   FAPI_FLASH_ReadBytes(h, 0, 1, &sp3);
   
   h->Data_44 = h->Data_8.firstSector;
   
   if (h->Data_8.sectorCount == 0)
   {
      h->Data_48 = h->Data_32->Data_12->totalSectors;
   }
   else
   {
      h->Data_48 = h->Data_8.sectorCount;
   }
   
   r3 = 0;
   
   for (i = h->Data_44; i < h->Data_48; i++)
   {
      r3 += h->Data_32->Data_12->sectorBytes[i];
   }
   
   h->Data_36 = r3 / 512;
   h->Data_40 = 512;
   
   res = 0;
   
   if (errorCodePtr != 0)
   {
      *errorCodePtr = res;
   }
   
   return h;
}


/* 21c1aa18 - complete */
int32_t FAPI_FLASH_Close(FAPI_SYS_HandleT handle)
{
   struct fapi_flash_handle* h = handle;
   int32_t res = 0;
   
   FAPI_SYS_GET_SEMAPHORE(flashSemaphore, FAPI_SYS_SUSPEND);
   
   if (0 != flashCheckHandle(h))
   {
      flashFlushBuffer(h->Data_32, (h->Data_8.forceFlush != 0)? 1: 0);
      
      fapi_flash_release_handle(h);
   }
   else
   {
      res = FAPI_FLASH_ERR_INVALID_HANDLE;
   }
   
   FAPI_SYS_SET_SEMAPHORE(flashSemaphore, FAPI_SYS_NO_SUSPEND);
   
   return res;
}


/* 21c1a950 - complete */
int32_t FAPI_FLASH_EraseChip(FAPI_SYS_HandleT handle)
{
   struct Struct_21efa710* r6;
   int32_t (*eraseChip)(struct Struct_21efa710_Inner_12*, int);
   struct Struct_21efa710_Inner_12* r5;
   int32_t res;
   struct fapi_flash_handle* a = handle;
   
   if (0 == flashCheckHandle(a))
   {
      return FAPI_FLASH_ERR_BAD_PARAMETER;
   }
   
   r6 = a->Data_32;
   eraseChip = r6->eraseChip;
   
   if (eraseChip == 0)
   {
      return FAPI_FLASH_ERR_BAD_PARAMETER;
   }

   r5 = r6->Data_12;
   
   //if (r6->Data_4 == 0)
   {
      FAPI_UPI_Lock();
   }
   
   res = (eraseChip)(r5, 10000);
   
   //if (r6->Data_4 == 0)
   {
      FAPI_UPI_Unlock();
   }
   
   if (res == 0)
   {
      r5->currSectorIndex = 0;
      r5->currSectorBytes = r5->sectorBytes[r5->currSectorIndex];
      r5->currSectorStart = r5->sectorStart[r5->currSectorIndex];
      
      fapi_flash_read_sector(r6);
   }
   
   return res;
}


/* 21c1aaa8 - complete */
int32_t FAPI_FLASH_EraseSector(FAPI_SYS_HandleT handle, uint32_t sectorIndex)
{
   int32_t res;
   struct Struct_21efa710* r7;
   int32_t (*eraseSector)(struct Struct_21efa710_Inner_12*, int);
   struct Struct_21efa710_Inner_12* sl;
   struct fapi_flash_handle* a = handle;
   
   if (0 == flashCheckHandle(a))
   {
      return FAPI_FLASH_ERR_BAD_PARAMETER;
   }
   
   r7 = a->Data_32;
   eraseSector = r7->eraseSector;
   
   if (eraseSector == 0)
   {
      return FAPI_FLASH_ERR_BAD_PARAMETER;
   }
   
   sl = r7->Data_12;
   
   if (sectorIndex >= sl->totalSectors)
   {
      return FAPI_FLASH_ERR_BAD_PARAMETER;
   }
   
   res = flashFlushBuffer(r7, 0);
   
   if (res != 0)
   {
      return res;
   }
   
   sl->currSectorIndex = sectorIndex;
   sl->currSectorBytes = sl->sectorBytes[sectorIndex];
   sl->currSectorStart = sl->sectorStart[sectorIndex];
   
   //if (r7->Data_4 == 0)
   {
      FAPI_UPI_Lock();
   }
   
   res = (eraseSector)(sl, 10000);
   
   //if (r7->Data_4 == 0)
   {
      FAPI_UPI_Unlock();
   }
   
   if ((res == 0) && (sl->currSectorIndex == sectorIndex))
   {
      sl->currSectorBytes = sl->sectorBytes[sl->currSectorIndex];
      sl->currSectorStart = sl->sectorStart[sl->currSectorIndex];
   }
   
   fapi_flash_read_sector(r7);
   
   if (a->Data_8.fsysFlag != 0)
   {
      memset(sl->buffer, 0, sl->currSectorBytes);
      
      sl->Data_52 = 1;
   }
   
   return res;
}


/* 21c1a828 - complete */
int32_t FAPI_FLASH_ReadBytes(FAPI_SYS_HandleT handle, uint32_t address, uint32_t byteCount, void* bufferPtr)
{
   int32_t res;
   struct Struct_21efa710* sl;
   struct Struct_21efa710_Inner_12* r7;
   char* buffer;
   struct fapi_flash_handle* a = handle;
   char* r9;
   
   if (0 == flashCheckHandle(a))
   {
      return FAPI_FLASH_ERR_BAD_PARAMETER;
   }
   
   if (bufferPtr == 0)
   {
      return FAPI_FLASH_ERR_BAD_PARAMETER;
   }
   
   r9 = bufferPtr;
   sl = a->Data_32;
   r7 = sl->Data_12;
   
   if ((address + byteCount) > r7->totalSize)
   {
      return FAPI_FLASH_ERR_BAD_PARAMETER;
   }
   
   buffer = (void*) r7->buffer;
   
   while (byteCount != 0)
   {
      unsigned r0;
      unsigned r1;
      unsigned sectorIndex = FAPI_FLASH_GetSectorIndex(a, address);
      
      if (sectorIndex != r7->currSectorIndex)
      {
         if (r7->Data_52 != 0)
         {
            res = flashFlushBuffer(sl, 0);
            if (res != 0)
            {
               return res;
            }
         }

         r7->currSectorIndex = sectorIndex;
         r7->currSectorBytes = r7->sectorBytes[sectorIndex];
         r7->currSectorStart = r7->sectorStart[sectorIndex];
         
         res = fapi_flash_read_sector(sl);
         if (res != 0)
         {
            return res;
         }
      }

      r0 = r7->currSectorBytes;
      r1 = address - r7->currSectorStart;
      
      while ((byteCount != 0) && (r1 < r0))
      {
         *r9++ = buffer[r1++];
         byteCount--;
         address++;
      }
   }

   return 0;
}


/* 21c1a6f8 - complete */
int32_t FAPI_FLASH_WriteBytes(FAPI_SYS_HandleT handle, uint32_t address, uint32_t byteCount, const void* bufferPtr)
{
   int32_t res;
   struct Struct_21efa710* sl;
   struct Struct_21efa710_Inner_12* r7;
   char* buffer;
   struct fapi_flash_handle* a = handle;
   const char* r9;
   
   if (0 == flashCheckHandle(a))
   {
      return FAPI_FLASH_ERR_BAD_PARAMETER;
   }
   
   if (bufferPtr == 0)
   {
      return FAPI_FLASH_ERR_BAD_PARAMETER;
   }
   
   r9 = bufferPtr;
   sl = a->Data_32;
   r7 = sl->Data_12;
   
   if ((address + byteCount) > r7->totalSize)
   {
      return FAPI_FLASH_ERR_BAD_PARAMETER;
   }
   
   buffer = (void*) r7->buffer;
   
   while (byteCount != 0)
   {
      unsigned r0, r1;
      unsigned sectorIndex = FAPI_FLASH_GetSectorIndex(a, address);
      
      if (r7->currSectorIndex != sectorIndex)
      {
         if (r7->Data_52 != 0)
         {
            res = flashFlushBuffer(sl, 0);
            if (res != 0)
            {
               return res;
            }
         }

         r7->currSectorIndex = sectorIndex;
         r7->currSectorBytes = r7->sectorBytes[sectorIndex];
         r7->currSectorStart = r7->sectorStart[sectorIndex];
         
         res = fapi_flash_read_sector(sl);
         if (res != 0)
         {
            return res;
         }
      }

      r0 = r7->currSectorBytes;
      r1 = address - r7->currSectorStart;
      
      while ((byteCount != 0) && (r1 < r0))
      {
         buffer[r1++] = *r9++;
         byteCount--;
         address++;
         
         r7->Data_52 = 1;
      }
   }

   return 0;
}


/* 21c1a6c8 - complete */
int32_t FAPI_FLASH_Flush( FAPI_SYS_HandleT handle )
{
   struct fapi_flash_handle* a = handle;

   if (flashCheckHandle(a))
   {
      return flashFlushBuffer(a->Data_32, 1);
   }
   else
   {
      return FAPI_FLASH_ERR_BAD_PARAMETER;
   }
}


/* 21c1a254 - complete */
int32_t FAPI_FLASH_GetDeviceSize(FAPI_SYS_HandleT handle)
{
   struct fapi_flash_handle* a = handle;
   
   if (flashCheckHandle(a))
   {
      return a->Data_32->Data_12->totalSize;
   }
   else
   {
      return 0;
   }
}


/* 21c1a234 - complete */
int32_t FAPI_FLASH_GetDeviceId(FAPI_SYS_HandleT handle)
{
   struct fapi_flash_handle* a = handle;
   
   if (flashCheckHandle(a))
   {
      return a->Data_32->Data_12->Data_0;
   }
   else
   {
      return 0;
   }
}


/* 21c1a210 - complete */
int32_t FAPI_FLASH_GetManufacturerId(FAPI_SYS_HandleT handle)
{
   struct fapi_flash_handle* a = handle;
   
   if (flashCheckHandle(a))
   {
      return a->Data_32->Data_12->chip->manufacturerId;
   }
   else
   {
      return 0;
   }
}


/* 21c1a188 - complete */
const char_t* FAPI_FLASH_GetDeviceName(FAPI_SYS_HandleT handle)
{
   struct fapi_flash_handle* a = handle;
   
   if (flashCheckHandle(a))
   {
      return a->Data_32->Data_12->chip->name;
   }
   else
   {
      return 0;
   }
}


struct
{
   int id;
   char* name;
} 
fapiFlashManufacturerIdStrArray[] = //21e0014c
{
   {0x00, "unknown"},
   {0x01, "Spansion"},
   {0x04, "Fujitsu"},
   {0x1f, "Atmel"},
   {0x20, "STMicro"},
   {0xc2, "Macronix"},
   {0x4a, "ExelSemi"},
   {0xec, "Samsung"}
};


/* 21c1a1ac - complete */
const char_t* FAPI_FLASH_GetManufacturerName(FAPI_SYS_HandleT handle)
{
   unsigned i;
   struct fapi_flash_handle* a = handle;
   
   if (flashCheckHandle(a))
   {
      int id = a->Data_32->Data_12->chip->manufacturerId;
      
      for (i = 0; i < 8; i++)
      {
         if (fapiFlashManufacturerIdStrArray[i].id == id)
         {
            return fapiFlashManufacturerIdStrArray[i].name;
         }
      }
      
      return fapiFlashManufacturerIdStrArray[0].name;
   }
   else
   {
      return 0;
   }   
}


/* 21c1a160 - complete */
int32_t FAPI_FLASH_GetSectorCount(FAPI_SYS_HandleT handle)
{
   struct fapi_flash_handle* a = handle;
   
   if (flashCheckHandle(a))
   {
      return a->Data_32->Data_12->totalSectors;
   }
   else
   {
      return FAPI_FLASH_ERR_BAD_PARAMETER;
   }
}


/* 21c1a0b8 - complete */
int32_t FAPI_FLASH_GetSectorIndex(FAPI_SYS_HandleT handle, uint32_t address)
{
   uint32_t i;
   struct fapi_flash_handle* a = handle;
   
   if (flashCheckHandle(a))
   {
      struct Struct_21efa710_Inner_12* r1 = a->Data_32->Data_12;
      unsigned* r6 = r1->sectorStart;
      
      if (r6[0] > address)
      {
         return FAPI_FLASH_ERR_BAD_PARAMETER;
      }

      unsigned r7 = r1->totalSectors;

      if ((FAPI_FLASH_GetSectorBytes(a, r7 - 1) + r6[r7 - 1]) > address)
      {
         for (i = 1; i < r7; i++)
         {
            if (r6[i] > address)
            {
               break;
            }
         }
      }
      else
      {
         return FAPI_FLASH_ERR_BAD_PARAMETER;
      }      
   }
   else
   {
      return FAPI_FLASH_ERR_BAD_PARAMETER;
   }
   
   return i - 1;
}


/* 21c1a074 - complete */
int32_t FAPI_FLASH_GetSectorStart(FAPI_SYS_HandleT handle, uint32_t sectorIndex)
{
   struct fapi_flash_handle* h = handle;
      
   if (flashCheckHandle(h))
   {
      if (sectorIndex < h->Data_32->Data_12->totalSectors)
      {
         return h->Data_32->Data_12->sectorStart[sectorIndex];
      }
      else
      {
         return FAPI_FLASH_ERR_BAD_PARAMETER; 
      }
   }
   else 
   {
      return FAPI_FLASH_ERR_BAD_PARAMETER; 
   }
}


/* 21c1a030 - complete */
int32_t FAPI_FLASH_GetSectorBytes(FAPI_SYS_HandleT handle, uint32_t sectorIndex)
{
   struct fapi_flash_handle* h = handle;
   
   if (flashCheckHandle(h))
   {
      if (sectorIndex < h->Data_32->Data_12->totalSectors)
      {
         return h->Data_32->Data_12->sectorBytes[sectorIndex];
      }
      else
      {
         return FAPI_FLASH_ERR_BAD_PARAMETER;
      }
   }
   else
   {
      return FAPI_FLASH_ERR_BAD_PARAMETER;
   }
}


/* 21c1a5c8 - complete */
int32_t FAPI_FLASH_IsSectorEmpty(FAPI_SYS_HandleT handle, uint32_t sectorIndex)
{
   uint32_t i;
   struct fapi_flash_handle* a = handle;

   if (0 == flashCheckHandle(a))
   {
      return FAPI_FLASH_ERR_BAD_PARAMETER;
   }
   else
   {
      struct Struct_21efa710* r5 = a->Data_32;
      struct Struct_21efa710_Inner_12* r4 = r5->Data_12;
      char* r7 = (void*) r4->buffer;
   
      flashFlushBuffer(r5, 0);
      
      r4->currSectorIndex = sectorIndex;
      r4->currSectorBytes = r4->sectorBytes[sectorIndex];
      r4->currSectorStart = r4->sectorStart[sectorIndex];
      
      fapi_flash_read_sector(r5);
      
      for (i = 0; i < r4->currSectorBytes; i++)
      {
         if (r7[i] != 0xFF)
         {
            return 0;
         }
      }
      
      return 1;
   }
}


/* 21c1a66c - complete */
int32_t FAPI_FLASH_IsChipEmpty(FAPI_SYS_HandleT handle)
{
   uint32_t i;
   struct fapi_flash_handle* a = handle;

   if (0 == flashCheckHandle(a))
   {
      return FAPI_FLASH_ERR_BAD_PARAMETER;
   }
   else
   {
      struct Struct_21efa710* r3 = a->Data_32;
      struct Struct_21efa710_Inner_12* r2 = r3->Data_12;
      unsigned r5 = r2->totalSectors;
      
      for (i = 0; i < r5; i++)
      {
         if (0 == FAPI_FLASH_IsSectorEmpty(a, i))
         {
            return 0;
         }
      }
      
      return 1;
   }
}


/* 21c1a000 - complete */
int32_t FAPI_FLASH_IsSectorProtected(FAPI_SYS_HandleT handle, uint32_t sectorIndex)
{
   struct fapi_flash_handle* a = handle;
   
   if (flashCheckHandle(a))
   {
      return a->Data_32->Data_12->sectorProtect[sectorIndex];
   }
   else
   {
      return FAPI_FLASH_ERR_BAD_PARAMETER;
   }   
}


/* 21c19fbc - complete */
int32_t FAPI_FLASH_ProtectSector(FAPI_SYS_HandleT handle, uint32_t sectorIndex, uint32_t flag)
{
   struct fapi_flash_handle* a = handle;
   
   if (flashCheckHandle(a))
   {
      a->Data_32->Data_12->sectorProtect[sectorIndex] = flag? 1: 0;
      
      return 0;
   }
   else
   {
      return FAPI_FLASH_ERR_BAD_PARAMETER;
   }   
}


/* 21c1a390 - complete */
int32_t FAPI_FLASH_ReadBytesDirect(FAPI_SYS_HandleT handle, uint32_t address, uint32_t byteCount, void* bufferPtr)
{
   struct Struct_21efa710* r1;
   struct Struct_21efa710_Inner_12* r8;
   int (*readDirect)(struct Struct_21efa710_Inner_12*, 
                     int, int, int, void*, int);
   char* buffer;
   char* sl;
   int32_t res = 0;
   struct fapi_flash_handle* a = handle;
   
   if (0 == flashCheckHandle(a))
   {
      return FAPI_FLASH_ERR_BAD_PARAMETER;
   }
   
   if (bufferPtr == 0)
   {
      return FAPI_FLASH_ERR_BAD_PARAMETER;
   }
   
   if (byteCount & 3)
   {
      return FAPI_FLASH_ERR_BAD_PARAMETER;
   }
   
   if (address & 3)
   {
      return FAPI_FLASH_ERR_BAD_PARAMETER;
   }
   
   r1 = a->Data_32;
   r8 = r1->Data_12;
   
   if ((address + byteCount) > r8->totalSize)
   {
      return FAPI_FLASH_ERR_BAD_PARAMETER;
   }
   
   readDirect = r1->readDirect;
   
   buffer = (void*) r8->buffer;
   
   if (readDirect == 0)
   {
      return FAPI_FLASH_ERR_BAD_PARAMETER;
   }
   
   sl = bufferPtr;
   
   while (byteCount > 0)
   {      
      unsigned sectorIndex = FAPI_FLASH_GetSectorIndex(a, address);
      
      int offset = address - FAPI_FLASH_GetSectorStart(handle, sectorIndex);
      
      if (r8->currSectorIndex == sectorIndex)
      {
         unsigned ip = r8->currSectorBytes;
         unsigned i = address - r8->currSectorStart;
         
         while ((byteCount > 0) && (i < ip))
         {
            *sl++ = buffer[i++];
            byteCount--;
            address++;
         }
      }
      else
      {
         res = (readDirect)(r8, sectorIndex, offset, byteCount, sl, 10000);
         if (res != 0) 
         {
            break;
         }

         byteCount = 0;
      }
   }
   
   return res;
}


/* 21c1a274 - complete */
int32_t FAPI_FLASH_WriteBytesDirect(FAPI_SYS_HandleT handle, uint32_t address, uint32_t byteCount, const void* bufferPtr)
{
   struct Struct_21efa710* r1;
   struct Struct_21efa710_Inner_12* r8;
   int32_t (*writeDirect)(struct Struct_21efa710_Inner_12*, 
                     int, int, int, const void*, int);
   char* buffer;
   unsigned sectorIndex;
   int offset;
   int32_t res = 0;
   const char* sl = bufferPtr;
   struct fapi_flash_handle* a = handle;
   
   if (0 == flashCheckHandle(a))
   {
      return FAPI_FLASH_ERR_BAD_PARAMETER;
   }
   
   if (bufferPtr == 0)
   {
      return FAPI_FLASH_ERR_BAD_PARAMETER;
   }
   
   if (byteCount & 3)
   {
      return FAPI_FLASH_ERR_BAD_PARAMETER;
   }
   
   if (address & 3)
   {
      return FAPI_FLASH_ERR_BAD_PARAMETER;
   }
   
   r1 = a->Data_32;
   r8 = r1->Data_12;
   
   if ((address + byteCount) > r8->totalSize)
   {
      return FAPI_FLASH_ERR_BAD_PARAMETER;
   }
   
   writeDirect = r1->writeDirect;
   
   buffer = (void*) r8->buffer;
   
   if (writeDirect == 0)
   {
      return FAPI_FLASH_ERR_BAD_PARAMETER;
   }
      
   sectorIndex = FAPI_FLASH_GetSectorIndex(a, address);
   
   offset = address - FAPI_FLASH_GetSectorStart(a, sectorIndex);
   
   res = (writeDirect)(r8, sectorIndex, offset, byteCount, sl, 20000);
   if (res != 0) 
   {
      return res;
   }
   
   if (r8->currSectorIndex == sectorIndex)
   {
      unsigned lr = r8->currSectorBytes;
      unsigned i = address - r8->currSectorStart;
      
      while ((byteCount > 0) && (i < lr))
      {
         buffer[i++] = *sl++;
         byteCount--;
         address++;
      }
   }
   
   return res;
}


/* 21c1a508 - complete */
int32_t fapi_flash_read_sector(struct Struct_21efa710* a)
{
   int32_t res;
   struct Struct_21efa710_Inner_12* r5 = a->Data_12;
   int32_t (*readSector)(struct Struct_21efa710_Inner_12*, int) = a->readSector;
   
   //if (a->Data_4 == 0)
   {
      FAPI_UPI_Lock();
   }
   
   res = (readSector)(r5, 10000);
   
   //if (a->Data_4 == 0)
   {
      FAPI_UPI_Unlock();
   }

   if (res != 0)
   {
      return res;
   }

   r5->Data_52 = 0;

   return 0;
}


/* 21c1a4bc - complete */
void func_21c1a4bc(void)
{
   uint32_t i;

   for (i = 0; i < 3; i++)
   {
      flashBlockArray[i].inUse = 0;
      flashBlockArray[i].devicePtr = 0;

      FAPI_SYS_DESTROY_SEMAPHORE(flashBlockArray[i].semaphore);

      flashBlockArray[i].semaphore = 0;
   }
}


int fapi_flash_open_gpio(void)
{
   uint32_t i;
   uint32_t numGpio = 5;
   int res = 1;

   for (i = 0; i < numGpio; i++)
   {
      fapi_flash_gpio_handles[i] = FAPI_GPIO_Open(&flashGpioParams[i], 0);

      if (fapi_flash_gpio_handles[i] == 0)
      {
         res = 0;
         break;
      }
   }
   return res;
}


/* 21c1b154 - complete */
void fapi_flash_close_gpio(void)
{
   uint32_t i;

   for (i = 0; i < 9; i++)
   {
      if (fapi_flash_gpio_handles[i] != 0)
      {
         FAPI_GPIO_Close(fapi_flash_gpio_handles[i]);

         fapi_flash_gpio_handles[i] = 0;
      }
   }
}


void func_214e2338(void)
{
   uint32_t i;

   for (i = 0; i < 3; i++)
   {
      struct Struct_21efa710_Inner_12* r4 = flashBlockArray[i].devicePtr;

      if ((r4 != 0) && (r4->buffer != 0))
      {
         FAPI_SYS_FREE(r4->buffer);
         FAPI_SYS_FREE(r4->sectorStart);
         FAPI_SYS_FREE(r4->sectorBytes);
         FAPI_SYS_FREE(r4->sectorProtect);

         r4->currSectorBytes = 0;
         r4->buffer = 0;
         r4->sectorStart = 0;
         r4->sectorBytes = 0;
         r4->sectorProtect = 0;
      }
   }
}


int func_214e2168(struct fapi_flash_handle* a)
{
   uint32_t i = 0;
   uint32_t r8 = a->Data_8.deviceType;
   uint32_t r6 = a->Data_8.firstSector;
   uint32_t r2 = r6 + a->Data_8.sectorCount;
   
   r2--;
   
   for (i = 0; i < 16; i++)
   {
      if ((flashHandleArray[i].inUse != 0) &&
            (flashHandleArray[i].openParams.deviceType == r8) &&
            (&flashHandleArray[i] != a))
      {
         uint32_t r5 = flashHandleArray[i].openParams.firstSector;
         uint32_t r1 = r5 + flashHandleArray[i].openParams.sectorCount;
         
         r1--;
         
         if (((r6 >= r5) && (r6 <= r1)) ||
               ((r2 >= r5) && (r2 <= r1)))
         {
            return 0;
         }
      }
   }
   
   return 1;
}


int flashAllocateExtGpioAddressPins(unsigned a)
{
   unsigned i, r13;
   int res = 1;
   unsigned sp4;
   a = a - 1;
   r13 = 0;
   
   while (a != 0)
   {
      a >>= 1;
      r13++;
   }
   
   r13 -= 22;
   sp4 = 9;
      
   for (i = 5; i < sp4; r13--, i++)
   {
      if (r13 == 0) 
      {
         break;
      }
      
      fapi_flash_gpio_handles[i] = FAPI_GPIO_Open(&flashGpioParams[i], 0);
      
      if (fapi_flash_gpio_handles[i] == 0)
      {
         res = 0;
         break;
      }
   }
   
   return res;
}


/* 21c1a540 - complete */
int32_t flashFlushBuffer(struct Struct_21efa710* a, int b)
{
   int32_t (*eraseSector)(struct Struct_21efa710_Inner_12*, int);
   int (*writeSector)(struct Struct_21efa710_Inner_12*, int);
   int res = 0;
   struct Struct_21efa710_Inner_12* r6 = a->Data_12;
   
   if ((r6->currSectorIndex == -1) || 
         ((r6->Data_52 == 0) && (b == 0)))
   {
      return 0;
   }
   
   eraseSector = a->eraseSector;
   
   //if (a->Data_4 == 0)
   {
      FAPI_UPI_Lock();
   }
   
   res = (eraseSector)(r6, 10000);
   
   //if (a->Data_4 == 0)
   {
      FAPI_UPI_Unlock();
   }
   
   if (res != 0)
   {
      return res;      
   }
   
   writeSector = a->writeSector;
   
   //if (a->Data_4 == 0)
   {
      FAPI_UPI_Lock();
   }
   
   res = (writeSector)(r6, 20000);
   
   //if (a->Data_4 == 0)
   {
      FAPI_UPI_Unlock();
   }
   
   if (res != 0)
   {
      return res; 
   }
   
   r6->Data_52 = 0;
   
   return 0;
}


struct fapi_flash_handle* fapi_flash_get_handle(struct Struct_21efa710* a)
{
   uint32_t i;
   struct fapi_flash_handle* h = 0;
   
#if 0
   if (fapi_flash_handle[0].inUse == 0)
   {
      fapi_flash_handle[0].inUse = 1;
      fapi_flash_handle[0].magic = 0x666c7368; //flsh
      fapi_flash_handle[0].Data_32 = a;
      
      h = &fapi_flash_handle[0];
      
      memset(&h->Data_8, 0, sizeof(FAPI_FLASH_OpenParamsT));
   }
   else
   for (i = 1; i < 16; i++)
#else
   for (i = 0; i < 16; i++)
#endif
   {
      if (flashHandleArray[i].inUse == 0)
      {
#if 1
         flashHandleArray[i].inUse = 1;
         flashHandleArray[i].id = 0x666c7368; //flsh
         flashHandleArray[i].blockPtr = a;

//         memset(&flashHandleArray[i].Data_8, 0, sizeof(FAPI_FLASH_OpenParamsT));
         
         h = &flashHandleArray[i];
         
         memset(&h->Data_8, 0, sizeof(FAPI_FLASH_OpenParamsT));

#else
         h = &flashHandleArray[i];
         
         h->inUse = 1;
         h->magic = 0x666c7368; //flsh
         h->Data_32 = a;
                  
         memset(&h->Data_8, 0, sizeof(FAPI_FLASH_OpenParamsT));
#endif
         
         break;
      }
   }
   
   return h;
}


/* 21c1a9d4 - complete */
void fapi_flash_release_handle(struct fapi_flash_handle* a)
{
   memset(a, 0, sizeof(struct fapi_flash_handle));
}


/* 21c19f30 - complete */
uint32_t flashCheckHandle( const flashHandleT* handlePtr )
{
   if ((flashInitialized != 0) &&
         (handlePtr != 0) &&
         (handlePtr->inUse != 0) &&
         (handlePtr->id == 0x666c7368) && //flsh
         (handlePtr->blockPtr != 0) &&
         (handlePtr->blockPtr->devicePtr != 0) &&
         (handlePtr->blockPtr->devicePtr->deviceId != 0) &&
         (handlePtr->blockPtr->devicePtr->descriptorPtr != 0) &&
         (handlePtr->blockPtr->devicePtr->sectorCount != 0) &&
         (handlePtr->blockPtr->devicePtr->sectorBuffer != 0)) 
   {
      return 1;
   }
   
   return 0;
}




