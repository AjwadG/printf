#include "main.h"

/**
 * _printf - the printF funtion
 *
 * @format: string
 *
 * Return: the number of printed chars
 ***/

int _printf(const char *format, ...)
{
	int i = 0, counter = 0, index, step = 1;
	va_list ap;
	int (*f[])(va_list) = {print_char,
		print_string, print_int, print_binary,
		print_u, print_octal, print_hex, print_HEX,
		print_non_printables};

	if (!format)
		return (-1);
	va_start(ap, format);
	while (format[i])
	{
		step = 1;
		if (format[i] != '%')
		{
			write(1, &format[i], 1);
			counter++;
		}
		else
		{
			step += determine(&format[i + 1], &index);
			if (index > 0)
				counter += f[--index](ap);
			else
				counter++;
			if (index == -1)
				return (-1);
		}
		i += step;
	}
	return (counter);
}
