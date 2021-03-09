
#define DEBUG 0

#include <fapi/sys_services.h>
#include <fapi/reg_efuse.h>
#include <fapi/reg_vo.h>
#include <fapi/drv_i2c.h>
#include <fapi/drv_hdmi.h>





FAPI_SYS_DriverT FAPI_HDMI_Driver = //21efb190
{
      "HDMI",
      30,
      0,
      FAPI_HDMI_Init,
      FAPI_HDMI_Exit,
      0,
      0,
      0,
      0,
};


struct fapi_hdmi_handle
{
   int magic; //0
   int inUse; //4
   FAPI_HDMI_OpenParamsT openParams; //8
   int fill_16[64]; //16
   int Data_272; //272
   uint8_t bData_276; //276
   int Data_280; //280;
   int Data_284; //284
   int Data_288; //288
   int Data_292; //292
   int fill_296[18]; //296
   int Data_368; //368
   int fill_372[15]; //372
   int Data_432; //432
   int fill_436; //436
   int Data_440; //440
   //444
};

struct Struct_21f23370
{
   int Data_0; //0
   int Data_4; //4
   int Data_8; //8
   int Data_12; //12
   int Data_16; //16
   int fill_20[16]; //20
   int Data_84; //84
   int Data_88; //88
   
};


struct Struct_21e002b8
{
   int fill_0; //0
   int Data_4; //4
   int Data_8; //8
   int Data_12; //12
   int Data_16; //16
   int Data_20; //20
   int Data_24; //24
   int fill_28; //28
   int Data_32; //32
   int Data_36; //36
   //40
};

struct Struct_21e002b8 Data_21e002b8[60] = //21e002b8
{
      //TODO
};

struct Struct_21e002b8 Data_21e00858[60] = //21e00858
{
      //TODO
};


FAPI_SYS_SemaphoreT hdmiSemaphore; //21f22fdc
int hdmiInitialized; //21f22fe0
char arData_21f22fe4[8]; //21f22fe4
uint64_t Data_21f22fec; //21f22fec
struct fapi_hdmi_handle hdmiHandleArray[2]; //21f22ff4
FAPI_SYS_HandleT hdmiI2cHandle; //21f2336c
struct Struct_21f23370 Data_21f23370; //21f23370



void func_21c212a8(int);
void func_21c21100(uint8_t);
void func_21c20c10(uint8_t);
void func_21c20a94(struct fapi_hdmi_handle*);
void func_21c209a8(uint8_t, uint8_t);
void func_21c20754(uint8_t, uint8_t, uint8_t);
void func_21c2073c(uint8_t, uint8_t);
void func_21c20708(uint8_t, uint8_t, uint8_t);
void func_21c206d4(struct fapi_hdmi_handle*);
void fapi_hdmi_i2c_write(uint8_t, uint8_t, uint8_t);
int fapi_hdmi_i2c_read(uint8_t, uint8_t);
void func_21c1f6b4(void);
int hdmiCheckHandle(struct fapi_hdmi_handle*);
static struct fapi_hdmi_handle* fapi_hdmi_get_handle(uint32_t block);



/* 21c22c78 - complete */
int32_t FAPI_HDMI_Init(void)
{
   unsigned i;
   FAPI_I2C_OpenParamsT sp;
   
   hdmiSemaphore = FAPI_SYS_CREATE_SEMAPHORE(1);
   
   if (hdmiInitialized != 0)
   {
      return FAPI_HDMI_ERR_ALREADY_INITIALIZED; //-14003;
   }
   
   hdmiInitialized = 1;
   
   sp.version = 0x30000; //FAPI_I2C_VERSION;
   sp.blockIndex = 2;
   sp.speed = FAPI_I2C_400KBPS;
   sp.slaveAddress = 0;
   sp.protocol = FAPI_I2C_RESTART_PROTOCOL;
   sp.type = FAPI_I2C_HARDWARE;
   sp.timeOut = 100;
   
   hdmiI2cHandle = FAPI_I2C_Open(&sp, 0);
   
   if (hdmiI2cHandle == 0)
   {
      return FAPI_HDMI_ERR_I2C_OPEN; //-14110;
   }
   
   FREG_VO_SetDispdachdmictrl_Hdmiiodcnt(5);
   FREG_VO_SetDispdachdmictrl_Hdmiiopcnt(3);
   FREG_VO_SetDispdachdmictrl_Hdmiidrvcnt(1);
   FREG_VO_SetDispdachdmictrl_Hdmiirdten(1);
   FREG_VO_SetDispdachdmictrl_Hdmiickh(0);
   FREG_VO_SetDispdachdmictrl_Hdmihdcpsel(0);
   FREG_VO_SetDispdachdmictrl_Hdmici2ca(0);
   
   for (i = 0; i < 8; i++)
   {
      arData_21f22fe4[i] = 0;
   }
   
   func_21c1f6b4();
   
   Data_21f22fec = 0;
   
   return 0;
}


