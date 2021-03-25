
#include <string.h>
#include <fapi/sys_services.h>
#include <fapi/drv_usb_volume.h>
#include "usbdrv.h"





/* 21ca3790 - complete */
static int usbdrvReadSector(F_DRIVER *driver,void *data, unsigned long sector)
{
//   printf("usbdrvReadSector\n");
   
   if (1 != FAPI_USB_ReadVolume(driver->user_ptr, data, sector, 1))
   {
      return F_ERR_READ;
   }
   
   return 0;
}


/* 21ca3770 - complete */
static int usbdrvReadMultipleSector(F_DRIVER *driver,void *data, unsigned long sector, int cnt)
{
//   printf("usbdrvReadMultipleSector\n");
  
   if (cnt != FAPI_USB_ReadVolume(driver->user_ptr, data, sector, cnt))
   {
      return F_ERR_READ;
   }
   
   return 0;
}


/* 21ca3750 - complete */
static int usbdrvWriteSector(F_DRIVER *driver,void *data, unsigned long sector)
{
//   printf("usbdrvWriteSector\n");

   if (1 != FAPI_USB_WriteVolume(driver->user_ptr, data, sector, 1))
   {
      return F_ERR_WRITE;
   }

   return 0;
}


/* 21ca3730 - complete */
static int usbdrvWriteMultipleSector(F_DRIVER *driver,void *data, unsigned long sector, int cnt)
{
//   printf("usbdrvWriteMultipleSector\n");
  
   if (cnt != FAPI_USB_WriteVolume(driver->user_ptr, data, sector, cnt))
   {
      return F_ERR_WRITE;
   }

   return 0;
}


/* 21ca36cc - todo */
int func_21ca36cc(F_DRIVER *driver,F_PHY *phy)
{
   printf("func_21ca36cc\n");
   
   return 0;
}


/* 21ca3694 - todo */
long func_21ca3694(F_DRIVER *driver)
{
   printf("func_21ca3694\n");
   
   return 0;
}


/* 21ca3574 - todo */
void func_21ca3574(F_DRIVER *driver)
{
   printf("func_21ca3574\n");
}


/* 21ca35a4 - todo */
F_DRIVER* USBDRV_Init(unsigned long driver_param)
{
   //printf("USBDRV_Init\n");
   
   if (driver_param == 0)
   {
      return 0;
   }
      
   FAPI_SYS_HandleT volume = FAPI_USB_OpenVolume((void*) driver_param, 0);
   
   if (volume == 0)
   {
      return 0;
   }
   
   F_DRIVER* driver = FAPI_SYS_MALLOC(sizeof(F_DRIVER));
   
   if (driver == 0)
   {
      FAPI_USB_CloseVolume(volume);
      
      return 0;
   }
   
   memset(driver, 0, sizeof(F_DRIVER)-4);
   
   //driver->mutex = 0;
   //driver->separated = 0;
   //driver->ioctl = 0;
   driver->readsector = usbdrvReadSector;
   driver->readmultiplesector = usbdrvReadMultipleSector;
   driver->writesector = usbdrvWriteSector;
   driver->writemultiplesector = usbdrvWriteMultipleSector;
   driver->getphy = func_21ca36cc;
   driver->getstatus = func_21ca3694;
   driver->release = func_21ca3574;
   
   driver->user_data = 0;
   driver->user_ptr = volume;
   
   return driver;
}


