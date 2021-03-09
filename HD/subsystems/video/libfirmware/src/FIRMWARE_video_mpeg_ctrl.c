

#include <fapi/sys_services.h>


struct fapi_boot_block
{
   int fill_0; //0
   uint32_t imageControl; //4
   int fill_8; //8
   uint32_t imageSize; //12
   uint32_t imageVersion; //16
   uint32_t loadAddress; //20
   uint32_t jumpAddress; //24
   unsigned data[1]; //28
};

struct fapi_boot_block Data_21e696fc = //21e696fc
{
      0x46424931, //FBI1
      0x00000000,
      1,
      1,
      0x4d30001b, //M0 
      0x60040c34,
      0x00000000,
      {
            0
      },
};
