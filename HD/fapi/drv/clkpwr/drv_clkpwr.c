

#define DEBUG 0


#include <fapi/sys_services.h>
#include <fapi/reg_irq_ctrl.h>
#include <fapi/reg_clkpwr.h>
#include <fapi/drv_intr.h>
#include <fapi/drv_gpio.h>
#include <fapi/drv_clkpwr.h>



FAPI_SYS_DriverT FAPI_CLKPWR_Driver = //21efa698
{
      "CLKPWR",
      -1,
      0,
      FAPI_CLKPWR_Init,
      FAPI_CLKPWR_Exit,
      0,
      0,
      0,
      0
};


typedef struct
{
   int Data_0; //0
   int Data_4; //4
   FAPI_CLKPWR_OpenParamsT openParams; //8
   uint32_t Data_12; //12
   int Data_16; //16
   //20
} FAPI_CLKPWR_HandleT;


int clkpwrInitialized; //21f21df8
FAPI_SYS_SemaphoreT clkpwrSemaphore; //21f21dfc
FAPI_CLKPWR_HandleT clkpwrHandleArray[1]; //21f21e44


int32_t func_21c173b8(FAPI_CLKPWR_HandleT*, int);
int32_t func_21c17200(void);
int32_t func_21c17120(FAPI_CLKPWR_HandleT*, unsigned);
int func_21c170c4(void);
static int clkpwrCheckHandle(FAPI_CLKPWR_HandleT*);
static FAPI_CLKPWR_HandleT* clkpwrGetHandle(void);



/* 21c176c8 - complete */
int32_t FAPI_CLKPWR_Init(void)
{
   int32_t res;
   
   if (clkpwrInitialized)
   {
      return FAPI_CLKPWR_ERR_ALREADY_INITIALIZED;
   }
   
   memset(&clkpwrHandleArray[0], 0, sizeof(FAPI_CLKPWR_HandleT));
   
   clkpwrSemaphore = FAPI_SYS_CREATE_SEMAPHORE(1);
   
   if (clkpwrSemaphore == 0)
   {
      return FAPI_CLKPWR_ERR_SEMAPHORE_CREATE;
   }
   
   res = func_21c173b8(&clkpwrHandleArray[0], 0x20000);
   
   clkpwrInitialized = 1;
   
   return res;
}


/* 21c17020 - complete */
void FAPI_CLKPWR_Exit(void)
{
   unsigned i;
   
   if (clkpwrInitialized)
   {
      for (i = 0; i < 1; i++)
      {
         if (clkpwrHandleArray[i].Data_4 == 1)
         {
            FAPI_CLKPWR_Close(&clkpwrHandleArray[i]);
         }
      }

      FAPI_SYS_GET_SEMAPHORE(clkpwrSemaphore, FAPI_SYS_SUSPEND);
      
      clkpwrInitialized = 0;
      
      FAPI_SYS_SET_SEMAPHORE(clkpwrSemaphore, FAPI_SYS_NO_SUSPEND);
      
      FAPI_SYS_DESTROY_SEMAPHORE(clkpwrSemaphore);
      
      clkpwrSemaphore = 0;
   }
}


/* 21c17f5c - complete */
FAPI_SYS_HandleT FAPI_CLKPWR_Open(const FAPI_CLKPWR_OpenParamsT* paramsPtr,
                                  int32_t* errorCodePtr)
{
   FAPI_CLKPWR_HandleT* h;
   int32_t res = 0;
   
//   FAPI_SYS_PRINT_MSG("FAPI_CLKPWR_Open\n");
   
   if (clkpwrInitialized == 0)
   {
      res = FAPI_CLKPWR_ERR_NOT_INITIALIZED; //-6004;
   }
   
   if (paramsPtr == 0)
   {
      //21c18038
      res = FAPI_CLKPWR_ERR_BAD_PARAMETER;      
      if (errorCodePtr != 0)
      {
         *errorCodePtr = res;
      }
      return 0;
   }
   
   if (paramsPtr->version > FAPI_CLKPWR_VERSION)
   {
      res = FAPI_CLKPWR_ERR_UNSUPPORTED_VERSION;
      //->21c18020
   }
   
   if (res != 0)
   {
      //->21c18020
      if (errorCodePtr != 0)
      {
         *errorCodePtr = res;
      }
      return 0;
   }
   
   FAPI_SYS_GET_SEMAPHORE(clkpwrSemaphore, FAPI_SYS_SUSPEND);

   h = clkpwrGetHandle();

   if (clkpwrCheckHandle(h))
   {
      memcpy(&h->openParams, paramsPtr, sizeof(FAPI_CLKPWR_OpenParamsT));
      h->Data_16 = 0;
   }
   else
   {
      res = FAPI_CLKPWR_ERR_OUT_OF_MEMORY;
   }
   
   FAPI_SYS_SET_SEMAPHORE(clkpwrSemaphore, FAPI_SYS_NO_SUSPEND);

   if (errorCodePtr != 0)
   {
      *errorCodePtr = res;
   }
   
   return h;
}


