

#include <fapi/sys_services.h>
#include <fapi/drv_intr.h>
#include <fapi/drv_gpio.h>
#include <fapi/drv_timer.h>
#include <fapi/drv_i2c.h>
#include "drv_i2c_priv.h"


struct fapi_i2c_handle;


uint32_t func_21c27174(int);
uint32_t func_21c26de4(int);
int i2cHardwareReceive(struct fapi_i2c_handle* r5, char addr,
      uint8_t* pTxData, unsigned numTxData,
      uint8_t* pRxData, unsigned numRxData);
int i2cHardwareTransmit(struct fapi_i2c_handle* r5, char addr,
      uint8_t* pTxData, unsigned numTxData);
int func_21c254f8(int);
uint32_t func_21c255ac(int);
void i2cHardwareReset(int);
void func_21c2445c(void);
void func_21c24348(void);
void func_21c23f00(void);

int func_21c240a4(struct fapi_i2c_handle*, 
      char, uint8_t*, unsigned, uint8_t*, unsigned);

static struct fapi_i2c_handle* fapi_i2c_get_handle(int);
int32_t fapi_i2c_check_handle(struct fapi_i2c_handle*);


FAPI_SYS_DriverT FAPI_I2C_Driver0 = //21efb1b4
{
      "I2C0",
      FAPI_INTR_I2C0,
      FAPI_SYS_BSR_EXEC_UNDEFINED,
      FAPI_I2C_Init,
      FAPI_I2C_Exit,
      FAPI_I2C_Isr0,
      0,
      0,
      0,
};

FAPI_SYS_DriverT FAPI_I2C_Driver1 = //21efb1d8
{
      "I2C1",
      FAPI_INTR_I2C1,
      FAPI_SYS_BSR_EXEC_UNDEFINED,
      FAPI_I2C_Init,
      FAPI_I2C_Exit,
      FAPI_I2C_Isr1,
      0,
      0,
      0,
};

FAPI_SYS_DriverT FAPI_I2C_Driver2 = //21efb1fc
{
      "I2C2",
      FAPI_INTR_I2C2,
      FAPI_SYS_BSR_EXEC_UNDEFINED,
      FAPI_I2C_Init,
      FAPI_I2C_Exit,
      FAPI_I2C_Isr2,
      0,
      0,
      0,
};


struct fapi_i2c_block
{
   int inUse; //0
   unsigned useCount; //4
   unsigned maxUse; //8
   FAPI_SYS_SemaphoreT semaphore; //12
   int error; //16
   FAPI_SYS_HandleT gpioClk; //20
   FAPI_SYS_HandleT gpioData; //24
   FAPI_I2C_OperationModeT operationMode; //28
   int fill_32; //32
   char* pRxData; //36
   char* pTxData; //40
   int fill_44; //44
   unsigned numRxData; //48
   unsigned numTxData; //52
   int fill_56; //56
   int addr; //60
   uint32_t controlReg0; //64
   uint32_t controlReg1; //68
   uint32_t (*Isr)(int); //72
   //76
};

static struct fapi_i2c_block i2cBlockData[3] = //21efb220
{
      {0,0,4,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,func_21c255ac},
      {0,0,4,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,func_21c255ac},
      {0,0,4,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,func_21c255ac},
};
static int i2cInitialized = 0; //21f233cc
static FAPI_SYS_SemaphoreT i2cSemaphore = 0; //21f233d0

struct fapi_i2c_handle
{
   int magic; //0
   int inUse; //4
   uint32_t index; //8
   FAPI_I2C_ProtocolT protocol; //12
   FAPI_I2C_OpenParamsT params; //16
   int (*Data_44)(int); //44
   int (*receive)(struct fapi_i2c_handle*, char, uint8_t*, unsigned, uint8_t*, unsigned); //48
   int (*transmit)(struct fapi_i2c_handle*, char, uint8_t*, unsigned); //52
   void (*resetLines)(int); //56
   //60
};

struct fapi_i2c_handle i2cHandleArray[12]; //21f2341c




