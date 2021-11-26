#include "libmx.h"

void *mx_memset(void *b, int c, size_t len)
{
  register unsigned char *ptr = (unsigned char *)b;
  while (len--)
    *ptr++ = c;
  return b;
}