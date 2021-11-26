#include "libmx.h"

int mx_sqrt(int x)
{
    if (x == 1)
    {
        return 1;
    }
    else if (x <= 0)
    {
        return 0;
    }

    unsigned long result = 0;
    unsigned long start = 1;
    unsigned long end = x / 2;
    while (start <= end)
    {
        unsigned long mid = (start + end) / 2;
        unsigned long long sqr = mid * mid;
        if ((int)sqr == x)
        {
            return (int)mid;
        }
        else if ((int)sqr < x)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return (int)result;
}