/* 21c23344 - complete */
int32_t FAPI_I2C_Init(void)
{
   int j;
   FAPI_GPIO_OpenParamsT gpio;
   int32_t i = 0;

   if (i2cInitialized == 1)
   {
      return 0;
   }

   i2cSemaphore = FAPI_SYS_CREATE_SEMAPHORE(1);
   if (i2cSemaphore == 0)
   {
      return FAPI_I2C_ERR_SEMAPHORE_CREATE;
   }

   for (i = 0; i < 3; i++)
   {
      i2cBlockData[i].semaphore = FAPI_SYS_CREATE_SEMAPHORE(1);
   }

   memset(i2cHandleArray, 0, 12*sizeof(struct fapi_i2c_handle));

   for (j = 11; j >= 0; j--)
   {
      i2cHandleArray[j].magic = 0x00693263;
   }

   for (i = 0; i < 3; i++)
   {
      if (i == 0)
      {
         gpio.version = FAPI_GPIO_VERSION;
         gpio.pin = FAPI_GPIO_PIN_AUTODETECT;
         gpio.function = FAPI_GPIO_BIDI_I2C0_CLK;
         gpio.callback = 0;
         i2cBlockData[i].gpioClk = FAPI_GPIO_Open(&gpio, 0);

         gpio.function = FAPI_GPIO_BIDI_I2C0_DATA;
         i2cBlockData[i].gpioData = FAPI_GPIO_Open(&gpio, 0);
      }
      else if (i == 1)
      {
         gpio.version = FAPI_GPIO_VERSION;
         gpio.pin = FAPI_GPIO_PIN_AUTODETECT;
         gpio.function = FAPI_GPIO_BIDI_I2C1_CLK;
         gpio.callback = 0;
         i2cBlockData[i].gpioClk = FAPI_GPIO_Open(&gpio, 0);

         gpio.function = FAPI_GPIO_BIDI_I2C1_DATA;
         i2cBlockData[i].gpioData = FAPI_GPIO_Open(&gpio, 0);
      }

      if (i2cBlockData[i].operationMode == FAPI_I2C_AUTO_MASTER_MODE)
      {
         i2cBlockData[i].Isr = func_21c255ac;
      }
      else if (i2cBlockData[i].operationMode == FAPI_I2C_GENERIC_MASTER_MODE)
      {
         i2cBlockData[i].Isr = func_21c27174;
      }
      else
      {
         i2cBlockData[i].Isr = func_21c26de4;
      }
   }

   i2cInitialized = 1;
   
   return 0;
}


/* 21c2325c - complete */
void FAPI_I2C_Exit(void)
{
   int j;

   if (i2cInitialized != 0)
   {
      for (j = 11; j >= 0; j--)
      {
         if (i2cHandleArray[j].inUse == 1)
         {
            FAPI_I2C_Close(&i2cHandleArray[j]);
         }
      }

      FAPI_SYS_GET_SEMAPHORE(i2cSemaphore, FAPI_SYS_SUSPEND);

      for (j = 1; j >= 0; j--)
      {
         FAPI_GPIO_Close(i2cBlockData[j].gpioData);
         FAPI_GPIO_Close(i2cBlockData[j].gpioClk);
      }

      i2cInitialized = 0;

      FAPI_SYS_SET_SEMAPHORE(i2cSemaphore, FAPI_SYS_NO_SUSPEND);

      FAPI_SYS_DESTROY_SEMAPHORE(i2cSemaphore);

      i2cSemaphore = 0;
   }
}


/* 21c23050 - complete */
uint32_t FAPI_I2C_Isr0(void)
{
   return i2cBlockData[0].Isr(0);
}


/* 21c2306c - complete */
uint32_t FAPI_I2C_Isr1(void)
{
   return i2cBlockData[0].Isr(1);
}


/* 21c23088 - complete */
uint32_t FAPI_I2C_Isr2(void)
{
   return i2cBlockData[0].Isr(2);
}


