#include "main.h"

/**
 * print_non_printables - Prints non printable characters
 *
 * @va: variadic argument
 * @flags: opject of the out put
 * Return: Number of printed characters
 */
int print_non_printables(va_list va, flags_t *flags)
{
	int i = 0, count = 0;
	char *s;

	if (flags == NULL)
		return (0);
	s = va_arg(va, char *);
	if (!s)
		return (0);
	while (s[i])
	{
		if ((s[i] > 0 && s[i] < 32) || s[i] >= 127)
		{
			write(1, "\\x", 2);
			count += 2;
			if (s[i] < 16)
			{
				write(1, "0", 1);
				count++;
			}
			convert_print(s[i], &count, 16, 'A');
		}
		else
		{
			write(1, &s[i], 1);
			count++;
		}
		i++;
	}
	return (count);
}
