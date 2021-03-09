
#define DEBUG 0

#include <string.h>
#include <fapi/sys_services.h>
#if 0
#include "famos.h"
#include "fapi_adapter.h"
#include "fapi/fapi_bm.h"
#endif
#if 0
#include "fapi_tsd.h"
#endif
#include "fapi/fapi_sync.h"


struct fapi_sync_handle;

int fapi_sync_check_handle(struct fapi_sync_handle*);


static void* fapi_sync_semaphore; //21efc058
static int Data_21efc05c; //21efc05c
static int fapi_sync_initialized; //21f27ec4
static int Data_21f27ed0; //21f27ed0
static struct fapi_sync_handle 
{
   int magic; //0
   int inUse; //4
   int fill_8; //8
   int fill_12; //12
   int Data_16; //16
   int fill_20[50]; //20
   int Data_220; //220
   void* Data_224; //224
   void* Data_228; //228
   int Data_232; //232
   int Data_236; //236
   //240
} fapi_sync_handles[1]; //21f27ed4



/* 21c2f7a4 - complete */
void func_21c2f7a4(void)
{
   fapi_sync_handles[0].Data_232 = 0; 
}


/* 21c2f91c - todo */
void func_21c2f91c(int a)
{
   FAPI_SYS_PRINT_DEBUG(4, "func_21c2f91c: a=%d\n", a);
}


/* 21c2f890 - complete */
int func_21c2f890(void)
{
   int res = fapi_sync_handles[0].Data_236;
   
   FAPI_SYS_PRINT_DEBUG(4, "func_21c2f890: res=%d\n", res);
   
   return res;
}