/* 21c24f3c - todo */
FAPI_SYS_HandleT FAPI_I2C_Open(const FAPI_I2C_OpenParamsT* pParams,
                               int32_t* errorCodePtr)
{
   struct fapi_i2c_handle* h;
   int32_t res = 0;

   if (i2cInitialized == 0)
   {
      res = 0xffffc564;
   }

   if (pParams == 0)
   {
      res = 0xffffc567;
      if (errorCodePtr != 0)
      {
         *errorCodePtr = res;
      }
      return 0;
   }

   if (pParams->version > 0x30000)
   {
      res = 0xffffc55e;
   }

#if 0
   if (pParams->blockIndex == 0)
   {
   }
   else if (pParams->blockIndex == 1)
   {
   }
   else if (pParams->blockIndex == 2)
   {
   }
   else
   {
      res = FAPI_I2C_ERR_BAD_PARAMETER;
   }

   if (pParams->type == FAPI_I2C_HARDWARE)
   {
   }
   else if (pParams->type == FAPI_I2C_SOFTWARE)
   {
   }
   else
   {
      res = FAPI_I2C_ERR_BAD_PARAMETER;
   }

   if (pParams->speed == FAPI_I2C_100KBPS)
   {
   }
   else if (pParams->speed == FAPI_I2C_400KBPS)
   {
   }
   else if (pParams->speed == 3)
   {
      if (pParams->type != FAPI_I2C_SOFTWARE)
      {
         res = FAPI_I2C_ERR_BAD_PARAMETER;
      }
   }
   else
   {
      res = FAPI_I2C_ERR_BAD_PARAMETER;
   }

   if (pParams->protocol == FAPI_I2C_COMMON_PROTOCOL)
   {
   }
   else if (pParams->protocol == FAPI_I2C_RESTART_PROTOCOL)
   {
   }
   else
   {
      res = FAPI_I2C_ERR_BAD_PARAMETER;
   }
#else
   if (pParams->blockIndex > 2)
   {
      res = 0xffffc567;
   }

   if (pParams->type > 1)
   {
      res = 0xffffc567;
   }

   if ((pParams->speed < 1) || (pParams->speed > 3))
   {
      res = 0xffffc567;
   }

   if ((pParams->speed == 3) && (pParams->type != 1))
   {
      res = 0xffffc567;
   }
   //21c24fa8
   if (pParams->protocol > 1)
   {
      res = 0xffffc567;
   }
#endif

   if (pParams->timeOut < 100)
   {
      res = 0xffffc567;
   }

   if (res != 0)
   {
      //21c2508c
      if (errorCodePtr != 0)
      {
         *errorCodePtr = res;
      }
      return 0;
   }

   FAPI_SYS_GET_SEMAPHORE(i2cSemaphore, FAPI_SYS_SUSPEND);

   h = fapi_i2c_get_handle(pParams->blockIndex);

   if (0 != fapi_i2c_check_handle(h))
   {
      memcpy(&h->params, pParams, sizeof(h->params));

      //h->index = pParams->blockIndex;
      
      i2cBlockData[pParams->blockIndex].inUse = 1;

      h->index = pParams->blockIndex;

#if 0
      if (i2cBlockData[pParams->blockIndex].operationMode != 2)
      {
         //21c25114
         i2cSetControlreg1_SlSlaAdd(pParams->blockIndex,
               h->params.slaveAddress >> 1);
      }
      else
      {
         //21c253b4
         i2cSetControlreg1_SlSlaAdd(pParams->blockIndex, 0);      
      }
#else
      i2cSetControlreg1_SlSlaAdd(pParams->blockIndex,
            (i2cBlockData[pParams->blockIndex].operationMode != 2)?
                  h->params.slaveAddress >> 1: 0);
#endif
      //21c25128
      h->protocol = pParams->protocol;

      if (pParams->type == FAPI_I2C_HARDWARE) //0)
      {
         //21c2513c
         h->Data_44 = func_21c254f8;
         h->receive = i2cHardwareReceive;
         h->transmit = i2cHardwareTransmit;
         h->resetLines = i2cHardwareReset;

         if (i2cBlockData[pParams->blockIndex].operationMode == 2)
         {
            //21c2524c
            i2cBlockData[pParams->blockIndex].Isr = func_21c255ac;

            i2cSetControlreg0_AmMode(pParams->blockIndex, 2);
            //21c25260
            i2cSetControlreg0_UseAdd(pParams->blockIndex, 1);
            //21c25274
            i2cSetControlreg0_AmOn(pParams->blockIndex, 1);
            //21c25288
            i2cSetControlreg1_I2cSpeed(pParams->blockIndex, 1);
            //21c2529c
            i2cSetControlreg0_SpikeFlt(pParams->blockIndex, 1);
            //21c252b0
            i2cSetControlreg0_OiDlyAl(pParams->blockIndex, 1);
            //21c252c4
            i2cBlockData[pParams->blockIndex].controlReg0 =
                  i2cGetControlreg0(pParams->blockIndex);
            //21c252f4
            i2cSetControlreg1(pParams->blockIndex, 0);
            //21c25308
            i2cBlockData[pParams->blockIndex].controlReg1 =
                  i2cGetControlreg1(pParams->blockIndex);
            //21c25338
            i2cSetIrqmask0(pParams->blockIndex, 0);
            //21c2534c
            i2cSetIrqmask1(pParams->blockIndex, 0);
            //21c25360
            i2cSetIrqmask1_AmEnd(pParams->blockIndex, 1);
            //21c25374
            i2cSetIrqmask1_AmErr(pParams->blockIndex, 1);
            //21c25388
            i2cSetIrqmask1_AmMrxReq(pParams->blockIndex, 1);
            //21c2539c
            i2cSetIrqmask1_AmMtxReq(pParams->blockIndex, 1);
            //->21c25060
         }
         //21c25184
         else if (i2cBlockData[pParams->blockIndex].operationMode == 0)
         {
            //21c25194
            i2cBlockData[pParams->blockIndex].Isr = func_21c27174;
            i2cBlockData[pParams->blockIndex].controlReg0 = 0;

            i2cSetControlreg0_SpikeFlt(pParams->blockIndex, 1);
            //21c251b0
            i2cSetControlreg0_OiDlyAl(pParams->blockIndex, 1);
            //21c251c4
            i2cBlockData[pParams->blockIndex].controlReg1 = 0;
            //->21c25060
         }
         else
         {
            //21c25188
            i2cBlockData[pParams->blockIndex].Isr = func_21c26de4;
            //->21c25060
         }
      } //if (pParams->type == FAPI_I2C_HARDWARE) //0)
      else
      {
         //21c2521c
         h->Data_44 = func_21c2445c;
         h->receive = func_21c240a4;
         h->transmit = func_21c23f00;
         h->resetLines = func_21c24348;
         //->21c25060
      }
   }
   else
   {
      res = 0xffffc566;
   }
   //21c25060
   FAPI_SYS_SET_SEMAPHORE(i2cSemaphore, FAPI_SYS_NO_SUSPEND);

   if (errorCodePtr != 0)
   {
      *errorCodePtr = res;
   }

   return h;
}


/* 21c23168 - complete */
void FAPI_I2C_Reset(FAPI_SYS_HandleT handle)
{
   struct fapi_i2c_handle* a = handle;

   if (0 == fapi_i2c_check_handle(a))
   {
      return;
   }

   (a->resetLines)(a->index);
}


