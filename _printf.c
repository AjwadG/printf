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
	int i = 0, counter = 0, step = 1;
	va_list ap;
	flags_t flags = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

	int (*f[])(va_list, flags_t *) = {print_char,
		print_string, print_int, print_binary,
		print_u, print_octal, print_hex, print_HEX,
		print_non_printables, print_pointer, print_rot13, print_rev};

	if (!format)
		return (-1);
	va_start(ap, format);
	for (i = 0; format[i]; i += step, counter++)
	{
		step = 1;
		if (format[i] != '%')
		{
			if (flags.index == 0 && (flags.h || flags.l) &&
					(format[i] == 'h' || format[i] == 'l'))
				flags.index = -5;
			else
				write(1, &format[i], 1);
		}
		else
		{
			step += determine(&format[i + 1], &flags);
			if (flags.index > 0)
				counter += f[flags.index - 1](ap, &flags) - 1;
			else
			if (flags.index == -1)
				return (-1);
		}
	}
	return (counter);
}
