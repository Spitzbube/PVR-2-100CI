

#include "reg_gpio.h"



#define GPIO_DataOut ((volatile unsigned*)0xc3000000)
#define GPIO_DataIn ((volatile unsigned*)0xc3000200)
#define GPIO_IrqCfg ((volatile unsigned*)0xc30004c0)
#define GPIO_Config ((volatile unsigned*)0xc30004c4)
#define GPIO_IrqStatus ((volatile unsigned*)0xc3000400)
#define GPIO_Input_31_0 ((volatile unsigned*)0xc3000404)
#define GPIO_Input_63_32 ((volatile unsigned*)0xc3000408)
#define GPIO_Input_95_64 ((volatile unsigned*)0xc300040c)
#define REG9 ((volatile unsigned*)0xc30004ec)


/*volatile*/ int FREG_GPIO_DataOutMirror[96]; //21b1d548
/*volatile*/ int FREG_GPIO_DataInMirror[67]; //21b1d6c8
/*volatile*/ int FREG_GPIO_IrqCfgMirror; //21b137ec
/*volatile*/ int FREG_GPIO_ConfigMirror; //21b137f0
/*volatile*/ int Data_21f6ac9c/*FREG_GPIO_PwmSettingMirror?*/; //21f6ac9c


/* 21b08058 - complete */
void FREG_GPIO_Init(void)
{
   unsigned i;
   
   for (i = 0; i < 96; i++)
   {
      FREG_GPIO_DataOutMirror[i] |= 0;
   }
   
   for (i = 0; i < 96; i++)
   {
      FREG_GPIO_DataOutMirror[i] |= 0;
   }

   for (i = 0; i < 96; i++)
   {
      FREG_GPIO_DataOutMirror[i] |= 0;
   }

   for (i = 0; i < 96; i++)
   {
      FREG_GPIO_DataOutMirror[i] |= (1 << 8);
   }

   for (i = 0; i < 96; i++)
   {
      FREG_GPIO_DataOutMirror[i] |= 0;
   }

   for (i = 0; i < 67; i++)
   {
      FREG_GPIO_DataInMirror[i] |= 0;
   }
   
   FREG_GPIO_IrqCfgMirror |= (1 << 9);
   FREG_GPIO_IrqCfgMirror |= 0;
   FREG_GPIO_IrqCfgMirror |= 0;
   
   FREG_GPIO_ConfigMirror |= 0;
   FREG_GPIO_ConfigMirror |= 0;
}


/* 21c70680 - complete */
void func_21c70680(int a, int b)
{
   FREG_GPIO_DataOutMirror[a] = b;
   (GPIO_DataOut)[a] = b;
}


/* 21b0f7d8 - complete */
void FREG_GPIO_SetDataOut_DataEnableInv(int a, int b)
{
   int c = ((b << 18) & (1 << 18)) |
      (FREG_GPIO_DataOutMirror[a] & ~(1 << 18));
    FREG_GPIO_DataOutMirror[a] = c;
   (GPIO_DataOut)[a] = c;
}


/* 21b0f854 - complete */
void FREG_GPIO_SetDataOut_DataOutInv(int a, int b)
{
   int c = ((b << 17) & (1 << 17)) |
      (FREG_GPIO_DataOutMirror[a] & ~(1 << 17));
   FREG_GPIO_DataOutMirror[a] = c;
   (GPIO_DataOut)[a] = c;
}


/* 21b0f8b4 - complete */
void FREG_GPIO_SetDataOut_DataEnExchange(int a, int b)
{
   int c = ((b << 16) & (1 << 16)) |
      (FREG_GPIO_DataOutMirror[a] & ~(1 << 16));
   FREG_GPIO_DataOutMirror[a] = c; 
   (GPIO_DataOut)[a] = c;
}


/* 21b0f8e0 - complete */
void FREG_GPIO_SetDataOut_DataEnSel(int a, int b)
{
   int c = ((b << 8) & (0xf << 8)) |
         (FREG_GPIO_DataOutMirror[a] & ~(0xf << 8));
   FREG_GPIO_DataOutMirror[a] = c;
   (GPIO_DataOut)[a] = c;
}


/* 21b0f90c - complete */
void FREG_GPIO_SetDataOut_DataOutSel(int a, int b)
{
   b = (FREG_GPIO_DataOutMirror[a] & ~0x7f) | (b & (0x7f));
   FREG_GPIO_DataOutMirror[a] = b;
   (GPIO_DataOut)[a] = b;
}


/* 21c70788 - complete */
void func_21c70788(int a, int b)
{
   FREG_GPIO_DataInMirror[a] = b;
   (GPIO_DataIn)[a] = b;
}


/* 21b0f754 - complete */
void FREG_GPIO_SetDataIn_DataInSel(int a, int b)
{
   b = (b & 0x7f) | (FREG_GPIO_DataInMirror[a] & ~0x7f);
   FREG_GPIO_DataInMirror[a] = b;
   (GPIO_DataIn)[a] = b;
}


/* 21b0f780 - complete */
void FREG_GPIO_SetIrqCfg_IrqClear(int a)
{
   a = ((a << 9) & (1 << 9)) | (FREG_GPIO_IrqCfgMirror & ~(1 << 9));
   FREG_GPIO_IrqCfgMirror = a;
   *(GPIO_IrqCfg) = a;
}


/* 21b0f7ac - complete */
void FREG_GPIO_SetIrqCfg_IrqMode(int a)
{
   a = ((a << 8) & (1 << 8)) | (FREG_GPIO_IrqCfgMirror & ~(1 << 8));
   FREG_GPIO_IrqCfgMirror = a;
   *(GPIO_IrqCfg) = a;
}


/* 21b0f804 - complete */
void FREG_GPIO_SetIrqCfg_IrqInput(int a)
{
   a = (a & 0x7f) | (FREG_GPIO_IrqCfgMirror & ~0x7f);
   FREG_GPIO_IrqCfgMirror = a;
   *(GPIO_IrqCfg) = a;
}


/* 21c70850 - complete */
void func_21c70850(int a)
{
   a = ((a << 3) & (1 << 3)) | (FREG_GPIO_ConfigMirror & ~(1 << 3));
   FREG_GPIO_ConfigMirror = a;
   *(GPIO_Config) = a;
}


/* 21b0f82c - complete */
void FREG_GPIO_SetConfig_FlashAddrEn(int a)
{
   a = (a & 1) | (FREG_GPIO_ConfigMirror & ~1);
   FREG_GPIO_ConfigMirror = a;
   *(GPIO_Config) = a;
}


/* 21b0f880 - complete */
unsigned FREG_GPIO_GetIrqStatus_GpioIrq(void)
{
   return *(GPIO_IrqStatus) & 1;
}


/* 21b0f890 - complete */
unsigned FREG_GPIO_GetInput_31_0(void)
{
   return *(GPIO_Input_31_0);
}


/* 21b0f89c - complete */
unsigned FREG_GPIO_GetInput_63_32(void)
{
   return *(GPIO_Input_63_32);
}


/* 21b0f8a8 - complete */
unsigned FREG_GPIO_GetInput_95_64(void)
{
   return *(GPIO_Input_95_64);
}


/* 21c708d8 - complete */
void func_21c708d8(int a)
{
   Data_21f6ac9c = a;
   *REG9 = a;
}


/* 21c708f0 - complete */
unsigned func_21c708f0(void)
{
   return Data_21f6ac9c;
}











