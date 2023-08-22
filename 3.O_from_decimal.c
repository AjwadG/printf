#include "main.h"

/**
 * print_u - Print unsigned number
 * @ap: opject
 * @flags: opject of the out put
 * Return: the number of printed chars
 */
int print_u(va_list ap, flags_t *flags)
{
	unsigned int n = va_arg(ap, unsigned int);
	int counter = 0;

	if (flags == NULL)
		return (0);
	convert_print(n, &counter, 10, 0);
	return (counter);
}

/**
 * print_octal - print octal
 * @ap: opject
 * @flags: opject of the out put
 * Return: the number of printed chars
 */
int print_octal(va_list ap, flags_t *flags)
{
	unsigned int n = va_arg(ap, unsigned int);
	int counter = 0;

	if (flags->hash)
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
 * @flags: opject of the out put
 * Return: the number of printed chars
 */
int print_hex(va_list ap, flags_t *flags)
{
	unsigned int n = va_arg(ap, unsigned int);
	int counter = 0;

	if (flags->hash)
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
 * @flags: opject of the out put
 * Return: the number of printed chars
 */
int print_HEX(va_list ap, flags_t *flags)
{
	unsigned int n = va_arg(ap, unsigned int);
	int counter = 0;

	if (flags->hash)
	{
		counter += 2;
		write(1, "0X", 2);
	}
	convert_print(n, &counter, 16, 'A');
	return (counter);
}
