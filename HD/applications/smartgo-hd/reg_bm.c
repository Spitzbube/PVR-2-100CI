


#include "reg_bm.h"


static volatile int Data_21f6a7f0; //21f6a7f0
static volatile int Data_21f6a7f4; //21f6a7f4
static volatile int Data_21f6a7f8; //21f6a7f8
static volatile int Data_21f6a7fc; //21f6a7fc
static volatile unsigned Data_21f6a800[8]; //21f6a800
static volatile int Data_21f6a820; //21f6a820
static volatile int Data_21f6a824; //21f6a824
static volatile int Data_21f6a828[5]; //21f6a828
static volatile int Data_21f6a83c; //21f6a83c
static volatile int Data_21f6a840; //21f6a840
static volatile int Data_21f6a844; //21f6a844
static volatile int Data_21f6a848; //21f6a848
static volatile int Data_21f6a84c; //21f6a84c
static volatile int Data_21f6a850; //21f6a850
static volatile unsigned Data_21f6a854[8]; //21f6a854
static volatile int Data_21f6a874; //21f6a874
static volatile int Data_21f6a878; //21f6a878
static volatile int Data_21f6a87c[5]; //21f6a87c
static volatile int Data_21f6a890; //21f6a890
static volatile int Data_21f6a894; //21f6a894
static volatile int Data_21f6a898; //21f6a898


#if 0
/* 21c6dfa8 - complete */
void FREG_BM_Init(void)
{
   int i;
   
   Data_21f6a7f0 |= 0xFFFFFFFF;
   
   Data_21f6a7f4 |= 0;
   Data_21f6a7f4 |= 0;
   
   Data_21f6a7fc |= 0;
   
   Data_21f6a820 |= 0xFFFFFFFF;
   
   Data_21f6a824 |= 0;
   
   for (i = 0; i < 5; i++)
   {
      Data_21f6a828[i] |= 0;
   }

   for (i = 0; i < 5; i++)
   {
      Data_21f6a828[i] |= 0;
   }
   
   Data_21f6a83c |= 0;
   Data_21f6a83c |= 0;
   
   Data_21f6a840 |= 0;
   Data_21f6a840 |= 0;
   Data_21f6a840 |= 0;
   Data_21f6a840 |= 0;
   Data_21f6a840 |= 0;   
   
   Data_21f6a844 |= 0xFFFFFFFF;
   
   Data_21f6a848 |= 0;
   Data_21f6a848 |= 0;
   
   Data_21f6a850 |= 0;
   
   Data_21f6a874 |= 0xFFFFFFFF;   
   
   Data_21f6a878 |= 0;
   
   for (i = 0; i < 5; i++)
   {
      Data_21f6a87c[i] |= 0;
   }

   for (i = 0; i < 5; i++)
   {
      Data_21f6a87c[i] |= 0;
   }
   
   Data_21f6a890 |= 0;
   Data_21f6a890 |= 0;
   
   Data_21f6a894 |= 0;
   Data_21f6a894 |= 0;
   Data_21f6a894 |= 0;
   Data_21f6a894 |= 0;
   Data_21f6a894 |= 0;
   Data_21f6a894 |= 0;
   Data_21f6a894 |= 0;
   Data_21f6a894 |= 0;
   Data_21f6a894 |= 0;
   Data_21f6a894 |= 0;
   Data_21f6a894 |= 0;
   Data_21f6a894 |= 0;
   Data_21f6a894 |= 0;
   Data_21f6a894 |= 0;
   
   Data_21f6a898 |= 0;
   Data_21f6a898 |= 0;
   Data_21f6a898 |= 0;
   Data_21f6a898 |= 0;
   Data_21f6a898 |= 0;
   Data_21f6a898 |= 0;
   Data_21f6a898 |= 0;
   Data_21f6a898 |= 0;
   Data_21f6a898 |= 0;
   Data_21f6a898 |= 0;
   Data_21f6a898 |= 0;
   Data_21f6a898 |= 0;
   Data_21f6a898 |= 0;
   Data_21f6a898 |= 0;
}
#endif


/* 21c6e314 - complete */
int func_21c6e314(void)
{
   return Data_21f6a7f0;
}


