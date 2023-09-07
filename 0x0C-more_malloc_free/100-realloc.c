#include "main.h"
#include <string.h>

/**
 * _realloc - Reallocates a memory block
 * @ptr: A pointer to the previous mem allocation
 * @old_size: The size of the old memory block in bytes
 * @new_size: The new size in byter
 * Return: A pointer to the reallocated memory block, NULL otherwise
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *pointer;

	if (new_size == old_size)
	{
		return (ptr);
	}
	if (ptr == NULL)
	{
		pointer = malloc(new_size);
		if (pointer == NULL)
		{
			return (NULL);
		}
		return (pointer);
	}

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}

	pointer = malloc(new_size);

	if (pointer == NULL)
	{
		return (NULL);
	}

	if (new_size < old_size)
	{
		old_size = new_size;
	}

	memcpy(pointer, ptr, old_size);
	free(ptr);

	return (pointer);
}