/* 21c22c20 - complete */
void FAPI_HDMI_Exit(void)
{
   if (hdmiInitialized != 0)
   {
      hdmiInitialized = 0;
      
      FAPI_I2C_Close(hdmiI2cHandle);
      
      FAPI_SYS_DESTROY_SEMAPHORE(hdmiSemaphore);
   }
}


/* 21c22784 - todo */
FAPI_SYS_HandleT FAPI_HDMI_Open(const FAPI_HDMI_OpenParamsT* pParams,
                                int32_t* errorCodePtr)
{
   int r0;
   int i;
   int32_t res = 0;
   struct fapi_hdmi_handle* r7 = 0;
   
//   FAPI_SYS_PRINT_MSG("FAPI_HDMI_Open\n");
  
   if (hdmiInitialized == 0)
   {
      res = FAPI_HDMI_ERR_NOT_INITIALIZED; //-14004;
   }
   
   if (pParams == 0)
   {
      //21c22be4
      res = FAPI_HDMI_ERR_BAD_PARAMETER;
      if (errorCodePtr) *errorCodePtr = res;
      return 0;
   }
   
   if (pParams->version > FAPI_HDMI_VERSION)
   {
      res = FAPI_HDMI_ERR_BAD_PARAMETER;
   }
   
   if (res != 0)
   {
      //21c22850
      if (errorCodePtr) *errorCodePtr = res;
      return 0;
   }

   FAPI_SYS_GET_SEMAPHORE(hdmiSemaphore, FAPI_SYS_SUSPEND);

   r7 = fapi_hdmi_get_handle(pParams->block);

   if (hdmiCheckHandle(r7))
   {
      //21c22868
      memcpy(&r7->openParams, pParams, sizeof(FAPI_HDMI_OpenParamsT));
      
      if (pParams->block & FAPI_HDMI_VIDEO)
      {
//         FAPI_SYS_PRINT_MSG("21c22a14\n");
         
         fapi_hdmi_i2c_write(0x72, 0x0d, 0x04);
         fapi_hdmi_i2c_write(0x72, 0x0f, 0x00);
         fapi_hdmi_i2c_write(0x72, 0x27, 0x00);
         fapi_hdmi_i2c_write(0x72, 0x32, 0x00);
         fapi_hdmi_i2c_write(0x72, 0x33, 0x00);
         fapi_hdmi_i2c_write(0x72, 0x34, 0x00);
         fapi_hdmi_i2c_write(0x72, 0x36, 0x00);
         fapi_hdmi_i2c_write(0x72, 0x37, 0x00);
         fapi_hdmi_i2c_write(0x72, 0x38, 0x00);
         fapi_hdmi_i2c_write(0x72, 0x39, 0x00);
         fapi_hdmi_i2c_write(0x72, 0x3e, 0x04);
         fapi_hdmi_i2c_write(0x72, 0x48, 0x00);
         fapi_hdmi_i2c_write(0x72, 0x49, 0x00);
         fapi_hdmi_i2c_write(0x72, 0x4a, 0x18);
         fapi_hdmi_i2c_write(0x72, 0x75, 0x00);
         fapi_hdmi_i2c_write(0x72, 0x76, 0x00);
         fapi_hdmi_i2c_write(0x72, 0x77, 0x00);
         fapi_hdmi_i2c_write(0x72, 0x79, 0x02);
         fapi_hdmi_i2c_write(0x72, 0x82, 0x20);
         fapi_hdmi_i2c_write(0x72, 0xed, 0x00);
         fapi_hdmi_i2c_write(0x72, 0xee, 0x00);
         fapi_hdmi_i2c_write(0x72, 0xef, 0x00);
         fapi_hdmi_i2c_write(0x72, 0xf0, 0x00);
         fapi_hdmi_i2c_write(0x72, 0xf1, 0x00);
         fapi_hdmi_i2c_write(0x72, 0xf3, 0x00);
         fapi_hdmi_i2c_write(0x72, 0xf5, 0x00);
         fapi_hdmi_i2c_write(0x7a, 0x2f, 0x00);
         fapi_hdmi_i2c_write(0x7a, 0xdf, 0x00);
         
         func_21c212a8(1);
      }
      
      if (pParams->block & FAPI_HDMI_AUDIO)
      {
//         FAPI_SYS_PRINT_MSG("21c2292c\n");
         
         fapi_hdmi_i2c_write(0x7a, 0x01, 0x02);
         fapi_hdmi_i2c_write(0x7a, 0x02, 0x01);
         fapi_hdmi_i2c_write(0x7a, 0x03, 0x00);
         fapi_hdmi_i2c_write(0x7a, 0x04, 0x00);
         fapi_hdmi_i2c_write(0x7a, 0x05, 0x00);
         fapi_hdmi_i2c_write(0x7a, 0x14, 0x00);
         fapi_hdmi_i2c_write(0x7a, 0x1d, 0x45);
         fapi_hdmi_i2c_write(0x7a, 0x1e, 0x00);
         fapi_hdmi_i2c_write(0x7a, 0x1f, 0x00);
         fapi_hdmi_i2c_write(0x7a, 0x20, 0x00);
         fapi_hdmi_i2c_write(0x7a, 0x21, 0x0f);
         fapi_hdmi_i2c_write(0x7a, 0x22, 0x01);
         fapi_hdmi_i2c_write(0x7a, 0x23, 0x00);
         fapi_hdmi_i2c_write(0x7a, 0x24, 0x0b);
      }
      
      if (pParams->block & FAPI_HDMI_HDCP)
      {
//         FAPI_SYS_PRINT_MSG("21c228cc\n");
         
         fapi_hdmi_i2c_write(0x72, 0xfa, 0x04);
         
         for (i = 100; i > 0; i--)
         {
            r0 = fapi_hdmi_i2c_read(0x72, 0xf9);
            
            if (r0 & 1)
            {
               break;
            }
         }
         
         if ((i != 0) && ((r0 & 2) == 0))
         {
            r7->Data_432 = 0;
         }
         else
         {
            r7->Data_432 = -1;
         }
         //21c22918
         r7->Data_440 = *((volatile uint32_t*)FREG_EFUSE_BASE_ADDRESS) & 6;
      }
      //21c22890
      r7->Data_368 = 0x10;
   }
   else
   {
      res = FAPI_HDMI_ERR_OUT_OF_MEMORY; //-14002;
   }
   
   FAPI_SYS_SET_SEMAPHORE(hdmiSemaphore, FAPI_SYS_NO_SUSPEND);
   //21c22840
   if (errorCodePtr) *errorCodePtr = res;
  
   return r7;
}


