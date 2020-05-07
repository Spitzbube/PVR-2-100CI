
#include <string.h>
#include "fapi/sys_services.h"
#include "fapi/reg_gpio.h"
#include "fapi/drv_gpio.h"



struct fapi_gpio_handle;
struct fapi_gpio_mail;


int FAPI_GPIO_Init(void);
void FAPI_GPIO_Exit(void);
void* FAPI_GPIO_Isr(void);
void FAPI_GPIO_Bsr(void);
static void gpioReleaseHandle(struct fapi_gpio_handle* a);
static int fapi_gpio_check_handle(struct fapi_gpio_handle* a);
static struct fapi_gpio_handle* fapi_gpio_get_handle(void);


static struct
{
   int Data_0;
   unsigned Data_4;
   //8
}
gpioXrefArray[96] = //21b12b94
{
      {0, 0xff},
      {0, 0xff},
      {0, 0xff},
      {0, 0xff},
      {0, 0xff},
      {0, 0xff},
      {0, 0xff},
      {0, 0xff},
      {0, 0xff},
      {0, 0xff},
      {0, 0xff},
      {0, 0xff},
      {0, 0xff},
      {0, 0xff},
      {0, 0xff},
      {0, 0xff},
      {0, 0xff},
      {0, 0xff},
      {0, 0xff},
      {0, 0xff},
      {0, 0xff},
      {0, 0xff},
      {0, 0xff},
      {0, 0xff},
      {0, 0xff},
      {0, 0xff},
      {0, 0xff},
      {0, 0xff},
      {0, 0xff},
      {0, 0xff},
      {0, 0xff},
      {0, 0xff},
      {0, 0xff},
      {0, 0xff},
      {0, 0xff},
      {0, 0xff},
      {0, 0xff},
      {0, 0xff},
      {0, 0xff},
      {0, 0xff},
      {0, 0xff},
      {0, 0xff},
      {0, 0xff},
      {0, 0xff},
      {0, 0xff},
      {0, 0xff},
      {0, 0xff},
      {0, 0xff},
      {0, 0xff},
      {0, 0xff},
      {0, 0xff},
      {0, 0xff},
      {0, 0xff},
      {0, 0xff},
      {0, 0xff},
      {0, 0xff},
      {0, 0xff},
      {0, 0xff},
      {0, 0xff},
      {0, 0xff},
      {0, 0xff},
      {0, 0xff},
      {0, 0xff},
      {0, 0xff},
      {0, 0xff},
      {0, 0xff},
      {0, 0xff},
      {0, 0xff},
      {0, 0xff},
      {0, 0xff},
      {0, 0xff},
      {0, 0xff},
      {0, 0xff},
      {0, 0xff},
      {0, 0xff},
      {0, 0xff},
      {0, 0xff},
      {0, 0xff},
      {0, 0xff},
      {0, 0xff},
      {0, 0xff},
      {0, 0xff},
      {0, 0xff},
      {0, 0xff},
      {0, 0xff},
      {0, 0xff},
      {0, 0xff},
      {0, 0xff},
      {0, 0xff},
      {0, 0xff},
      {0, 0xff},
      {0, 0xff},
      {0, 0xff},
      {0, 0xff},
      {0, 0xff},
      {0, 0xff},
};

static struct
{
   unsigned Data_0; //0
   int Data_4; //4
}
gpioBlockData = //21b12b8c
{
      1, 0
};

static int gpioInitialized; //21b12b7c
static void* gpioSemaphore; //21b12b80
static unsigned gpioMailReadIndex; //21b12b84
static unsigned gpioMailWriteIndex; //21b12b88
static struct fapi_gpio_mail
{
   void (*func)(int); //0
   int Data_4; //4
} gpioMailFifo[96]; //21b14474
static struct fapi_gpio_handle
{
   int magic; //0
   int Data_4; //4
   struct fapi_gpio_params Data_8; //8
   //24
} gpioHandleArray[96]; //21b14774



