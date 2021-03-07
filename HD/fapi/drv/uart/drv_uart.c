
#include <string.h>
#include "fapi/reg_uart.h"
#include "fapi/sys_services.h"
#include "fapi/drv_gpio.h"
#include "fapi/drv_uart.h"


struct fapi_uart_handle
{
   int magic; //0
   int Data_4; //4
   int index; //8
   FAPI_UART_OpenParamsT Data_12; //12
   //20
};


struct Struct_21efc5bc
{
   int Data_0;
   void* semaphore; //4
   unsigned baudrate; //8
   int Data_12; //12
   unsigned Data_16; //16
   int Data_20; //20
   int Data_24; //24
   volatile char* rxReadPtr; //28
   volatile char* rxWritePtr; //32
   char* rxBuffer; //36
   char* rxEnd; //40
   volatile int Data_44; //44
   volatile char* txReadPtr; //48
   volatile char* txWritePtr; //52
   char* txBuffer; //56
   char* txEnd; //60
   volatile unsigned Data_64; //64
   int useInterrupt; //68
   int Data_72; //72
   //76
};

//char uartReadBuffer[2][0x1000]; //21f624f0 size???
//char uartWriteBuffer[2][0x1000]; //21f644f0 size???


int FAPI_UART_Init(void);
void FAPI_UART_Exit(void);
void* FAPI_UART_Isr0(void);
void* FAPI_UART_Isr1(void);
static int uartCheckHandle(struct fapi_uart_handle*);
static void fapi_uart_clear_handle(struct fapi_uart_handle*);
static void fapi_uart_set_freq(int i, unsigned baudrate);
static void func_214c9c48(int i, unsigned b);
static void fapi_uart_set_cts_rts(int i, unsigned b);
static void func_214c909c(int i, unsigned b);
static void func_214c90c0(int i, unsigned b);

static char uartReadBuffer[2][0x1000]; //21b194d0
static char uartWriteBuffer[2][0x1000]; //21b1b4d0
static struct fapi_uart_handle uartHandleArray[2]; //21b1d4d0
static struct fapi_uart_handle uartHandleStdlibc; //21b1d4f8

static int uartInitialized = 0; //21b13604
static void* uartSemaphore = 0; //21b13608
static unsigned uartClockFrequency = 81000000; //21b1360c
static int uartStdioBlockIndex = 0; //21b13610
void* uartRetargetHandle = 0; //21b13614

FAPI_SYS_DriverT FAPI_UART_Driver0 = //21efc574
{
      "UART0",
      8,
      0,
      FAPI_UART_Init,
      FAPI_UART_Exit,
      FAPI_UART_Isr0,
      0,
      0,
      0,
};

FAPI_SYS_DriverT FAPI_UART_Driver1 = //21efc598
{
      "UART1",
      9,
      0,
      FAPI_UART_Init,
      FAPI_UART_Exit,
      FAPI_UART_Isr1,
      0,
      0,
      0,
};

static struct Struct_21efc5bc uartBlockArray[2] = //21b13618
{
   {
      0, 
      0,
      115200,
      8,
      0, 
      1, 
      0,
      uartReadBuffer[0],
      uartReadBuffer[0],
      uartReadBuffer[0],
      &uartReadBuffer[0][0x1000-1],
      0,
      uartWriteBuffer[0],
      uartWriteBuffer[0],
      uartWriteBuffer[0],
      &uartWriteBuffer[0][0x1000-1],
      0,
      0,
      0,
   },
   {
      0, 
      0,
      9600,
      8,
      0, 
      1, 
      0,
      uartReadBuffer[1],
      uartReadBuffer[1],
      uartReadBuffer[1],
      &uartReadBuffer[1][0x1000-1],
      0,
      uartWriteBuffer[1],
      uartWriteBuffer[1],
      uartWriteBuffer[1],
      &uartWriteBuffer[1][0x1000-1],
      0,
      0,
      0,
   },
};




