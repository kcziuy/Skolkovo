#ifndef MY_MALLOC_H_INCLUDED
#define MY_MALLOC_H_INCLUDED

#include <stddef.h>

extern void* mymalloc(size_t size);
extern void myfree(void* ptr);

#endif // MY_MALLOC_H_INCLUDED