/* 21b03d58 - complete */
int FAPI_GPIO_Init(void)
{
   unsigned i;

   if (gpioInitialized != 0)
   {
      return 0;
   }

   gpioSemaphore = (FAPI_SYS_Services.createSemaphore != 0)?
         (FAPI_SYS_Services.createSemaphore)(1): 0;

   if (gpioSemaphore == 0)
   {
      return -12009;
   }

   memset(gpioMailFifo, 0, 96*sizeof(struct fapi_gpio_mail));

   gpioMailReadIndex = 0;
   gpioMailWriteIndex = 0;

   if ((gpioBlockData.Data_0 == 0) ||
         (gpioBlockData.Data_0 == 1))
   {
      FREG_GPIO_SetIrqCfg_IrqMode(gpioBlockData.Data_0);
   }

   FREG_GPIO_SetIrqCfg_IrqInput(0);

   if (gpioBlockData.Data_4 != 0)
   {
      FREG_GPIO_SetIrqCfg_IrqClear(1);
      FREG_GPIO_SetIrqCfg_IrqClear(0);
   }

   for (i = 0; i < 96; i++)
   {
      memset(&gpioHandleArray[i], 0, sizeof(struct fapi_gpio_handle));

      gpioHandleArray[i].magic = 0x6770696f; //gpio
      gpioHandleArray[i].Data_4 = 0;
   }

   FREG_GPIO_SetConfig_FlashAddrEn(
         (FREG_GPIO_GetInput_63_32() >> 8) & 1);

   gpioInitialized = 1;

   return 0;
}


/* 21b03e50 - complete */
int FAPI_GPIO_Close(void* a)
{
   struct fapi_gpio_handle* h = a;
   int res = 0;

   LOCK(gpioSemaphore);

   if (0 != fapi_gpio_check_handle(h))
   {
      gpioReleaseHandle(h);
   }
   else
   {
      res = -12008;
   }

   UNLOCK(gpioSemaphore);

   return res;
}


/* 21b03ecc - complete */
void FAPI_GPIO_Exit(void)
{
   if (gpioInitialized != 0)
   {
      unsigned i;

      for (i = 0; i < 96; i++)
      {
         FAPI_GPIO_Close(&gpioHandleArray[i]);
      }

      if (FAPI_SYS_Services.deleteSemaphore != 0)
      {
         (FAPI_SYS_Services.deleteSemaphore)(gpioSemaphore);
      }

      gpioSemaphore = 0;
      gpioInitialized = 0;
   }
}


/* 21b03f74 - complete */
void FAPI_GPIO_SetPinFunction(unsigned a, unsigned b)
{
   if (a <= 95)
   {
      if (((b >= 0x80) && (b <= 0xd9)) ||
            ((b >= 0x101) && (b <= 0x142)) ||
            ((b >= 0x940110) && (b <= 0xc20142)))
      {
         gpioXrefArray[a].Data_0 = 1;
         gpioXrefArray[a].Data_4 = b;
      }
   }
}


/* 21b03fbc - complete */
void FAPI_GPIO_SetIrqTrigger(unsigned a)
{
   if ((a == 0) || (a == 1))
   {
      gpioBlockData.Data_0 = a;
   }
}


/* 21b03fd0 - complete */
void FAPI_GPIO_SetIrqEnable(unsigned a)
{
   if (a == 1)
   {
      gpioBlockData.Data_4 = a;
   }
}


static void* fapi_gpio_queue_request(struct fapi_gpio_mail* a)
{
   void* r1;

   memcpy(&gpioMailFifo[gpioMailWriteIndex], a, sizeof(struct fapi_gpio_mail));

   r1 = &gpioMailFifo[gpioMailWriteIndex++];

   if (gpioMailWriteIndex >= 96)
   {
      gpioMailWriteIndex = 0;
   }

   return r1;
}


