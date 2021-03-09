
#include <string.h>
#include <fapi/sys_services.h>
#include <fapi/drv_gpio.h>
#if 0
#include "famos.h"
#endif
#include "fapi/reg_sflash.h"
#if 0
#include "fapi_adapter.h"
#endif
#include "fapi/fapi_flash.h"
#if 0
#include "drv_sflash.h"
#endif


struct fapi_flash_handle;
struct Struct_21efa710;

static int func_214e2168(struct fapi_flash_handle*);
static int func_214e2230(unsigned);
int flashCheckHandle(struct fapi_flash_handle*);
void fapi_flash_release_handle(struct fapi_flash_handle*);
int flashFlushBuffer(struct Struct_21efa710*, int);
static struct fapi_flash_handle* fapi_flash_get_handle(struct Struct_21efa710*);
int fapi_flash_read_sector(struct Struct_21efa710* a);


static int Data_21efa6e0 = 0x80000000; //21efa6e0
static int Data_21efa6e4 = 0x80000000; //21efa6e4
static int Data_21efa6e8 = 0x80000000; //21efa6e8

#if 0
struct fapi_driver fapi_flash_driver = //21efa6ec 
{
      "FLASH",
      -1,
      0,
      FAPI_FLASH_Init, 
      FAPI_FLASH_Exit,
      0,
      0,
      0,
      0,
};
#endif

struct Struct_21efa710
{
   int Data_0; //0
   int fill_4; //4
   void* semaphore; //8
   struct Struct_21efa710_Inner_12* Data_12; //12
   int (*detectChip)(struct Struct_21efa710_Inner_12**, int); //16
   int (*eraseChip)(struct Struct_21efa710_Inner_12*, int); //20
   int (*eraseSector)(struct Struct_21efa710_Inner_12*, int); //24
   int (*readSector)(struct Struct_21efa710_Inner_12*, int); //28
   int (*writeSector)(struct Struct_21efa710_Inner_12*, int); //32
   int (*readDirect)(struct Struct_21efa710_Inner_12*, 
         int, int, int, void*, int); //36
   int (*writeDirect)(struct Struct_21efa710_Inner_12*, 
         int, int, int, void*, int); //40
   //44
} 
Data_21efa710[3]; //21efa710

static FAPI_GPIO_OpenParamsT Data_21efa794[9] = //21efa794
{
      {0x20000, -1, 0x102, 0},
      {0x20000, -1, 0xb1, 0},
      {0x20000, -1, 0xb2, 0},
      {0x20000, -1, 0xb3, 0},
      {0x20000, -1, 0xb4, 0},
      {0x20000, -1, 0xd6, 0},
      {0x20000, -1, 0xd7, 0},
      {0x20000, -1, 0xd8, 0},
      {0x20000, -1, 0xd9, 0},
};


struct fapi_flash_handle
{
   int magic; //0
   int inUse; //4
   struct fapi_flash_params Data_8; //8
   struct Struct_21efa710* Data_32; //32
   int Data_36; //36
   int Data_40; //40
   int Data_44; //44
   int Data_48; //48
   //52
};

int fapi_flash_upi_index[3]; //21f21eec
int fapi_flash_enables[3]; //21f21f00
static void* fapi_flash_gpio_handles[9]; //21f21f0c
struct fapi_flash_handle fapi_flash_handle[16]; //21f21f38

static int fapi_flash_initialized; //21f21ef8
static void* fapi_flash_semaphore; //21f21efc
static void* Data_21f21f30; //21f21f30
static void* Data_21f21f34; //21f21f34



struct Struct_12 
{
   unsigned magic; //0
   unsigned registerSettings; //4
   unsigned firmwareBlocks; //8
   //12
};


struct Struct_21c1b74c
{
   struct Struct_12 Data_0; //0
   struct register_value
   {
      unsigned reg; 
      unsigned val;
   } registerSetup[256]; //12
   struct Struct_21c1b74c_Inner_2060
   {
      struct Struct_21c1b74c_Inner
      {
         int Data_0; //0
         int Data_4; //0
         int numWords; //0
         int Data_12; //0
         int Data_16; //0
         void* Data_20; //0
         int Data_24; //0
      } Data_0; //0
      int addr; //28
      //32
   } firmware[16]; //2060
   int lastAddr; //2572
   int nextSector; //2576
};


