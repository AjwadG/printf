#include "main.h"

/**
 * get_unsigned_int - gets the right sized number
 * @ap: opject
 * @flags: opject of the out put
 * Return: the number of printed chars
 */
unsigned long int get_unsigned_int(va_list ap, flags_t *flags)
{
	if (flags->l)
		return (va_arg(ap, unsigned long int));
	else if (flags->h)
		return ((unsigned short int) va_arg(ap, unsigned int));
	else
		return (va_arg(ap, unsigned int));
}
/**
 * print_u - Print unsigned number
 * @ap: opject
 * @flags: opject of the out put
 * Return: the number of printed chars
 */
int print_u(va_list ap, flags_t *flags)
{
	unsigned long int n;
	int counter = 0, l;
	char fill = flags->zero ? '0' : ' ';

	n =  get_unsigned_int(ap, flags);

	l = get_int_lenght(n);
	if (!flags->neg && !flags->prec)
		counter += print_fill(fill, flags->width - l);
	if (flags->prec)
		counter += print_fill('0', flags->prec - l);
	if (!(flags->dont && n == 0))
		convert_print(n, &counter, 10, 0);
	if (flags->neg && !flags->prec)
		counter += print_fill(' ', flags->width - l);
	return (counter);
}

/**
 * print_octal - print octal
 * @ap: opject
 * @flags: opject of the out put
 * Return: the number of printed chars
 */
int print_octal(va_list ap, flags_t *flags)
{
	unsigned long int n;
	int counter = 0, l;

	n =  get_unsigned_int(ap, flags);

	l = get_int_lenght(n);
	if (!flags->zero && !flags->neg && !flags->prec)
		counter += print_fill(' ', flags->width - l -
				(flags->hash && n != 0));

	if (flags->hash && n != 0)
		counter += write(1, "0", 1);
	if (flags->prec)
		counter += print_fill('0', flags->prec - l - counter);
	if (flags->zero & !flags->neg && !flags->prec)
		counter += print_fill('0', flags->width - l -
				(flags->hash && n != 0));
	if (!(flags->dont && n == 0))
		convert_print(n, &counter, 8, 0);

	if (flags->neg && !flags->prec)
		counter += print_fill(' ', flags->width - l - flags->hash);

	return (counter);
}

/**
 * print_hex - print lowercase hex
 * @ap: opject
 * @flags: opject of the out put
 * Return: the number of printed chars
 */
int print_hex(va_list ap, flags_t *flags)
{
	unsigned long int n;
	int counter = 0, l;

	n =  get_unsigned_int(ap, flags);

	l = get_int_lenght(n) + (flags->hash && n != 0) * 2;
	if (!flags->zero && !flags->neg && !flags->prec)
		counter += print_fill(' ', flags->width - l
				+ (n != 0) + (flags->dont && n == 0));

	if (flags->hash && n != 0)
		counter += write(1, "0x", 2);

	if (flags->prec)
		counter += print_fill('0', flags->prec -
				l + counter + 1 - (n == 0));
	if (flags->zero && !flags->neg && !flags->prec)
		counter += print_fill('0', flags->width - l + (n != 0));
	if (!(flags->dont && n == 0))
		convert_print(n, &counter, 16, 'a');

	if (flags->neg && !flags->prec)
		counter += print_fill(' ', flags->width - l + (n != 0));
	return (counter);
}

/**
 * print_HEX - print uppercase hex
 * @ap: opject
 * @flags: opject of the out put
 * Return: the number of printed chars
 */
int print_HEX(va_list ap, flags_t *flags)
{
	unsigned long int n;
	int counter = 0, l;

	n =  get_unsigned_int(ap, flags);

	l = get_int_lenght(n) + (flags->hash && n != 0) * 2;
	if (!flags->zero && !flags->neg && !flags->prec)
		counter += print_fill(' ', flags->width - l +
				(n != 0) + (flags->dont && n == 0));

	if (flags->hash && n != 0)
		counter += write(1, "0X", 2);

	if (flags->prec)
		counter += print_fill('0', flags->prec - l
				+ counter + 1 - (n == 0));
	if (flags->zero && !flags->neg && !flags->prec)
		counter += print_fill('0', flags->width - l + (n != 0));

	if (!(flags->dont && n == 0))
		convert_print(n, &counter, 16, 'A');

	if (flags->neg && !flags->prec)
		counter += print_fill(' ', flags->width - l + (n != 0));
	return (counter);
	if (!flags->prec && !n)
		return (0);
}
