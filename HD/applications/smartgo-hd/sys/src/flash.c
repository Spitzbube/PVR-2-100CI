

#include <fapi/sys_services.h>
#include <fapi/drv_flash.h>
#include <flashfs/flashfs.h>
#include <fatfs/fatfs.h>
#include <flash.h>
#include "sys.h"



typedef struct
{
   int fill_0; //0
   int fill_4; //4
   int Data_8; //8
   int Data_12; //12
   int fill_16[3]; //16
   //28
} FCDATA;


FLASHFS_FILE_T Data_21ed5a9c[8] = //21ed5a9c
{
   {0x6a720001, "Satellite.dat", FLASHFS_FILE_SEMI_STATIC, 2, 0, 0x40, 0},
   {0x6a720002, "tplist_sat.dat", FLASHFS_FILE_SEMI_STATIC, 2, 0, 0x180, 0},
   {0x6a720006, "startup.dat", FLASHFS_FILE_SEMI_STATIC, 4, 0, 0x40, 0},
   {0x6a720008, "fc.dat", FLASHFS_FILE_FREQ_CHANGING, 2, 0, 0x40, sizeof(FCDATA)},
   {0x6a720009, "rectimers.dat", FLASHFS_FILE_SEMI_STATIC, 2, 0, 0x40, 0},
   {0x6a72000b, "parental_ctrl.dat", FLASHFS_FILE_SEMI_STATIC, 2, 0, 0x40, 0},
   {0x6a72000c, "ca.dat", FLASHFS_FILE_SEMI_STATIC, 2, 0, 0x80, 0},
   {0x6a720007, "services.dat", FLASHFS_FILE_SEMI_STATIC, 2, 0, 0x2c0, 0},
};


/* 21b8d704 - todo */
int32_t SYS_FlashInit(uint32_t stack_size, uint32_t priority)
{
   int32_t sectorBytes;
   uint32_t r5;
   uint32_t i;
   FAPI_FLASH_OpenParamsT flashParams;
   FAPI_SYS_HandleT flashHandle;
   FLASHFS_InitParamsT flashfsParams;
   int32_t res = 0;

   flashfsParams.device_type = sysData->flashDeviceType;
   flashfsParams.first_sector = sysData->flashUsrStartSector;
   flashfsParams.num_sector = 0;
   flashfsParams.num_file = 8;
   flashfsParams.file = SYS_MemoryAllocate(flashfsParams.num_file * sizeof(FLASHFS_FILE_T));
   if (flashfsParams.file == NULL)
   {
      return -2;
   }
   flashfsParams.stack_size = stack_size;
   flashfsParams.priority = priority;
   flashfsParams.flag = 0;


   flashParams.version = FAPI_FLASH_VERSION;
   flashParams.deviceType = sysData->flashDeviceType;
   flashParams.firstSector = sysData->flashUsrStartSector;
   flashParams.sectorCount = 32;
   flashParams.fsysFlag = 0;
   flashParams.forceFlush = 0;

   flashHandle = FAPI_FLASH_Open(&flashParams, &res);

   if (flashHandle != 0)
   {
      for (i = 0; i < flashfsParams.num_file; i++)
      {
         flashfsParams.file[i].id = Data_21ed5a9c[i].id;
         flashfsParams.file[i].revision = Data_21ed5a9c[i].revision;
         flashfsParams.file[i].sector_offset = flashfsParams.num_sector;
         flashfsParams.file[i].num_sector = 0;

         SYS_StrNCpy(flashfsParams.file[i].name, Data_21ed5a9c[i].name, FLASHFS_FILE_NAME_MAX_LEN);

         if (Data_21ed5a9c[i].type != 0)
         {
            flashfsParams.file[i].type = FLASHFS_FILE_FREQ_CHANGING;
            flashfsParams.file[i].chunk_size = Data_21ed5a9c[i].chunk_size;
         }
         else
         {
            flashfsParams.file[i].type = FLASHFS_FILE_SEMI_STATIC;
            flashfsParams.file[i].chunk_size = 0;
         }

         r5 = 0;

         while ((r5 < Data_21ed5a9c[i].num_sector) ||
               (flashfsParams.file[i].num_sector < Data_21ed5a9c[i].sector_offset))
         {
            if ((flashfsParams.first_sector + flashfsParams.num_sector) >= sysData->flashSectorCount)
            {
               FAPI_SYS_PRINT_MSG("%s %d SMARTGO_SYS_ERR_CAPACITY \n",
                     "sys/src/flash.c", 216);

               res = -10001005;
               break;
            }

            sectorBytes = FAPI_FLASH_GetSectorBytes(flashHandle, flashfsParams.first_sector + flashfsParams.num_sector);

#if 0
            FAPI_SYS_PRINT_MSG("SYS_FlashInit: sectorBytes=%d\n", sectorBytes);
#endif

            if (sectorBytes < 0)
            {
               FAPI_SYS_PRINT_MSG("%s %d SMARTGO_SYS_ERR_CAPACITY \n",
                     "sys/src/flash.c", 226);

               res = sectorBytes;
               break;
            }

            r5 += ((uint32_t)sectorBytes >> 10);

            flashfsParams.file[i].num_sector++;
            flashfsParams.num_sector++;
         }
      } //for (i = 0; i < flashfsParams.num_file; i++)

      FAPI_FLASH_Close(flashHandle);

      if (res >= 0)
      {
         res = FLASHFS_Init(&flashfsParams);
      }

      FAPI_SYS_FREE(flashfsParams.file);
   }

   return res;
}


/* 21b8d63c - todo */
int32_t func_21b8d63c(F_FILE* a)
{
   char filename[28];
   FCDATA sp;

   memset(&sp, 0, sizeof(FCDATA));

   if (a != 0)
   {
      f_read(&sp, 1, sizeof(FCDATA), a);
   }
   else
   {
      sprintf(filename, "%s%s", "a:/", "fc.dat");

      F_FILE* filehandle = f_open(filename, "r");

      if (filehandle == 0)
      {
         return 0;
      }

      f_read(&sp, 1, sizeof(FCDATA), filehandle);

      f_close(filehandle);

   }

   time_get_current(&sp.Data_8, &sp.Data_12, 0);

   return SYS_FlashWriteFcData(&sp);
}


/* 21b8d5dc - complete */
int32_t SYS_FlashWriteFcData(const void* buf)
{
   int32_t res = 0;

   FLASHFS_HANDLE fileHandle = FLASHFS_Open(0x6a720008, "w", &res);

   if (fileHandle != 0)
   {
      res = FLASHFS_Write(fileHandle, sizeof(FCDATA), buf, 0);

      FLASHFS_Close(fileHandle);
   }

   return res;
}


/* 21b8d49c - complete */
int32_t SYS_FlashReadFcData(void* buf)
{
   FLASHFS_HANDLE h;
   int32_t res = 0;
   
//   FAPI_SYS_PRINT_MSG("SYS_FlashReadFcData\n");
   
   h = FLASHFS_Open(0x6a720008, "r", &res);
   
   if (h)
   {
      res = FLASHFS_Read(h, sizeof(FCDATA), buf, 0);
      
      FLASHFS_Close(h);
   }

   return res;
}