/* 21c226ec - complete */
int32_t FAPI_HDMI_Close(FAPI_SYS_HandleT handle)
{
   int res = 0;
   struct fapi_hdmi_handle* h = handle;
   
   FAPI_SYS_PRINT_DEBUG(5, "FAPI_HDMI_Close\n");
   
   FAPI_SYS_GET_SEMAPHORE(hdmiSemaphore, FAPI_SYS_SUSPEND);
   
   if (hdmiCheckHandle(h))
   {
      memset(h, 0, sizeof(struct fapi_hdmi_handle));
      
      h->magic = 0x68646d69;
      h->inUse = 0;
   }
   else
   {
      res = FAPI_HDMI_ERR_INVALID_HANDLE;
   }
   
   FAPI_SYS_SET_SEMAPHORE(hdmiSemaphore, FAPI_SYS_NO_SUSPEND);
   
   FAPI_SYS_PRINT_DEBUG(4, "FAPI_HDMI_Close: res=%d\n", res);

   return res;
}


/* 21c21334 - todo */
int32_t FAPI_HDMI_VIDEO_Start(FAPI_SYS_HandleT handle)
{
   int res = 0;
   struct fapi_hdmi_handle* r7 = handle;

   //printf("FAPI_HDMI_VIDEO_Start\n");
   
   if (hdmiCheckHandle(r7))
   {
      if (r7->Data_292 == 0)
      {
         r7->Data_288 = 0;         
      }
      
      hdmiHandleArray[0].Data_272 = 0;

      FAPI_SYS_GET_SEMAPHORE(hdmiSemaphore, FAPI_SYS_SUSPEND);
      
      func_21c212a8(1);
      //21c2138c
      //r4 = r7->bData_276;
      if (r7->Data_280 == 0)
      {
         //21c2139c
         uint8_t r2;
         
         if ((r7->bData_276 == 4) ||
               (r7->bData_276 == 5) ||
               (r7->bData_276 == 16) ||
               (r7->bData_276 == 20) ||
               (r7->bData_276 == 19) ||
               (r7->bData_276 > 31))
         {
            //21c213b0
            r2 = 0;
         }
         else
         {
            //21c213b4
            r2 = 0x30;
         }
         
         func_21c20754(0x72, 0x33, r2);
         //21c213c0
      }
      else
      {
         //21c2142c
         if (r7->bData_276 < 60)
         {
            //21c21434
            struct Struct_21e002b8* r5 = &Data_21e002b8[r7->bData_276];
            unsigned r4 = r5->Data_8;
            unsigned r6 = r5->Data_4;
            unsigned r3 = r5->Data_12;
            
            r4 = -r4;
            r4 = r4 - r6;
            r4 = r4 + r3;
            
            fapi_hdmi_i2c_write(0x72, 0x33, ((r4 >> 8) & 0x0F) | 0x40);
            fapi_hdmi_i2c_write(0x72, 0x32, r4);
            //21c21488
            unsigned r2 = r5->Data_20;
            r4 = r5->Data_16;
            r3 = r5->Data_24;
            
            r2 = -r2;
            r2 = r2 - r4;
            r2 = r2 + r3;
            
            fapi_hdmi_i2c_write(0x72, 0x34, r2);
            fapi_hdmi_i2c_write(0x72, 0x36, r6); 
            fapi_hdmi_i2c_write(0x72, 0x37, r6 >> 8); 
            
            fapi_hdmi_i2c_write(0x72, 0x38, r4); 
            fapi_hdmi_i2c_write(0x72, 0x39, r4 >> 8); 
            //21c214f8
         }
         else
         {
            //21c215e0
            struct Struct_21e002b8* r4 = &Data_21e00858[r7->bData_276 - 60];
            unsigned r5 = r4->Data_8;
            unsigned r6 = r4->Data_4;
            unsigned r3 = r4->Data_12;
            
            r5 = -r5;
            r5 = r5 - r6;
            r5 = r5 + r3;
            
            fapi_hdmi_i2c_write(0x72, 0x33, ((r5 >> 8) & 0x0F) | 0x40);
            fapi_hdmi_i2c_write(0x72, 0x32, r5);

            unsigned r2 = r4->Data_20;
            r5 = r4->Data_16;
            r3 = r4->Data_24;
            
            r2 = -r2;
            r2 = r2 - r5;
            r2 = r2 + r3;
            
            fapi_hdmi_i2c_write(0x72, 0x34, r2);
            fapi_hdmi_i2c_write(0x72, 0x36, r6); 
            fapi_hdmi_i2c_write(0x72, 0x37, r6 >> 8); 
            
            fapi_hdmi_i2c_write(0x72, 0x38, r5); 
            fapi_hdmi_i2c_write(0x72, 0x39, r5 >> 8); 
         }
      }
      //21c213c0
      uint8_t r3;
      uint8_t r4;
      uint8_t r5;
      
      if (r7->bData_276 < 60)
      {
         //21c213cc
         r3 = (Data_21e002b8[r7->bData_276].Data_32 & 3) | 
            (Data_21e002b8[r7->bData_276].Data_36 << 4);            
      }
      else
      {
         //21c21504
         r3 = (Data_21e00858[r7->bData_276 - 60].Data_32 & 3) | 
            (Data_21e00858[r7->bData_276 - 60].Data_36 << 4);            
      }         
      
      if (r7->Data_284 == r7->Data_288)
      {
         //21c21540
         r4 = 0;
         r5 = 0;
      }
      else if (r7->Data_284 == 0)
      {
         //21c21540
         r4 = 0;
         r5 = 0;
      }
      else if (r7->Data_284 == 2)
      {
         //21c216b0
         if (r7->Data_288 == 0)
         {
            r5 = 0; //r2
            r4 = 0x18;
            //->21c21548
         }
         else
         {
            r5 = 1; 
            r4 = 0;
            //->21c21548
         }
      }
      else
      {
         //21c21414
         if (r7->Data_288 == 0)
         {
            r5 = 0; //r2
            r4 = 0x3c;
         }
         else
         {
            r5 = 0;
            r4 = 0x24;
         }
      }
      //21c21548
      fapi_hdmi_i2c_write(0x72, 0x48, r3);
      fapi_hdmi_i2c_write(0x72, 0x49, r5);
      fapi_hdmi_i2c_write(0x72, 0x4a, r4);
      
      func_21c206d4(r7);
      
      fapi_hdmi_i2c_write(0x72, 0x82, 0x20);
      //21c21590
      if (r7->Data_292 == 1)
      {
         //->21c216c8
         func_21c20a94(r7);
      }
      //21c2159c
      FAPI_SYS_SET_SEMAPHORE(hdmiSemaphore, FAPI_SYS_NO_SUSPEND);
      
      res = (hdmiHandleArray[0].Data_272 == -1);
   }
   else
   {
      res = FAPI_HDMI_ERR_INVALID_HANDLE;
   }   
   
   return res;
}


