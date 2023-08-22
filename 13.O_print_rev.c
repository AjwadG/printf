#include "main.h"

/**
 * print_rev - Prints the reversed string
 *
 * @va: variadic argument
 * @flags: opject of the out put
 * Return: Number of printed characters
 */
int print_rev(va_list va, flags_t *flags)
{
	int count, i;
	char *s;

	if (flags == NULL)
		return (0);
	s = va_arg(va, char *);
	if (!s)
		return (0);
	count = len(s);
	for (i = count - 1; i >= 0; i--)
		write(1, &s[i], 1);
	return (count);
}
