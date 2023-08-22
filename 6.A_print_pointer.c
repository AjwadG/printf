#include "main.h"

/**
 * print_pointer - print pointer
 * @ap: opject
 * @flags: opject of the out put
 * Return: the number of printed chars
 */
int print_pointer(va_list ap, flags_t *flags)
{
	unsigned long int n;
	int counter = 2, l;

	if (flags->width == -1)
		flags->width = va_arg(ap, unsigned int);

	n = (unsigned long int) va_arg(ap, void *);
	if (n)
		l = get_int_lenght(n) + (flags->plus || flags->space) + 2;
	else
		l = 5;
	if ((!flags->zero || !n) && !flags->neg)
		counter += print_fill(' ', flags->width - l);


	if (n)
	{
		if (flags->plus)
		{
			counter++;
			write(1, "+", 1);
		}
		else if (flags->space)
		{
			counter++;
			write(1, " ", 1);
		}
		write(1, "0x", 2);
		if (flags->zero && !flags->neg)
			counter += print_fill('0', flags->width - l);
		convert_print(n, &counter, 16, 'a');
	}
	else
	{
		write(1, "(nil)", 5);
		counter += 3;
	}
	if (flags->neg)
		counter += print_fill(' ', flags->width - l);
	return (counter);
}

/**
 * print_pers - print %
 * @ap: opject
 * @flags: opject of the out put
 * Return: the number of printed chars
 */
int print_pers(va_list ap, flags_t *flags)
{
	(void) ap;
	(void) flags;
	return (write(1, "%", 1));
}

/**
 * _strcpy - cp from src to dest
 * @dest: pointer to dest
 * @src: pointer to src
 * @steps: number of chars to copy
 */
void _strcpy(char *dest, const char *src, int steps)
{
	dest[steps] = '\0';
	while (steps--)
	{
		dest[steps] = src[steps];
	}
}
