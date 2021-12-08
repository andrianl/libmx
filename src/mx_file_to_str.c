#include "libmx.h"

int mx_file_length(const char *filename)
{
    int fd = open(filename, O_RDONLY);
    int len = 0;
    char buffer = 0;

    if (fd == -1)
        return -1;
    while (read(fd, &buffer, 1) > 0)
        ++len;
    close(fd);
    return len;
}

char *mx_file_to_str(const char *filename)
{
    char *str = NULL;
    int length = mx_file_length(filename);
    int fd = open(filename, O_RDONLY);

    if (fd == -1)
        return NULL;
    str = mx_strnew(length);
    if (str == NULL)
        return NULL;
    if (read(fd, str, length) != length)
        return NULL;
    return str;
}
