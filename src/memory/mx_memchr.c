#include "mem.h"
#include <stddef.h>

void *mx_memchr(register const void *s, int c, unsigned long n)
{
  register const byte *src = (const byte *)s;

  while (n--)
  {
    if (*src == c)
      return (void *)src;
    src++;
  }
  return NULL;
}
