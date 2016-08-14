#pragma once
#include <stdio.h>

void* fastMalloc(size_t size);
void fastFree(void* ptr);