void fapi_uart_clear_handle(struct fapi_uart_handle* a)
{
   if (0 != uartCheckHandle(a))
   {      
      if (0 != memset(a, 0, sizeof(struct fapi_uart_handle)))
      {
         a->Data_4 = 0;
         a->magic = 0x75617274; //uart
         a->index = -1;
      }
   }
}


/* 21b067c4 - complete */
int FAPI_UART_Init(void)
{
   void* hGpio;
   unsigned i = 0;
   unsigned j = 0;
   volatile unsigned long* r17 = (void*) 0x2000000;
   
   FAPI_GPIO_OpenParamsT gpio_params;
   
   if (uartInitialized != 0)
   {
      return 0;
   }
   
   uartSemaphore = (FAPI_SYS_Services.createSemaphore != 0)?
         (FAPI_SYS_Services.createSemaphore)(1): 0;
         
   if (uartSemaphore == 0)
   {
      return 0xffffd8e7; //-25009;
   }
               
   for (i = 0; i < 2; i++)
   {
      if (0 != FAPI_SYS_IsMasterCpu())
      {
         FREG_UART_SetCr_Uarten(i, 0);
      }

      uartBlockArray[i].Data_0 = 0;
      
      uartBlockArray[i].semaphore = (FAPI_SYS_Services.createSemaphore != 0)?
            (FAPI_SYS_Services.createSemaphore)(1): 0;
      
      fapi_uart_set_freq(i, uartBlockArray[i].baudrate);            
      func_214c909c(i, uartBlockArray[i].Data_12);
      func_214c9c48(i, uartBlockArray[i].Data_16);
      func_214c90c0(i, uartBlockArray[i].Data_20);
      fapi_uart_set_cts_rts(i, uartBlockArray[i].Data_24);

      if (0 != FAPI_SYS_IsMasterCpu())
      {
         FREG_UART_SetLcrH_Fen(i, 0);
         FREG_UART_SetDr_Data(i, 0);
      }

      uartBlockArray[i].rxReadPtr = uartReadBuffer[i]; 
      uartBlockArray[i].rxWritePtr = uartReadBuffer[i]; 
      uartBlockArray[i].rxBuffer = uartReadBuffer[i];
      uartBlockArray[i].rxEnd = &uartReadBuffer[i][0xFFF]; 
      uartBlockArray[i].Data_44 = 0;
      uartBlockArray[i].txReadPtr = uartWriteBuffer[i]; 
      uartBlockArray[i].txWritePtr = uartWriteBuffer[i]; 
      uartBlockArray[i].txBuffer = uartWriteBuffer[i]; 
      uartBlockArray[i].Data_44 = 0;
      uartBlockArray[i].txEnd = &uartWriteBuffer[i][0xFFF]; 
      uartBlockArray[i].Data_72 = 0;            
   } //for (i = 0; i < 2; i++)

   for (i = 0; i < 2; i++)
   {
      memset(&uartHandleArray[i], 0, 20);
      
      uartHandleArray[i].magic = 0x75617274; //uart
      uartHandleArray[i].Data_4 = 0;
      uartHandleArray[i].index = 0;
   }
   
   uartHandleStdlibc.magic = 0x75617274; //uart
   uartHandleStdlibc.Data_4 = 1;
   uartHandleStdlibc.index = uartStdioBlockIndex;
   uartHandleStdlibc.Data_12.version = 0x20000;
   uartHandleStdlibc.Data_12.index = uartStdioBlockIndex;
   
   if (0 != FAPI_SYS_IsMasterCpu())
   {
      memset(&gpio_params, 0, sizeof(gpio_params));
      
      gpio_params.version = 0x20000;
      gpio_params.callback = 0;
      gpio_params.pin = -1;
//      gpio_params.function = 0;

      //UART TX
      if (uartHandleStdlibc.index == 0)
      {
         gpio_params.function = 0x97;
      }
      else
      {
         gpio_params.function = 0xAC;
      }
      
      hGpio = FAPI_GPIO_Open(&gpio_params, 0);
      
      if (hGpio != 0)
      {
         FAPI_GPIO_Close(hGpio); 
      }

      gpio_params.pin = -1;
      
      //UART RX
      if (uartHandleStdlibc.index == 0)
      {
         gpio_params.function = 0x115;
      }
      else
      {
         gpio_params.function = 0x140;
      }
      
      if (hGpio != 0)
      {
         hGpio = FAPI_GPIO_Open(&gpio_params, 0);
      }

      FAPI_GPIO_Close(hGpio); 
      
      FREG_UART_SetCr_Rxe(uartHandleStdlibc.index, 1);
      FREG_UART_SetCr_Txe(uartHandleStdlibc.index, 1);
      FREG_UART_SetLcrH_Fen(uartHandleStdlibc.index, 1);
      FREG_UART_SetCr_Uarten(uartHandleStdlibc.index, 1);
      
      if (uartBlockArray[uartHandleStdlibc.index].useInterrupt == 1)
      {
         FREG_UART_SetImsc(uartHandleStdlibc.index, 0);
      }
      
      r17[64] = 0x539;      
   }

   if (0 == FAPI_SYS_IsMasterCpu())
   {
      while ((r17[64] != 0x539) &&
            (j < 0x7FFFFFF))
      {
         /* wait */
         j++;
      }
   }

   uartRetargetHandle = &uartHandleStdlibc;
   
   uartInitialized = 1;
   
   return 0;
}