/* 21c2318c - complete */
int32_t FAPI_I2C_Close(const FAPI_SYS_HandleT handle)
{
   int32_t res = 0;
   struct fapi_i2c_handle* a = handle;

   FAPI_SYS_GET_SEMAPHORE(i2cSemaphore, FAPI_SYS_SUSPEND);

   if (0 == fapi_i2c_check_handle(a))
   {
      res = FAPI_I2C_ERR_INVALID_HANDLE;
   }
   else
   {
      i2cBlockData[a->index].useCount--;

      memset(a, 0, sizeof(struct fapi_i2c_handle));

      a->inUse = 0;
      a->magic = 0x00693263;
      a->index = -1;
   }

   FAPI_SYS_SET_SEMAPHORE(i2cSemaphore, FAPI_SYS_NO_SUSPEND);

   return res;
}


void FAPI_I2C_CancelProcess(const FAPI_SYS_HandleT handle)
{
   
}


int32_t FAPI_I2C_Process(const FAPI_SYS_HandleT handle,
                                  uint8_t* dataPtr,
                                  const uint32_t dataLength)
{
   return 0;
}


/* 21c23124 - complete */
int32_t FAPI_I2C_Write(const FAPI_SYS_HandleT handle,
                                const uint8_t msSlaveAddress,
                                uint8_t* txDataPtr,
                                const uint32_t txDataLength)
{
   struct fapi_i2c_handle* a = handle;

   if (0 == fapi_i2c_check_handle(a))
   {
      return 0xffffc560;
   }

   return a->transmit(a, msSlaveAddress, txDataPtr, txDataLength);
}


/* 21c230c8 - complete */
int32_t FAPI_I2C_Read(const FAPI_SYS_HandleT handle,
                               const uint8_t msSlaveAddress,
                               uint8_t* txDataPtr,
                               const uint32_t txDataLength,
                               uint8_t* rxDataPtr,
                               uint32_t rxDataLength)
{
   struct fapi_i2c_handle* a = handle;

   if (0 == fapi_i2c_check_handle(a))
   {
      return 0xffffc560;
   }

   return a->receive(a, msSlaveAddress, txDataPtr, txDataLength, 
         rxDataPtr, rxDataLength);
}


void FAPI_I2C_SetOperationMode(const uint32_t blockIndex,
                                           const FAPI_I2C_OperationModeT operationMode)
{
   
}


int32_t FAPI_I2C_SetProtocol(const FAPI_SYS_HandleT handle,
                                      const FAPI_I2C_ProtocolT protocol)
{
   return 0;
}


void FAPI_I2C_SetMaxHandleCount(const uint32_t blockIndex,
                                            const uint32_t maximum)
{
   
}


/* 21c27174 - todo */
uint32_t func_21c27174(int a)
{
   printf("func_21c27174(a=%d)\n", a);

   return 0;
}


/* 21c254f8 - complete */
int func_21c254f8(int a)
{
   printf("func_21c254f8(a=%d)\n", a);
   
#if 0
   int r0 = FREG_I2C_get_ControlReg2(a);

   if (r0 != 0)
   {
      i2cSetControlreg2(a, 1);
      i2cSetTxdatareg(a, 0);
   }

   r0 = FREG_I2C_get_ControlReg3(a);

   if (r0 == 0)
   {
      return 0;
   }

   i2cSetControlreg3(a, 1);

   return i2cGetRxdatareg(a);
#endif
   return 0;
}


