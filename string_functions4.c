#include "shell.h"

/**
 * **split_string - function that splits a string into words.
 * @str: the input string
 * @d: the delimeter string
 * Return: returns a pointer to an array of strings, or NULL on error
 */
char **split_string(char *str, char *d)
{
	int p, l, k, v, test = 0;
	char **m;

	if (str == NULL || str[0] == 0)
		return (NULL);
	if (!d)
		d = " ";
	for (p = 0; str[p] != '\0'; p++)
		if (!is_delim(str[p], d) && (is_delim(str[p + 1], d) || !str[p + 1]))
			test++;

	if (test == 0)
		return (NULL);
	m = malloc((1 + test) * sizeof(char *));
	if (!m)
		return (NULL);
	for (p = 0, l = 0; l < test; l++)
	{
		while (is_delim(str[p], d))
			p++;
		k = 0;
		while (!is_delim(str[p + k], d) && str[p + k])
			k++;
		m[l] = malloc((k + 1) * sizeof(char));
		if (!m[l])
		{
			for (k = 0; k < l; k++)
				free(m[k]);
			free(m);
			return (NULL);
		}
		for (v = 0; v < k; v++)
			m[l][v] = str[p++];
		m[l][v] = 0;
	}
	m[l] = NULL;
	return (m);
}

/**
 * **split_string2 - function that splits a string into words
 * @str: the input string
 * @d: the delimeter
 * Return: returns a pointer to an array of strings, NULL on failure
 */
char **split_string2(char *str, char d)
{
	int i, j, k, v, test = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	for (i = 0; str[i] != '\0'; i++)
		if ((str[i] != d && str[i + 1] == d) ||
		    (str[i] != d && !str[i + 1]) || str[i + 1] == d)
			test++;
	if (test == 0)
		return (NULL);
	s = malloc((1 + test) * sizeof(char *));
	if (!s)
		return (NULL);
	for (i = 0, j = 0; j < test; j++)
	{
		while (str[i] == d && str[i] != d)
			i++;
		k = 0;
		while (str[i + k] != d && str[i + k] && str[i + k] != d)
			k++;
		s[j] = malloc((k + 1) * sizeof(char));
		if (!s[j])
		{
			for (k = 0; k < j; k++)
				free(s[k]);
			free(s);
			return (NULL);
		}
		for (v = 0; v < k; v++)
			s[j][v] = str[i++];
		s[j][v] = 0;
	}
	s[j] = NULL;
	return (s);
}