/* 21b06d90 - todo */
void FAPI_UART_Exit(void)
{   
   if (uartInitialized != 0)
   {
      unsigned i;
      for (i = 0; i < 2; i++)
      {
         FAPI_UART_Close(&uartBlockArray[i]);
         
         if (uartBlockArray[i].semaphore != 0)
         {
            if (FAPI_SYS_Services.deleteSemaphore != 0)
            {
               (FAPI_SYS_Services.deleteSemaphore)(
                     uartBlockArray[i].semaphore);
            }
         }
      }
      
      LOCK(uartSemaphore); 

      FREG_UART_SetCr_Rxe(uartHandleStdlibc.index, 0);
      FREG_UART_SetCr_Txe(uartHandleStdlibc.index, 0);
      FREG_UART_SetCr_Uarten(uartHandleStdlibc.index, 0);
      FREG_UART_SetImsc(uartHandleStdlibc.index, 0);

      UNLOCK(uartSemaphore);

      if (FAPI_SYS_Services.deleteSemaphore != 0)
      {
         (FAPI_SYS_Services.deleteSemaphore)(
               uartSemaphore);
      }

      uartSemaphore = 0;
      uartInitialized = 0;
   }   
}


/* 21b06f1c - complete */
void FAPI_UART_SetClockFrequency(unsigned a)
{
   if ((a >= 4000000) && (a < 800000000))
   {
      uartClockFrequency = a;
   }
}


/* 21b06f38 - complete */
void FAPI_UART_SetStdioBlockIndex(unsigned a)
{
   if (a <= 1)
   {
      uartStdioBlockIndex = a;
   }
}


/* 21c3bbac - complete */
void FAPI_UART_SetInterruptMode(unsigned a, unsigned b)
{
   if ((a <= 1) && (b <= 1))
   {
      uartBlockArray[a].useInterrupt = b;
   }
}


/* 21b06f6c - complete */
void FAPI_UART_SetBaudrate(unsigned a, unsigned baudrate)
{
   if ((a < 2) &&
         //(baudrate >= 2400) && (baudrate < 460801))
         ((baudrate - 2400) < 458401))
   {
      uartBlockArray[a].baudrate = baudrate;
   }
}


/* 21b06f98 - complete */
void FAPI_UART_SetDataBits(unsigned a, unsigned b)
{
   if ((a < 2) &&
         ((b >= 5) && (b < 9)))
   {
      uartBlockArray[a].Data_12 = b;
   }
}


/* 21b06ffc - complete */
void FAPI_UART_SetStopBits(unsigned a, unsigned b)
{
   if ((a < 2) &&
         ((b >= 1) && (b < 3)))
   {
      uartBlockArray[a].Data_20 = b;
   }
}


