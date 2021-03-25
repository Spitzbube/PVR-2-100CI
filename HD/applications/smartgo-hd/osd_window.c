
#define DEBUG 0

#include "fapi/sys_services.h"
#include "sys.h"
#include "osd.h"
#include "osd_window.h"


#if 0

/*static*/ int osd_window_set_handler(void* a, int b);


Struct_372988* Data_21f02fdc; //21f02fdc
Struct_372988* Data_21f02fe0; //21f02fe0


/* sd: 372988 */
/* 21baf78c - complete */
int32_t /*func_21baf78c*/FGS_PANEL_Init(Struct_372988* a)
{
   FAPI_SYS_PRINT_DEBUG(4, "func_21baf78c\n");
   
   if (a == 0)
   {
      return -10000001;
   }
   
   Data_21f02fdc = SYS_MemoryAllocate(sizeof(Struct_372988));
   if (Data_21f02fdc == 0)
   {
      return -10002002;
   }
   
   *Data_21f02fdc = *a;
   
   Data_21f02fe0 = Data_21f02fdc;
   
   return 0;
}


/* 21baf6fc - complete */
int32_t /*osd_window_destroy*/FGS_PANEL_Close(void* a)
{
   struct OsdWindow* window = a;
   uint16_t i = 0;
   
   if (window == 0)
   {
      return -10002008;
   }
   
   func_376790(a); //21baf35c
   osd_window_set_handler(a, 0);
   
   for (i = 0; i < window->numItems; i++)
   {
      if (window->items[i].Release != 0)
      {
         (window->items[i].Release)(window->items[i].Data_16);         
      } 
   } 
   
   osd_view_remove(window->view);
   
   if (window->fRelease == 1)
   {
      SYS_MemoryFree(window);
   } 
   
   return 0;
}


/* 21baee54 - complete */
int /*osd_window_set_handler*/FGS_PANEL_SetFocus(void* a, int b)
{
   struct OsdWindowItem* item;
   struct OsdWindow* window = a;
   
   if (b == window->Data_36) 
   {
      return 0;
   } 
   
   window->Data_36 = b;
   
   if (window->params.SetHandler != 0)
   {
      (window->params.SetHandler)(window->params.Data_24, b);
   }
   
   if (window->activeItem >= 0)
   {
      item = &window->items[window->activeItem];
      
      if (item->activated != b)
      {
         item->activated = b;
         
         (item->SetHandler)(item->Data_16, b);
      }
   }    

   return 0;   
}

#endif