/* 21c212a8 - complete */
void func_21c212a8(int a)
{   
//   FAPI_SYS_PRINT_MSG("func_21c212a8\n");

   if (a != 0)
   {
      fapi_hdmi_i2c_write(0x72, 0x08, 0x35);
      fapi_hdmi_i2c_write(0x72, 0x05, 0x01);
      fapi_hdmi_i2c_write(0x72, 0x71, 0x60);
      func_21c20754(0x72, 0x05, 0x02);
      fapi_hdmi_i2c_write(0x72, 0x3e, 0x00);
      fapi_hdmi_i2c_write(0x72, 0x3f, 0x00);
      
      func_21c21100(0);
   }
   else
   {
      fapi_hdmi_i2c_write(0x72, 0x08, 0x00);
   }
}


/* 21c2118c - complete */
void func_21c2118c/*FAPI_HDMI_VIDEO_Stop?*/(FAPI_SYS_HandleT handle)
{
   struct fapi_hdmi_handle* h = handle;
   
//   printf("func_21c2118c\n");
   
   FAPI_SYS_GET_SEMAPHORE(hdmiSemaphore, FAPI_SYS_SUSPEND);
   
   if (hdmiCheckHandle(h))
   {
      func_21c21100(2);    
   }
   
   FAPI_SYS_SET_SEMAPHORE(hdmiSemaphore, FAPI_SYS_NO_SUSPEND);
}


