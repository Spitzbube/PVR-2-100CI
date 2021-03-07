

typedef struct
{
   void (*Func_0)(void); //0
   void* lock; //4
   void* request; //8
   void* response; //12
   void* Data_16; //16
   unsigned Data_20; //20
   int Data_24; //24
   //28
} Struct_35e444;


typedef struct
{
   unsigned a;
   unsigned b;   
} Struct_35e0a8;


struct Struct_21b8f67c;


extern struct appData* func_21b8e50c(void);
extern int func_21b91298(struct appData* a);
extern void SYS_PrintString(char*);
extern uint64_t SYS_TimeDiff(uint64_t, uint64_t);
extern void* SYS_MemoryAllocate(int a);
extern void SYS_MemoryFree(void* a);
extern int SYS_ThreadCreate(void (*func)(int), 
                     int b, int prio, unsigned stacksize, 
                     const char* thread_name, void** thread);
extern int func_21b8ecf8(Struct_35e444*, int*);
extern void* SYS_ReceiveRequestMessage(Struct_35e444*);
extern int SYS_SendResponseMessage(Struct_35e444*, void*);
extern int SYS_SendRequestMessage(Struct_35e444*, void*, int*);
extern int SYS_StrNCpy(char_t*, const char_t*, uint32_t);
extern void func_21b8e92c(Struct_35e0a8*, unsigned, unsigned);
extern int SYS_GetPowerOn(void);
extern int SYS_OnOff(int);




