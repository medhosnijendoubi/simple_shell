#include "shell.h"

/**
 * _stringcopy - function to copy a string
 * @dest: the destination
 * @src: the source
 *
 * Return: pointer to the destination
 */
char *_stringcopy(char *dest, char *src)
{
	int j = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[j])
	{
		dest[j] = src[j];
		j++;
	}
	dest[j] = 0;
	return (dest);
}

/**
 * _stringduplicate - function to duplicate a string
 * @str: the string to duplicate
 *
 * Return: returns a pointer to the duplicated string
 */
char *_stringduplicate(const char *str)
{
	int test = 0;
	char *test2;

	if (str == NULL)
		return (NULL);
	while (*str++)
		test++;
	test2 = malloc(sizeof(char) * (test + 1));
	if (!test2)
		return (NULL);
	for (test++; test--;)
		test2[test] = *--str;
	return (test2);
}

/**
 * _putcharacter - function to write a character c to stdout
 * @c: the character to print
 *
 * Return: returns 1 on success.
 * On error, there is -1 is returned, and there is an error is set appropriately.
 */
int _putcharacter(char c)
{
	static int j;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || j >= WRITE_BUF_SIZE)
	{
		write(1, buf, j);
		j = 0;
	}
	if (c != BUF_FLUSH)
		buf[j++] = c;
	return (1);
}

/**
 *_printstring - function to print all input string
 *@str: the string to be printed
 *
 * Return: returns Nothing
 */
void _printstring(char *str)
{
	int j = 0;

	if (!str)
		return;
	while (str[j] != '\0')
	{
		_putcharacter(str[j]);
		j++;
	}
}