/* 21c6e380 - complete */
void func_21c6e380(int a)
{
   a = (a << 0) & (0x7f << 0);
   a |= (Data_21f6a7f4 & ~(0x7f << 0));
   Data_21f6a7f4 = a;
   *((volatile int*)0xc8300208) = a;
}


/* 21c6e3bc - complete */
int func_21c6e3bc(void)
{
   return Data_21f6a7f4 & 0x7f;
}


/* 21c6e5a4 - complete */
int func_21c6e5a4(void)
{
   return Data_21f6a820;
}


/* 21c6e708 - complete */
int func_21c6e708(void)
{
   return Data_21f6a844;
}


/* 21c6e774 - complete */
void func_21c6e774(int a)
{
   a = (a << 0) & (0x7f << 0);
   a |= (Data_21f6a848 & ~(0x7f << 0));
   Data_21f6a848 = a;
   *((volatile int*)0xc8b00208) = a;
}


/* 21c6e7b0 - complete */
int func_21c6e7b0(void)
{
   return Data_21f6a848 & 0x7f;
}


/* 21c6e998 - complete */
int func_21c6e998(void)
{
   return Data_21f6a874;
}


/* 21c6e294 - complete */
int freg_bm1_get_write_pointer(int a)
{
   return ((volatile unsigned*)0xc8300080)[a];
}


/* 21c6e2e8 - complete */
int freg_bm1_get_read_pointer(int a)
{
   return ((volatile unsigned*)0xc8300180)[a];
}


/* 21c6e274 - complete */
int freg_bm1_get_buffer_size(int a)
{
   return *((volatile unsigned*)(0xc8300000 + a*4));
}


/* 21c6e2c8 - complete */
int freg_bm1_get_buffer_address(int a)
{
   return *((volatile unsigned*)(0xc8300100 + a*4));
}


/* 21c6e578 - complete */
int freg_bm2_get_read_pointer(int a)
{
   return ((volatile unsigned*)0xc8300580)[a];
}


/* 21c6e524 - complete */
int freg_bm2_get_write_pointer(int a)
{
   return ((volatile unsigned*)0xc8300480)[a];
}


/* 21c6e504 - complete */
int freg_bm2_get_buffer_size(int a)
{
   return *((volatile unsigned*)(0xc8300400 + a*4));
}


/* 21c6e558 - complete */
int freg_bm2_get_buffer_address(int a)
{
   return *((volatile unsigned*)(0xc8300500 + a*4));   
}


/* 21c6e6dc - complete */
int freg_bm3_get_read_pointer(int a)
{
   return ((volatile unsigned*)0xc8b00180)[a];
}


/* 21c6e688 - complete */
int freg_bm3_get_write_pointer(int a)
{
   return ((volatile unsigned*)0xc8b00080)[a];
}


/* 21c6e668 - complete */
int freg_bm3_get_buffer_size(int a)
{
   return *((volatile unsigned*)(0xc8b00000 + a*4));
}


/* 21c6e6bc - complete */
int freg_bm3_get_buffer_address(int a)
{
   return *((volatile unsigned*)(0xc8b00100 + a*4));
}


/* 21c6e96c - complete */
int freg_bm4_get_read_pointer(int a)
{
   return ((volatile unsigned*)0xc8b00580)[a];
}


/* 21c6e918 - complete */
int freg_bm4_get_write_pointer(int a)
{
   return ((volatile unsigned*)0xc8b00480)[a];
}


/* 21c6e8f8 - complete */
int freg_bm4_get_buffer_size(int a)
{
   return *((volatile unsigned*)(0xc8b00400 + a*4)); 
}


/* 21c6e94c - complete */
int freg_bm4_get_buffer_address(int a)
{
   return *((volatile unsigned*)(0xc8b00500 + a*4)); 
}


/* 21c6e444 - complete */
void func_21c6e444(int a, int b)
{
   b = (b << 31) | (Data_21f6a800[a] & ~(1 << 31));
   Data_21f6a800[a] = b;
   *((volatile unsigned*)(0xc8300220 + a*4)) = b;
}


/* 21c6e46c - complete */
int func_21c6e46c(unsigned a)
{
   return Data_21f6a800[a] >> 31;
}


/* 21c6e490 - complete */
void func_21c6e490(int a, int b)
{
   b = (b << 31);
   *((volatile unsigned*)(0xc8300240 + a*4)) = 
      (*((volatile unsigned*)(0xc8300240 + a*4)) & ~(1 << 31)) | b;
}


