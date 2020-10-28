#ifndef FAMOS_TIMER_H_
#define FAMOS_TIMER_H_

struct famos_timer
{
   struct famos_timer* next; //0
   struct famos_timer* prev; //4   
   struct famos_thread* thread; //8
   int type; //12
   int Data_16; //16
   char name[8]; //20
   int counter; //28
   int active; //32
   int cyclic; //36
   int reload; //40
   struct famos_semaphore* semaphore; //44
   //48
};

#endif /*FAMOS_TIMER_H_*/
