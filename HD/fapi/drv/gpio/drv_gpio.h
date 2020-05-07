#ifndef DRV_GPIO_H_
#define DRV_GPIO_H_

extern struct fapi_driver FAPI_GPIO_Driver; //21b12e94

struct fapi_gpio_params
{
   int Data_0; //0
   unsigned index; //4
   unsigned Data_8; //8
   void (*func)(int); //12
};

extern int FAPI_GPIO_Init(void);
extern void* FAPI_GPIO_Open(struct fapi_gpio_params*, int*);
extern int FAPI_GPIO_Close(void*);
extern int FAPI_GPIO_WriteBit(void*, int);
extern int FAPI_GPIO_ReadBit(void*);
extern void FAPI_GPIO_SetIrqTrigger(unsigned);
extern void FAPI_GPIO_SetIrqEnable(unsigned);
extern void FAPI_GPIO_SetPinFunction(unsigned, unsigned);

#endif /*DRV_GPIO_H_*/
