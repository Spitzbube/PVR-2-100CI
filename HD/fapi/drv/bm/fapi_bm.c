
#define DEBUG 4

#include <string.h>
#include <fapi/sys_services.h>
#include "fapi/reg_bm_old.h"
#if 0
#include "famos.h"
#include "fapi_adapter.h"
#endif
#include "fapi/drv_timer.h"
#include "fapi/fapi_bm.h"



struct fapi_bm_handle;

static int fapi_bm_isr(void);
static void fapi_bm_bsr(void* a);
void fapi_bm_clear_mail_fifo(int);
int fapi_bm_check_handle(struct fapi_bm_handle* a);
void fapi_bm_clear_handle(struct fapi_bm_handle*);
void func_21c140e8(int, int, void*);
void func_21c12354(struct fapi_bm_handle*, int);
int func_21c12478(unsigned, int, int);
int get_buffer_level(struct fapi_bm_handle*);

#if 0
struct fapi_driver fapi_bm_driver0 = //21efa524
{
      "BM0",
      24,
      1,
      0, 
      0,
      fapi_bm_isr,
      fapi_bm_bsr,
      0x2000,
      0x400,
};


struct fapi_driver fapi_bm_driver1 = //21efa548
{
      "BM1",
      24,
      1,
      0, 
      0,
      fapi_bm_isr,
      fapi_bm_bsr,
      0x2000,
      0x400,
};


struct fapi_driver fapi_bm_driver2 = //21efa56c
{
      "BM2",
      25,
      1,
      0, 
      0,
      fapi_bm_isr,
      fapi_bm_bsr,
      0x2000,
      0x400,
};


struct fapi_driver fapi_bm_driver3 = //21efa590
{
      "BM3",
      25,
      1,
      0, 
      0,
      fapi_bm_isr,
      fapi_bm_bsr,
      0x2000,
      0x400,
};
#endif

int Data_21efa5b4[8] = //21efa5b4
{
      -1, -1, -1, -1, -1, -1, -1, -1,
};


struct fapi_bm_handle
{
   int magic; //0
   int inUse; //4
   unsigned Data_8; //8
   struct fapi_bm_params Data_12; //12
   unsigned Data_44; //44
   int readPtr; //48
   int baseAddress; //52
   void (*Data_56)(int, int, void*); //56
   void* Data_60; //60
   void (*Data_64)(unsigned, unsigned, int); //64
   int Data_68; //68
   void (*Data_72)(unsigned, unsigned, int); //72
   int Data_76; //76
   struct
   {
      int fill_0[4]; //0
   } Data_80; //80
   //96
};


struct Struct_21f19b00
{
   int fill_0[3088]; //0
   //12352
};


struct Struct_21f19b04
{
   unsigned Data_0; //0
   int Data_4; //4
   void (*Data_8)(unsigned, int, int, int); //8
   int Data_12; //12
   //16
};

static void* fapi_bm_semaphore = 0; //21f19ac4
static unsigned Data_21f19ac8 = 0; //21f19ac8
static int fapi_bm_initialized = 0; //21f19acc
struct  
{
   int Data_0; //0
   int Data_4; //4
} fapi_bm_baseAddress; //21f19ad0
static struct fapi_bm_handle* fapi_bm_handles = 0; //21f19ad8
int Data_21f19adc = 0; //21f19adc
static volatile struct Struct_21f19ae0
{
   int Data_0; //0
   unsigned Data_4; //4
   //8
} Data_21f19ae0[4]; //21f19ae0
static struct Struct_21f19b00* Data_21f19b00 = 0; //21f19b00
static struct Struct_21f19b04 Data_21f19b04[2][5]; //21f19b04
static int Data_21f19ba4[4][32]; //21f19ba4
static struct
{
   int Data_0; //0
   unsigned Data_4; //4
   unsigned Data_8; //8
   int handleIndex; //12
   //16
} fapi_bm_mail_fifo[2][1024]; //21f19da4
static unsigned fapi_bm_fifo_entries[2]; //21f21da4
static unsigned fapi_bm_fifo_read_ptr[2]; //21f21dac
static unsigned fapi_bm_fifo_write_ptr[2]; //21f21db4
static unsigned Data_21f21dbc[2]; //21f21dbc