/* 21b07024 - complete */
void FAPI_UART_SetParity(unsigned a, unsigned b)
{
   if (a >= 2) return;

   if (b <= 2)
   {
      uartBlockArray[a].Data_16 = b;
   }
}


/* 21b0704c - complete */
void FAPI_UART_SetFlowControl(unsigned a, unsigned b)
{
   if (a >= 2) return;
   
   if (b <= 3) 
   {
      uartBlockArray[a].Data_24 = b;
   }
}


static struct fapi_uart_handle* fapi_uart_get_handle(void)
{
   unsigned i;
   struct fapi_uart_handle* res = 0;
   
   for (i = 0; i < 2; i++)
   {
      if (uartHandleArray[i].Data_4 == 0)
      {
         uartHandleArray[i].Data_4 = 1;
         uartHandleArray[i].index = -1;
         
         res = &uartHandleArray[i];
         break;
      }
   }
   
   return res;
}


/* 21b07074 - complete */
void* FAPI_UART_Open(FAPI_UART_OpenParamsT* param, int* pres)
{
   struct fapi_uart_handle* h;
   int res = 0;
   
   if (uartInitialized == 0)
   {
      res = 0xffffd8ec;
      if (pres != 0)
      {
         *pres = res; //-25004;
      }
      return 0;
   }
   
   if (param == 0)
   {
      res = 0xffffd8e6;
      if (pres != 0)
      {
         *pres = res; //-25010;
      }
      return 0;
   }
   
   if (param->version > 0x20000)
   {
      res = 0xffffd8e6;
      if (pres != 0)
      {
         *pres = res; //-25010;
      }
      return 0;
   }
   
   LOCK(uartSemaphore);
   
   h = fapi_uart_get_handle();

   if (0 != uartCheckHandle(h))
   {
      memcpy(&h->Data_12, param, sizeof(FAPI_UART_OpenParamsT));
      
      if (uartBlockArray[param->index].Data_0 != 0)
      {
         fapi_uart_clear_handle(h);
         
         h = 0;
         res = 0xffffd8ee; //-25002;
      }
      else
      {
         uartBlockArray[param->index].Data_0 = 1;
         
         h->index = param->index;
         
         FREG_UART_SetCr_Uarten(h->index, 1);
         
         if (uartBlockArray[h->index].useInterrupt == 1)
         {
            FREG_UART_SetLcrH_Fen(h->index, 1);
            FREG_UART_SetImsc_Rxim(h->index, 1);
            FREG_UART_SetImsc_Txim(h->index, 0);
            FREG_UART_SetImsc_Rtim(h->index, 1);
            FREG_UART_SetImsc_Oeim(h->index, 1);
            
            FREG_UART_SetIfls_Rxiflsel(uartHandleStdlibc.index, 0);
            FREG_UART_SetIfls_Txiflsel(uartHandleStdlibc.index, 0x04);
         }
      }
   }
   else
   {
      res = 0xffffd8ee; //-25002;
   }

   UNLOCK(uartSemaphore);
   
   if (pres != 0)
   {
      *pres = res;
   }
   
   return h;
}


/* 21b06ca8 - nearly complete */
int FAPI_UART_Close(void* h)
{
   struct fapi_uart_handle* a = h;
   int res = 0;
 
   LOCK(uartSemaphore);
   
   if (0 != uartCheckHandle(a))
   {
      FREG_UART_SetCr_Uarten(a->index, 0);
      FREG_UART_SetImsc_Rxim(a->index, 0);
      FREG_UART_SetImsc_Txim(a->index, 0);
      FREG_UART_SetImsc_Rtim(a->index, 0);
      FREG_UART_SetImsc_Oeim(a->index, 0);
      
      uartBlockArray[a->index].Data_0 = 0;
      
      fapi_uart_clear_handle(a);
   }
   else
   {
      res = 0xffffd8e8; //-25008;
   }

   UNLOCK(uartSemaphore);

   return res;
}


