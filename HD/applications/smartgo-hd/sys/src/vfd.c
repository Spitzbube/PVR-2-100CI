
#if 0

#include <fapi/sys_services.h>
#include <fapi/drv_gpio.h>
#include "rtos.h"
#include "vfd.h"



FAPI_SYS_HandleT Data_21f02e8c; //21f02e8c
FAPI_SYS_HandleT Data_21f02e84; //21f02e84
FAPI_SYS_HandleT Data_21f02e80; //21f02e80
FAPI_SYS_HandleT Data_21f02e88; //21f02e88
FAPI_SYS_HandleT Data_21f02e90; //21f02e90
void* Data_21f02e94; //21f02e94


void func_21ba4e98(uint32_t);
void func_21ba4e7c(uint32_t);


/* 21ba5ca8 - complete */
int32_t VFD_Init(void)
{
   int32_t res = 0;
   FAPI_GPIO_OpenParamsT gpioParams;

   FAPI_SYS_PRINT_MSG("\n %s %d VFD_Init", "sys/src/vfd.c", 2323);

   do
   {
      gpioParams.version = FAPI_GPIO_VERSION;
      gpioParams.pin = 28;
      gpioParams.function = FAPI_GPIO_OUT_0;
      gpioParams.callback = 0;

      Data_21f02e8c = FAPI_GPIO_Open(&gpioParams, &res);

      if (res != FAPI_OK)
      {
         break;
      }

      gpioParams.pin = 29;

      Data_21f02e84 = FAPI_GPIO_Open(&gpioParams, &res);

      if (res != FAPI_OK)
      {
         break;
      }

      gpioParams.pin = 27;

      Data_21f02e80 = FAPI_GPIO_Open(&gpioParams, &res);

      if (res != FAPI_OK)
      {
         break;
      }

      gpioParams.function = FAPI_GPIO_IN_GENERIC_SW_FUNCTION;
      gpioParams.pin = 30;

      Data_21f02e88 = FAPI_GPIO_Open(&gpioParams, &res);

      if (res != FAPI_OK)
      {
         break;
      }

      gpioParams.pin = 42;

      Data_21f02e90 = FAPI_GPIO_Open(&gpioParams, &res);

      if (res != FAPI_OK)
      {
         break;
      }

      FAPI_GPIO_WriteBit(Data_21f02e8c, 1);
      FAPI_GPIO_WriteBit(Data_21f02e80, 1);
      FAPI_GPIO_WriteBit(Data_21f02e84, 1);

      func_21ba4e98(100);

      Data_21f02e94 = rtos_create_semaphore(1);
   }
   while (0);

   FAPI_SYS_PRINT_MSG("VFD driver: FD_GPIO_Open status 0x%x\n", res);

   return res;
}


/* 21ba4eb4 - todo */
void func_21ba4eb4(void)
{

}


/* 21ba4e98 - complete */
void func_21ba4e98(uint32_t a)
{
   while (a)
   {
      a--;
      asm("mov %0,%0" : /*"=r" (a)*/: "r" (a));
   }
}


/* 21ba4e7c - complete */
void func_21ba4e7c(uint32_t a)
{
   while (a)
   {
      a--;
      asm("mov %0,%0" : /*"=r" (a)*/: "r" (a));
   }
}


/* 21ba4f80 - todo */
void func_21ba4f80(int a)
{

}


/* 21ba500c - todo */
void func_21ba500c(void)
{

}

#endif

/* 21ba5b48 - todo */
void func_21ba5b48(char* a, int b, int c)
{

}