/* 21c26288 - todo */
int i2cHardwareReceive(struct fapi_i2c_handle* r5, char addr,
      uint8_t* pTxData, unsigned numTxData,
      uint8_t* pRxData, unsigned numRxData)
{
   unsigned long long t1, t2;
   int tdiff;
   unsigned cpu_sr;
   int r4_;
   unsigned tmax;

   if (0 == fapi_i2c_check_handle(r5))
   {
      return 0xffffc560;
   }

   unsigned speed = r5->params.speed;

   if ((speed - 1) > 1)
   {
      return 0xffffc567;
   }

   if (r5->params.type > 1)
   {
      return 0xffffc567;
   }

   if (r5->protocol > 1)
   {
      return 0xffffc567;
   }

   if (pRxData == 0)
   {
      return 0xffffc567;
   }

   if ((numTxData >= 4096) || (numRxData >= 4096))
   {
      return 0xffffc567;
   }

   if (i2cBlockData[r5->index].error == 0xffffc504)
   {
      return 0xffffc504;
   }

   if (speed == 1)
   {
      //21c26da4
      tmax = numRxData*16/100 + r5->params.timeOut;
   }
   else
   {
      //21c26330
      tmax = numRxData*16/400 + r5->params.timeOut;
   }
   //21c26348
   int r0 = i2cGetStatusreg1(r5->index);
   //21c26358
   if (0 != FREG_I2C_ExtractStatusreg1_Occup(r0))
   {
      return 0xffffc503;
   }

   FAPI_SYS_GET_SEMAPHORE(i2cSemaphore, -1);

   i2cBlockData[r5->index].pTxData = pTxData;
   i2cBlockData[r5->index].pRxData = pRxData;

   FAPI_SYS_SET_SEMAPHORE(i2cSemaphore, 0);

   cpu_sr = FAPI_SYS_DISABLE_IRQ;;

   i2cSetControlreg1(r5->index,
         i2cBlockData[r5->index].controlReg1);
   //21c26414
   if (speed == 2)
   {
      //21c26d6c
      i2cSetControlreg1_I2cSpeed(r5->index, 1);
   }
   else
   {
      //21c2641c
      i2cSetControlreg1_I2cSpeed(r5->index, 0);
   }
   //21c26430
   switch (i2cBlockData[r5->index].operationMode)
   {
   case 2:
      //21c26544
      i2cSetControlreg0(r5->index,
            i2cBlockData[r5->index].controlReg0);
      //21c26554
      i2cSetControlreg0_AmMode(r5->index, 2);
      //21c26568
      i2cSetControlreg0_Reset(r5->index, 1);
      //21c2657c
      i2cSetControlreg0_Reset(r5->index, 0);
      //21c26590
      switch (r5->protocol)
      {
      case 0:
         //21c26734
         if (numTxData != 0)
         {
            //21c26744
            i2cSetIrqmask1_AmEnd(r5->index, 1);
            //21c26758
            i2cSetIrqmask1_AmErr(r5->index, 1);
            //21c2676c
            i2cSetIrqmask1_AmMrxReq(r5->index, 1);
            //21c26780
            i2cSetIrqmask1_AmMtxReq(r5->index, 1);
            //21c26794
            i2cSetIrqmask0(r5->index, 0);
            //21c267a8
            i2cSetControlreg1_MsSlaAdd(r5->index, addr >> 1);
            //21c267bc
            i2cSetControlreg2(r5->index, numTxData + 2);
            //21c267d0
            i2cSetControlreg3(r5->index, 1);
            //21c267e4
            i2cBlockData[r5->index].error = 0xffffc504;
            //21c2680c
            i2cSetGoreg_AmReset(r5->index, 1);
            //21c26820
            i2cSetGoreg(r5->index, 0);
            //21c26834
            i2cSetGoreg_AmStart(r5->index, 1);
            //21c26848
            FAPI_SYS_ENABLE_IRQ(cpu_sr);

            t1 = FAPI_TIMER_GetTimeStamp(1000);
            do
            {
               //21c26870
               t2 = FAPI_TIMER_GetTimeStamp(1000);
               tdiff = t2 - t1;

               if (t1 > t2)
               {
                  if (tdiff < 0)
                  {
                     tdiff = -tdiff;
                  }
               }
               //21c26888
            }
            while ((i2cBlockData[r5->index].error == 0xffffc504) &&
                  (tdiff < tmax));
            //21c268cc
            FAPI_SYS_GET_SEMAPHORE(i2cSemaphore, -1);
            //21c268e8
            cpu_sr = FAPI_SYS_DISABLE_IRQ;
            //21c268fc
            if (i2cBlockData[r5->index].error == 0xffffc504)
            {
               i2cBlockData[r5->index].error = -6;
            }

            FAPI_SYS_SET_SEMAPHORE(i2cSemaphore, 0);
            //21c26950
            if (i2cBlockData[r5->index].error != 0)
            {
               return i2cBlockData[r5->index].error;
            }
            //21c2697c
            r4_ = 1;
         } //if (numTxData != 0)
         else
         {
            r4_ = 0;
            //->21c26980
         }
         //21c26980
         i2cSetControlreg0_AmMode(r5->index, 1);
         //21c26994
         if (r4_ == 0)
         {
            //21c2699c
            i2cSetIrqmask1_AmEnd(r5->index, 1);
            //21c269b0
            i2cSetIrqmask1_AmErr(r5->index, 1);
            //21c269c4
            i2cSetIrqmask1_AmMrxReq(r5->index, 1);
            //21c269d8
            i2cSetIrqmask1_AmMtxReq(r5->index, 1);
            //21c269ec
            i2cSetIrqmask0(r5->index, 0);
            //21c26a00
            i2cSetControlreg1_MsSlaAdd(r5->index, addr >> 1);
         }
         //21c26a14
         i2cSetControlreg2(r5->index, 1);
         //21c26a28
         i2cSetControlreg3(r5->index, numRxData);
         //21c26a3c
         i2cBlockData[r5->index].error = 0xffffc504;
         //21c26a64
         i2cSetGoreg_AmReset(r5->index, 1);
         //->21c266d8
         i2cSetGoreg(r5->index, 0);
         //21c266ec
         i2cSetGoreg_AmStart(r5->index, 1);
         //->21c26464
         break;

      case 1:
         //21c265a4
         i2cBlockData[r5->index].numTxData = numTxData + 2;
         i2cBlockData[r5->index].error = -15100; //0xffffc504;

         i2cSetControlreg0_AmMode(r5->index, 2);
         //21c26608
         i2cSetControlreg1_MsSlaAdd(r5->index, addr >> 1);
         //21c2661c
         i2cSetControlreg2(r5->index,
               i2cBlockData[r5->index].numTxData);
         //21c2664c
         i2cSetControlreg3(r5->index, numRxData);
         //21c26660
         i2cSetIrqmask1_AmEnd(r5->index, 1);
         //21c26674
         i2cSetIrqmask1_AmErr(r5->index, 1);
         //21c26688
         i2cSetIrqmask1_AmMrxReq(r5->index, 1);
         //21c2669c
         i2cSetIrqmask1_AmMtxReq(r5->index, 1);
         //21c266b0
         i2cSetIrqmask0(r5->index, 0);
         //21c266c4
         i2cSetGoreg_AmReset(r5->index, 1);
         //21c266d8
         i2cSetGoreg(r5->index, 0);
         //21c266ec
         i2cSetGoreg_AmStart(r5->index, 1);
         //->21c26464
         break;
      }
      break;
      //->21c26464

   case 0:
      //21c26c28
#if 0
      i2cBlockData[r5->index].numTxData = numTxData;
      i2cBlockData[r5->index].numRxData = numRxData;
      i2cBlockData[r5->index].addr = addr;
      i2cBlockData[r5->index].fill_32 = 2;
      i2cBlockData[r5->index].error = 0xffffc504;
#else
      i2cBlockData[r5->index].fill_32 = 2;
      i2cBlockData[r5->index].numTxData = numTxData;
      i2cBlockData[r5->index].numRxData = numRxData;
      i2cBlockData[r5->index].addr = addr;
      i2cBlockData[r5->index].error = 0xffffc504;
#endif

      i2cSetControlreg0(r5->index, 0);
      //21c26cb0
      i2cSetIrqmask0(r5->index, 0xffff);
      //21c26cc4
      i2cSetTxdatareg(r5->index, addr);
      //21c26cd8
      i2cSetControlreg0(r5->index, 4);
      //21c26cec
      i2cSetGoreg(r5->index, 1);
      //21c26d00
      i2cSetControlreg0(r5->index, 0);
      //->21c26464
      break;
   }
   //21c26464
   FAPI_SYS_ENABLE_IRQ(cpu_sr);

   t1 = FAPI_TIMER_GetTimeStamp(1000);
   do
   {
      //21c2648c
      t2 = FAPI_TIMER_GetTimeStamp(1000);
      tdiff = t2 - t1;

      if (t1 > t2)
      {
         if (tdiff < 0)
         {
            tdiff = -tdiff;
         }
      }
      //21c264a4
   }
   while ((i2cBlockData[r5->index].error == 0xffffc504) &&
         (tdiff < tmax));
   //21c264ec
   if (i2cBlockData[r5->index].error == 0xffffc504)
   {
      i2cBlockData[r5->index].error = -6;
      //->21c2651c
   }
   else
   {
      //21c264fc
      i2cSetIrqmask1(r5->index, 0);
      //21c26508
      i2cSetGoreg_AmReset(r5->index, 1);
   }
   //21c2651c
   return i2cBlockData[r5->index].error;
}