/* 21c1b5a0 - complete */
int func_21c1b5a0(void* h, int b)
{
   struct Struct_12 sp;
   struct fapi_flash_handle* a = h;
   
   if (0 == flashCheckHandle(a))
   {
      return 0;
   }
   
   memset(&sp, 0, sizeof(sp));

   FAPI_FLASH_ReadBytes(a, 0, sizeof(struct Struct_12), &sp);
   
   return (sp.magic == b)? 1: 0;
}


/* 21c1b5f8 - todo */
unsigned func_21c1b5f8(void)
{
   void* h;
   unsigned i;
   int sp[8];
   struct fapi_flash_params sp32;
   FAPI_GPIO_OpenParamsT sp56;
   int r7 = -1;
   
   sp[0] = 0x46443331;
   sp[1] = 0x46443332;
         
   memset(&sp32, 0, sizeof(struct fapi_flash_params));
   
   sp32.Data_0 = 0x20000;
   //sp32.index = FAPI_PARALLEL_FLASH;
   
   h = FAPI_FLASH_Open(&sp32, 0);
   
   if (h != 0)
   {      
      for (i = 0; i < 2; i++)
      {
         if (0 != func_21c1b5a0(h, sp[i]))
         {
            //21c1b724
            r7 = sp32.index & 0x7FFFFFFF;
            break;
         }
      }
      
      FAPI_FLASH_Close(h);      
   }
            
   if (r7 == -1)
   {
      //21c1b678
      memset(&sp56, 0, sizeof(FAPI_GPIO_OpenParamsT));
      
      sp56.version = FAPI_GPIO_VERSION;
      sp56.pin = 0x27; //= 39;
      sp56.function = 0x810000;
      sp56.callback = 0;
            
      h = FAPI_GPIO_Open(&sp56, 0);
      
      if (h != 0)
      {
         int r6 = FAPI_GPIO_ReadBit(h);
         
         FAPI_GPIO_Close(h);
         
         if (r6 == 1)
         {
            //21c1b6d8
            memset(&sp32, 0, sizeof(struct fapi_flash_params));
            
            sp32.Data_0 = 0x20000;
            sp32.index = FAPI_SERIAL_FLASH;

            h = FAPI_FLASH_Open(&sp32, 0);
            
            if (h != 0)
            {               
               if (0 != func_21c1b5a0(h, 0x46443334))
               {
                  //21c1b724
                  r7 = sp32.index & 0x7FFFFFFF;
               }
               
               FAPI_FLASH_Close(h);
            }            
         }
      }
   }
   //21c1b6c4
   return r7;
}

//TODO
#define MEMCPY_DEBUG    10


/* 21c1b74c - todo */
int func_21c1b74c(void* h, struct Struct_21c1b74c* b)
{
   unsigned i;
   unsigned addr;
   unsigned registerValueBlockSize;
   
   struct fapi_flash_handle* a = h;
   
   if (0 == flashCheckHandle(a))
   {
      return -10001;
   }
   
   if (b == 0)
   {
      return -10001;
   }
   
   struct Struct_12 sp28; // = {0};
   
   memset(&sp28, 0, sizeof(struct Struct_12));
   
   // Read the boot header
   FAPI_FLASH_ReadBytes(a, 0, sizeof(struct Struct_12), &sp28);
   
   memcpy(&b->Data_0, &sp28, sizeof(struct Struct_12)*MEMCPY_DEBUG);
   
   if ((/*b->Data_0.magic*/sp28.magic & 0xFFFFFF00) != 0x46443300)
   {
      return 0xffffd889;
   }
   
   if (b->Data_0.registerSettings < 256)
   {
      registerValueBlockSize = b->Data_0.registerSettings * 
         sizeof(struct register_value); 
   }
   else
   {
      registerValueBlockSize = 256 * sizeof(struct register_value);
   }
   
   addr = b->Data_0.registerSettings * sizeof(struct register_value); 
   
   memset(b->registerSetup, 0, sizeof(b->registerSetup));
   
   // Read the register value setup 
   FAPI_FLASH_ReadBytes(a, sizeof(struct Struct_12), 
         registerValueBlockSize, b->registerSetup);
   
   addr += sizeof(struct Struct_12);
   
   unsigned blocks = b->Data_0.firmwareBlocks;

   // Read the firmware header
   for (i = 0; (i < blocks) && (i < 16); i++)
   {            
      struct Struct_21c1b74c_Inner sp;
      
      memset(&sp, 0, sizeof(struct Struct_21c1b74c_Inner)*MEMCPY_DEBUG);
            
      FAPI_FLASH_ReadBytes(a, addr, 
            sizeof(struct Struct_21c1b74c_Inner), &sp);
      
      memcpy(&b->firmware[i].Data_0, &sp, 
            sizeof(struct Struct_21c1b74c_Inner)*MEMCPY_DEBUG);
   
      addr += sizeof(struct Struct_21c1b74c_Inner);
      
      b->firmware[i].addr = addr;
      
      addr += sp.numWords * sizeof(unsigned);
   }
   
   int sector = FAPI_FLASH_GetSectorIndex(a, addr);
   
   if (sector < 0)
   {
      return -10001;
   }
   
   b->lastAddr = addr;
   b->nextSector = sector + 1;

   return 0;
}


