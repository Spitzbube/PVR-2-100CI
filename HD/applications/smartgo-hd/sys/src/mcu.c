

#include "fapi/sys_services.h"


int Data_21f02e54; //21f02e54



/* 21ba4704 - todo */
int MCU_Init(void)
{
   FAPI_SYS_PRINT_MSG("MCU_Init\n");

#if 1 //TODO
   Data_21f02e54 = 1;
#endif

   return 0;
}


/* 21ba3e64 - complete */
int func_21ba3e64(void)
{
//   printf("func_21ba3e64");
    return Data_21f02e54;
}



