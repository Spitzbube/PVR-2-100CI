#ifndef FAPI_FLASH_H_
#define FAPI_FLASH_H_


#define FAPI_PARALLEL_FLASH 0
#define FAPI_SERIAL_FLASH   1
#define FAPI_NAND_FLASH     2


struct fapi_flash_params
{
   unsigned Data_0; //0
   unsigned index; //4
   unsigned Data_8; //8
   unsigned Data_12; //12
   int Data_16; //16
   int Data_20; //20
   //24
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


extern struct fapi_driver fapi_flash_driver; //21efa6ec 

extern void* FAPI_FLASH_Open(struct fapi_flash_params*, int*);
extern int FAPI_FLASH_Close(void*);
extern void FAPI_FLASH_SetEnable(unsigned, int);
extern void FAPI_FLASH_SetUpiIndex(int, unsigned);
extern int FAPI_FLASH_ReadBytes(void*, int, int, void*);
extern int FAPI_FLASH_WriteBytes(void*, int, int, void*);
extern int FAPI_FLASH_GetSectorIndex(void*, int);
extern int FAPI_FLASH_GetSectorBytes(void*, unsigned);
extern int FAPI_FLASH_GetSectorStart(void*, unsigned);
extern int FAPI_FLASH_EraseSector(void*, unsigned);
extern int FAPI_FLASH_EraseChip(void*);
extern int FAPI_FLASH_Flush(void*);
extern int FAPI_FLASH_IsSectorEmpty(void*, int);
extern int FAPI_FLASH_IsChipEmpty(void*);
extern int FAPI_FLASH_ReadBytesDirect(void*, unsigned, unsigned, void*);
extern int FAPI_FLASH_WriteBytesDirect(void*, unsigned, unsigned, void*);
extern int FAPI_FLASH_GetDeviceSize(void*);
extern int FAPI_FLASH_GetDeviceId(void*);
extern int FAPI_FLASH_GetManufacturerId(void*);
extern char* FAPI_FLASH_GetManufacturerName(void*);
extern char* FAPI_FLASH_GetDeviceName(void*);
extern int FAPI_FLASH_GetSectorCount(void*);
extern int FAPI_FLASH_IsSectorProtected(void*, int);
extern int FAPI_FLASH_ProtectSector(void*, int, int);

extern int func_21c1ba44(void*, unsigned, void*);

   
#endif /*FAPI_FLASH_H_*/