/* 21c1b8f4 - todo */
int func_21c1b8f4(void* h, unsigned b, void* c)
{
   int res;
   struct Struct_21c1b74c sp;
   unsigned buffer[1024/4];
   struct fapi_flash_handle* a = h;
   
   if (0 == flashCheckHandle(a))
   {
      return -10001;
   }
   
   res = func_21c1b74c(a, &sp);
   
   if (res != 0)
   {
      return res;
   }
   
   if (b >= sp.Data_0.firmwareBlocks)
   {
      return -10001;
   }
   
   struct Struct_21c1b74c_Inner_2060* r5_ = &sp.firmware[b]; 
   
   if (r5_->Data_0.Data_0 != 0x46424931)
   {
      return -10001;
   }
   
   void* r0 = r5_->Data_0.Data_20;
   
   if (FAPI_SYS_Services.getVirtAddressFunc != 0)
   {
      r0 = (FAPI_SYS_Services.getVirtAddressFunc)(r0);
   }
         
   if (c != 0)
   {
      r0 = c;
   }
   
   int addr = r5_->addr;
   unsigned* sl = r0;
   unsigned words = r5_->Data_0.Data_12 * 4;
   
   while (words > 0)
   {      
      unsigned chunk = (words < 1024)? words: 1024;
      
      res = FAPI_FLASH_ReadBytes(a, addr, chunk, buffer);
      if (res != 0)
      {
         return res;
      }
      
      words -= chunk;
      addr += chunk;
      
      unsigned r1 = 0;
      
      while ((chunk > 0) && (r1 < 256))
      {         
         *sl++ = buffer[r1++];
#if 1
         if (chunk < 4)
         {
            break;
         }
#endif
         chunk -= 4;
      }      
   }
         
   return 0;
}


/* 21c1ba44 - complete */
int FAPI_FLASH_LoadBootImageByVersion(void* h, unsigned b, void* c)
{
   int res;
   unsigned i;
   struct Struct_21c1b74c sp;
   struct fapi_flash_handle* a = h;
   
   if (0 == flashCheckHandle(a))
   {
      return -10001;
   }
   
   if (b == 0)
   {
      return -10001;
   }
   
   res = func_21c1b74c(a, &sp);
   
   if (res != 0)
   {
      return res;
   }
   
   for (i = 0; i < sp.Data_0.firmwareBlocks; i++)
   {
      if (sp.firmware[i].Data_0.Data_16 == b)
      {
         return func_21c1b8f4(a, i, c);
      }
   }
   
   return -10001;
}


/* 21c1baf8 - complete */
int func_21c1baf8(void* h, unsigned b, struct Struct_21c1b74c_Inner* c)
{
   int res;
   struct Struct_21c1b74c sp;
   struct fapi_flash_handle* a = h;
   
   if (0 == flashCheckHandle(a))
   {
      return -10001;
   }
   
   if (c == 0)
   {
      return -10001;
   }
   
   res = func_21c1b74c(a, &sp);
   
   if (res != 0)
   {
      return res;
   }
   
   if (b >= sp.Data_0.firmwareBlocks)
   {
      return -10001;
   }

   struct Struct_21c1b74c_Inner_2060* r1 = &sp.firmware[b];

   if (r1->Data_0.Data_0 != 0x46424931)
   {
      return -10001;
   }
   
   memcpy(c, &r1->Data_0, 
         sizeof(struct Struct_21c1b74c_Inner));
   
   return 0;
}


