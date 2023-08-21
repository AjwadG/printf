#include "main.h"

/**
 * determine - determin the definer
 * @s: pointer to string
 * @index: pointer to number
 * Return: the number of skiped chars
 */
int determine(const char *s, int *index)
{
	int tmp;

	*index = (s[0] == 'c') + (s[0] == 's') * 2 +
			(s[0] == 'd' || s[0] == 'i') * 3 + (s[0] == 'b') * 4 +
			(s[0] == 'u') * 5 + (s[0] == 'o') * 6 + (s[0] == 'x') * 7 +
			(s[0] == 'X') * 8 + (s[0] == 'S') * 9 + (s[0] == 'p') * 10 +
			(s[0] == 'R') * 11 + (s[0] == 'r') * 12;
	if (*index == 0)
	{
		switch (s[0])
		{
			case '%':
				write(1, s, 1);
				*index = 0;
				break;
			case '\0':
				*index = -1;
				break;
			case '+':
			case ' ':
			case '#':
				tmp = determine(&s[1], index);
				return ((1 + tmp) * (tmp > 0));
			default:
				write(1, "%", 1);
				*index = 0;
				return (0);
		}
	}
	return (1);
}

/**
 * print_char - print 1 char
 * @ap: opject
 * @pattaren: pattaren of the output
 * Return: the number of printed chars
 */
int print_char(va_list ap, char *pattaren)
{
	char c = va_arg(ap, int);

	if (pattaren == NULL)
		return (0);
	write(1, &c, 1);
	return (1);
}

/**
 * print_string - print string;
 * @ap: opject
 * @pattaren: pattaren of the output
 * Return: the number of printed chars
 */
int print_string(va_list ap, char *pattaren)
{
	char *s = va_arg(ap, char*);

	if (pattaren == NULL)
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
