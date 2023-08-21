#include "main.h"

/**
 * print_u - Print unsigned number
 * @ap: opject
 * @pattaren: pattaren of the output
 * Return: the number of printed chars
 */
int print_u(va_list ap, char *pattaren)
{
	unsigned int n = va_arg(ap, unsigned int);
	int counter = 0;

	if (pattaren == NULL)
		return (0);
	convert_print(n, &counter, 10, 0);
	return (counter);
}

/**
 * print_octal - print octal
 * @ap: opject
 * @pattaren: pattaren of the output
 * Return: the number of printed chars
 */
int print_octal(va_list ap, char *pattaren)
{
	unsigned int n = va_arg(ap, unsigned int);
	int counter = 0;

	if (pattaren[0] == '#')
	{
		counter++;
		write(1, "0", 1);
	}
	convert_print(n, &counter, 8, 0);
	return (counter);
}

/**
 * print_hex - print lowercase hex
 * @ap: opject
 * @pattaren: pattaren of the output
 * Return: the number of printed chars
 */
int print_hex(va_list ap, char *pattaren)
{
	unsigned int n = va_arg(ap, unsigned int);
	int counter = 0;

	if (pattaren[0] == '#')
	{
		counter += 2;
		write(1, "0x", 2);
	}
	convert_print(n, &counter, 16, 'a');
	return (counter);
}

/**
 * print_HEX - print uppercase hex
 * @ap: opject
 * @pattaren: pattaren of the output
 * Return: the number of printed chars
 */
int print_HEX(va_list ap, char *pattaren)
{
	unsigned int n = va_arg(ap, unsigned int);
	int counter = 0;

	if (pattaren[0] == '#')
	{
		counter += 2;
		write(1, "0X", 2);
	}
	convert_print(n, &counter, 16, 'A');
	return (counter);
}
