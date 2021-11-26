#include "libmx.h"

int mx_read_line(char **lineptr, size_t buf_size, char delim, const int fd)
{
    *lineptr = mx_strnew(buf_size);
    int byte, i = 0;
    char buff;

    if (fd == -1)
        return -2;

    byte = read(fd, &buff, sizeof(buff));
    if (byte == 0)
        return -1;

    while (byte != 0 && buff != delim)
    {
        (*lineptr)[i] = buff;
        byte = read(fd, &buff, sizeof(buff));
        if (byte == 0)
            return -1;
        i++;
    }
    return i;
}
