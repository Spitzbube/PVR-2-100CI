#ifndef FAMOS_THREAD_H_
#define FAMOS_THREAD_H_


#define FAMOS_THREAD_STATE_RUNNING    1
#define FAMOS_THREAD_STATE_READY      2
#define FAMOS_THREAD_STATE_SUSPEND    16
#define FAMOS_THREAD_STATE_DELAYWAIT  32
#define FAMOS_THREAD_STATE_EVENTWAIT  64
#define FAMOS_THREAD_STATE_DESTROYWAIT  128


struct famos_event
{
   void* next; //0
   void* prev; //4
   struct famos_thread* thread; //8
   int type; //12
   unsigned Data_16; //16
   char name[8]; //20
   //28
};

struct famos_thread
{
   int* sp; //0
   int Data_4; //4
   struct famos_thread* next; //8
   struct famos_thread* prev; //12
   char name[16]; //16 size??
   int* stackBuffer; //32
   unsigned stacksize; //36
   int stackAlloc; //40
   void (*func)(int); //44
   int param; //48
   int private; //52
   unsigned priority; //56
   unsigned Data_60; //60
   struct famos_event* event; //64
   unsigned state; //68
   unsigned Data_72; //72
   int lastError; //76
   int Data_80; //80
   char* printBuffer; //84
   struct
   {
      int fill_0; //0
      int Data_4; //4
      int fill_8[2]; //8
      int Data_16; //16
      int Data_20; //20
   }* Data_88; //88;
   int* spPeakTop; //92
   int* spPeakBottom; //96
   long long Data_100_104; //100
   long long timeStart; //108
   int CtxSwCtr; //116
   unsigned Data_120; //120
   //124
};


#endif /*FAMOS_THREAD_H_*/