/* 21c26de4 - todo */
uint32_t func_21c26de4(int a)
{
   printf("func_21c26de4(a=%d)\n", a);
   
   return 0;
}


/* 21c255ac - complete */
uint32_t func_21c255ac(int a)
{
//   printf("func_21c255ac(a=%d)\n", a);
   
   unsigned status = i2cGetStatusreg1(a);

   if (0 != FREG_I2C_ExtractStatusreg1_AmErr(status))
   {
      status = i2cGetStatusreg0(a);

      if (0 != FREG_I2C_ExtractStatusreg0_BeStop(status))
      {
         i2cBlockData[a].error = FAPI_I2C_ERR_BE_STOP; //-15104; //0xffffc500;
      }
      else if (0 != FREG_I2C_ExtractStatusreg0_BeStart(status))
      {
         i2cBlockData[a].error = FAPI_I2C_ERR_BE_START; //-15105;
      }
      else if (0 != FREG_I2C_ExtractStatusreg0_AlAdrsta(status))
      {
         i2cBlockData[a].error = FAPI_I2C_ERR_AL_ADRSTA; //-15106; //0xffffc4fe;
      }
      else if (0 != FREG_I2C_ExtractStatusreg0_AlData(status))
      {
         i2cBlockData[a].error = FAPI_I2C_ERR_AL_DATA; //-15107; //0xffffc4fd;
      }
      else if (0 != FREG_I2C_ExtractStatusreg0_AlStop(status))
      {
         i2cBlockData[a].error = FAPI_I2C_ERR_AL_STOP; //-15108; //0xffffc4fc;
      }
      else if (0 != FREG_I2C_ExtractStatusreg0_SlNack(status))
      {
         i2cBlockData[a].error = FAPI_I2C_ERR_SL_NACK; //-15109; //0xffffc4fb;
      }
      else if (0 != FREG_I2C_ExtractStatusreg0_RcNack(status))
      {
         i2cBlockData[a].error = FAPI_I2C_ERR_RC_NACK; //-15103; //0xffffc501;
      }
      else if (0 != FREG_I2C_ExtractStatusreg0_MsStopRec(status))
      {
         i2cBlockData[a].error = FAPI_I2C_ERR_MS_STOP_REC; //-15110; //0xffffc4fa;
      }
      else if (i2cBlockData[a].error == FAPI_I2C_ERR_BUSY) //-15100) //0xffffc504)
      {
         i2cBlockData[a].error = FAPI_I2C_ERR_AMDMA; //-15111; //0xFFFFC4F9;
      }

      i2cSetIrqmask1(a, 0);
   }
   else
   {
      int r8 = 0;

      if (0 != FREG_I2C_ExtractStatusreg1_AmMtxReq(status))
      {
         i2cSetTxdatareg(a, i2cBlockData[a].pTxData[0]);
         i2cBlockData[a].pTxData++;
         r8 = 1;
      }

      if (0 != FREG_I2C_ExtractStatusreg1_AmMrxReq(status))
      {
         i2cBlockData[a].pRxData[0] = i2cGetRxdatareg(a);
         i2cBlockData[a].pRxData++;
         r8 = 1;
      }

      if (0 != FREG_I2C_ExtractStatusreg1_AmEnd(status))
      {
         i2cBlockData[a].error = 0;
      }
      else if ((i2cBlockData[a].error != FAPI_I2C_ERR_BUSY) &&
               (r8 == 0))
      {
         i2cSetIrqmask1(a, 0);
      }
   }

   return 0;
}


