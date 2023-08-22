#include "main.h"

/**
 * print_int - Prints numbers
 *
 * @va: variadic argument
 * @flags: opject of the out put
 * Return: Number of printed characters
 */
int print_int(va_list va, flags_t *flags)
{
	long int n, place, count = 0, abs = 1;
	char c;

	n = get_int(va, flags);
	if (n < 0)
	{
		abs = -1;
		write(1, "-", 1);
		count++;
	}
	else
	{
		if (flags->plus)
		{
			count++;
			write(1, "+", 1);
		}
		else if (flags->space)
		{
			count++;
			write(1, " ", 1);
		}
	}
	place = get_place(n);
	while (place)
	{
		c = n / place % 10 * abs + '0';
		write(1, &c, 1);
		place /= 10;
		count++;
	}
	return (count);
}
/**
 * get_place - Gets decimal place value
 *
 * @n: Decimal
 * Return: Decimal place
 */
int get_place(long int n)
{
	int place = 1;

	n /= 10;
	while (n)
	{
		place *= 10;
		n /= 10;
	}
	return (place);
}

/**
 * get_int - gets the right sized number
 * @ap: opject
 * @flags: opject of the out put
 * Return: the number of printed chars
 */
long int get_int(va_list ap, flags_t *flags)
{
	if (flags->l)
		return (va_arg(ap, long int));
	else if (flags->h)
		return ((short int) va_arg(ap, int));
	else
		return (va_arg(ap, int));
}
