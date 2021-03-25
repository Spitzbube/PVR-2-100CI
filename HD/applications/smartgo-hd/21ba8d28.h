#ifndef X21BA8D28_H_
#define X21BA8D28_H_


struct Struct_21ba8d28_Funcs
{
   void (*Func_16)(void); //0
   void (*Func_20)(void); //4
   void (*Func_24)(void); //8
   int32_t (*Func_28)(uint8_t r7, uint8_t* ascender, uint8_t* descender, uint8_t* fp); //12
   void (*Func_32)(void); //16
   int fill_36; //20
   //24
};

struct Struct_21ba8d28
{
   unsigned short wData_0; //0
   unsigned short wData_2; //2
   unsigned short wData_4; //4
   unsigned short wData_6; //6
   char bData_8; //8
   unsigned short fill_10; //10
   char bData_12; //12
   char bData_13; //13
   struct Struct_21ba8d28_Funcs funcs; //16
   //40
};


extern int32_t func_21ba8d28(struct Struct_21ba8d28*);



#endif /*X21BA8D28_H_*/
