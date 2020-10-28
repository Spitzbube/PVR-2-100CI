#ifndef FAMOS_MAILQUEUE_H_
#define FAMOS_MAILQUEUE_H_

struct famos_mailqueue
{
   struct famos_mailqueue* next; //0
   struct famos_mailqueue* prev; //4
   struct famos_thread* Data_8; //8
   int type; //12
   unsigned Data_16; //16
   char name[8]; //20
   unsigned itemCount; //28
   int itemSize; //32
   void* buffer; //36
   unsigned queueLength; //40
   int tail; //44
   int head; //48
   //52
};

#endif /*FAMOS_MAILQUEUE_H_*/