/* 21b03fe0 - complete */
void* FAPI_GPIO_Isr(void)
{
   unsigned i;
   struct fapi_gpio_mail* r4 = 0;

   if (0 != FREG_GPIO_GetIrqStatus_GpioIrq())
   {
      FREG_GPIO_SetIrqCfg_IrqClear(1);
      FREG_GPIO_SetIrqCfg_IrqClear(0);

      for (i = 0; i < 96; i++)
      {
         if ((gpioHandleArray[i].Data_4 != 0) &&
               ((gpioHandleArray[i].Data_8.Data_8 == 0x138) ||
               (gpioHandleArray[i].Data_8.Data_8 == 0x143)))
         {
            struct fapi_gpio_mail sp;

            memset(&sp, 0, sizeof(struct fapi_gpio_mail));

            sp.Data_4 = gpioHandleArray[i].Data_8.index;
            sp.func = gpioHandleArray[i].Data_8.func;

            r4 = fapi_gpio_queue_request(&sp);
            break;
         }
      }
   }

   return r4;
}


static struct fapi_gpio_mail* fapi_gpio_dequeue_request(void)
{
   struct fapi_gpio_mail* r0 = &gpioMailFifo[gpioMailReadIndex];

   if (gpioMailReadIndex == gpioMailWriteIndex)
   {
      return 0;
   }

   if (++gpioMailReadIndex >= 96)
   {
      gpioMailReadIndex = 0;
   }

   return r0;
}


/* 21b040a8 - complete */
void FAPI_GPIO_Bsr(void)
{
   struct fapi_gpio_mail* r0 = fapi_gpio_dequeue_request();

   while (r0 != 0)
   {
      if (r0->func != 0)
      {
         (r0->func)(r0->Data_4);
      }

      r0 = fapi_gpio_dequeue_request();
   }
}


static int func_21c1ec74(unsigned r0)
{
   unsigned i;
   for (i = 0; i < 96; i++)
   {
      if (r0 == gpioXrefArray[i].Data_4)
      {
         return i;
      }
   }
   return -1;
}


