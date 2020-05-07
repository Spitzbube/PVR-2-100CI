#ifndef REG_IRQ_CTRL_H_
#define REG_IRQ_CTRL_H_

extern void FREG_IRQ_CTRL_Init(void);
extern unsigned FREG_IRQ_CTRL_GetTimerxCntHigh(int);
extern unsigned FREG_IRQ_CTRL_GetTimerxCntLow(int);
extern void FREG_IRQ_CTRL_SetTimerxEnable_Endless(unsigned, int);
extern void FREG_IRQ_CTRL_SetTimerxEnable_IrqEnable(unsigned, int);
extern void FREG_IRQ_CTRL_SetTimerxEnable_Enable(unsigned, int);
extern int FREG_IRQ_CTRL_GetTimerxEnable_Enable(unsigned);
extern void FREG_IRQ_CTRL_SetTimerxCntPre(unsigned, int);
extern void FREG_IRQ_CTRL_SetTimerxCntLow(unsigned, int);
extern void FREG_IRQ_CTRL_SetTimerxCntHigh(unsigned, int);
extern void FREG_IRQ_CTRL_SetTimerxIrqReset_IrqReset(unsigned, int);
extern void FREG_IRQ_CTRL_SetArcirqmask(int);
extern int FREG_IRQ_CTRL_GetArcirqmask(void);
extern void FREG_IRQ_CTRL_SetArcirqxor(int);
extern int FREG_IRQ_CTRL_GetArcirqxor(void);
extern void FREG_IRQ_CTRL_SetArmirqmask(int);
extern int FREG_IRQ_CTRL_GetArmirqmask(void);
extern void FREG_IRQ_CTRL_SetArmirqxor(int);
extern int FREG_IRQ_CTRL_GetArmirqxor(void);
extern int FREG_IRQ_CTRL_GetArmirqstatus(void);

#endif /*REG_IRQ_CTRL_H_*/
