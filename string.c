#include "string.h"
#include <stdint.h>

void* memset(void* anything, int thingToWrite, size_t n)
{
    unsigned char* target = anything;
    for(size_t i = 0; i < n; i++)
    {
	target[i] = (unsigned char) thingToWrite;
    }
    return anything;
}

size_t strlen(const char* str)
{
    	size_t nullCharPos = 0;
	while (str[nullCharPos] != 0)
		nullCharPos++;
	return nullCharPos;
}
