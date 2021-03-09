
#define DEBUG 0

#include <string.h>
#include <fapi/sys_services.h>
#include <fapi/reg_sflash.h>
#include <fapi/drv_timer.h>
#include <fapi/drv_flash.h>
#include <fapi/drv_flash_priv.h>




static flashDeviceT sFlashDevice; //21f222b4


int32_t sflashWaitWipCleared(uint32_t);



/* 21c1d13c - todo */
int32_t sflashDetectChip(flashDeviceT** devicePtrPtr, uint32_t timeout)
{
   uint32_t i, j;
   uint32_t sectorCount;
   uint32_t sectorSize;
   uint32_t r10;
   uint32_t r4, r5;
   uint32_t arraySize;
   uint32_t port;
   uint32_t numPartitions;
   uint32_t maxSectorSize;
   flashRegionT* part;
   uint32_t sectorAddr;
   uint32_t k;

   flashDescriptorT* descriptor; //r7
   
   FAPI_SYS_PRINT_DEBUG(4, "sflashDetectChip()\n");
   
   FREG_SFLASH_SetCommand(0x9f);
   
   port = FREG_SFLASH_GetPort();
      
   memset(&sFlashDevice, 0, sizeof(flashDeviceT));
            
   for (descriptor = fapiSFlashDescriptorArray; descriptor->deviceName != 0; descriptor++)
   {      
      r4 = (port & 0xff0000) >> 16;
      r5 = port & 0xFFFF;
      
      FAPI_SYS_PRINT_DEBUG(4, "\015\n DEVICE ID VALUE IS %d", r5);
      FAPI_SYS_PRINT_DEBUG(4, "\015\n manufactorer_id ID VALUE IS %d", r4);
      
      if ((descriptor->manufacturerId == r4) &&
            (descriptor->deviceId == r5))
      {
#if 0
         sFlashDevice.deviceId = port;
         sFlashDevice.deviceBytes = 0;
         sFlashDevice.sectorCount = 0;
         sFlashDevice.cfiVersion = 0;
         sFlashDevice.cfiOffset = 0;
         sFlashDevice.descriptorPtr = descriptor;
         sFlashDevice.sectorStartArray = 0;
         sFlashDevice.sectorBuffer = 0;
         sFlashDevice.sectorIndex = 0xFFFFFFFF;
         sFlashDevice.sectorStart = 0;
         sFlashDevice.sectorBytes = 0;
         sFlashDevice.dirtyFlag = 0;
         
         *devicePtrPtr = &sFlashDevice;
#endif
         
         break;
      }
   }
   
#if 1
   if (descriptor->deviceName == 0)
   {
#if 1
      FAPI_SYS_PRINT_MSG("\n unknow flash device XXXXXXX m=%x id=%x XXXXXXXX assume 4M",
            r4, r5);
      
      descriptor--;
#else
      memset(&sFlashDevice, 0, sizeof(struct Struct_21efa710_Inner_12));
      
      return -10101;
#endif
   }
   
   sFlashDevice.deviceId = port;
   sFlashDevice.deviceBytes = 0;
   sFlashDevice.sectorCount = 0;
   sFlashDevice.cfiVersion = 0;
   sFlashDevice.cfiOffset = 0;
   sFlashDevice.descriptorPtr = descriptor;
   sFlashDevice.sectorStartArray = 0;
   sFlashDevice.sectorBuffer = 0;
   sFlashDevice.sectorIndex = -1;
   sFlashDevice.sectorStart = 0;
   sFlashDevice.sectorBytes = 0;
   sFlashDevice.dirtyFlag = 0;
   
   *devicePtrPtr = &sFlashDevice;
#endif
   
#if 0
   if (descriptor->deviceName == 0)
   {
      FAPI_SYS_PRINT_MSG("\n unknow flash device XXXXXXX m=%x id=%x XXXXXXXX assume 4M",
            r4, r5);
            
      memset(&sFlashDevice, 0, sizeof(flashDeviceT));
      
      return FAPI_FLASH_ERR_DEVICE_NOT_SUPPORTED;
   }   
#endif
   
   numPartitions = descriptor->eraseRegionCount;
   part = descriptor->eraseRegionTable;
   maxSectorSize = 0;
      
   for (i = 0; i < numPartitions; i++)
   {
      sectorCount = part[i].sectorCount;
      sectorSize = part[i].sectorBytes;
   
      r10 = (sectorCount * sectorSize);

      sFlashDevice.deviceBytes += r10;
      sFlashDevice.sectorCount += sectorCount;
      
      if (sectorSize > maxSectorSize)
      {
         maxSectorSize = sectorSize;
      }
   }

   sFlashDevice.sectorBuffer = FAPI_SYS_MALLOC_CACHED(maxSectorSize);
         
   if (sFlashDevice.sectorBuffer == 0)
   {
      memset(&sFlashDevice, 0, sizeof(flashDeviceT));
            
      return FAPI_FLASH_ERR_OUT_OF_MEMORY;
   }

   memset(sFlashDevice.sectorBuffer, 0, maxSectorSize);
   
   arraySize = sFlashDevice.sectorCount * sizeof(uint32_t);
   
   sFlashDevice.sectorStartArray = FAPI_SYS_MALLOC_CACHED(arraySize);
         
   if (sFlashDevice.sectorStartArray == 0)
   {
      FAPI_SYS_FREE(sFlashDevice.sectorBuffer);

      memset(&sFlashDevice, 0, sizeof(flashDeviceT));
            
      return FAPI_FLASH_ERR_OUT_OF_MEMORY;
   }

   memset(sFlashDevice.sectorStartArray, 0, arraySize);
   
   arraySize = sFlashDevice.sectorCount * sizeof(uint32_t);

   sFlashDevice.sectorBytesArray = FAPI_SYS_MALLOC_CACHED(arraySize);
         
   if (sFlashDevice.sectorBytesArray == 0)
   {
      FAPI_SYS_FREE(sFlashDevice.sectorBuffer);
      
      FAPI_SYS_FREE(sFlashDevice.sectorStartArray);

      memset(&sFlashDevice, 0, sizeof(flashDeviceT));
            
      return FAPI_FLASH_ERR_OUT_OF_MEMORY;
   }

   memset(sFlashDevice.sectorBytesArray, 0, arraySize);
   
   arraySize = sFlashDevice.sectorCount * sizeof(uint8_t);

   sFlashDevice.sectorProtectArray = FAPI_SYS_MALLOC_CACHED(arraySize);
         
   if (sFlashDevice.sectorProtectArray == 0)
   {
      FAPI_SYS_FREE(sFlashDevice.sectorBuffer);      
      FAPI_SYS_FREE(sFlashDevice.sectorStartArray);
      FAPI_SYS_FREE(sFlashDevice.sectorBytesArray);

      memset(&sFlashDevice, 0, sizeof(flashDeviceT));
            
      return FAPI_FLASH_ERR_OUT_OF_MEMORY;
   }

   memset(sFlashDevice.sectorProtectArray, 0, arraySize);
      
   numPartitions = descriptor->eraseRegionCount;
   part = descriptor->eraseRegionTable;
   k = 0;
   sectorAddr = 0;
   
   for (i = 0; i < numPartitions; i++)
   {
      sectorCount = part[i].sectorCount;
      sectorSize = part[i].sectorBytes;
            
      for (j = 0; j < sectorCount; k++, j++)
      {
         sFlashDevice.sectorStartArray[k] = sectorAddr;
         sFlashDevice.sectorBytesArray[k] = sectorSize;
         
         sectorAddr += sectorSize;
      }
   }

   sectorCount = sFlashDevice.sectorCount;
   
   for (j = 0; j < sectorCount; j++)
   {
      sFlashDevice.sectorProtectArray[j] = 0;
   }

   return FAPI_OK;
}


