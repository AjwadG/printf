#include "main.h"

/**
 * print_err - funtion
 * @flags: opject
 * @c: char
 * Return: number of printed cahrs
 */
int print_err(flags_t *flags, char c)
{
	int i = 0;

	if ((flags->index <= 0 || flags->index >= -2) && (flags->h || flags->l)
			&& (c == 'h' || c == 'l'))
	{
		switch (flags->index)
		{
			case -1:
				flags->index = -5;
				return (c == 'l' ? write(1, &c, 1) : 0);
			case -2:
				flags->index = -5;
				return (c == 'h' ? write(1, &c, 1) : 0);
			default:
				flags->index = c == 'l' ? -2 : -1;
				return (0);
		}
	}
	else if (flags->tmp && c == '*')
	{
		if (flags->tmp < 0)
			return (0);
		convert_print(flags->tmp, &i, 10, 0);
		flags->tmp = 0;
		return (i);
	}
	else if (flags->tmp1 && c == '*')
	{
		if (flags->tmp1 < 0)
			return (0);
		convert_print(flags->tmp1, &i, 10, 0);
		flags->tmp1 = 0;
		return (i);
	}
	else
	{
		return (write(1, &c, 1));
	}
}
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
	flags_t flags = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

	int (*f[])(va_list, flags_t *) = {print_char,
		print_string, print_int, print_binary, print_u,
		print_octal, print_hex, print_HEX, print_non_printables,
		print_pointer, print_rot13, print_rev, print_pers};

	if (!format)
		return (-1);
	va_start(ap, format);
	for (i = 0; format[i]; i += step)
	{
		step = 1;
		if (format[i] != '%')
		{
			counter += print_err(&flags, format[i]);
		}
		else
		{
			step += determine(&format[i + 1], &flags, ap);
			if (flags.index > 0)
				counter += f[flags.index - 1](ap, &flags);
			else
				counter++;
			if (flags.index > 0)
				init_flags(&flags);
			if (flags.index == -1)
				return (-1);
		}
	}
	return (counter);
}

