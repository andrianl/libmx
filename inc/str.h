#pragma once

#include <stdbool.h>


bool mx_isalpha(char c);
bool mx_isdigit(char c);
bool mx_islower(char c);
bool mx_isspace(char c);
bool mx_isupper(char c);

char mx_tolower(char c);
char mx_toupper(char c);

char *concat_words(char **words);
char *mx_strchr(const char *s, int c);

int count_substr(const char *str, const char *sub);
int count_words(const char *str, char delimiter);
int get_char_index(const char *str, char c);
int get_substr_index(const char *str, const char *sub);
int check_substr(const char *src, const char *sub);

int mx_strlen(const char *s);
unsigned long mx_strlenf(const char *str);

char *mx_strcat(char *restrict s1, const char *restrict s2);
char *mx_strcpy(char *restrict dst, const  char *restrict src);
char *mx_strdup(const char *s1);
char *mx_strndup(const char *s1, unsigned long n);
char *mx_strjoin(const   char *restrict s1, const  char *restrict s2);
char *mx_strncpy(char *restrict dst, const char *restrict src, int len);
char *mx_strstr(const char *restrict haystack, const char *restrict needle);
int mx_strcmp(const char *restrict s1, const char *restrict s2);
int mx_strncmp(register const char *restrict s1, register const char *restrict s2,
    register unsigned long n);

char *del_extra_spaces(const char *str);
char *replace_substr(const char *str, const char *sub, const char *replace);
char *mx_strtrim(const char *str);
char **strsplit(const char *s, char c);

// ------- malloc & free char* -------
char *mx_strnew(unsigned long size);
void mx_strdel(char **str);
void del_strarr(char ***arr);

char *concat_words(char **words);
void mx_str_reverse(char *s);
