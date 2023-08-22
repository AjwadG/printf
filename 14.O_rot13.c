#include "main.h"

/**
 * print_rot13 - Prints the rot13'ed string
 *
 * @va: variadic argument
 * @flags: opject of the out put
 * Return: Number of printed characters
 */
int print_rot13(va_list va, flags_t *flags)
{
	int i = 0, count = 0, ascii, c;
	char *s;

	if (flags == NULL)
		return (0);
	s = va_arg(va, char *);
	if (!s)
		return (0);
	while (s[i])
	{
		ascii = get_ascii(s[i]);
		if (ascii)
		{
			c = (s[i] - ascii) + 13;
			c = (c % 26);
			c = (c + ascii);
			write(1, &c, 1);
			count++;
			i++;
		}
		else
		{
			write(1, &s[i], 1);
			count++;
			i++;
		}
	}
	return (count);
}
/**
 * get_ascii - Gets the ascii value of the character
 * @c: character
 * Return: Int
 */
int get_ascii(char c)
{
	int lower, upper;

	lower = ('a' * (c >= 'a' && c <= 'z'));
	upper = ('A' * (c >= 'A' && c <= 'Z'));

	return (lower + upper);
}
