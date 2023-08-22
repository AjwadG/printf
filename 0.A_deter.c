#include "main.h"

/**
 * determine - determin the definer
 * @s: pointer to string
 * @flags: opject of the out put
 * Return: the number of skiped chars
 */
int determine(const char *s, flags_t *flags)
{
	int i = 0;

	while (get_f(&s[i], flags))
		i++;
	get_index(&s[i], flags);

	if (flags->index == 0)
	{
		switch (s[i])
		{
			case '%':
				write(1, s, 1);
				break;
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
			default:
				return (i);
		}
	}
	return (0);
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
		(s[0] == 'R') * 11 + (s[0] == 'r') * 12;
}
