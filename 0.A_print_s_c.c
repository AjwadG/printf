#include "main.h"

/**
 * print_char - print 1 char
 * @ap: opject
 * @flags: opject of the out put
 * Return: the number of printed chars
 */
int print_char(va_list ap, flags_t *flags)
{
	char c, counter = 0;

	if (flags->width == -1)
		flags->width = va_arg(ap, unsigned int);

	c =  va_arg(ap, int);

	if (!flags->neg)
		counter += print_fill(' ', flags->width - 1);

	counter += write(1, &c, 1);

	if (flags->neg)
		counter += print_fill(' ', flags->width - 1);

	return (counter);
}

/**
 * print_string - print string;
 * @ap: opject
 * @flags: opject of the out put
 * Return: the number of printed chars
 */
int print_string(va_list ap, flags_t *flags)
{
	char *s;
	int l, counter = 0;

	if (flags->width == -1)
		flags->width = va_arg(ap, unsigned int);

	s =  va_arg(ap, char*);

	if (s == NULL)
		s = "(null)";

	l = len(s);
	if (flags->prec)
	{
		if (l > flags->prec)
			l = flags->prec;
	}
	if (!flags->neg)
		counter += print_fill(' ', flags->width - l);
	counter += write(1, s, l);

	if (flags->neg)
		counter += print_fill(' ', flags->width - l);

	return (counter);
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

/**
 * print_fill - prints n (c)s
 * @n: number of c to print
 * @c: the char to print
 * Return: the number of printed char
 */
int print_fill(char c, int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		write(1, &c, 1);
	}
	return (i);
}

/**
 * init_flags - asign 0 to all
 * @flags: opject
 */
void init_flags(flags_t *flags)
{
	flags->neg = 0;
	flags->plus = 0;
	flags->zero = 0;
	flags->space = 0;
	flags->width = 0;
	flags->h = 0;
	flags->l = 0;
	flags->index = 0;
	flags->hash = 0;
	flags->prec = 0;
	flags->tmp = 0;
	flags->tmp1 = 0;
}