/* 21c21100 - complete */
void func_21c21100(uint8_t a)
{
//   FAPI_SYS_PRINT_MSG("func_21c21100\n");
  
   switch (a)
   {
   case 1:
      func_21c20c10(1);
      break;
      
   case 2:
      fapi_hdmi_i2c_write(0x72, 0x0d, 0x04);
      break;
      
   case 3:
      fapi_hdmi_i2c_write(0x72, 0x0d, 0x02);
      break;
      
   case 4:
      fapi_hdmi_i2c_write(0x72, 0x0d, 0x06);
      break;
      
   default:
      func_21c20c10(0);
      fapi_hdmi_i2c_write(0x72, 0x0d, 0x00);
      break;
   }
}


/* 21c20c10 - complete */
void func_21c20c10(uint8_t a)
{
   uint8_t r4;
   
//   FAPI_SYS_PRINT_MSG("func_21c20c10\n");
   
   if ((a & 0xff) == 0)
   {
      r4 = 0x10;
   }
   else
   {
      r4 = 0x01;
   }
   
   func_21c209a8(0x08, 1);
   
   fapi_hdmi_i2c_write(0x7a, 0xdf, r4);
   
   func_21c2073c(0x08, 1);
}


/* 21c209a8 - complete */
void func_21c209a8(uint8_t a, uint8_t b)
{
   unsigned i;
   
//   FAPI_SYS_PRINT_MSG("func_21c209a8\n");
   
   uint8_t r5 = (b + 0x3e) & 0xff;
   
   func_21c20754(0x7a, r5, (a >> 1) ^ 0xff);
   
   for (i = 0; i < 10; i++)
   {
      if ((a & fapi_hdmi_i2c_read(0x7a, r5)) == 0)
      {
         break;
      }
   }
}


