#include "libmx.h"

int mx_lcm(int a, int b)
{
    if (a == 0 && b == 0)
        return 0;

    int an = (a < 0 && a != -2147483648) ? a * -1 : a;
    int bn = (b < 0 && b != -2147483648) ? b * -1 : b;

    return an * bn / mx_gcd(an, bn);
}
