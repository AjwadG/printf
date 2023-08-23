#include "main.h"

/**
 * print_binary - print 1 char
 * @ap: opject
 * @flags: opject of the out put
 * Return: the number of printed chars
 */
int print_binary(va_list ap, flags_t *flags)
{
	unsigned int n = va_arg(ap, unsigned int);
	int counter = 0;

	if (flags == NULL)
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


/**
 * get_pres - determin the width
 * @s: pointer to string
 * @flags: opject of the out put
 * @ap: opject
 * Return: the number of skiped chars
 */
int get_pres(const char *s, flags_t *flags, va_list ap)
{
	int i;

	if (s[0] != '.')
		return (0);
	for (i = 1; s[i]; i++)
	{
		if (s[i] == '*')
		{
			if (i == 1)
			{
				flags->tmp1 = flags->prec = va_arg(ap, int);
				i++;
			}
			break;
		}
		else if (s[i] >= '0' && s[i] <= '9')
		{
			flags->prec = flags->prec * 10 + (s[i] - '0');
		}
		else
		{
			break;
		}
	}
	if (s[0] == '.' && flags->prec == 0)
		flags->dont = 1;
	return (i);
}
