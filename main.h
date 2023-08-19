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
int print_binary(va_list ap);
void convert_print(unsigned int n, int *i, int conv , char xX);
int print_u(va_list);
int print_octal(va_list);
int print_hex(va_list);
int print_HEX(va_list);
#endif
