#include "libmx.h"

#define INT_DIGITS 19 /* enough for 64 bit integer */
#define UINT_DIGITS 20
#define BASE 10

char *mx_itoa(int number)
{

  static char buf[INT_DIGITS + 2];
  char *p = buf + INT_DIGITS + 1;
  if (number >= 0)
  {
    while (number != 0)
    {
      *--p = '0' + (number % BASE);
      number /= BASE;
    }
    return p;
  }
  else
  { 
    while (number != 0)
    {
      *--p = '0' - (number % BASE);
      number /= BASE;
    };
    *--p = '-';
  }
  return p;
}
