

#include <fapi/sys_services.h>
#if 0
#include <assert.h>
#include "rtos.h"
#include "fapi_adapter.h"
#endif
#include "app_main.h"
#if 0
#include "device.h"
#endif
#include "event_queue.h"

extern struct appData Data_21f7be58; //21f7be58


int SYS_HandleEvent(int a, void* b);


/* 21b8fd08 - complete */
void ApplicationThread(int a)
{
   int retVal;
   struct Event event;
   
#if 0
   func_21b8961c(); //->device.c
#endif
   
   if (Data_21f7be58.init != 0)
   {
      retVal = (Data_21f7be58.init)();
      
      FAPI_SYS_PRINT_MSG("\n %s %d retVal=%x  ",
            "sys/src/main.c", 1641, retVal);
      
      if (retVal != 0)
      {
         FAPI_SYS_PRINT_MSG("Application initialisation failed: %d!\n",
               retVal);
         
         rtos_halt(-1);
      }
   }

   // The main application loop
   while (1)
   {
      if (0 != EVT_Get(&event, 1))
      {
         FAPI_SYS_PRINT_MSG("EVT_Get: ERROR \n");
      }
      else
      {
         if (0 != SYS_HandleEvent(event.header.tag, &event))
         {
            if (Data_21f7be58.handleEvent != 0)
            {
               (Data_21f7be58.handleEvent)(event.header.tag, &event);
            }
         }
      }
   }
}


/* 21b8fa28 - todo */
int SYS_HandleEvent(int a, void* b)
{
   FAPI_SYS_PRINT_MSG("SYS_HandleEvent() a=%d\n", a);
   
   switch (a)
   {
   case 59: //"USB"
      //21b8fc00
#if 0
      func_21bc382c(b);
#endif
      //->21b8fb48
      return 1;
      //break;
      
   default:
      //->21b8fb44
      break;
   }
   //21b8fb44
   return 1;
}

