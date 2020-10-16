


#include "reg_irq_ctrl.h"



unsigned FREG_IRQ_CTRL_GetTimerxCntHigh(int a)
{
   return 0;
}


unsigned FREG_IRQ_CTRL_GetTimerxCntLow(int a)
{
   return 0;
}


/* 21b0fa14 - complete */
void FREG_IRQ_CTRL_SetArmirqmask(int a)
{
   *((volatile unsigned*)0xcf000300) = a;
}


/* 21b0fa20 - complete */
int FREG_IRQ_CTRL_GetArmirqmask(void)
{
   return *((volatile unsigned*)0xcf000300);
}


/* 21b0fa2c - complete */
void FREG_IRQ_CTRL_SetArmirqxor(int a)
{
   *((volatile unsigned*)0xcf000304) = a;
}


/* 21b0fa38 - complete */
int FREG_IRQ_CTRL_GetArmirqxor(void)
{
   return *((volatile unsigned*)0xcf000304);
}


/* 21b0fa44 - complete */
int FREG_IRQ_CTRL_GetArmirqstatus(void)
{
   return *((volatile unsigned*)0xcf000308);
}


