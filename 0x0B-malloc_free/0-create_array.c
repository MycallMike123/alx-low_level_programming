#include "main.h"
#include <stdlib.h>

/**
 * create_array - Creates an array of characters
 * @size: The size of the array to be created
 * @c: The character that initializes the array
 *
 * Return: the pointer to the created array, NULL otherwise
 */

char *create_array(unsigned int size, char c)
{
	unsigned int a;
	char *array = (char *)malloc(size * sizeof(char));

	if (array == NULL || size == 0)
	{
		return (NULL);
	}

	for (a = 0; a < size; a++)
	{
		array[a] = c;
	}

	return (array);
}
