

#include <rt_misc.h>


extern unsigned __main;
extern char Image$$ER_ZI$$ZI$$Limit;

int __heap2_start__; //21b139d4
int __heap2_end__; //21b139d8



/* 21b0cb2c - complete */
__value_in_regs struct __initial_stackheap __user_initial_stackheap(
        unsigned R0, unsigned SP, unsigned R2, unsigned SL)
{
    struct __initial_stackheap config;
    
    config.heap_limit = 0;
    config.stack_limit = 0;
    
    config.stack_limit = (unsigned)(&Image$$ER_ZI$$ZI$$Limit + 7) & ~0x07; 
    config.stack_base = (config.stack_limit + PROGRAM_STACK_BYTES + 7) & ~0x07;
    config.heap_base = config.stack_base;
    config.heap_limit = (config.stack_base + PROGRAM_HEAP_BYTES + 7) & ~0x07;

    if (&__main >= (void*)0x40000000)
    {
       __heap2_start__ = (config.heap_limit + 0xfffff) & 0xfff00000;
       __heap2_end__ = 0x43FFFFFC; 
    }
    else
    {
       __heap2_start__ = (config.heap_limit + 0xfffff) & 0xfff00000;
       __heap2_end__ = 0x23FFFFFC; 
    }
    
    config.heap_limit = __heap2_start__ - 8;

    return config;
}




