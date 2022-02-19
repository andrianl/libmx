#pragma once 

#define print(x) cout(x)


void cout(const char *s);
void cerr(const char *s);


void print_char(char c);

void print_str_array(char **arr, const char *delim);
void print_int(int n);
void print_unicode(wchar_t c);

void ShowPrintable(void);
void print_arr_int(const int *arr, int size);

