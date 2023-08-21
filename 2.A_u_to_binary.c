#include "main.h"

/**
 * print_binary - print 1 char
 * @ap: opject
 * @pattaren: pattaren of the output
 * Return: the number of printed chars
 */
int print_binary(va_list ap, char *pattaren)
{
	unsigned int n = va_arg(ap, unsigned int);
	int counter = 0;

	if (pattaren == NULL)
		return (0);
	convert_print(n, &counter, 2, 0);
	return (counter);
}


/**
 * convert_print - Converts from decimal
 * @n: Int to be converted
 * @i: pointer to counter
 * @conv: the base
 * @xX: converting to x or X or 0 if otherwise
 ***/
void convert_print(unsigned long int n, int *i, int conv, char xX)
{
	char c = n % conv;

	if (c >= 10)
		c = c % 10 + xX;
	else
		c += '0';

	if (n / conv != 0)
		convert_print(n / conv, i, conv, xX);
	write(1, &c, 1);
	(*i)++;
}
