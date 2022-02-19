#pragma once

#include <stddef.h>
#include <stdlib.h>

typedef unsigned char ubyte;
typedef char byte;

// ======================= mx_mx_memORY ========================
int mx_mx_memcmp(const void *s1, const void *s2, size_t n);

void *mx_memchr(register const void *s, int c, size_t n);
void *mx_memcpy(void *restrict dst, const void *restrict src, size_t n);
void *ft_memcpy(void *restrict dst, const void *restrict src, size_t n);
void *mx_memccpy(void *restrict dst, const void *restrict src, int c, size_t n);
void *mx_memmem(const void *big, size_t big_len, const void *little, size_t little_len);
void *mx_memset(void *b, int c, size_t len);
int mx_memcmp(const void *restrict s1, const void *restrict s2, size_t n);
void *mx_memrchr(const void *s, int c, size_t n);
void *mx_memmove(void *restrict dst, const void *restrict src, size_t len);
void *mx_realloc(void *ptr, size_t size);
