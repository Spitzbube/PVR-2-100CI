#ifndef DRV_TIMER_H_
#define DRV_TIMER_H_

extern struct fapi_driver FAPI_TIMER_Driver0;  
extern struct fapi_driver FAPI_TIMER_Driver1; 
extern struct fapi_driver FAPI_TIMER_Driver2; 


struct fapi_timer_params
{
   int Data_0; //0
   unsigned index; //4
   int type; //8 1=single
   unsigned Data_12; //12
   int Data_16; //16
   void (*Data_20)(unsigned long long, void*); //20
   void* Data_24; //24
   void (*Data_28)(unsigned long long, void*); //28
   void* Data_32; //32
   int Data_36; //36
   int Data_40; //40
   //44
};

extern int FAPI_TIMER_Stop(void*);
extern void* FAPI_TIMER_Open(struct fapi_timer_params*, int*);
extern int FAPI_TIMER_Close(void*);
extern unsigned FAPI_TIMER_GetIndex(unsigned);
extern int FAPI_TIMER_GetResolution(unsigned);
extern void FAPI_TIMER_SetClockFrequency(unsigned);
extern void FAPI_TIMER_SetResolution(unsigned, unsigned);
extern unsigned long long FAPI_TIMER_GetTimeStamp(unsigned);
extern int FAPI_TIMER_Start(void*);
extern unsigned long long FAPI_TIMER_ReadValue(void*);

#endif /*DRV_TIMER_H_*/
