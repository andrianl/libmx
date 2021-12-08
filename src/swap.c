#include "libmx.h"

void swap(int *xp, int *yp)
{
    *xp ^= *yp;
    *yp ^= *xp;
    *xp ^= *yp;
}

