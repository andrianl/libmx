#include "libmx.h"

void swapn(void* v1, void* v2, int size)
{
	// buffer is array of characters which will
	// store element byte by byte
	char buffer[size];

	// memcpy will copy the contents from starting
	// address of v1 to length of size in buffer
	// byte by byte.
	mx_memcpy(buffer, v1, size);
	mx_memcpy(v1, v2, size);
	mx_memcpy(v2, buffer, size);
}
