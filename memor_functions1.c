#include "shell.h"

/**
 * myfree - that will used to frees a pointer and NULLs the address
 * @ptr: is an address of the pointer to free
 *
 * Return: will retur n  1 if freed, or otherwise 0.
 */
int myfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}

