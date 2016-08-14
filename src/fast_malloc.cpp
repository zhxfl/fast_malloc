#define FAST_MALLOC_ALIGN 32 // required for avx optimization
#include <stdio.h>
#include <stdlib.h>

template<typename T> inline T* alignPtr(T* ptr, size_t n = sizeof(T)){
    return (T*)(((size_t)ptr + n - 1) & -n);
}

void* fastMalloc( size_t size)
{
    unsigned char* udata = (unsigned char*)malloc(size + sizeof(void*) + FAST_MALLOC_ALIGN);
    if(!udata)
        return NULL;

    unsigned char** adata = alignPtr((unsigned char**)udata + 1, FAST_MALLOC_ALIGN);
    adata[-1] = udata;
    return adata;
}

void fastFree(void* ptr)
{
    if(ptr){
        unsigned char* udata = ((unsigned char**)ptr)[-1];
        free(udata);
    }
}
