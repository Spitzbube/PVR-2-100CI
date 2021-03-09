#ifndef ROM_SYMBOLS_H_
#define ROM_SYMBOLS_H_

typedef struct 
{
   int fill[65]; //0
   void (*arm_poll)(void); //260
   void (*arc_poll)(void); //264
   //268
} BOOT_ROM_SymbolT;


#endif /* ROM_SYMBOLS_H_ */
