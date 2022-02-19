#include "mem.h"

void *mx_memset(void *b, int c, size_t len)
{
  register byte *ptr = (byte *)b;
  while (len--)
    *ptr++ = c;
  return b;
}