/* 21b0412c - nearly complete */
void* FAPI_GPIO_Open(struct fapi_gpio_params* params, int* pres)
{
   int r16, r17;
   struct fapi_gpio_handle* h = 0;
   int res = 0;

   if (gpioInitialized == 0)
   {
      res = -12004;
   }

   if (params == 0)
   {
      res = -12001;

      if (pres != 0)
      {
         *pres = res;
      }
      return 0;
   }

   if ((params->index > 95) && (params->index != -1))
   {
      if (pres != 0)
      {
         *pres = -12010;
      }
      return 0;
   }

   if (params->Data_0 > 0x20000)
   {
      if (pres != 0)
      {
         *pres = -12010;
      }
      return 0;
   }

   LOCK(gpioSemaphore);

   h = fapi_gpio_get_handle();

   if (h == 0)
   {
      UNLOCK(gpioSemaphore);

      res = -12002;
      if (pres != 0)
      {
         *pres = res;
      }
      return 0;
   }

   memcpy(&h->Data_8, params, sizeof(struct fapi_gpio_params));

   if (pres != 0)
   {
      *pres = res;
   }

   if (h->Data_8.index == -1)
   {
      h->Data_8.index = func_21c1ec74(h->Data_8.Data_8);

      if (h->Data_8.index == -1)
      {
         gpioReleaseHandle(h);

         UNLOCK(gpioSemaphore);

         res = -12101;
         if (pres != 0)
         {
            *pres = res;
         }
         return 0;
      }
   }
   else
   {
      gpioXrefArray[h->Data_8.index].Data_0 = 1;
      gpioXrefArray[h->Data_8.index].Data_4 = h->Data_8.Data_8;
   }

   if ((h->Data_8.Data_8 >= 0x101) && (h->Data_8.Data_8 <= 0x142))
   {
      r17 = h->Data_8.Data_8 - 0x100;

      FREG_GPIO_SetDataOut_DataEnSel(h->Data_8.index, 1);
      FREG_GPIO_SetDataIn_DataInSel(r17, h->Data_8.index + 2);

      UNLOCK(gpioSemaphore);

      return h;
   }
   else if ((h->Data_8.Data_8 >= 0x80) && (h->Data_8.Data_8 <= 0xd9))
   {
      r16 = h->Data_8.Data_8 - 0x80;

      FREG_GPIO_SetDataOut_DataEnSel(h->Data_8.index, 0);
      FREG_GPIO_SetDataOut_DataOutSel(h->Data_8.index, r16);
      FREG_GPIO_SetDataOut_DataEnExchange(h->Data_8.index, 0);

      if (h->Data_8.Data_8 == 0x9d)
      {
         FREG_GPIO_SetDataOut_DataEnSel(h->Data_8.index, 0x0a);
      }

      if (h->Data_8.Data_8 == 0x94)
      {
         FREG_GPIO_SetDataOut_DataEnSel(h->Data_8.index, 0x05);
      }

      if ((h->Data_8.Data_8 == 0x98) ||
            (h->Data_8.Data_8 == 0x99) ||
            (h->Data_8.Data_8 == 0xc1) ||
            (h->Data_8.Data_8 == 0xc2))
      {
         FREG_GPIO_SetDataOut_DataEnExchange(h->Data_8.index, 1);
      }

      UNLOCK(gpioSemaphore);

      return h;
   }
   else if ((h->Data_8.Data_8 >= 0x940110) &&
         (h->Data_8.Data_8 <= 0xc20142))
   {
      r16 = (h->Data_8.Data_8 >> 16) - 0x80;
      r17 = (h->Data_8.Data_8 & 0xFFFF) - 0x100;

      FREG_GPIO_SetDataOut_DataEnSel(h->Data_8.index, 0);
      FREG_GPIO_SetDataOut_DataEnExchange(h->Data_8.index, 1);

      if (h->Data_8.Data_8 == 0x9d0112)
      {
         FREG_GPIO_SetDataOut_DataEnSel(h->Data_8.index, 0x0a);
         FREG_GPIO_SetDataOut_DataEnExchange(h->Data_8.index, 0);
      }

      if (h->Data_8.Data_8 == 0x940110)
      {
         FREG_GPIO_SetDataOut_DataEnSel(h->Data_8.index, 0x05);
         FREG_GPIO_SetDataOut_DataEnExchange(h->Data_8.index, 0);
      }

      FREG_GPIO_SetDataIn_DataInSel(r17, h->Data_8.index + 2);
      FREG_GPIO_SetDataOut_DataOutSel(h->Data_8.index, r16);

      UNLOCK(gpioSemaphore);

      return h;
   }
   else if (h->Data_8.Data_8 == 0x810000)
   {
      FREG_GPIO_SetDataOut_DataEnableInv(h->Data_8.index, 0);
      FREG_GPIO_SetDataOut_DataOutInv(h->Data_8.index, 0);
      FREG_GPIO_SetDataOut_DataEnExchange(h->Data_8.index, 0);
      FREG_GPIO_SetDataOut_DataOutSel(h->Data_8.index, 0);
      FREG_GPIO_SetDataOut_DataEnSel(h->Data_8.index, 1);

      UNLOCK(gpioSemaphore);

      return h;
   }
   else if (h->Data_8.Data_8 == 0x143)
   {
      FREG_GPIO_SetDataOut_DataEnableInv(h->Data_8.index, 0);
      FREG_GPIO_SetDataOut_DataOutInv(h->Data_8.index, 0);
      FREG_GPIO_SetDataOut_DataEnExchange(h->Data_8.index, 0);
      FREG_GPIO_SetDataOut_DataOutSel(h->Data_8.index, 0);
      FREG_GPIO_SetDataOut_DataEnSel(h->Data_8.index, 1);
      FREG_GPIO_SetIrqCfg_IrqInput(h->Data_8.index);
      FREG_GPIO_SetIrqCfg_IrqClear(1);
      FREG_GPIO_SetIrqCfg_IrqClear(0);

      UNLOCK(gpioSemaphore);

      return h;
   }
   else if (h->Data_8.Data_8 >= 0x810000)
   {
      r16 = (h->Data_8.Data_8 >> 16) - 0x80;

      FREG_GPIO_SetDataOut_DataEnSel(h->Data_8.index, 0);
      FREG_GPIO_SetDataOut_DataEnExchange(h->Data_8.index, 1);
      FREG_GPIO_SetDataOut_DataOutSel(h->Data_8.index, r16);
   }
   else
   {
      gpioReleaseHandle(h);

      res = -12001;

      UNLOCK(gpioSemaphore);

      if (pres != 0)
      {
         *pres = res;
      }
      return 0;
   }

   UNLOCK(gpioSemaphore);

   return h;
}


