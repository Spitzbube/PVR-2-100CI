#ifndef STRINGOP_H_
#define STRINGOP_H_


struct Struct_21ba1a6c
{
   uint8_t bData_0; //0
   uint32_t Data_4; //4
   void* data; //8
   uint32_t size; //12
   int memAllocated; //16
   //20
};


extern int32_t func_21ba1adc(struct appData* a);
extern int32_t STR_BufOpen(struct Struct_21ba1a6c*, int, void*);
extern int32_t STR_BufClear(struct Struct_21ba1a6c*);
extern void STR_Terminate(void* data, uint32_t size);
extern void STR_Clear(struct Struct_21ba1a6c*);
extern void func_21b9ef54(struct Struct_21ba1a6c*, uint8_t, uint32_t);


#endif /*STRINGOP_H_*/
