#ifndef DRV_INTR_H_
#define DRV_INTR_H_

extern struct fapi_driver FAPI_INTR_Driver;

extern void* (*FAPI_INTR_IsrFunctionTable[])(void);
extern int (*FAPI_INTR_BsrFunctionTable[])(void*); 
extern int (*FAPI_INTR_SwiFunctionTable[])(int);

extern void FAPI_INTR_Exit(void);
extern int FAPI_INTR_RegisterIrq(unsigned, void* (*)(void), int (*)(void*));
extern int FAPI_INTR_UnregisterIrq(unsigned);
extern int FAPI_INTR_DisableIrqCtrl(unsigned);
extern int FAPI_INTR_EnableIrqCtrl(unsigned);
extern void FAPI_INTR_SetReceiver(unsigned, unsigned);
extern void FAPI_INTR_SetPriority(unsigned, unsigned);
uint32_t FAPI_INTR_Isr31( void );

#endif /*DRV_INTR_H_*/
