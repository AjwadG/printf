#include "main.h"

/**
 * print_u - Print unsigned number
 * @ap: opject
 * Return: the number of printed chars
 */
int print_u(va_list ap)
{
	unsigned int n = va_arg(ap, unsigned int);
	int counter = 0;

	convert_print(n, &counter, 10, 0);
	return (counter);
}

/**
 * print_octal - print octal
 * @ap: opject
 * Return: the number of printed chars
 */
int print_octal(va_list ap)
{
	unsigned int n = va_arg(ap, unsigned int);
	int counter = 0;

	convert_print(n, &counter, 8, 0);
	return (counter);
}

/**
 * print_hex - print lowercase hex
 * @ap: opject
 * Return: the number of printed chars
 */
int print_hex(va_list ap)
{
	unsigned int n = va_arg(ap, unsigned int);
	int counter = 0;

	convert_print(n, &counter, 16, 'a');
	return (counter);
}

/**
 * print_HEX - print uppercase hex
 * @ap: opject
 * Return: the number of printed chars
 */
int print_HEX(va_list ap)
{
	unsigned int n = va_arg(ap, unsigned int);
	int counter = 0;

	convert_print(n, &counter, 16, 'A');
	return (counter);
}