static /*inline*/ int func_21c3cb08(int a)
{
   int res;
   
   if ((0 != FAPI_SYS_IsIrqEnabled()) &&
         (0 == FAPI_SYS_IsIsrActive()))
   {
      res = 1;
   }      
   else
   {
      res = 0;
   }
   
//   if (res != 0) LOCK(uartBlockArray[a].semaphore);
   
   return res;
}


/* 21b07270 - todo */
int FAPI_UART_WriteByte(void* a, char r5)
{      
   unsigned cpu_sr;
   int r8;
   int r6;
   struct Struct_21efc5bc* r7;
   struct fapi_uart_handle* r4 = a;
   
   if (0 == uartCheckHandle(r4))
   {
      return 0xffffd8e8; //-25008;
   }

   r8 = r4->index;
   
   r7 = &uartBlockArray[r8];
            
   if (r7->Data_64 > 0x1000)
   {
      return 0xffff9df3; //-25101;
   }
   
   r6 = func_21c3cb08(r8); 
   
   if (r6 != 0) LOCK(uartBlockArray[r8].semaphore);

   DI(cpu_sr);
   
   *(r7->txWritePtr)++ = r5;  
   
   r7->Data_64++;
   
   if (r7->txWritePtr > r7->txEnd)
   {
      r7->txWritePtr = r7->txBuffer;
   }   

   EI(cpu_sr);

   if (uartBlockArray[r4->index].useInterrupt == 1)
   {
      if (0 != FREG_UART_GetFr_Txff(r8)) 
      {
         FREG_UART_SetImsc_Txim(r8, 1); 
         FREG_UART_SetIfls_Txiflsel(r8, 0x04); 
      }
      else
      {
         DI(cpu_sr);
            
         r5 = *(r7->txReadPtr)++;
         
         r7->Data_64--;
         
         if (r7->txReadPtr > r7->txEnd)
         {
            r7->txReadPtr = r7->txBuffer;
         }
         
         EI(cpu_sr);      

         FREG_UART_SetDr(r4->index, r5);
      }
   }
   else
   {
      while (1)
      {
         if (0 == FREG_UART_GetFr_Txff(r4->index)) break;
      }

      while (1)
      {
         if (0 == FREG_UART_GetFr_Busy(r4->index)) break;
      }

      DI(cpu_sr);
         
      r5 = *(r7->txReadPtr)++;
      
      r7->Data_64--;
      
      if (r7->txReadPtr > r7->txEnd)
      {
         r7->txReadPtr = r7->txBuffer;
      }
      
      EI(cpu_sr);      

      FREG_UART_SetDr(r4->index, r5);
   }

   if (r6 != 0) UNLOCK(uartBlockArray[r8].semaphore);

   return 0;
}


/* 21b07474 - complete */
int FAPI_UART_ReadByte(void* a) 
{
   int r5;
   struct Struct_21efc5bc* r4;
   int fp;
   struct fapi_uart_handle* r6 = a;
   int res = 0;
      
   if (0 == uartCheckHandle(r6))
   {
      return 0xffffd8e8; //-0x61B0;
   }
   
   r5 = r6->index;
   
   r4 = &uartBlockArray[r5];
   
   if (r4->Data_72 != 0)
   {
      r4->Data_72 = 0;
      return -0x620D;
   }
      
   fp = func_21c3cb08(r5);
   
   if (fp != 0) LOCK(uartBlockArray[r5].semaphore);

   if (uartBlockArray[r6->index].useInterrupt == 1)
   {
      unsigned cpu_sr;

#if 0
      while (r4->rxWritePtr == r4->rxReadPtr) { /* wait */ }
#else
      {
          volatile struct Struct_21efc5bc* r4_;
          for (r4_ = r4; r4_->rxWritePtr == r4_->rxReadPtr; ) {}
      }
#endif

      DI(cpu_sr);
      
      res = *(r4->rxReadPtr);
      (r4->rxReadPtr)++;
      
      r4->Data_44--;
            
      if (r4->rxReadPtr > r4->rxEnd)
      {
         r4->rxReadPtr = r4->rxBuffer;
      }

      EI(cpu_sr);
   }
   else
   {      
      while (1)
      {
         if (0 == FREG_UART_GetFr_Rxfe(r5)) break;
      }
      
      res = FREG_UART_GetDr_Data(r5) & 0xFF; 
   }

   if (fp != 0) UNLOCK(uartBlockArray[r5].semaphore);

   return res;
}


