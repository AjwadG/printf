#ifndef HEADER_FILE
#define HEADER_FILE
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

/**
 * struct infos - struct
 * @plus: int
 * @neg: int
 * @space: int
 * @hash: int
 * @zero: int
 * @l: int
 * @h: int
 * @width: int
 * @prec: int
 * @index: int
 * @tmp: int
 */
typedef struct infos
{
	int plus;
	int neg;
	int space;
	int hash;
	int zero;
	int l;
	int h;
	int width;
	int prec;
	int index;
	int tmp;
} flags_t;


int _printf(const char *format, ...);
int determine(const char *s, flags_t *flags, va_list ap);

void get_index(const char *s, flags_t *flags);
int get_f(const char *s, flags_t *flags);
int get_length(const char *s, flags_t *flags);
int get_width(const char *s, flags_t *flags, va_list ap);
int print_fill(char c, int n);

int get_int_lenght(long int n);
long int get_int(va_list ap, flags_t *flags);
unsigned long int get_unsigned_int(va_list ap, flags_t *flags);
void init_flags(flags_t *flags);


int print_pers(va_list ap, flags_t *flags);
int print_char(va_list ap, flags_t *flags);
int print_string(va_list ap, flags_t *flags);
int len(char *s);
int print_int(va_list, flags_t *flags);
int get_place(long int);
int print_binary(va_list ap, flags_t *flags);
void convert_print(unsigned long int n, int *i, int conv, char xX);
int print_u(va_list, flags_t *flags);
int print_octal(va_list, flags_t *flags);
int print_hex(va_list, flags_t *flags);
int print_HEX(va_list, flags_t *flags);
int print_non_printables(va_list, flags_t *flags);
int print_pointer(va_list, flags_t *flags);
void _strcpy(char *dest, const char *src, int steps);
int print_rot13(va_list, flags_t *flags);
int get_ascii(char c);
int print_rev(va_list, flags_t *flags);
#endif
