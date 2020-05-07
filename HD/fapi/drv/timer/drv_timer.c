

#include <string.h>
#include "fapi/reg_irq_ctrl.h"
#include "fapi/sys_services.h"
#include "fapi/drv_timer.h"


/* 21b06000 - todo */
unsigned long long FAPI_TIMER_GetTimeStamp(unsigned a)
{
   unsigned long long t, r2;
   
   if ((a-1) >= 1000000)
   {
      return 0;
   }

   t = FREG_IRQ_CTRL_GetTimerxCntHigh(2);
   t = (t << 32) | FREG_IRQ_CTRL_GetTimerxCntLow(2);
   
   r2 = 0xFFFFFFFFFFFFFFFF;
   
   t = r2 - t;
   t /= a;
         
   return t;
}

