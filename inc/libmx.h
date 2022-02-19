#ifndef __LIBH__
#define __LIBH__

// ==================== typedefs =====================
typedef unsigned char ubyte;
typedef char byte;

// ===================== defines ======================

// ------------ cross platform ------------
#if defined(__APPLE__)
#include <malloc/malloc.h>
#define malloc_size(x) malloc_size(x)
#elif defined(_WIN64) || defined(_WIN32)
#include <malloc.h>
#define malloc_size(x) _msize(x)
#elif defined(__linux__)
#include <malloc.h>
#define malloc_size(x) malloc_usable_size(x)
#endif

// ===================== macros =====================
#define size(x) sizeof(x) / sizeof(x[0])

// ===================== includes =====================
#include <fcntl.h>
#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <stdio.h>

#include "str.h"
// ===================== structs =====================

typedef struct s_list
{
  void *data;
  struct s_list *next;
} t_list;

typedef unsigned char t_ftbyte;
//-------- READ_LINE --------//
//-------- STRUCTURE --------//

typedef struct s_fd
{
  bool eof;
  char *str;
  int fd;
  struct s_fd *next;
} t_fd;

// ===================== Functions =====================

// ===================== UTILS =====================

// ---------------- print ----------------
void printchar(char c);
void printstr(const char *s);
void print_strarr(char **arr, const char *delim);
void printint(int n);
void print_unicode(wchar_t c);

// ---------------- convert ----------------
char *nbr_to_hex(unsigned long nbr);
char *itoa(int number);
unsigned long hex_to_nbr(const char *hex);

// ---------------- math ----------------
double mx_pow(double n, unsigned int mx_pow);
int mx_sqrt(int x);

// ---------------- sort and search ----------------
int binary_search(char **arr, int size, const char *s, int *count);
int bubble_sort(int *arr, int size);
int quicksort(int *arr, int left, int right);
int BinarySearch(int *arr, size_t size, int x);

// ---------------- function pointer ----------------
void foreach(int *arr, int size, void (*f)(int));

// ---------------- delete arrays ----------------
void del_intarr(int **arr, int num);
void del_strarr(char ***arr);
void del_strarr(char ***arr);

// ==================== char* ====================

// ------------ format char* ------------
// char* del_extra_spaces(const char* str);
// char* replace_substr(const char* str, const char* sub, const char* replace);
// char* strtrim(const char* str);
// char* *strsplit(const char* s, char c);

// ------- malloc & free char* -------
// char* strnew(const int size);
// void strdel(char* *str);

// // ---------- char* utils  ----------
// char* strcat(char* restrict s1, const char* restrict s2);
// char* mx_strcpy(char* dst, const char* src);
// char* strdup(const char* s1);
// char* strndup(const char* s1, size_t n);
// char* strjoin(const char* s1, const char* s2);
// char* mx_strncpy(char* dst, const char* src, int len);
// char* mx_strstr(const char* haystack, const char* needle);
// int strcmp(const char* s1, const char* s2);
// int strncmp(register const char* s1, register const char* s2,
//             register size_t n);
// //int mx_strlen(const char* s);
// unsigned long mx_strlenf(const char* str);

// // -------------- useful functions  --------------
// int count_substr(const char* str, const char* sub);
// int count_words(const char* str, char delimiter);
// int get_char_index(const char* str, char c);
// int get_substr_index(const char* str, const char* sub);
// int check_substr(const char* src, const char* sub);

// // ----------- swap & reverse ---------
// void str_reverse(char* s);

// --------- files -----------
char *file_to_str(const char *filename);
int read_line(char **lineptr, size_t buf_size, char delim, const int fd);

// // ======================= MEMORY ========================
// int mx_memcmp(const void *s1, const void *s2, size_t n);

// void *mx_memchr(const void *s, int c, size_t n);
// void *mx_memcpy(void *restrict dst, const void *restrict src, size_t n);
// void *ft_mx_memcpy(void *restrict dst, const void *restrict src, unsigned long n);
// void *mx_memccpy(void *restrict dst, const void *restrict src, int c, size_t n);
// void *mx_memmx_mem(const void *big, size_t big_len, const void *little,
//              size_t little_len);
// void *mx_memset(void *b, int c, size_t len);
// void *mx_memrchr(const void *s, int c, size_t n);
// void *mx_memmove(void *restrict dst, const void *restrict src, size_t len);
// void *realloc(void *ptr, size_t size);

// // ======================== LIST ========================
// int list_size(t_list *list);

// t_list *create_node(void *data);
// t_list *sort_list(t_list *list, bool (*cmp)(void *, void *));

// void pop_back(t_list **list);
// void pop_front(t_list **list);
// void push_back(t_list **list, void *data);
// void push_front(t_list **list, void *data);
// void swap_node(void **s1, void **s2);

// ======================== OPTIONAL ========================
// bool isalpha(int c);
// bool isdigit(int c);
// bool islower(int c);
// bool isspace(char c);
// bool isupper(int c);
// void swap(int *restrict xp, int *restrict yp);
// void swapn(void *v1, void *v2, int size);

// char* concat_words(char* *words);
// char* strchr(const char* s, int c);

int atoi(const char *str);
int check_substr(const char *src, const char *sub);
int factorial_iter(int n);
int gcd(int a, int b);
int lcm(int a, int b);
// int tolower(int c);
// int toupper(int c);

int min(int a, int b);
int max(int a, int b);
int abs(int a);
unsigned long mod(int num);
float mx_powf(float base, int exp);

void only_printable(void);
void print_arr_int(const int *arr, int size);
void printerr(const char *s);

#endif // __LIBH__
