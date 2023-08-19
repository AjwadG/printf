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
	int (*f[])(va_list) = {print_char, print_string};

	if (!format)
		return (0);
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
			if (index)
				counter += f[--index](ap);
			else if (step > 1)
				counter++;
		}
		i += step;
	}
	return (counter);
}
