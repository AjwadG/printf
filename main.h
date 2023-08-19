#ifndef HEADER_FILE
#define HEADER_FILE
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>


int _printf(const char *format, ...);
int determine(const char *s, int *index);
int print_char(va_list ap);
int print_string(va_list ap);
int len(char *s);
int print_int(va_list);
int get_place(int);
#endif