/* 21c1bba0 - todo */
/* Evolve: 218aece4 - todo */
int FAPI_FLASH_GetBootImageInfoByVersion(void* h, unsigned b, void* c)
{
   int res;
   unsigned i;
   struct Struct_21c1b74c sp;
   struct fapi_flash_handle* a = h;
   
   if (0 == flashCheckHandle(a))
   {
      return -10001;
   }
   
   if (b == 0)
   {
      return -10001;
   }

   if (c == 0)
   {
      return -10001;
   }

   res = func_21c1b74c(a, &sp);
   
   if (res != 0)
   {
      return res;
   }
   
   for (i = 0; i < sp.Data_0.firmwareBlocks; i++)
   {
      if (sp.firmware[i].Data_0.Data_16 == b)
      {
         return func_21c1baf8(a, i, c);
      }
   }
   
   return -10001;
}

#if 0
/* 21c1ab9c - todo */
void* FAPI_FLASH_Open(struct fapi_flash_params* params, int* pres)
{
   int sp3;
   int (*detectChip)(struct Struct_21efa710_Inner_12**, int);
   struct fapi_flash_handle* h;
   int res = 0;
   
   if (fapi_flash_initialized == 0)
   {
      //21c1aecc
      res = -10004;
      if (pres != 0)
      {
         *pres = res;
      }
      return 0;
   }
   
   if (params == 0)
   {
      //21c1afa0
      res = -10001;
      if (pres != 0)
      {
         *pres = res;
      }
      return 0;
   }

   if ((params->index != FAPI_PARALLEL_FLASH) &&
         (params->index != FAPI_SERIAL_FLASH) &&
         (params->index != FAPI_NAND_FLASH))
   {
      //21c1af3c
      res = -10001;
      if (pres != 0)
      {
         *pres = res;
      }
      return 0;
   }
   
   if (params->Data_0 > 0x20000)
   {
      //21c1af54
      res = -10010;
      if (pres != 0)
      {
         *pres = res;
      }
      return 0;
   }
   
   FAPI_SYS_GET_SEMAPHORE(fapi_flash_semaphore, -1);
   
   if (fapi_flash_enables[params->index] != 1)
   {
      //21c1ae98
      FAPI_SYS_SET_SEMAPHORE(fapi_flash_semaphore, 0);
      
      res = -10101;
      if (pres != 0)
      {
         *pres = res;
      }
      return 0;
   }
   //21c1ac10
   struct Struct_21efa710* r6 = &Data_21efa710[params->index];
   
   detectChip = r6->detectChip;
   
   if ((detectChip == 0) ||
         (r6->eraseChip == 0) ||
         (r6->eraseSector == 0) ||
         (r6->readSector == 0) ||
         (r6->writeSector == 0))
   {
      //21c1adac
      FAPI_SYS_SET_SEMAPHORE(fapi_flash_semaphore, 0);
      
      res = -10106;
      if (pres != 0)
      {
         *pres = res;
      }
      return 0;
   }
   
   if (r6->Data_12 == 0)
   {
      //21c1afb8
      FAPI_UPI_Lock();
      
      res = (detectChip)(&r6->Data_12, 2000);
      
      FAPI_UPI_Unlock();
      
      if (res != 0)
      {
         //21c1b084
         FAPI_SYS_SET_SEMAPHORE(fapi_flash_semaphore, 0);
         
         if (pres != 0)
         {
            *pres = res;
         }
         return 0;
      }
      
      if (params->index == FAPI_PARALLEL_FLASH)
      {
         //21c1afe4
         if (0 == func_214e2230(r6->Data_12->totalSize))
         {
            FAPI_SYS_SET_SEMAPHORE(fapi_flash_semaphore, 0);

            res = -10108;
            if (pres != 0)
            {
               *pres = res;
            }
            return 0;
         }
      }
      //21c1b044
      if (r6->Data_12 == 0)
      {
         FAPI_SYS_SET_SEMAPHORE(fapi_flash_semaphore, 0);

         res = -10107;
         if (pres != 0)
         {
            *pres = res;
         }
         return 0;
      }
   } //if (r6->Data_12 == 0)
   //21c1ac70
   h = fapi_flash_get_handle(r6);
   
   if (0 == flashCheckHandle(h))
   {
      //21c1af6c
      FAPI_SYS_SET_SEMAPHORE(fapi_flash_semaphore, 0);

      res = -10008;
      if (pres != 0)
      {
         *pres = res;
      }
      return 0;
   }
   
   memcpy(&h->Data_8, params, sizeof(struct fapi_flash_params));
   
   if (0 == func_214e2168(h))
   {
      //21c1ad68
      fapi_flash_release_handle(h);
      
      FAPI_SYS_SET_SEMAPHORE(fapi_flash_semaphore, 0);

      res = -10109;
      if (pres != 0)
      {
         *pres = res;
      }
      return 0;      
   }
   //21c1ade0
   FAPI_SYS_SET_SEMAPHORE(fapi_flash_semaphore, 0);
   
   FAPI_FLASH_ReadBytes(h, 0, 1, &sp3);
   
   h->Data_44 = h->Data_8.Data_8;
   
   if (h->Data_8.Data_12 == 0)
   {
      h->Data_48 = h->Data_32->Data_12->totalSectors;
   }
   else
   {
      h->Data_48 = h->Data_8.Data_12;
   }
   
   unsigned r1;
   unsigned r3 = 0;   
   
   for (r1 = h->Data_44; r1 < h->Data_48; r1++)
   {
      r3 += h->Data_32->Data_12->sectorBytes[r1];
   }
   
   h->Data_36 = r3 / 512;
   h->Data_40 = 512;
   
   res = 0;
   
   if (pres != 0)
   {
      *pres = res;
   }
   
   return h;
}
#endif