/* 21c1306c - todo */
int fapi_bm_isr(void)
{
   unsigned r19;
   int i;
   unsigned j;
   unsigned r16 = 0;
   unsigned r9 = 0;
   unsigned r15 = 0;
   
   r16 = func_21c6eab8();
   
   unsigned r4 = r16 & (0x1F << 19); //xxxx x000 0000 0000 0000 0000
   
   FREG_BM01_SetClearAudIrq(~(r4 >> 19));
   
   if (r16 & 0x10000) //x 0000 0000 0000 0000
   {
      r15 = 1;
      r19 = FREG_BM1_GetIrqReg();      
   }
   else
   {
      r19 = FREG_BM0_GetIrqReg();
   }
   
   if (r4 != 0)
   {
      r4 >>= 19;
      
      for (j = 0; j < 5; j++)
      {
         unsigned r3 = r4 & (1 << j); 
         r3 >>= j;
         
         if ((r3 & 1) == 1)
         {
            if (Data_21f19b04[0][j].Data_8 != 0)
            {               
               (Data_21f19b04[0][j].Data_8)(j, 
                     Data_21f19b04[0][j].Data_4,
                     func_21c6e628_1(r15, j),
                     Data_21f19b04[0][j].Data_12);
            }
         }
      }
   }
   
   if (r19 != 0)
   {
      //214cb39e      
      for (j = 0; j < 32; j++)
      {
         //214cb3aa
         unsigned r3 = r19 & (1 << j);
         r3 >>= j;
         
         if ((r3 & 1) == 1)
         {
            //214cb3c0
            for (i = 127; i >= 0; i--)
            {               
               if ((fapi_bm_handles[i].inUse != 0) &&
                     (fapi_bm_handles[i].Data_8 == r15) &&
                     (fapi_bm_handles[i].Data_44 == j))
               {
                  //214cb3f2
                  if (fapi_bm_handles[i].Data_56 != 0)
                  {
                     //214cb3fa
                     bmSetIrqMask(fapi_bm_handles[i].Data_8, 
                           bmGetmIrqMask(fapi_bm_handles[i].Data_8) | (1 << fapi_bm_handles[i].Data_44));
                     //21c131cc
                     func_21c12354(&fapi_bm_handles[i], 3);
                     
                     if (fapi_bm_fifo_entries[0] >= 1024)
                     {
                        //->214cb670
                        return 0;
                     }
                     
                     fapi_bm_mail_fifo[0][fapi_bm_fifo_write_ptr[0]].Data_0 = 3;
                     fapi_bm_mail_fifo[0][fapi_bm_fifo_write_ptr[0]].Data_4 = r15;
                     fapi_bm_mail_fifo[0][fapi_bm_fifo_write_ptr[0]].Data_8 = j;
                     fapi_bm_mail_fifo[0][fapi_bm_fifo_write_ptr[0]].handleIndex = i;
                     
                     fapi_bm_fifo_write_ptr[0]++;
                     
                     if (fapi_bm_fifo_write_ptr[0] >= 1024)
                     {
                        fapi_bm_fifo_write_ptr[0] = 0;
                     }
                     
                     fapi_bm_fifo_entries[0]++;
                     
                     r9 = 1;
                  }
                                    
                  break;
               }
            } //for (i = 127; i >= 0; i--)
         }
      } //for (j = 0; j < 32; j++)
   }
   //214cb4ac
   if (r16 & 0x60000) //0xx0 0000 0000 0000 0000
   {
      if (r16 & 0xFF) //0000 0000 xxxx xxxx
      {
         //214cb4c4
         r16 &= 0xFF;
         
         for (j = 0; j < 8; j++)
         {
            //214cb4d2
            unsigned r3 = r16 & (1 << j);            
            r3 >>= j;
            
            if ((r3 & 1) == 1)
            {
               //214cb4e8
               unsigned r0 = func_21c6e4d0(j) & 0x20;
               r15 = r0 >> 5;
               
               for (i = 127; i >= 0; i--)
               {
                  if ((fapi_bm_handles[i].inUse != 0) &&
                        (fapi_bm_handles[i].Data_8 == r15) &&
                        (fapi_bm_handles[i].Data_44 == Data_21efa5b4[j]))
                  {
                     if (fapi_bm_handles[i].Data_64 != 0)
                     {
                        //214cb540
                        if (fapi_bm_fifo_entries[0] >= 1024)
                        {
                           //->214cb670
                           return 0;
                        }
                        //214cb54c       
                        fapi_bm_mail_fifo[0][fapi_bm_fifo_write_ptr[0]].Data_0 = 1;
                        fapi_bm_mail_fifo[0][fapi_bm_fifo_write_ptr[0]].Data_4 = r15;
                        fapi_bm_mail_fifo[0][fapi_bm_fifo_write_ptr[0]].Data_8 = fapi_bm_handles[i].Data_44;
                        fapi_bm_mail_fifo[0][fapi_bm_fifo_write_ptr[0]].handleIndex = i;
                         
                        fapi_bm_fifo_write_ptr[0]++;
                        
                        if (fapi_bm_fifo_write_ptr[0] >= 1024)
                        {
                           fapi_bm_fifo_write_ptr[0] = 0;
                        }
                        
                        fapi_bm_fifo_entries[0]++;
                        
                        r9 = 1;                        
                     }
                     break;                     
                  }
               }
            }
            //214cb586
         } //for (j = 0; j < 8; j++)
         //->214cb652
      }
      else
      {
         //214cb590         
         r16 &= 0xff00; //xxxx xxxx 0000 0000
         
         for (j = 0; j < 8; j++)
         {
            //214cb5ac
            unsigned r3 = r16 & (1 << (j + 8));
            r3 >>= (j + 8);
            
            if ((r3 & 1) == 1)
            {
               //214cb5c4
               for (i = 127; i >= 0; i--)
               {
                  //214cb5ca
                  if ((fapi_bm_handles[i].inUse != 0) &&
                        (fapi_bm_handles[i].Data_8 == Data_21f19ac8) &&
                        (fapi_bm_handles[i].Data_44 == j))
                  {
                     if (fapi_bm_handles[i].Data_72 != 0)
                     {
                        //214cb5fe
                        if (fapi_bm_fifo_entries[0] >= 1024)
                        {
                           //->214cb670
                           return 0;
                        }
                        //21c13480                               
                        fapi_bm_mail_fifo[0][fapi_bm_fifo_write_ptr[0]].Data_0 = 2;
                        fapi_bm_mail_fifo[0][fapi_bm_fifo_write_ptr[0]].Data_4 = Data_21f19ac8;
                        fapi_bm_mail_fifo[0][fapi_bm_fifo_write_ptr[0]].Data_8 = j;
                        fapi_bm_mail_fifo[0][fapi_bm_fifo_write_ptr[0]].handleIndex = i;
                        
                        fapi_bm_fifo_write_ptr[0]++;
                        
                        if (fapi_bm_fifo_write_ptr[0] >= 1024)
                        {
                           fapi_bm_fifo_write_ptr[0] = 0;
                        }
                        
                        fapi_bm_fifo_entries[0]++;
                        
                        r9 = 1;
                     }
                     
                     break;
                  }
               }
            }
            //214cb64a
         } //for (j = 0; j < 8; j++)
         //->21c13358
      }
   }
   //214cb652
   if (r9 != 0)
   {
      if (Data_21f21dbc[0] < 10)
      {
         Data_21f21dbc[0]++;
         
         return 1;
      }
   }
   //214cb670
   return 0;
}


