#include "shell.h"

/**
 * bfree - this function will free a pointer and NULLs the address
 * @ptr: the address of the pointer
 * Return: will return 1 if freed, otherwise 0.
 */

int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}

