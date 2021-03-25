

#include <fapi/sys_services.h>
#include <fapi/drv_boot.h>



/* 21b902b8 - complete */
int SYS_GetFlashDeviceType(int* devType)
{
   int32_t res; //sp12
   FAPI_BOOT_OpenParamsT sp8;
   uint32_t bootMode;
   uint32_t bootDevice;
   FAPI_SYS_HandleT r6;
      
   *devType = 0;
   
   sp8.version = FAPI_BOOT_VERSION;
   
   r6 = FAPI_BOOT_Open(&sp8, &res);
   
   if (res != 0)
   {
      return res;
   }
   
   res = FAPI_BOOT_GetBootMode(r6, &bootMode);
   
   if ((res == 0) &&
         ((bootMode - 2) < 2))
   {
      res = FAPI_BOOT_GetBootDevice(r6, &bootDevice);
      
      if (bootDevice == 2) //FAPI_BOOT_DEVICE_SFLASH
      {
         *devType = 1;
      }
      else if (bootDevice == 1) //FAPI_BOOT_DEVICE_PFLASH
      {
         *devType = 0;
      }
   }

   FAPI_BOOT_Close(r6);
   
   return res;
}