struct fapi_flash_handle* fapi_flash_get_handle(struct Struct_21efa710* a)
{
   unsigned i;
   struct fapi_flash_handle* h = 0;
   
   for (i = 0; i < 16; i++)
   {
      if (fapi_flash_handle[i].inUse == 0)
      {
#if 0
         fapi_flash_handle[i].inUse = 1;
         fapi_flash_handle[i].magic = 0x666c7368; //flsh
         fapi_flash_handle[i].Data_32 = (void*) a;
         
         h = &fapi_flash_handle[i];
         
         memset(&h->Data_8, 0, sizeof(struct fapi_flash_params));
#else
         h = &fapi_flash_handle[i];
         
         h->inUse = 1;
         h->magic = 0x666c7368; //flsh
         h->Data_32 = a;
                  
         memset(&h->Data_8, 0, sizeof(struct fapi_flash_params));
#endif
         break;
      }
   }
   
   return h;
}


int func_214e2168(struct fapi_flash_handle* a)
{
   unsigned i;
   unsigned r8 = a->Data_8.index;
   unsigned r6 = a->Data_8.Data_8;
   unsigned r2 = a->Data_8.Data_12 + r6 - 1;
   
   for (i = 0; i < 16; i++)
   {
      if ((fapi_flash_handle[i].inUse != 0) &&
            (fapi_flash_handle[i].Data_8.index == r8) &&
            (&fapi_flash_handle[i] != a))
      {
         unsigned r5 = fapi_flash_handle[i].Data_8.Data_8;
         unsigned r1 = fapi_flash_handle[i].Data_8.Data_12 + r5 - 1;
         
         if (((r6 >= r5) && (r6 <= r1)) ||
               ((r2 >= r5) && (r2 <= r1)))
         {
            return 0;
         }
      }
   }
   
   return 1;
}


int func_214e2230(unsigned a)
{
   unsigned i, r13;
   int res = 1;
   a = a - 1;
   r13 = 0;
   
   while (a != 0)
   {
      a >>= 1;
      r13++;
   }
   
   r13 -= 22;
      
   for (i = 5; r13 != 0; r13--, i++)
   {
      fapi_flash_gpio_handles[i] = FAPI_GPIO_Open(&Data_21efa794[i], 0);
      
      if (fapi_flash_gpio_handles[i] == 0)
      {
         res = 0;
         break;
      }
   }
   
   return res;
}





