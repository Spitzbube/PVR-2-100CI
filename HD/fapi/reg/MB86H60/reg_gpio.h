#ifndef REG_GPIO_H_
#define REG_GPIO_H_

extern void FREG_GPIO_Init(void);
extern void func_21c70680(int, int);
extern void FREG_GPIO_SetDataOut_DataEnableInv(int, int);
extern void FREG_GPIO_SetDataOut_DataOutInv(int, int);
extern void FREG_GPIO_SetDataOut_DataEnExchange(int, int);
extern void FREG_GPIO_SetDataOut_DataEnSel(int, int);
extern void FREG_GPIO_SetDataOut_DataOutSel(int, int);

extern void func_21c70788(int, int);
extern void FREG_GPIO_SetDataIn_DataInSel(int, int);
extern void FREG_GPIO_SetIrqCfg_IrqClear(int);
extern void FREG_GPIO_SetIrqCfg_IrqMode(int);
extern void FREG_GPIO_SetIrqCfg_IrqInput(int);

extern void func_21c70850(int);
extern void FREG_GPIO_SetConfig_FlashAddrEn(int);

extern unsigned FREG_GPIO_GetIrqStatus_GpioIrq(void);

extern unsigned FREG_GPIO_GetInput_31_0(void);
extern unsigned FREG_GPIO_GetInput_63_32(void);
extern unsigned FREG_GPIO_GetInput_95_64(void);

extern void func_21c708d8(int);
extern unsigned func_21c708f0(void);

#endif /*REG_GPIO_H_*/
