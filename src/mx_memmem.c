#include "libmx.h"

void *mx_memmem(const void *big, size_t big_len, const void *little, size_t little_len)
{
    register char *cur, *last;
    const char *cl = (const char *)big;
    const char *cs = (const char *)little;

    /* we need something to compare */
    if (big_len == 0 || little_len == 0)
        return NULL;

    /* "s" must be smaller or equal to "l" */
    if (big_len < little_len)
        return NULL;

    /* special case where s_len == 1 */
    if (little_len == 1)
        return mx_memchr(big, (int)*cs, big_len);

    /* the last position where its possible to find "s" in "l" */
    last = (char *)cl + big_len - little_len;

    for (cur = (char *)cl; cur <= last; cur++)
        if (cur[0] == cs[0] && mx_memcmp(cur, cs, little_len) == 0)
            return cur;

    return NULL;
}
