#include "main.h"

/**
 * print_char - print 1 char
 * @ap: opject
 * @flags: opject of the out put
 * Return: the number of printed chars
 */
int print_char(va_list ap, flags_t *flags)
{
	char c = va_arg(ap, int);

	if (flags == NULL)
		return (0);
	write(1, &c, 1);
	return (1);
}

/**
 * print_string - print string;
 * @ap: opject
 * @flags: opject of the out put
 * Return: the number of printed chars
 */
int print_string(va_list ap, flags_t *flags)
{
	char *s = va_arg(ap, char*);

	if (flags == NULL)
		return (0);
	if (s == NULL)
		s = "(null)";
	write(1, s, len(s));
	return (len(s));
}


/**
 * len - calc the len
 * @s: pointer to string
 * Return: the lenght
 ***/
int len(char *s)
{
	int i = 0;

	while (s && *(s++))
	{
		i++;
	}
	return (i);
}
