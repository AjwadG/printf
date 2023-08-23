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
	long int n, place, count = 0, abs = 1, l;
	char c, fill = flags->zero ? '0' : ' ';

	n = get_int(va, flags);
	l = get_int_lenght(n);
	if (n >= 0 && !flags->neg && ((!flags->plus && !flags->space)
			|| fill == ' ') && !flags->prec)
		count += print_fill(fill, flags->width - l);
	if (n < 0)
	{
		abs = -1;
		count += write(1, "-", 1);
		if (!flags->neg && !flags->prec)
			count += print_fill(fill, flags->width - l - 1);
		if (flags->prec)
			count += print_fill('0', flags->prec - l);
	}
	else
	{
		if (flags->plus)
			count += write(1, "+", 1);
		else if (flags->space)
			count += write(1, " ", 1);
		if (!flags->neg && (flags->plus || flags->space)
				&& !flags->prec)
			count += print_fill(fill, flags->width - l - 1);
		if (flags->prec)
			count += print_fill('0', flags->prec - l);
	}
	place = get_place(n);
	while (place)
	{
		c = n / place % 10 * abs + '0';
		count += write(1, &c, 1);
		place /= 10;
	}
	if (flags->neg && !flags->prec)
		count += print_fill(' ', flags->width - l -
			(n < 0 || flags->space || flags->plus));
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
	long int place = 1;

	n /= 10;
	while (n)
	{
		place *= 10;
		n /= 10;
	}
	return (place);
}

/**
 * get_int_lenght - Gets lenght of number
 *
 * @n: Decimal
 * Return: Decimal place
 */
int get_int_lenght(long int n)
{
	int place = 1;

	n /= 10;
	while (n)
	{
		place++;
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
