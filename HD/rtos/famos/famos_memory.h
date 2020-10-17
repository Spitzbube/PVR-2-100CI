#ifndef FAMOS_MEMORY_H_
#define FAMOS_MEMORY_H_

extern void* famos_malloc_segment(int a, int b);
extern void* famos_malloc_cached(int a);
extern void famos_free(void* a);

#endif /*FAMOS_MEMORY_H_*/