/* 21b075b0 - complete */
int FAPI_UART_CheckRxFifo(void* a)
{   
   struct fapi_uart_handle* r4 = a;
   
   LOCK(uartSemaphore);
      
   if (0 == uartCheckHandle(r4))
   {
      UNLOCK(uartSemaphore);
      return 0;
   }
      
   if (uartBlockArray[r4->index].useInterrupt == 1)
   {
      if (uartBlockArray[r4->index].rxWritePtr != 
         uartBlockArray[r4->index].rxReadPtr)
      {
         UNLOCK(uartSemaphore);
         return 1;
      }
   }
   else
   {
      if (0 == FREG_UART_GetFr_Rxfe(r4->index))
      {
         UNLOCK(uartSemaphore);
         return 1;
      }
   }

   UNLOCK(uartSemaphore);
      
   return 0;
}


/* 21b07680 - complete */
int FAPI_UART_CheckTxFifo(void* a)
{
   struct fapi_uart_handle* r5 = a;
   
   LOCK(uartSemaphore);
   
   if (0 == uartCheckHandle(r5))
   {
      UNLOCK(uartSemaphore);
      
      return 0;
   }
   
   if (0 == FREG_UART_GetFr_Txff(r5->index))
   {
      UNLOCK(uartSemaphore);
      
      return 1;
   }
   
   UNLOCK(uartSemaphore);
   
   return 0;
}


/* 21b0770c - complete */
void FAPI_UART_LockMutex(void)
{
   volatile unsigned* l = (void*) 0xcf000100;
   
   while (1)
   {
      *l = 1;
      
      if (*l == 1)
         break;
   }
}


/* 21b07728 - complete */
void FAPI_UART_UnlockMutex(void)
{
   volatile unsigned* l = (void*) 0xcf000100;
   
   *l = 0;
}


/* 21b1238c - complete */
/*static*/ INLINE void* uartIsrHandler(int a)
{ 
   char c;
   int irqStatus = FREG_UART_GetMis(a);
   struct Struct_21efc5bc* r4 = &uartBlockArray[a];
   
   if (irqStatus & (0x40|0x10))
   {
      if (irqStatus & 0x10)
      {
         FREG_UART_SetIcr_Rxic(a, 1);
      }

      if (irqStatus & 0x40)
      {
         FREG_UART_SetIcr_Rtic(a, 1);
      }

      while (0 == FREG_UART_GetFr_Rxfe(a))
      {
         c = FREG_UART_GetDr_Data(a) & 0xFF;
         
         *(r4->rxWritePtr) = c;

         r4->rxWritePtr++;
         r4->Data_44++;
         
         if (r4->rxWritePtr > r4->rxEnd)
         {
            r4->rxWritePtr = r4->rxBuffer;
         }         
      }
   }

   if (irqStatus & 0x20)
   {
      FREG_UART_SetIcr_Txic(a, 1);
      FREG_UART_SetImsc_Txim(a, 0);

      while (r4->txReadPtr != r4->txWritePtr)
      {
         if (0 != FREG_UART_GetFr_Txff(a))
         {
            FREG_UART_SetImsc_Txim(a, 1);
            FREG_UART_SetIfls_Txiflsel(a, 0x04);
            break;
         }
         else
         {
            c = *(r4->txReadPtr)++;
            
            r4->Data_64--;
            
            FREG_UART_SetDr(a, c);
                        
            if (r4->txReadPtr > r4->txEnd)
            {
               r4->txReadPtr = r4->txBuffer;
            }
         }
      }
   }

   if (irqStatus & 0x400)
   {
      FREG_UART_SetIcr_Oeic(a, 1);
      
      r4->Data_72++;
   }

   return 0;
}