/* 21c14ad4 - complete */
int fapi_bm_read(void* h, void* b, unsigned c, unsigned d)
{
   struct fapi_bm_handle* a = h;
   int r16 = 0;
   
   if (0 == fapi_bm_check_handle(a))
   {
      return -5008;
   }
   
   if (b == 0)
   {
      return -5001;
   }

   if ((c == 0) || (c > 0x7fffffff))
   {
      return -5001;
   }
      
   if ((a->Data_8 == Data_21f19ac8) && 
         (a->Data_44 < 8))
   {
      return -5001;
   }
   
   if (a->readPtr >= a->Data_12.size)
   {
      return -5105;
   }
   
   if ((d == 0))
   {
      if (get_buffer_level(h) < c)
      {
         return 0;
      }
   }
   else
   {
      unsigned long long t1 = FAPI_TIMER_GetTimeStamp(1000);
      
      while ((c > get_buffer_level(h)) &&
            ((d == -1) || (r16 < d)))
      {     
         unsigned long long t2 = FAPI_TIMER_GetTimeStamp(1000);
         
         r16 = t2 - t1;
         
         if (t2 < t1)
         {
            if (r16 < 0)
            {
               r16 = -r16;
            }
         }
      }
   
      if ((d != -1) && (r16 >= d))
      {
         return -5006;
      }
   }
   
   int r2 = a->Data_12.address + a->baseAddress + a->readPtr;
   
   volatile char* r0;

   r0 = FAPI_SYS_GET_VIRTUAL_ADDRESS(r2);

   unsigned i = 0;

   if ((((int)r0 & 3) == 0) && 
         (((int)b & 3) == 0))
   {
      volatile int* r1 = (void*) r0;

      while ((i + 4) <= c)
      {            
         ((int*)b)[i/4] = *r1++;
         
         r0 += 4;
                     
         a->readPtr += 4;
         
         i += 4;
                  
         if (a->readPtr == a->Data_12.size)
         {
            a->readPtr = 0;
            
            r2 = a->Data_12.address + a->baseAddress;
            
            r0 = FAPI_SYS_GET_VIRTUAL_ADDRESS(r2);

            if ((int)r0 & 3)
            {
               break;
            }

            r1 = (void*) r0;
         }
      }
   }

   for (; i < c; i++)
   {
      ((char*)b)[i] = *r0++;
      
      a->readPtr++;
      
      if (a->readPtr == a->Data_12.size)
      {
         a->readPtr = 0;
         
         r2 = a->Data_12.address + a->baseAddress;
         
         r0 = FAPI_SYS_GET_VIRTUAL_ADDRESS(r2);
      }
   }
   
   bmSetRdPtr(a->Data_8, a->Data_44, a->readPtr & ~0x3f);
   
   FAPI_SYS_FlushDataCache(a, sizeof(struct fapi_bm_handle));

   return i;
}


