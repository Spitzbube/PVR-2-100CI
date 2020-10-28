#ifndef FAMOS_MAILBOX_H_
#define FAMOS_MAILBOX_H_


struct famos_mailbox
{
   struct famos_event event; //0
   int busy; //28
   int size; //32
   void* data[4]; //36
   //52
};


#endif /*FAMOS_MAILBOX_H_*/