/* 21b07738 - complete */
void* FAPI_UART_Isr0(void)
{
   return uartIsrHandler(0);
}


/* 21b07740 - complete */
void* FAPI_UART_Isr1(void)
{   
   return uartIsrHandler(1);
}


/* 21b07748 - complete */
int uartCheckHandle(struct fapi_uart_handle* h)
{
   //int res = 0;
   
   if ((uartInitialized != 0) && 
         (h != 0) &&
         (h->Data_4 != 0) &&
         (h->magic == 0x75617274)) //uart
   {
      return 1; //res = 1;
   }
   
   return 0; //res;
}


void fapi_uart_set_freq(int i, unsigned baudrate)
{
   unsigned r6 = uartClockFrequency / (baudrate*16);   
   unsigned r4 = (((uartClockFrequency*4) / baudrate) - r6*64);
   
   r4 = (r4*10 + 5)/10;
               
   FREG_UART_SetIbrd_BaudDivint(i, r6);
   FREG_UART_SetFbrd_BaudDivfrac(i, r4);
}


void func_214c9c48(int i, unsigned b)
{   
   switch (b)
   {
      case 2:
         if (0 == FREG_UART_GetLcrH_Pen(i))
         {
            FREG_UART_SetLcrH_Pen(i, 1);
         }

         if (0 == FREG_UART_GetLcrH_Eps(i))
         {
            FREG_UART_SetLcrH_Eps(i, 1);
         }
         break;  
         
      case 0:
         if (0 != FREG_UART_GetLcrH_Pen(i))
         {
            FREG_UART_SetLcrH_Pen(i, 0);
         }
         return; //break;
         
      case 1:
         if (0 == FREG_UART_GetLcrH_Pen(i))
         {
            FREG_UART_SetLcrH_Pen(i, 1);
         }

         if (0 != FREG_UART_GetLcrH_Eps(i))
         {
            FREG_UART_SetLcrH_Eps(i, 0);            
         }
         break;               
   }   
}


void fapi_uart_set_cts_rts(int i, unsigned b)
{
   switch (b)
   {         
      case 0:
         if (0 != FREG_UART_GetCr_Ctsen(i))
         {
            FREG_UART_SetCr_Ctsen(i, 0);
         }

         if (0 != FREG_UART_GetCr_Rtsen(i))
         {
            FREG_UART_SetCr_Rtsen(i, 0);
         }
         break;
         
      case 1:
         if (0 == FREG_UART_GetCr_Ctsen(i))
         {
            FREG_UART_SetCr_Ctsen(i, 1);
         }

         if (0 != FREG_UART_GetCr_Rtsen(i))
         {
            FREG_UART_SetCr_Rtsen(i, 0);
         }
         break;
         
      case 2:
         if (0 != FREG_UART_GetCr_Ctsen(i))
         {
            FREG_UART_SetCr_Ctsen(i, 0);
         }

         if (0 == FREG_UART_GetCr_Rtsen(i))
         {
            FREG_UART_SetCr_Rtsen(i, 1);
         }
         break;
         
      case 3:
         if (0 == FREG_UART_GetCr_Ctsen(i))
         {
            FREG_UART_SetCr_Ctsen(i, 1);
         }
         
         if (0 == FREG_UART_GetCr_Rtsen(i))
         {
            FREG_UART_SetCr_Rtsen(i, 1);
         }
         break;
   }
}


void func_214c909c(int i, unsigned b)
{
   b = b - 5;
   
   if (b != FREG_UART_GetLcrH_Wlen(i))
   {
      FREG_UART_SetLcrH_Wlen(i, b);
   }
}


void func_214c90c0(int i, unsigned b)
{
   b = b - 1;
   
   if (b != FREG_UART_GetLcrH_Stp2(i))
   {
      FREG_UART_SetLcrH_Stp2(i, b);
   }   
}