int fapi_gpio_check_handle(struct fapi_gpio_handle* a)
{
   //int res = 0;

   if ((gpioInitialized != 0) &&
         (a != 0) &&
         (a->Data_4 != 0) &&
         (a->magic == 0x6770696f)) //gpio
   {
      //res = 1;
      return 1;
   }

   return 0; //res;
}


/* 21b045d4 - complete */
int FAPI_GPIO_ReadBit(void* a)
{
   struct fapi_gpio_handle* r4 = a;

   if (0 == fapi_gpio_check_handle(r4))
   {
      return -12008;
   }

   if (((r4->Data_8.Data_8 >= 0x101) && (r4->Data_8.Data_8 <= 0x142)) ||
         ((r4->Data_8.Data_8 >= 0x940110) && (r4->Data_8.Data_8 <= 0xc20142)) ||
         (r4->Data_8.Data_8 == 0x810000) ||
         (r4->Data_8.Data_8 == 0x143))
   {
      if ((unsigned)(r4->Data_8.index) <= 31)
      {
         return (FREG_GPIO_GetInput_31_0() >> r4->Data_8.index) & 1;
      }

      if ((r4->Data_8.index >= 32) && (r4->Data_8.index <= 63))
      {
         return (FREG_GPIO_GetInput_63_32() >> (r4->Data_8.index - 32)) & 1;
      }

      if ((r4->Data_8.index >= 64) && (r4->Data_8.index <= 95))
      {
         return (FREG_GPIO_GetInput_95_64() >> (r4->Data_8.index - 64)) & 1;
      }
   }

   return -12005;
}


/* 21b046b4 - complete */
int FAPI_GPIO_WriteBit(void* a, int b)
{
   struct fapi_gpio_handle* r5 = a;

   if (0 == fapi_gpio_check_handle(r5))
   {
      return -12008;
   }

   if ((b < 0) || (b > 1))
   {
      return -12001;
   }

   if (((r5->Data_8.Data_8 >= 0x80) && (r5->Data_8.Data_8 <= 0xd9)) ||
         ((r5->Data_8.Data_8 >= 0x940110) && (r5->Data_8.Data_8 <= 0xc20142)) ||
         (r5->Data_8.Data_8 == 0x810000))
   {
      if (r5->Data_8.Data_8 != 0x810000)
      {
         FREG_GPIO_SetDataOut_DataOutSel(r5->Data_8.index, b);
      }
      else
      {
         FREG_GPIO_SetDataOut_DataEnSel(r5->Data_8.index, b);
      }
   }
   else
   {
      return -12005;
   }

   return b;
}


/* 21b04760 - complete */
void gpioReleaseHandle(struct fapi_gpio_handle* a)
{
   if (0 != fapi_gpio_check_handle(a))
   {
      if (memset(a, 0, sizeof(struct fapi_gpio_handle)) != 0)
      {
         a->Data_4 = 0;
         a->magic = 0x6770696f; //gpio
         a->Data_8.Data_8 = 0xFF;
         a->Data_8.index = 96;
      }
   }
}


struct fapi_gpio_handle* fapi_gpio_get_handle(void)
{
   unsigned i;
   struct fapi_gpio_handle* h = 0;

   for (i = 0; i < 96; i++)
   {
      if (gpioHandleArray[i].Data_4 == 0)
      {
         gpioHandleArray[i].Data_4 = 1;

         h = &gpioHandleArray[i];
         break;
      }
   }

   return h;
}