/* 21c14260 - complete */
int fapi_bm_write(void* h, void* b, unsigned c, unsigned d)
{
   struct fapi_bm_handle* a = h;
   int r16 = 0;
   
   if (0 == fapi_bm_check_handle(a))
   {
      return -5008;
   }
   
   if (b == 0)
   {
      return -5008;
   }

   if ((c == 0) || (c > 0x7fffffff))
   {
      return -5001;
   }
   
   int writePtr = bmGetWrPtr(a->Data_8, a->Data_44);
   
   if (writePtr >= a->Data_12.size)
   {
      return -5105;
   }
   
   if (d == 0)
   {
      if ((a->Data_12.size - get_buffer_level(h)) < (c + 1))
      {
         return 0;
      }
   }
   else
   {
      unsigned long long t1 = FAPI_TIMER_GetTimeStamp(1000);
      
      while (((a->Data_12.size - get_buffer_level(h)) < (c + 1)) &&
            ((d == -1) || (r16 < d)))
      {     
         unsigned long long t2 = FAPI_TIMER_GetTimeStamp(1000);
         
         r16 = t2 - t1;
         
         if (t2 < t1)
         {
            if (r16 < 0)
            {
               r16 = -r16;
            }
         }
      }
   
      if ((d != -1) && (r16 >= d))
      {
         return -5006;
      }
   }

   int r9 = a->Data_12.address + a->baseAddress;
   int r2 = r9 + writePtr;
   
   volatile char* r0;
   r0 = FAPI_SYS_GET_VIRTUAL_ADDRESS(r2);

   unsigned i = 0;

   if ((((int)r0 & 3) == 0) && 
         (((int)b & 3) == 0))
   {
      volatile int* r1 = (void*) r0;

      while ((i + 4) <= c)
      {            
         *r1++ = ((int*)b)[i/4];
         
         r0 += 4;
                     
         writePtr += 4;
         
         i += 4;
                  
         if (a->Data_12.size == writePtr)
         {
            writePtr = 0;
            
            r2 = a->Data_12.address + a->baseAddress;
            
            r0 = FAPI_SYS_GET_VIRTUAL_ADDRESS(r2);

            if ((int)r0 & 3)
            {
               break;
            }

            r1 = (void*) r0;
         }
      }
   }

   for (; i < c; i++)
   {
      *r0++ = ((char*)b)[i];
      
      writePtr++;
      
      if (a->Data_12.size == writePtr)
      {
         writePtr = 0;
         
         r2 = a->Data_12.address + a->baseAddress;
         
         r0 = FAPI_SYS_GET_VIRTUAL_ADDRESS(r2);
      }
   }

   bmSetWrPtr(a->Data_8, a->Data_44, writePtr);
   
   FAPI_SYS_FlushDataCache((void*)r9, a->Data_12.size);

   return i;
}