/* 21c6e4ac - complete */
int func_21c6e4ac(int a)
{
   return *((volatile unsigned*)(0xc8300240 + a*4));
}


/* 21c6e4bc - complete */
int func_21c6e4bc(unsigned a)
{
   return (*((volatile unsigned*)(0xc8300240 + a*4))) >> 31;
}


/* 21c6e838 - complete */
void func_21c6e838(int a, int b)
{
   b = (b << 31) | (Data_21f6a854[a] & ~(1 << 31));
   Data_21f6a854[a] = b;
   *((volatile unsigned*)(0xc8b00220 + a*4)) = b;
}


/* 21c6e860 - complete */
int func_21c6e860(unsigned a)
{
   return Data_21f6a854[a] >> 31;
}


/* 21c6e884 - complete */
void func_21c6e884(int a, int b)
{
   b = (b << 31);
   *((volatile unsigned*)(0xc8b00240 + a*4)) = 
      (*((volatile unsigned*)(0xc8b00240 + a*4)) & ~(1 << 31)) | b;
}


/* 21c6e8a0 - complete */
int func_21c6e8a0(int a)
{
   return *((volatile unsigned*)(0xc8b00240 + a*4));
}


/* 21c6e8b0 - complete */
int func_21c6e8b0(unsigned a)
{
   return (*((volatile unsigned*)(0xc8b00240 + a*4))) >> 31;
}


/* 21c6e9e4 - complete */
void func_21c6e9e4(int a, int b)
{
   Data_21f6a87c[a] = b;
   *((volatile unsigned*)(0xc8b002e0 + a*4)) = b;
}


/* 21c6e5f0 - complete */
void func_21c6e5f0(int a, int b)
{
   Data_21f6a828[a] = b;
   *((volatile unsigned*)(0xc83002e0 + a*4)) = b;
}


/* 21c6ea60 - complete */
void func_21c6ea60(int a)
{
   Data_21f6a894 = a;
   *((volatile unsigned*)0xc8300214) = a;
}


/* 21c6ea7c - complete */
int func_21c6ea7c(void)
{
   return Data_21f6a894;
}


/* 21c6ea8c - complete */
void func_21c6ea8c(int a)
{
   Data_21f6a898 = a;
   *((volatile unsigned*)0xc8b00214) = a;
}


/* 21c6eaa8 - complete */
int func_21c6eaa8(void)
{
   return Data_21f6a898;
}


/* 21c6e3fc - complete */
void func_21c6e3fc(int a)
{
   Data_21f6a7fc = a;
   *((volatile unsigned*)0xc8300218) = a;
}


/* 21c6e418 - complete */
int func_21c6e418(void)
{
   return Data_21f6a7fc;
}


/* 21c6e5c4 - complete */
void func_21c6e5c4(int a)
{
   Data_21f6a824 = a;
   *((volatile unsigned*)0xc8300618) = a;
}


/* 21c6e5e0 - complete */
int func_21c6e5e0(void)
{
   return Data_21f6a824;
}


/* 21c6e7f0 - complete */
void func_21c6e7f0(int a)
{
   Data_21f6a850 = a;
   *((volatile unsigned*)0xc8b00218) = a;
}


/* 21c6e80c - complete */
int func_21c6e80c(void)
{
   return Data_21f6a850;
}


/* 21c6e9b8 - complete */
void func_21c6e9b8(int a)
{
   Data_21f6a878 = a;
   *((volatile unsigned*)0xc8b00618) = a;
}


/* 21c6e9d4 - complete */
int func_21c6e9d4(void)
{
   return Data_21f6a878;
}


/* 21c6eab8 - complete */
int func_21c6eab8(void)
{
   return *((volatile unsigned*)0xc8300264);
}


/* 21c6e628 - complete */
int func_21c6e628(int a)
{
   return *((volatile unsigned*)(0xc83002e0 + a*4)) & 0xffffff;
}


/* 21c6ea1c - complete */
int func_21c6ea1c(int a)
{
   return *((volatile unsigned*)(0xc8b002e0 + a*4)) & 0xffffff;
}


/* 21c6e4d0 - complete */
int func_21c6e4d0(int a)
{
   return *((volatile unsigned*)(0xc8300240 + a*4)) & 0x3F;
}







