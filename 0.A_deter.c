#include "main.h"

/**
 * determine - determin the definer
 * @s: pointer to string
 * @flags: opject of the out put
 * @ap: opject
 * Return: the number of skiped chars
 */
int determine(const char *s, flags_t *flags, va_list ap)
{
	int i = 0;

	init_flags(flags);

	while (get_f(&s[i], flags))
		i++;
	i += get_length(&s[i], flags);
	i += get_width(&s[i], flags, ap);
	get_index(&s[i], flags);
	if (flags->index == 0)
	{
		switch (s[i])
		{
			case '\0':
				flags->index = -1;
				break;
			default:
				write(1, "%", 1);
				return (0);
		}
	}
	return (i + 1);
}

/**
 * get_f - determin the definer
 * @s: pointer to string
 * @flags: opject of the out put
 * Return: the number of skiped chars
 */
int get_f(const char *s, flags_t *flags)
{
	int i = 0;

	while (i >= 0)
	{
		switch (s[i])
		{
			case '-':
				flags->neg = 1;
				break;
			case '+':
				flags->plus = 1;
				break;
			case ' ':
				flags->space = 1;
				break;
			case '#':
				flags->hash = 1;
				break;
			case '0':
				flags->zero = 1;
				break;
			default:
				return (i);
		}
		i++;
	}
	return (0);
}

/**
 * get_width - determin the width
 * @s: pointer to string
 * @flags: opject of the out put
 * @ap: opject
 * Return: the number of skiped chars
 */
int get_width(const char *s, flags_t *flags, va_list ap)
{
	int i;

	for (i = 0; s[i]; i++)
	{
		if (s[i] == '*')
		{
			if (!i)
			{
				flags->tmp = flags->width = va_arg(ap, int);
				i++;
			}
			break;
		}
		else if (s[i] >= '0' && s[i] <= '9')
		{
			flags->width = flags->width * 10 + (s[i] - '0');
		}
		else
		{
			break;
		}
	}
	return (i);
}
/**
 * get_length - determin the lenght
 * @s: pointer to string
 * @flags: opject of the out put
 * Return: the number of skiped chars
 */
int get_length(const char *s, flags_t *flags)
{
	switch (s[0])
	{
		case 'l':
			flags->l = 1;
			break;
		case 'h':
			flags->h = 1;
			break;
		default:
			return (0);
	}
	return (1);
}

/**
 * get_index - determin the definer
 * @s: pointer to string
 * @flags: opject of the out put
 */
void get_index(const char *s, flags_t *flags)
{
	flags->index  = (s[0] == 'c') + (s[0] == 's') * 2 +
		(s[0] == 'd' || s[0] == 'i') * 3 + (s[0] == 'b') * 4 +
		(s[0] == 'u') * 5 + (s[0] == 'o') * 6 + (s[0] == 'x') * 7 +
		(s[0] == 'X') * 8 + (s[0] == 'S') * 9 + (s[0] == 'p') * 10 +
		(s[0] == 'R') * 11 + (s[0] == 'r') * 12 + (s[0] == '%') * 13;
}
