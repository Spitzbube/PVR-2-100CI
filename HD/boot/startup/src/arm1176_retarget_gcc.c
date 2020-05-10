
#include <stdio.h>
#include <errno.h>
#include <sys/stat.h>
#include "fapi/drv_uart.h"


struct
{
   int fill_0[62]; //0
   int Data_248; //248
}* Data_21f018c0 = (void*) 0x02000000; //21f018c0



/* 21cb4d4c - complete */
int _close_r(void *reent, int fd)
{
    return 0;
}

/* 21cb4e14 - complete */
off_t _lseek_r(void *reent, int fd, off_t pos, int whence)
{
    return 0;
}


/* todo */
long _read_r(void *reent, int fd, void *buf, size_t cnt)
{
    return 0;
}


long _write_r(void *reent, int fd, const void *buf, size_t cnt)
{
    int res;
    unsigned int i;
    const char* c = buf;

    for (i = 0; i < cnt; i++)
    {
        if (Data_21f018c0->Data_248 != 0)
        {
            Data_21f018c0->Data_248 = 0;
        }

        if (c[i] == 0x0A)
        {
            FAPI_UART_WriteByte(uartRetargetHandle, 0x0D);
        }

        res = FAPI_UART_WriteByte(uartRetargetHandle, c[i]);

        if (res != 0)
        {
            break;
        }

        if (c[i] == 0x0A)
        {
            Data_21f018c0->Data_248 = 1;
        }
    }

    return i;
}


/* 21cb4fac - complete */
char *_sbrk_r(void *reent, size_t incr)
{
    extern char __heap_start__[];
    extern char __heap_end__[];
    static char* heap_ptr = 0;
    char* prev_heap_end;

    if (heap_ptr == 0)
    {
        heap_ptr = __heap_start__;
    }

    prev_heap_end = heap_ptr;

    if ((heap_ptr + incr) >= __heap_end__)
    {
        errno = ENOMEM;
        return 0;
    }

    heap_ptr += incr;

    return prev_heap_end;
}


/* 21cb4e44 - complete */
int _fstat_r(struct _reent *r, int fd, struct stat *pstat)
{
   pstat->st_mode = 0x2000;

   return 0;
}


