#ifndef REG_VIC_H_
#define REG_VIC_H_

extern void FREG_VIC_Init(void);
extern void FREG_VIC_SetIntselect(int);
extern void FREG_VIC_SetIntenable(int);
extern void FREG_VIC_SetVectaddrx(int, int);
extern int FREG_VIC_GetVectaddrx(int);
extern void FREG_VIC_SetVectpriorityx(int, int);
extern void FREG_VIC_SetAddress(int);

#endif /*REG_VIC_H_*/
