#ifndef FLASH_HEADER_H_
#define FLASH_HEADER_H_


typedef struct
{
   
} BOOT_FLASH_SetupT;


typedef struct
{
   uint32_t fill_0; //0
   uint32_t imageControl; //4
   uint32_t fill_8; //8
   uint32_t imageSize; //12
   uint32_t imageVersion; //16
   uint32_t loadAddress; //20
   uint32_t jumpAddress; //24
   //28
} BOOT_FLASH_ImageT;


typedef struct
{
   
} BOOT_FLASH_HeaderT;



#endif /*FLASH_HEADER_H_*/
