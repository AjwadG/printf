#include "main.h"

/**
 * determine - determin the definer
 * @s: pointer to string
 * @index: pointer to number
 * Return: the number of skiped chars
 */
int determine(const char *s, int *index)
{
	switch (s[0])
	{
		case 'c':
			*index = 1;
			break;
		case 's':
			*index = 2;
			break;
		case 'd':
		case 'i':
			*index = 3;
			break;
		case 'b':
			*index = 4;
			break;
		case 'u':
			*index = 5;
			break;
		case 'o':
			*index = 6;
			break;
		case 'x':
			*index = 7;
			break;
		case 'X':
			*index = 8;
			break;
		case '%':
			write(1, s, 1);
			*index = 0;
			break;
		case '\0':
			*index = -1;
			break;
		default:
			write(1, "%", 1);
			*index = 0;
			return (0);
	}
	return (1);
}

/**
 * print_char - print 1 char
 * @ap: opject
 * Return: the number of printed chars
 */
int print_char(va_list ap)
{
	char c = va_arg(ap, int);

	write(1, &c, 1);
	return (1);
}

/**
 * print_string - print string;
 * @ap: opject
 * Return: the number of printed chars
 */
int print_string(va_list ap)
{
	char *s = va_arg(ap, char*);

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