/* 21c14e60 - complete */
int func_21c14e60(void* h, void (*b)(int, int, void*), void* c, int d)
{      
   struct fapi_bm_handle* a = h;
   
   if (0 == fapi_bm_check_handle(a))
   {
      return -5008;
   }

   if (d != 0)
   {
      bmSetIrqMask(a->Data_8, 
            bmGetmIrqMask(a->Data_8) & ~(1 << a->Data_44));
   }

   if ((b == 0) && (d != 0) &&
         (a->Data_56 == 0))
   {
      return -5001;
   }

   if (d != 0)
   {
      if (c != 0)
      {
         a->Data_60 = c;
      }
      
      if (b != 0)
      {
         a->Data_56 = b;
      }
   }   
   else
   {
      a->Data_56 = func_21c140e8;
      a->Data_60 = a;
      
      func_21c12354(a, 3);
   }

   FAPI_SYS_FlushDataCache(a, sizeof(struct fapi_bm_handle));

   return 0;
}


/* 21c12478 - complete */
int func_21c12478(unsigned a, int b, int c)
{
   int ip;
   unsigned r5;
   
   FAPI_SYS_GET_SEMAPHORE(fapi_bm_semaphore, -1);

   if ((a == 0) || (a == 1))
   {
      r5 = fapi_bm_baseAddress.Data_0;
   }
   else
   {
      r5 = fapi_bm_baseAddress.Data_4;
   }
   
   r5 += b;   
   unsigned r1 = r5 + (c - 1);
      
   for (ip = 127; ip >= 0; ip--)
   {
      if (fapi_bm_handles[ip].inUse == 1)
      {    
         unsigned r3;
         
         if ((fapi_bm_handles[ip].Data_8 == 0) ||
               (fapi_bm_handles[ip].Data_8 == 1))
         {
            r3 = fapi_bm_baseAddress.Data_0;
         }
         else
         {
            r3 = fapi_bm_baseAddress.Data_4;
         }
         
         r3 += fapi_bm_handles[ip].Data_12.address;
         unsigned r0 = r3 + (fapi_bm_handles[ip].Data_12.size - 1);
         
         if (((r3 >= r5) && (r3 <= r1)) ||
               ((r0 >= r5) && (r0 <= r1)))
         {
            FAPI_SYS_SET_SEMAPHORE(fapi_bm_semaphore, 0);
            
            return 1;
         }         
      }
   }

   FAPI_SYS_SET_SEMAPHORE(fapi_bm_semaphore, 0);

   return 0;
}


/* 21c13fec - complete */
int fapi_bm_get_buffer_level(void* h)
{
   struct fapi_bm_handle* a = h;
   
   if (0 == fapi_bm_check_handle(a))
   {
      return -5008;
   }
   
   return get_buffer_level(a);
}


/* 21c13ee8 - todo */
int get_buffer_level(struct fapi_bm_handle* a)
{
   unsigned readPtr;
   unsigned writePtr = bmGetWrPtr(a->Data_8, a->Data_44);

   if ((Data_21f19ac8 == a->Data_8) &&
         (a->Data_44 < 8))
   {
      readPtr = bmGetRdPtr(a->Data_8, a->Data_44) & 0xFFFFFF;
   }
   else
   {
      readPtr = a->readPtr;
   }
   
   if (writePtr > a->Data_12.size)
   {
      if (readPtr > a->Data_12.size)
      {
         return -5105;
      }
      else
      {
         return a->Data_12.size;
      }
   }
   else
   {
      if (readPtr > a->Data_12.size)
      {
         return 0;
      }
      else
      {         
         if (readPtr > writePtr)
         {
            writePtr += a->Data_12.size;
            return writePtr - readPtr;
         }
         else
         {
            return writePtr - readPtr;
         }         
      }
   }
   
   return 0;
}


/* 21c12354 - complete */
void func_21c12354(struct fapi_bm_handle* a, int b)
{
   unsigned i;
   int r3;
   
   if ((a->Data_8 == 0) || (a->Data_8 == 1))
   {
      r3 = 0;
   }
   else
   {
      r3 = 1;
   }
   
   if (b == 3)
   {
      for (i = 0; i < 1024; i++)
      {
         if (fapi_bm_mail_fifo[r3][i].Data_0 & 3)
         {
            int k = fapi_bm_mail_fifo[r3][i].handleIndex;
            
            if ((fapi_bm_handles[k].Data_8 == a->Data_8) &&
                  (fapi_bm_handles[k].Data_44 == a->Data_44))
            {
               fapi_bm_mail_fifo[r3][i].Data_0 = 0;               
            }
         }
      }
   }
   else
   {
      for (i = 0; i < 1024; i++)
      {
         if (fapi_bm_mail_fifo[r3][i].Data_0 == b)
         {
            int k = fapi_bm_mail_fifo[r3][i].handleIndex;
            
            if ((fapi_bm_handles[k].Data_8 == a->Data_8) &&
                  (fapi_bm_handles[k].Data_44 == a->Data_44))
            {
               fapi_bm_mail_fifo[r3][i].Data_0 = 0;               
            }
         }
      }
   }
}


