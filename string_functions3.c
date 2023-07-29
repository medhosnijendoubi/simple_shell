#include "shell.h"

/**
 **_stringcopy - function to copy a string
 *@dest: the destination of string to be copied to
 *@src: the source of string
 *@n: the amount of characters that be copied
 *Return: that will return concatenated string
 */
char *_stringcopy(char *dest, char *src, int n)
{
	int p, k;
	char *s = dest;

	p = 0;
	while (src[p] != '\0' && p < n - 1)
	{
		dest[p] = src[p];
		p++;
	}
	if (p < n)
	{
		k = p;
		while (k < n)
		{
			dest[k] = '\0';
			k++;
		}
	}
	return (s);
}

/**
 **_stringsearch - function to locates a character in a string
 *@s: the string to be parsed
 *@c: the character to look for
 *Return: that will return (s) a pointer to the memory area s
 */
char *_stringsearch(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}

/**
 **_stringconcat - function to concatenate two strings
 *@dest: the first string
 *@src: the second string
 *@n: the amount of bytes to be maximally used
 *Return: that will return concatenated string
 */
char *_stringconcat(char *dest, char *src, int n)
{
	int p, k;
	char *s = dest;

	p = 0;
	k = 0;
	while (dest[p] != '\0')
		p++;
	while (src[k] != '\0' && k < n)
	{
		dest[p] = src[k];
		p++;
		k++;
	}
	if (k < n)
		dest[p] = '\0';
	return (s);
}

