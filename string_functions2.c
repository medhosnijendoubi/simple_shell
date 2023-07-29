#include "shell.h"

/**
 * _strlength - function to return the length of a string
 * @s: the string whose length to check
 *
 * Return: returns an integer length of a string
 */
int _strlength(char *s)
{
	int j = 0;

	if (!s)
		return (0);

	while (*s++)
		j++;
	return (j);
}

/**
 * _stringcompare - function to perform lexicographic comparison of two strings.
 * @s1: the first string
 * @s2: the second string
 *
 * Return: returns negative if s1 < s2, positive if s1 > s2, zero if s1 == s2
 */
int _stringcompare(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}

/**
 * starts_with - function to check if needle starts with haystack or not
 * @haystack: the string to search
 * @needle: the substring to find
 *
 * Return: returns address of the next char of haystack or NULL
 */
char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}

/**
 * _stringconcat - function to concatenate two strings
 * @dest: the destination buffer
 * @src: the source buffer
 *
 * Return: returns pointer to the destination buffer
 */
char *_stringconcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (ret);
}