/* 21c16f98 - complete */
int32_t FAPI_CLKPWR_Close(FAPI_SYS_HandleT handle)
{
//   FAPI_SYS_PRINT_MSG("FAPI_CLKPWR_Close\n");
   
   FAPI_CLKPWR_HandleT* h = handle;

   FAPI_SYS_GET_SEMAPHORE(clkpwrSemaphore, FAPI_SYS_SUSPEND);
   
   if (clkpwrCheckHandle(h))
   {
      memset(h, 0, sizeof(FAPI_CLKPWR_HandleT));
   }
   
   FAPI_SYS_SET_SEMAPHORE(clkpwrSemaphore, FAPI_SYS_NO_SUSPEND);

   return 0;
}


/* 21c16ed4 - complete */
int32_t FAPI_CLKPWR_StartWatchdog(FAPI_SYS_HandleT handle, uint32_t startValue)
{
   int32_t res = 0;
   FAPI_CLKPWR_HandleT* h = handle;

   if (clkpwrCheckHandle(h))
   {
      if ((startValue - 0x1000) <= 0x0fffe000)
      {
         FAPI_SYS_GET_SEMAPHORE(clkpwrSemaphore, FAPI_SYS_SUSPEND);
         
         h->Data_12 = startValue;
         
         FREG_CLKPWR_SetWatchdog(startValue);
         
         FAPI_SYS_SET_SEMAPHORE(clkpwrSemaphore, FAPI_SYS_NO_SUSPEND);
      }
      else
      {
         res = FAPI_CLKPWR_ERR_BAD_PARAMETER;
      }
   }
   else
   {
      res = FAPI_CLKPWR_ERR_INVALID_HANDLE; 
   }
   
   return res;
}


/* 21c17334 - complete */
int32_t FAPI_CLKPWR_ResetAudioProcessor(void)
{
   int32_t res = 0;

   res = func_21c17120(&clkpwrHandleArray[0], 1);
   
   if (res == 0)
   {
      res = func_21c17200();
   }

   return res;
}


/* 21c16e2c - complete */
void func_21c16e2c(unsigned a)
{
   uint32_t r0;
   uint32_t r5 = FREG_CLKPWR_GetConfigdmacaudio();
   
   if ((a == 0) || (a == 1))
   {
      r0 = r5 & 0xFFF3FFFF; //~0xc0000;
   }
   else
   {
      r0 = r5 & 0xFFF7FFFF; //~0x80000;
   }
   
   FREG_CLKPWR_SetConfigdmacaudio(r0);
   
   FREG_CLKPWR_SetConfigdmacaudio(r5);
}


