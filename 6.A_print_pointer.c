#include "main.h"

/**
 * print_pointer - print pointer
 * @ap: opject
 * @pattaren: pattaren of the output
 * Return: the number of printed chars
 */
int print_pointer(va_list ap, char *pattaren)
{
	unsigned long int n = (unsigned long int) va_arg(ap, void *);
	int counter = 2;

	if (n)
	{
		if (pattaren[0] == '+')
		{
			counter++;
			write(1, "+", 1);
		}
		else if (pattaren[0] == ' ')
		{
			counter++;
			write(1, " ", 1);
		}
		write(1, "0x", 2);
		convert_print(n, &counter, 16, 'a');
	}
	else
	{
		write(1, "(nil)", 5);
		counter += 3;
	}
	return (counter);
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
