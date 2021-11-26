#include "libmx.h"

void mx_printint(int n)
{

    char integer[12];
    int count = 0;
    int base = 10;
    if (n <= INT_MIN && base == 10)
    {
        write(1, "-2147483648", 11);
        return;
    }
    if (n >= INT_MAX && base == 10)
    {
        write(1, "2147483647", 10);
        return;
    }

    if (!n)
    {
        //mx_printchar('0');
        write(1, "0", 1);
        return;
    }
    if (n < 0)
    {
        n = -n;
        //mx_printchar('-');
        write(1, "-", 1);
    }

    while (n)
    {
        int rem = n % base;
        //integer[count] = n % base + '0';
        integer[count] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
        n = n / base;
        count++;
    }

    for (int character = count - 1; character >= 0; character--)
    {
        //mx_printchar(intseger[character]);
        write(1, &integer[character], 1);
    }
    // mx_printchar('\n');
}
