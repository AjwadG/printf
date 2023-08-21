#ifndef HEADER_FILE
#define HEADER_FILE
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>


int _printf(const char *format, ...);
int determine(const char *s, int *index);
int print_char(va_list ap, char *pattaren);
int print_string(va_list ap, char *pattaren);
int len(char *s);
int print_int(va_list, char *pattaren);
int get_place(int);
int print_binary(va_list ap, char *pattaren);
void convert_print(unsigned long int n, int *i, int conv, char xX);
int print_u(va_list, char *pattaren);
int print_octal(va_list, char *pattaren);
int print_hex(va_list, char *pattaren);
int print_HEX(va_list, char *pattaren);
int print_non_printables(va_list, char *pattaren);
int print_pointer(va_list, char *pattaren);
void _strcpy(char *dest, const char *src, int steps);
int print_rot13(va_list, char *);
int get_ascii(char c);
#endif