/* 21c25c38 - todo */
int i2cHardwareTransmit(struct fapi_i2c_handle* r5, char addr,
      uint8_t* pTxData, unsigned numTxData)
{
   unsigned tmax;
   unsigned cpu_sr;
   unsigned long long t1, t2;
   int tdiff;

   if (0 == fapi_i2c_check_handle(r5))
   {
      return 0xffffc560;
   }

   unsigned speed = r5->params.speed;

   if ((speed - 1) > 1)
   {
      return 0xffffc567;
   }

   if (r5->params.type > 1)
   {
      return 0xffffc567;
   }

   if (r5->protocol > 1)
   {
      return 0xffffc567;
   }

   if (pTxData == 0)
   {
      return 0xffffc567;
   }

   unsigned fp = numTxData + 1;

   if (fp >= 4096)
   {
      return 0xffffc567;
   }

   if (i2cBlockData[r5->index].error == 0xffffc504)
   {
      return 0xffffc504;
   }

   if (speed == 2)
   {
      tmax = numTxData*16/400 + r5->params.timeOut;
   }
   else
   {
      tmax = numTxData*16/100 + r5->params.timeOut;
   }

   int r0 = i2cGetStatusreg1(r5->index);
   //21c25d0c
   if (0 != FREG_I2C_ExtractStatusreg1_Occup(r0))
   {
      return 0xffffc503;
   }
   //21c25d1c
   FAPI_SYS_GET_SEMAPHORE(i2cSemaphore, -1);

   cpu_sr = FAPI_SYS_DISABLE_IRQ;;

   i2cBlockData[r5->index].pTxData = pTxData;

   i2cSetControlreg1(r5->index,
         i2cBlockData[r5->index].controlReg1);

   if (speed == 2)
   {
      //21c2618c
      i2cSetControlreg1_I2cSpeed(r5->index, 1);
   }
   else
   {
      //21c25d90
      i2cSetControlreg1_I2cSpeed(r5->index, 0);
   }
   //21c25da4
   if (i2cBlockData[r5->index].operationMode == 2)
   {
      //21c26014
      i2cSetControlreg0(r5->index,
            i2cBlockData[r5->index].controlReg0);
      //21c26028
      i2cSetControlreg0_AmMode(r5->index, 0);
      //21c2603c
      i2cSetControlreg0_Reset(r5->index, 1);
      //21c26050
      i2cSetControlreg0_Reset(r5->index, 0);
      //21c26064
      i2cSetIrqmask1_AmEnd(r5->index, 1);
      //21c26078
      i2cSetIrqmask1_AmErr(r5->index, 1);
      //21c2608c
      i2cSetIrqmask1_AmMrxReq(r5->index, 1);
      //21c260a0
      i2cSetIrqmask1_AmMtxReq(r5->index, 1);
      //21c260b4
      i2cSetIrqmask0(r5->index, 0);
      //21c260c8
      i2cSetControlreg1_MsSlaAdd(r5->index, addr >> 1);
      //21c260dc
      i2cSetControlreg2(r5->index, fp);
      //21c260f0
      i2cSetControlreg3(r5->index, 0);
      //21c26104
      i2cBlockData[r5->index].error = 0xffffc504;
      //21c2612c
      i2cSetGoreg_AmReset(r5->index, 1);
      //21c26140
      i2cSetGoreg(r5->index, 0);
      //21c26154
      i2cSetGoreg_AmStart(r5->index, 1);
      //->21c25e9c
   }
   else
   {
#if 0
      i2cBlockData[r5->index].numTxData = numTxData;
      struct fapi_i2c_block* r0 = &i2cBlockData[r5->index];
      r0->addr = addr;
      r0->fill_32 = 1;
      i2cBlockData[r5->index].error = 0xffffc504;
#else
      //21c25dd0
      i2cBlockData[r5->index].numTxData = numTxData;
      //21c25dd4
      i2cBlockData[r5->index].addr = addr;
      //21c25df4
      i2cBlockData[r5->index].error = 0xffffc504;
      //21c25e18
      i2cBlockData[r5->index].fill_32 = 1;
#endif

      i2cSetControlreg0(r5->index, 0);
      //21c25e38
      i2cSetIrqmask0(r5->index, 0xffff);
      //21c25e4c
      i2cSetTxdatareg(r5->index, addr);
      //21c25e60
      i2cSetControlreg0(r5->index, 4);
      //21c25e74
      i2cSetGoreg(r5->index, 1);
      //21c25e88
      i2cSetControlreg0(r5->index, 0);
      //21c25e9c
   }
   //21c25e9c
   FAPI_SYS_SET_SEMAPHORE(i2cSemaphore, 0);

   FAPI_SYS_ENABLE_IRQ(cpu_sr);

   t1 = FAPI_TIMER_GetTimeStamp(1);
   do
   {
      //21c25ee8
      t2 = FAPI_TIMER_GetTimeStamp(1);
      tdiff = t2 - t1;

      if (t1 > t2)
      {
         if (tdiff < 0)
         {
            tdiff = -tdiff;
         }
      }
      //21c25f00
   }
   while ((i2cBlockData[r5->index].error == 0xffffc504) &&
         (tdiff < tmax));
   //21c25f48
   if (i2cBlockData[r5->index].error == 0xffffc504)
   {
      i2cBlockData[r5->index].error = -6;
   }
   else
   {
      //21c25f58
      i2cSetIrqmask1(r5->index, 0);
      //21c25f64
      i2cSetGoreg_AmReset(r5->index, 1);
   }
   //21c25f78
   return i2cBlockData[r5->index].error;
}


