
#include "reg_vic.h"


/* 21b08294 - complete */
void FREG_VIC_Init(void)
{
}


/* 21b10308 - complete */
void FREG_VIC_SetIntselect(int a)
{
   *((volatile unsigned*)0xe000000c) = a;
}


/* 21b102b4 - complete */
void FREG_VIC_SetIntenable(int a)
{
   *((volatile unsigned*)0xe0000010) = a;
}


/* 21b102c0 - complete */
void FREG_VIC_SetVectaddrx(int a, int b)
{
   ((volatile unsigned*)0xe0000100)[a] = b;
}


/* 21b102d0 - complete */
int FREG_VIC_GetVectaddrx(int a)
{
   return ((volatile unsigned*)0xe0000100)[a];
}


/* 21b102e0 - complete */
void FREG_VIC_SetVectpriorityx(int a, int b)
{
   ((volatile unsigned*)0xe0000200)[a] = b;
}


/* 21b102f0 - complete */
void FREG_VIC_SetAddress(int a)
{
   *((volatile unsigned*)0xe0000f00) = a;
}


/* 21b102fc - complete */
int FREG_VIC_GetAddress(void)
{
   return *((volatile unsigned*)0xe0000f00);
}



