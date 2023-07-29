#include "shell.h"

/**
 * is_interactive - that will used to if true if shell is in interactive mode
 * @info: is a struct address
 *
 * Return: 1 if it's in interactive mode, or 0 otherwise
 */
int is_interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delimiter - that will checks if character is a delimiter
 * @c: is a char to check
 * @delim: is a delimiter string
 * Return: 1 if true, or 0 if false
 */
int is_delimiter(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
 * _isalpha - that checks for an alphabetic character
 * @c: he is a character to input
 * Return: 1 if c is alphabetic, or 0 otherwise
 */
int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * _atoi - that will used to convert a string to an integer
 * @s: is a string to be converted
 * Return: 0 if no numbers in the string, or the converted number otherwise
 */
int _atoi(char *s)
{
	int j, sign = 1, test1 = 0, result = 0;

	for (j = 0; s[j] != '\0' && test1 != 2; j++)
	{
		if (s[j] == '-')
			sign *= -1;

		if (s[j] >= '0' && s[j] <= '9')
		{
			test1 = 1;
			result *= 10;
			result += (s[j] - '0');
		}
		else if (test1 == 1)
			test1 = 2;
	}

	return (result * sign);
}