/* 21c13508 - complete */
int func_21c13508(void* h, unsigned b)
{
   struct fapi_bm_handle* a = h;
   
   if (0 == fapi_bm_check_handle(a))
   {
      return -5008;
   }

   if (Data_21f19ac8 != a->Data_8)
   {
      return -5103;
   }
   
   if (a->Data_44 > 6)
   {
      return -5103;
   }
   
   FAPI_SYS_GET_SEMAPHORE(fapi_bm_semaphore, -1);
   
   if (b != 0)
   {            
      func_21c6e380_1(a->Data_8, 
            func_21c6e3bc_1(a->Data_8) | (1 << a->Data_44));
   }
   else
   {      
      int r0 = func_21c6e3bc_1(a->Data_8);
      
      r0 &= ~(1 << a->Data_44);
      
      func_21c6e380_1(a->Data_8, r0);
   }
   
   FAPI_SYS_SET_SEMAPHORE(fapi_bm_semaphore, 0);
   
   return 0;
}


/* 21c1362c - complete */
int func_21c1362c(void* h, unsigned b, unsigned c)
{
   struct fapi_bm_handle* a = h;
   
   if (0 == fapi_bm_check_handle(a))
   {
      return -5008;
   }
   
   if (b > 1)
   {
      return -5001;
   }

   if (c > 1)
   {
      return -5001;
   }
   
   if (a->Data_44 > 7)
   {
      return -5103;
   }
   
   int r0 = bmGetmEndianSwapRd(a->Data_8);
   
   r0 &= ~(1 << a->Data_44);
   r0 |= (b << a->Data_44);
   r0 &= ~(1 << (a->Data_44 + 8));
   r0 |= (c << (a->Data_44 + 8));

   bmSetEndianSwapRd(a->Data_8, r0);
   
   return 0;
}


/* 21c140e8 - complete */
void func_21c140e8(int a, int b, void* c)
{
   bmSetRdPtr(a, b, 0);

   bmSetWrPtr(a, b, 0);
}


/* 21c12d18 - complete */
int func_21c12d18(void* h, void (*b)(unsigned, unsigned, int), int c, unsigned d, int e)
{
   struct fapi_bm_handle* a = h;
   unsigned i = 0;
   int r14 = 0;
   int r18 = 0;
   
   if (0 == fapi_bm_check_handle(a))
   {
      return -5008;
   }
   
   if (((b == 0) && (e != 0) && (a->Data_64 == 0)) ||
         ((d >= a->Data_12.size) && (e != 0)))
   {
      return -5001;
   }
      
   if ((Data_21f19adc == 8) && (e != 0))
   {
      return -5109;
   }

   FAPI_SYS_GET_SEMAPHORE(fapi_bm_semaphore, -1);

   if (e == 1)
   {
      for (i = 0; i < 8; i++)
      {
         if (a->Data_44 == Data_21efa5b4[i])
         {
            r18 = 1;
            break;
         }
      }
      
      if (i == 8)
      {
         for (i = 0; i < 8; i++)
         {
            if (Data_21efa5b4[i] == -1)
            {
               Data_21efa5b4[i] = a->Data_44;
               break;
            }
         }
      }
   }

   if ((e == 1) && (r18 == 0))
   {
      Data_21f19adc++;
      
      if (b != 0)
      {
         a->Data_64 = b;
      }
      
      if (c != 0)
      {
         a->Data_68 = c;
      }
      
      r14 |= 0x80000000;
      r14 |= (d & 0xffff00);
      r14 |= (a->Data_44 & 0x1f);
      
      if ((a->Data_8 == 1) || (a->Data_8 == 3))
      {
         r14 |= 0x20;
      }
      
      func_21c6e480_1(a->Data_8, i, r14);
   }
   else
   {
      if (r18 != 0)
      {
         func_21c6e490_1(a->Data_8, i, 1);
      }
      else
      {
         for (i = 0; i < 8; i++)
         {
            if (a->Data_44 == Data_21efa5b4[i])
            {
               break;
            }
         }

         if (i == 8)
         {
            FAPI_SYS_SET_SEMAPHORE(fapi_bm_semaphore, 0);
            
            return -5109;
         }
         
         if (e == 0)
         {            
            func_21c6e480_1(a->Data_8, i, 0);
            
            Data_21efa5b4[i] = -1;
            
            Data_21f19adc--;
            
            func_21c12354(a, 1);
         }
         else
         {
            func_21c6e490_1(a->Data_8, i, 0);
         }
      }
   }

   FAPI_SYS_FlushDataCache(a, sizeof(struct fapi_bm_handle));
   
   FAPI_SYS_SET_SEMAPHORE(fapi_bm_semaphore, 0);
   
   return 0;
}