/* 21c1d0ac - complete */
int32_t sflashEraseChip(flashDeviceT* devicePtr, uint32_t timeout)
{
   int32_t res;
   uint32_t i;
   
   for (i = 0; i < devicePtr->sectorCount; i++)
   {
      if (0 != devicePtr->sectorProtectArray[i])
      {
         return FAPI_FLASH_ERR_SECTOR_PROTECTED;
      }
   }
   
   FREG_SFLASH_SetCommand(0x06);
   FREG_SFLASH_GetPort();
   FREG_SFLASH_SetCommand(0xC7);
   FREG_SFLASH_SetPort(0);
   
   res = sflashWaitWipCleared(timeout);
   
   FREG_SFLASH_SetCommand(0x04);
   FREG_SFLASH_GetPort();

   return res;
}


/* 21c1d048 - complete */
int32_t sflashEraseSector(flashDeviceT* devicePtr, uint32_t timeout)
{
   int32_t res;
   uint32_t addr = devicePtr->sectorStart;
   uint32_t sectorIndex = devicePtr->sectorIndex;
   
   if (devicePtr->sectorProtectArray[sectorIndex] != 0)
   {
      return FAPI_FLASH_ERR_SECTOR_PROTECTED;
   }

   FREG_SFLASH_SetCommand(0x06);
   FREG_SFLASH_GetPort();
   FREG_SFLASH_SetCommand(0xD8);
   FREG_SFLASH_SetPort(addr);
   
   res = sflashWaitWipCleared(timeout);
   
   FREG_SFLASH_SetCommand(0x04);
   FREG_SFLASH_GetPort();
   
   return res;
}


/* 21c1cff8 - complete */
int32_t sflashReadSector(flashDeviceT* devicePtr, uint32_t timeout)
{
   uint32_t* buffer;
   uint32_t i;
   int32_t res = FAPI_OK;
   uint32_t addr = devicePtr->sectorStart;
   uint32_t words = devicePtr->sectorBytes / 4;

   buffer = devicePtr->sectorBuffer;
   
   FREG_SFLASH_SetCommand(0x03);
   FREG_SFLASH_SetPort(addr);
   
   for (i = 0; i < words; i++)
   {
      *buffer++ = FREG_SFLASH_GetPort();
   }
   
   return res;
}


