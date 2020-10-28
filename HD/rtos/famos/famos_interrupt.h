#ifndef FAMOS_INTERRUPT_H_
#define FAMOS_INTERRUPT_H_

extern void ARM1176_INTR_UndefFunction(int); 
extern void ARM1176_INTR_SwiFunction(int, int); 
extern void ARM1176_INTR_PrefetchFunction(int); 
extern void ARM1176_INTR_AbortFunction(int); 
extern void ARM1176_INTR_IrqFunction(int); 
extern void ARM1176_INTR_FiqFunction(int);

#endif /*FAMOS_INTERRUPT_H_*/