/* 21c12cb8 - complete */
void fapi_bm_clear_handle(struct fapi_bm_handle* a)
{
   func_21c12354(a, 3);

   Data_21f19ae0[a->Data_8].Data_4--;
   
   memset(a, 0, sizeof(struct fapi_bm_handle));
   
   a->magic = 0x626d;
   
   FAPI_SYS_FlushDataCache(a, sizeof(struct fapi_bm_handle));
}


/* 21c12ae4 - complete */
int func_21c12ae4(void* h, void (*b)(unsigned,unsigned,int), int c, unsigned d, int e)
{
   struct fapi_bm_handle* a = h;
   int r13 = 0;
   
   if (0 == fapi_bm_check_handle(a))
   {
      return -5008;
   }
   
   if (((b == 0) && (e != 0) && (a->Data_72 == 0)) ||
         ((d >= a->Data_12.size) && (e != 0))) 
   {
      return -5001;
   }
      
   if (a->Data_44 >= 8)
   {
      return -5110;
   }
   
   FAPI_SYS_GET_SEMAPHORE(fapi_bm_semaphore, -1);
      
   if (e != 0)
   {
      if (b != 0)
      {
         a->Data_72 = b;
      }
      
      if (c != 0)
      {
         a->Data_76 = c;
      }
      
      r13 |= 0x80000000;
      r13 |= (d & 0xffffe0);
      
      func_21c6e428_1(a->Data_8, a->Data_44, r13);
   }
   else
   {
      func_21c6e444_1(a->Data_8, a->Data_44, 0);

      func_21c12354(a, 2);
   }   

   FAPI_SYS_FlushDataCache(a, sizeof(struct fapi_bm_handle));
   
   FAPI_SYS_SET_SEMAPHORE(fapi_bm_semaphore, 0);

   return 0;
}