/* 21c1cec4 - complete */
int32_t sflashWriteSector(flashDeviceT* devicePtr, uint32_t timeout)
{
   int32_t res = 0;
   uint32_t addr = devicePtr->sectorStart;
   uint32_t words = devicePtr->sectorBytes / 4;   
   uint32_t* buffer = devicePtr->sectorBuffer;
   
   uint64_t t = FAPI_TIMER_GetTimeStamp(1000);
      
   if (devicePtr->sectorProtectArray[devicePtr->sectorIndex] != 0)
   {
      return FAPI_FLASH_ERR_SECTOR_PROTECTED;
   }
   else
   {
      uint32_t i;
      
      for (i = 0; i < words; i++)
      {
         if ((addr & 0xFF) == 0)
         {
            FREG_SFLASH_SetCommand(0x06);
            FREG_SFLASH_GetPort();
            FREG_SFLASH_SetCommand(0x02);
            FREG_SFLASH_SetPort(addr);            
         }

         FREG_SFLASH_SetPort(buffer[i]);
         
         addr += 4;
         
         if ((FAPI_TIMER_GetTimeStamp(1000) - t) > timeout/*r22*/)
         {
            break;
         }
         
         if ((addr & 0xFF) == 0)
         {
            if (0 != sflashWaitWipCleared(timeout))
            {
               break;
            }
         }
      }

      res = sflashWaitWipCleared(timeout);
      
      FREG_SFLASH_SetCommand(0x04);
      FREG_SFLASH_GetPort();
      FREG_SFLASH_SetCommand(0x05);
      FREG_SFLASH_GetPort();
   }

   return res;
}


/* 21c1ce74 - complete */
int32_t sflashReadDirect(flashDeviceT* devicePtr, uint32_t sectorIndex,
                         uint32_t byteOffset, uint32_t bytes,
                         void* bufferPtr, uint32_t timeout)
{
   int32_t res = FAPI_OK;
   uint32_t address = devicePtr->sectorStartArray[sectorIndex] + byteOffset;
   uint32_t* buf = bufferPtr;
   
   FREG_SFLASH_SetCommand(0x03);
   FREG_SFLASH_SetPort(address);
      
   while (bytes != 0)
   {
      *buf++ = FREG_SFLASH_GetPort();
      bytes -= 4;
   }
   
   return res;
}


/* 21c1cd34 - complete */
int32_t sflashWriteDirect( flashDeviceT* devicePtr, uint32_t sectorIndex,
                           uint32_t byteOffset, uint32_t bytes,
                           const void* bufferPtr, uint32_t timeout )
{
   int32_t res;
   const uint32_t* buf;
   uint32_t address = devicePtr->sectorStartArray[sectorIndex] + byteOffset;
   
   uint64_t t = FAPI_TIMER_GetTimeStamp(1000);
      
   if (devicePtr->sectorProtectArray[devicePtr->sectorIndex] != 0)
   {
      return FAPI_FLASH_ERR_SECTOR_PROTECTED;
   }
      
   if (address & 0xFF)
   {
      FREG_SFLASH_SetCommand(0x06);
      FREG_SFLASH_GetPort();
      FREG_SFLASH_SetCommand(0x02);
      FREG_SFLASH_SetPort(address);
   }
   
   buf = bufferPtr;
   
   while (bytes != 0)
   {                  
      if ((address & 0xFF) == 0)
      {
         FREG_SFLASH_SetCommand(0x06);
         FREG_SFLASH_GetPort();
         FREG_SFLASH_SetCommand(0x02);
         FREG_SFLASH_SetPort(address);
      }
      
      FREG_SFLASH_SetPort(*buf++);
   
      address += 4;
      bytes -= 4;
      
      if ((FAPI_TIMER_GetTimeStamp(1000) - t) > timeout)
      {
         break;
      }
      
      if ((address & 0xFF) == 0)
      {
         if (0 != sflashWaitWipCleared(timeout))
         {
            break;
         }
      }
   }
                     
   res = sflashWaitWipCleared(timeout);
   
   FREG_SFLASH_SetCommand(0x04);
   FREG_SFLASH_GetPort();
   FREG_SFLASH_SetCommand(0x05);
   FREG_SFLASH_GetPort();

   return res;
}


/* 21c1ccac - complete */
int32_t sflashWaitWipCleared(uint32_t a)
{
   uint32_t wip = 1;
   uint64_t t = FAPI_TIMER_GetTimeStamp(1000);

   FREG_SFLASH_SetCommand(0x05);
   
   if ((wip & FREG_SFLASH_GetPort()) == wip)
   {
      while (1)
      {
         FREG_SFLASH_SetCommand(0x05);
         
         if ((wip & FREG_SFLASH_GetPort()) != wip)
         {
            break;
         }
         
         if ((FAPI_TIMER_GetTimeStamp(1000) - t) > a)
         {
            return FAPI_FLASH_ERR_TIMEOUT;
         }
      }
   }
      
   return 0;
}



