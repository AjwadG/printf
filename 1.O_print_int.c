#include "main.h"

/**
 * print_int - Prints numbers
 *
 * @va: variadic argument
 * Return: Number of printed characters
 */
int print_int(va_list va)
{
	int n, place, count = 0, abs = 1;
	char c;

	n = va_arg(va, int);
	if (n < 0)
	{
		abs = -1;
		write(1, "-", 1);
		count++;
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
int get_place(int n)
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