/* 21c24cf8 - nearly complete */
void i2cHardwareReset(int a)
{
//   printf("i2cHardwareReset(a=%d)\n", a);
   
   FAPI_GPIO_OpenParamsT gpioParams;
   unsigned cpu_sr;

   FAPI_SYS_GET_SEMAPHORE(i2cSemaphore, -1);

   cpu_sr = FAPI_SYS_DISABLE_IRQ;;

   i2cSetIrqmask0_SlAck(a, 0);
   //21c24d50
   i2cSetIrqmask0_DataTrmMs(a, 0);
   //21c24d5c
   i2cSetIrqmask0_DataRecMs(a, 0);
   //21c24d68
   i2cSetIrqmask0_DataRecSl(a, 0);
   //21c24d74
   i2cSetIrqmask0_DataTrmSl(a, 0);
   //21c24d80
   if ((i2cBlockData[a].gpioData != 0) &&
         (i2cBlockData[a].gpioClk != 0))
   {
      FAPI_GPIO_Close(i2cBlockData[a].gpioData);
      FAPI_GPIO_Close(i2cBlockData[a].gpioClk);

      gpioParams.function = 0x81; //0x0099010f;
      gpioParams.version = 0x20000;
      gpioParams.pin = -1;
      gpioParams.callback = 0;
      i2cBlockData[a].gpioClk = FAPI_GPIO_Open(&gpioParams, 0);

      i2cBlockData[a].gpioData = FAPI_GPIO_Open(&gpioParams, 0);

      FAPI_GPIO_Close(i2cBlockData[a].gpioData);
      FAPI_GPIO_Close(i2cBlockData[a].gpioClk);

      gpioParams.version = 0x20000;
      gpioParams.pin = -1;

      if (a == 0)
      {
         //21c24ed0
         gpioParams.function = 0x0099010f;
         gpioParams.callback = 0;
         i2cBlockData[a].gpioClk = FAPI_GPIO_Open(&gpioParams, 0);

         gpioParams.function = 0x0098010e;
      }
      else if (a == 1)
      {
         //21c24ef8
         gpioParams.function = 0x00c20142;
         gpioParams.callback = 0;
         i2cBlockData[a].gpioClk = FAPI_GPIO_Open(&gpioParams, 0);

         gpioParams.function = 0x00c10141;
      }
      else
      {
         gpioParams.callback = 0;
         i2cBlockData[a].gpioClk = FAPI_GPIO_Open(&gpioParams, 0);
      }

      i2cBlockData[a].gpioData = FAPI_GPIO_Open(&gpioParams, 0);
   }

   FAPI_SYS_SET_SEMAPHORE(i2cSemaphore, 0);

   FAPI_SYS_ENABLE_IRQ(cpu_sr);
}


/* 21c2445c - todo */
void func_21c2445c(void)
{

}


/* 21c240a4 - todo */
int func_21c240a4(struct fapi_i2c_handle* a, char b,
      uint8_t* c, unsigned d,
      uint8_t* e, unsigned f)
{
   return 0;
}


/* 21c24348 - todo */
void func_21c24348(void)
{

}


/* 21c23f00 - todo */
void func_21c23f00(void)
{

}


struct fapi_i2c_handle* fapi_i2c_get_handle(int a)
{
   int32_t i;
   struct fapi_i2c_handle* h = 0;

   if ((i2cBlockData[a].useCount + 1) >=
      i2cBlockData[a].maxUse)
   {
      return NULL;
   }

   for (i = 11; i >= 0; i--)
   {
      if (i2cHandleArray[i].inUse == 0)
      {
         i2cHandleArray[i].inUse = 1;
         i2cHandleArray[i].index = a;
         h = &i2cHandleArray[i];

         i2cBlockData[a].useCount++;

         break;
      }
   }

   return h;
}


/* 21c22da0 - complete */
int32_t fapi_i2c_check_handle(struct fapi_i2c_handle* a)
{
   int32_t res = 0;

   if ((i2cInitialized != 0) &&
         (a != 0) &&
         (a->inUse != 0) &&
         (a->magic == 0x00693263))
   {
      res = 1;
   }

   return res;
}


