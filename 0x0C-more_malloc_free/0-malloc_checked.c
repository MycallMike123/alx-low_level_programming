#include "main.h"

/**
 * malloc_checked - Allocates memory
 * @b: The number of bytes to allocate
 * Return: A pointer to allocated mem, otherwise exit status 98
 */

void *malloc_checked(unsigned int b)
{
	void *pointer = malloc(b);

	if (ptr == NULL)
	{
		exit(98);
	}

	return (pointer);
}
