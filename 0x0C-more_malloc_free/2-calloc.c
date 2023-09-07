#include "main.h"
#include <string.h>

/**
 * _calloc - Allocates memory for an array by init it to 0
 * @nmemb: The number of elements in the array
 * @size: Size of each element in bytes
 * Return: A pointer to the allocated memory, NULL otherwise
 */

void *_calloc(unsigned int nmemb, unsigned int size)
{
	unsigned int total;
	void *pointer;

	if (nmemb == 0 || size == 0)
	{
		return (NULL);
	}

	total = size * nmemb;

	if (total / nmemb != size)
	{
		return (NULL);
	}

	pointer = malloc(total);
	if (pointer == NULL)
	{
		return (NULL);
	}
	memset(pointer, 0, total);

	return (pointer);
}
