#include "shell.h"

/**
 * _anotheratoi - function to convert a string to an integer
 * @s: the string to be converted
 * Return: 0 if no numbers in the string, or the converted number otherwise
 *       -1 on error
 */
int _anotheratoi(char *s)
{
	int j = 0;
	unsigned long int test = 0;

	if (*s == '+')
		s++;  /* TODO: why does this make main return 255? */
	for (j = 0;  s[j] != '\0'; j++)
	{
		if (s[j] >= '0' && s[j] <= '9')
		{
			test *= 10;
			test += (s[j] - '0');
			if (test > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (test);
}

/**
 * display_error - function to print an error message
 * @info: parameter and return info struct
 * @estr: a string containing the specified error type
 * Return: 0 if no numbers in the string, or the converted number otherwise
 *        -1 on error
 */
void display_error(info_t *info, char *estr)
{
	_eputs(info->fname);
	_eputs(": ");
	print_d(info->line_test, STDERR_FILENO);
	_eputs(": ");
	_eputs(info->argv[0]);
	_eputs(": ");
	_eputs(estr);
}

/**
 * print_d - function to print a decimal (integer) number (base 10)
 * @input: input value
 * @fd: file descriptor to write to
 *
 * Return: number of characters that are printed
 */
int print_d(int input, int fd)
{
	int (*__putchar)(char) = _putchar;
	int j, test = 0;
	unsigned int _abc_, curr;

	if (fd == STDERR_FILENO)
		__putchar = _eputchar;
	if (input < 0)
	{
		_abc_ = -input;
		__putchar('-');
		test++;
	}
	else
		_abc_ = input;
	curr = _abc_;
	for (j = 1000000000; j > 1; j /= 10)
	{
		if (_abc_ / j)
		{
			__putchar('0' + curr / j);
			test++;
		}
		curr %= j;
	}
	__putchar('0' + curr);
	test++;

	return (test);
}

/**
 * convert_number - function to convert a clone of itoa
 * @num: the number to convert
 * @base: the base
 * @flags: argument flags
 *
 * Return: the converted string or not
 */
char *convert_number(long int num, int base, int flags)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long k = num;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		k = -num;
		sign = '-';

	}
	array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do	{
		*--ptr = array[k % base];
		k /= base;
	} while (k != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}

/**
 * remove_comments - function to replace the first instance of '#' with '\0'
 * @buf: the address of the string to modify
 *
 * Return: Always 0 or not;
 */
void remove_comments(char *buf)
{
	int j;

	for (j = 0; buf[j] != '\0'; j++)
		if (buf[j] == '#' && (!j || buf[j - 1] == ' '))
		{
			buf[j] = '\0';
			break;
		}
}

