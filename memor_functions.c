#include "shell.h"

/**
 **_mymemset - That will used to fills memory with a constant byte
 *@s: He is a pointer to the memory area
 *@b: He is a byte to fill with
 *@n: He is an amount of bytes to be filled
 *Return: (s) will retur n a pointer to the memory area s
 */
char *_mymemset(char *s, char b, unsigned int n)
{
	unsigned int j;

	for (j = 0; j < n; j++)
		s[j] = b;
	return (s);
}

/**
 * ffree - That will used to frees a string of strings
 * @pp: He is a string of strings
 */
void ffree(char **pp)
{
	char **e = pp;

	if (!pp)
		return;
	while (*pp)
		free(*pp++);
	free(e);
}

/**
 * _myrealloc - That will used to reallocates a block of memory
 * @ptr: He is a pointer to the previously allocated block
 * @old_size: It's a byte size of the previous block
 * @new_size: It's a byte size of the new block
 *
 * Return: Will retur n pointer to the new block nameen.
 */
void *_myrealloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *k;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	k = malloc(new_size);
	if (!k)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		k[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (k);
}