/* 21c173b8 - complete */
int32_t func_21c173b8(FAPI_CLKPWR_HandleT* a, int b)
{
   int32_t res = 0;

   //   FAPI_SYS_PRINT_MSG("func_21c173b8\n");

   if (a == 0)
   {
      return FAPI_CLKPWR_ERR_BAD_PARAMETER;
   }
   
   if (b & 1)
   {
      FREG_CLKPWR_SetConfigarm_Resetarm(0);
      FREG_CLKPWR_SetConfigarm_Resetarm(0x0F);
   }

   if (b & 4)
   {
      res = func_21c17120(a, 1);
      
      if (res == 0)
      {
         res = func_21c17200();
      }
   }

   if (b & 2)
   {
      FREG_CLKPWR_SetConfigdmacaudio_Confdmacau23(0);
      FREG_CLKPWR_SetConfigdmacaudio_Confdmacau23(1);
   }

   if (b & 8)
   {
      FREG_CLKPWR_SetSoftreset162_ResetAxi162(0);
      FREG_CLKPWR_SetConfigdmacaudio_Confdmacau16(0);
      FREG_CLKPWR_SetSoftreset162_ResetAxi162(1);
      FREG_CLKPWR_SetConfigdmacaudio_Confdmacau16(1);
   }
   
   if (b & 0x10)
   {
      FREG_CLKPWR_SetSoftreset162_ResetSdram1621(0);
      FREG_CLKPWR_SetSoftreset162_ResetSdram1622(0);
      FREG_CLKPWR_SetSoftreset162_ResetSdram1621(1);
      FREG_CLKPWR_SetSoftreset162_ResetSdram1622(1);
   }

   if (b & 0x20)
   {
      FREG_CLKPWR_SetConfigdmacaudio_Confdmacau20(0);
      FREG_CLKPWR_SetConfigdmacaudio_Confdmacau20(1);
   }

   if (b & 0x40)
   {
      FREG_CLKPWR_SetConfigdmacaudio_Confdmacau22(0);
      FREG_CLKPWR_SetConfigdmacaudio_Confdmacau22(1);
   }

   if (b & 0x400)
   {
      FREG_CLKPWR_SetSoftreset81_ResetGpio(0);
      FREG_CLKPWR_SetSoftreset81_ResetGpio(1);
   }

   if (b & 0x80)
   {
      FREG_CLKPWR_SetSoftreset81_ResetI2c01(0);
      FREG_CLKPWR_SetSoftreset81_ResetI2c2(0);
      FREG_CLKPWR_SetSoftreset81_ResetI2c01(1);
      FREG_CLKPWR_SetSoftreset81_ResetI2c2(1);
   }

   if (b & 0x100)
   {
      FREG_CLKPWR_SetSoftreset81_ResetApbEIcc(0);
      FREG_CLKPWR_SetSoftreset81_Reserved(0);
      FREG_CLKPWR_SetSoftreset81_ResetApbEIcc(1);
      FREG_CLKPWR_SetSoftreset81_Reserved(1);
   }

   if (b & 0x200)
   {
      FREG_CLKPWR_SetSoftreset81_ResetIrqCtrl(0);
      FREG_CLKPWR_SetSoftreset81_ResetIrqCtrl(1);
   }

   if (b & 0x800)
   {
      FREG_CLKPWR_SetSoftreset81_ResetSflash(0);
      FREG_CLKPWR_SetSoftreset81_ResetSflash(1);
   }

   if (b & 0x1000)
   {
      FREG_CLKPWR_SetSoftreset81_ResetSsp(0);
      FREG_CLKPWR_SetSoftreset81_ResetSsp(1);
   }

   if (b & 0x2000)
   {
      FREG_CLKPWR_SetConfigdmacaudio_Confdmacau18(0);
      FREG_CLKPWR_SetConfigdmacaudio_Confdmacau19(0);
      FREG_CLKPWR_SetConfigdmacaudio_Confdmacau18(1);
      FREG_CLKPWR_SetConfigdmacaudio_Confdmacau19(1);
   }

   if (b & 0x4000)
   {
      FREG_CLKPWR_SetSoftreset81_ResetUartFpc(0);
      FREG_CLKPWR_SetSoftreset81_ResetUartFpc(1);
   }

   if (b & 0x8000)
   {
      FREG_CLKPWR_SetSoftreset162_ResetUpi(0);
      FREG_CLKPWR_SetSoftreset162_ResetUpi(1);
   }

   if (b & 0x10000)
   {
      FREG_CLKPWR_SetConfigdmacaudio_Confdmacau21(0);
      FREG_CLKPWR_SetConfigdmacaudio_Confdmacau21(1);
   }

   if (b & 0x20000)
   {
      FREG_CLKPWR_SetClk54enable_Clk27En(1);
      FREG_CLKPWR_SetFdclksel_ClkHdmiEn(1);
      FREG_CLKPWR_SetConfigvo(0xFFF1FFFF);
      FREG_CLKPWR_SetConfigvd(0xFFF1FFFF);
      FREG_CLKPWR_SetSoftreset54(0);
      FREG_CLKPWR_SetConfigvo(0xFFFFFFFF);
      FREG_CLKPWR_SetConfigvd(0xFFFFFFFF);
      FREG_CLKPWR_SetSoftreset54(0xFFFFFFFF);
   }
   
   return res;
}