/* 21c15bb4 - complete */
void fapi_bm_bsr(void* a)
{
   unsigned entries;
   unsigned cpu_sr;
   int r6 = 0;
   
   if ((int)a != 1)
   {
      r6 = 1;
   }

   cpu_sr = FAPI_SYS_DISABLE_IRQ;
   
   entries = fapi_bm_fifo_entries[r6];
   
   FAPI_SYS_ENABLE_IRQ(cpu_sr);
   
   while (entries != 0)
   {
      if ((fapi_bm_mail_fifo[r6][fapi_bm_fifo_read_ptr[r6]].Data_0 == 1) &&
            (fapi_bm_handles[fapi_bm_mail_fifo[r6][fapi_bm_fifo_read_ptr[r6]].handleIndex].Data_64 != 0))
      {
         unsigned r0;            
         for (r0 = 0; r0 < 8; r0++)
         {
            if (Data_21efa5b4[r0] ==
               fapi_bm_mail_fifo[r6][fapi_bm_fifo_read_ptr[r6]].Data_8)
            {
               break;
            }
         }

         if ((r0 != 8) &&
               (0 != func_21c6e4bc_1(fapi_bm_mail_fifo[r6][fapi_bm_fifo_read_ptr[r6]].Data_4, r0)))
         {
            (fapi_bm_handles[fapi_bm_mail_fifo[r6][fapi_bm_fifo_read_ptr[r6]].handleIndex].Data_64)(
                  fapi_bm_mail_fifo[r6][fapi_bm_fifo_read_ptr[r6]].Data_4,
                  fapi_bm_mail_fifo[r6][fapi_bm_fifo_read_ptr[r6]].Data_8,
                  fapi_bm_handles[fapi_bm_mail_fifo[r6][fapi_bm_fifo_read_ptr[r6]].handleIndex].Data_68);
         }
      }
      else if ((fapi_bm_mail_fifo[r6][fapi_bm_fifo_read_ptr[r6]].Data_0 == 2) &&
            (fapi_bm_handles[fapi_bm_mail_fifo[r6][fapi_bm_fifo_read_ptr[r6]].handleIndex].Data_72 != 0))
      {
         if (0 != func_21c6e46c_1(fapi_bm_mail_fifo[r6][fapi_bm_fifo_read_ptr[r6]].Data_4,
               fapi_bm_mail_fifo[r6][fapi_bm_fifo_read_ptr[r6]].Data_8))
         {
            (fapi_bm_handles[fapi_bm_mail_fifo[r6][fapi_bm_fifo_read_ptr[r6]].handleIndex].Data_72)(
                  fapi_bm_mail_fifo[r6][fapi_bm_fifo_read_ptr[r6]].Data_4,
                  fapi_bm_mail_fifo[r6][fapi_bm_fifo_read_ptr[r6]].Data_8,
                  fapi_bm_handles[fapi_bm_mail_fifo[r6][fapi_bm_fifo_read_ptr[r6]].handleIndex].Data_76);
         }
      }
      else if (fapi_bm_handles[fapi_bm_mail_fifo[r6][fapi_bm_fifo_read_ptr[r6]].handleIndex].Data_56 != 0)
      {
         (fapi_bm_handles[fapi_bm_mail_fifo[r6][fapi_bm_fifo_read_ptr[r6]].handleIndex].Data_56)(
               fapi_bm_mail_fifo[r6][fapi_bm_fifo_read_ptr[r6]].Data_4,
               fapi_bm_mail_fifo[r6][fapi_bm_fifo_read_ptr[r6]].Data_8,
               fapi_bm_handles[fapi_bm_mail_fifo[r6][fapi_bm_fifo_read_ptr[r6]].handleIndex].Data_60);

         bmSetIrqMask(fapi_bm_handles[fapi_bm_mail_fifo[r6][fapi_bm_fifo_read_ptr[r6]].handleIndex].Data_8,
               bmGetmIrqMask(fapi_bm_handles[fapi_bm_mail_fifo[r6][fapi_bm_fifo_read_ptr[r6]].handleIndex].Data_8) &
               ~(1 << fapi_bm_handles[fapi_bm_mail_fifo[r6][fapi_bm_fifo_read_ptr[r6]].handleIndex].Data_44));
      }

      cpu_sr = FAPI_SYS_DISABLE_IRQ;
      
      fapi_bm_mail_fifo[r6][fapi_bm_fifo_read_ptr[r6]].Data_0 = 0;
      
      fapi_bm_fifo_read_ptr[r6]++;
      
      if (fapi_bm_fifo_read_ptr[r6] >= 1024)
      {
         fapi_bm_fifo_read_ptr[r6] = 0;
      }
                  
      entries = --fapi_bm_fifo_entries[r6];

      FAPI_SYS_ENABLE_IRQ(cpu_sr);
   }   

   cpu_sr = FAPI_SYS_DISABLE_IRQ;
   
   Data_21f21dbc[r6]--;
   
   FAPI_SYS_ENABLE_IRQ(cpu_sr);
}


/* 21c1288c - complete */
int fapi_bm_check_handle(struct fapi_bm_handle* a)
{    
   if (a == 0)
   {
      return 0;
   }
   
   FAPI_SYS_InvalidateDataCache((int)a, sizeof(struct fapi_bm_handle));
   
   int res = 1;
   
   if ((fapi_bm_initialized == 0) ||
         (a->inUse == 0) ||
         (a->magic != 0x626d))
   {
      res = 0;
   }
   
   return res;
}


/* 21c12628 - complete */
unsigned func_21c12628(void)
{
   return Data_21f19ac8;
}


/* 21c12c60 - complete */
void fapi_bm_clear_mail_fifo(int a)
{
   int i;
   
   if ((a == 0) || (a == 1))
   {
      i = 0;
   }
   else
   {
      i = 1;
   }
   
   memset(fapi_bm_mail_fifo[i], 0, sizeof(fapi_bm_mail_fifo[i]));
   
   fapi_bm_fifo_entries[i] = 0;
   fapi_bm_fifo_read_ptr[i] = 0;
   fapi_bm_fifo_write_ptr[i] = 0;
}



