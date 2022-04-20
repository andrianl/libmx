#include "mem.h"

void *mx_memmem(const void *restrict big, size_t big_len, const void *restrict little,
                size_t little_len)
{
    register ubyte *uc_big = (ubyte *)big;
    register ubyte *uc_lil = (ubyte *)little;
    int cmp_rslt = 0;

    if (uc_big && uc_lil)
    {
        for (size_t i = 0; i < big_len && uc_big[i]; i++)
        {
            if (*(uc_big + i) == *uc_lil)
            {
                cmp_rslt = mx_memcmp((uc_big + i), uc_lil, little_len);

                if (cmp_rslt == 0)
                {
                    return (void *)(uc_big + i);
                }
            }
        }
    }

    return (void *)NULL;
}