/* 21c17200 - todo */
int32_t func_21c17200(void)
{
   int32_t res = 0;

   FAPI_SYS_PRINT_MSG("func_21c17200\n");

   return res;
}


/* 21c17120 - complete */
int32_t func_21c17120(FAPI_CLKPWR_HandleT* a, unsigned b)
{
   int32_t res = 0;

//   FAPI_SYS_PRINT_MSG("func_21c17120\n");
   
   if (a == 0)
   {
      return FAPI_CLKPWR_ERR_INVALID_HANDLE; 
   }
   
   if (b > 1)
   {
      return FAPI_CLKPWR_ERR_BAD_PARAMETER; 
   }
   
   res = func_21c170c4();
   
   if (res == 0)
   {
      return FAPI_CLKPWR_ERR_FEATURE_NOT_SUPPORTED;
   }
   
   if (res < 0)
   {
      return res;
   }
   
   *((volatile uint32_t*)(FREG_IRQ_CTRL_ARCJMPADDRESS)) = 0;
   
   if (b == 0)
   {
      *((volatile uint32_t*)(FREG_IRQ_CTRL_ARCSTATUS)) = 0x10;
   }
   else
   {
      *((volatile uint32_t*)(FREG_IRQ_CTRL_ARCSTATUS)) = 0x20;
   }
   
   FAPI_INTR_ThrowPollingModeIrq(2);
   
   FAPI_SYS_SLEEP(100);
   
   if (*((volatile uint32_t*)(FREG_IRQ_CTRL_ARCSTATUS)) == 1)
   {
      return 0;
   }

   if (*((volatile uint32_t*)(FREG_IRQ_CTRL_ARCSTATUS)) == 0)
   {
      return 0;
   }
   
   if (a->Data_12 == 0)
   {
      FREG_CLKPWR_SetWatchdog(0x0ffff000);
   }
   
   FREG_CLKPWR_SetConfigdmacaudio_Confdmacau17(0);
   FREG_CLKPWR_SetConfigdmacaudio_Confdmacau17(1);
   
   FREG_CLKPWR_SetWatchdog(a->Data_12);

   return 0;
}


/* 21c170c4 - complete */
int func_21c170c4(void)
{
//   FAPI_SYS_PRINT_MSG("func_21c170c4\n");
  
   int32_t res;
   FAPI_SYS_HandleT gpioHandle;
   FAPI_GPIO_OpenParamsT gpioParams;
   int32_t errorCode = 0;
   
   gpioParams.version = FAPI_GPIO_VERSION;
   gpioParams.pin = 41;
   gpioParams.function = FAPI_GPIO_IN_GENERIC_SW_FUNCTION; //0x810000;
   gpioParams.callback = 0;
      
   gpioHandle = FAPI_GPIO_Open(&gpioParams, &errorCode);
   
   if (gpioHandle != 0)
   {
      res = !FAPI_GPIO_ReadBit(gpioHandle);
      
      FAPI_GPIO_Close(gpioHandle);
   }
   else
   {
      res = errorCode;
   }
   
   return res;
}


FAPI_CLKPWR_HandleT* clkpwrGetHandle(void)
{
   unsigned i;
   FAPI_CLKPWR_HandleT* h = 0;
   
   for (i = 0; i < 1; i++)
   {
      if (clkpwrHandleArray[i].Data_4 == 0)
      {
         clkpwrHandleArray[i].Data_4 = 1;
         clkpwrHandleArray[i].Data_0 = 0x63707772;
         
         h = &clkpwrHandleArray[i];
         break;
      }
   }

   return h;
}


/* 21c16dc4 - complete */
int clkpwrCheckHandle(FAPI_CLKPWR_HandleT* a)
{
//   FAPI_SYS_PRINT_MSG("clkpwrCheckHandle\n");
   
   int res = 0;
   
   if (clkpwrInitialized &&
         (a != 0) &&
         (a->Data_4) &&
         (a->Data_0 == 0x63707772)) //cpwr
   {
      res = 1;
   }

   return res;
}




