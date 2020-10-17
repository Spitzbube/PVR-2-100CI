#ifndef FAMOS_SEMAPHORE_H_
#define FAMOS_SEMAPHORE_H_


struct famos_semaphore
{
   struct famos_semaphore* next; //0
   struct famos_semaphore* prev; //4
   struct famos_thread* thread; //8
   int type; //12
   unsigned Data_16; //16
   char name[8]; //20
   int Data_28; //28
   int Data_32; //32
   //36
};

void* famos_semaphore_create(unsigned r8);
int famos_semaphore_delete(struct famos_semaphore* semaphore);


#endif /*FAMOS_SEMAPHORE_H_*/