/* 21c20754 - complete */
void func_21c20754(uint8_t a, uint8_t b, uint8_t c)
{
//   FAPI_SYS_PRINT_MSG("func_21c20754\n");
   
   int r0 = fapi_hdmi_i2c_read(a, b);
   
   fapi_hdmi_i2c_write(a, b, r0 & c);
}


/* 21c20708 - complete */
void func_21c20708(uint8_t a, uint8_t b, uint8_t c)
{
//   FAPI_SYS_PRINT_MSG("func_21c20708\n");
   
   int r0 = fapi_hdmi_i2c_read(a, b);
   
   fapi_hdmi_i2c_write(a, b, r0 | c);
}


/* 21c2073c - complete */
void func_21c2073c(uint8_t a, uint8_t b)
{
//   FAPI_SYS_PRINT_MSG("func_21c2073c\n");
   
   func_21c20708(0x7a, b + 0x3e, a | (a >> 1));
}


/* 21c20a94 - todo */
void func_21c20a94(struct fapi_hdmi_handle* a)
{
   FAPI_SYS_PRINT_MSG("func_21c20a94\n");
}


/* 21c206d4 - todo */
void func_21c206d4(struct fapi_hdmi_handle* a)
{
//   FAPI_SYS_PRINT_MSG("func_21c206d4\n");
   
   uint8_t r2 = 0;
   int r0 = fapi_hdmi_i2c_read(0x7a, 0x2f);
   
   if (a->Data_292 != 0)
   {
      r2 = (r0 | 1) & 3;
   }
   
   fapi_hdmi_i2c_write(0x7a, 0x2f, r2);
}


/* 21c204cc - complete */
void fapi_hdmi_i2c_write(uint8_t a, uint8_t b, uint8_t c)
{
//   FAPI_SYS_PRINT_MSG("fapi_hdmi_i2c_write\n");

   int32_t res;
   uint8_t buf[2] = {0, 0};
   
   buf[0] = b;
   buf[1] = c;
   
   res = FAPI_I2C_Write(hdmiI2cHandle, a, buf, 2);
   
   if (res < 0)
   {
      hdmiHandleArray[0].Data_272 = res;
   }
}


/* 21c2046c - complete */
int fapi_hdmi_i2c_read(uint8_t a, uint8_t b)
{
   int32_t res;
   uint8_t buf[1];
   uint8_t data = 0;
   
//   FAPI_SYS_PRINT_MSG("fapi_hdmi_i2c_read\n");

   buf[0] = b;

   res = FAPI_I2C_Read(hdmiI2cHandle, a, buf, 1, &data, 1);
   
   if (res < 0)
   {
      hdmiHandleArray[0].Data_272 = res;
   }

   return data;
}


/* 21c1f6b4 - complete */
void func_21c1f6b4(void)
{
//   FAPI_SYS_PRINT_MSG("func_21c1f6b4\n");
   
   Data_21f23370.Data_0 = 0x67452301;
   Data_21f23370.Data_4 = 0xefcdab89;
   Data_21f23370.Data_8 = 0x98badcfe;
   Data_21f23370.Data_12 = 0x10325476;
   Data_21f23370.Data_16 = 0xc3d2e1f0;
   
   Data_21f23370.Data_84 = 0;
   Data_21f23370.Data_88 = 0;
}


struct fapi_hdmi_handle* fapi_hdmi_get_handle(uint32_t block)
{
   unsigned i;
   struct fapi_hdmi_handle* h = 0;

//   for (i = 1; i != 0; i--)
   for (i = 0; i < 2; i++)
   {
      if (0 == (hdmiHandleArray[i].inUse & block))
      {
#if 1
         hdmiHandleArray[i].inUse |= block;
         hdmiHandleArray[i].magic = 0x68646d69;
         
         h = &hdmiHandleArray[i];
#else
         h = &hdmiHandleArray[i];

         h->inUse |= block;
         h->magic = 0x68646d69;
#endif
         break;
      }      
   }

   return h;
}


/* 21c1f578 - complete */
int hdmiCheckHandle(struct fapi_hdmi_handle* a)
{
   int res = 0;
   
   if (hdmiInitialized &&
         (a != 0) &&
         (a->inUse != 0) &&
         (a->magic == 0x68646d69))
   {
      res = 1;
   }
   
   return res;
}



