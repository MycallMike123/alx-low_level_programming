#include "main.h"
#include <stdio.h>

/**
 * array_range - Creates an array of integers from min to max
 * @min: The minimum value
 * @max: The maximum value
 * Return: A pointer to the created array, NULL otherwise
 */

int *array_range(int min, int max)
{
	int a, int_size;
	int *ar;

	if (min > max)
	{
		return (NULL);
	}

	int_size = max - min + 1;

	ar = malloc(sizeof(int) * int_size);
	if (ar == NULL)
	{
		return (NULL);
	}

	for (a = 0; a < int_size; a++)
	{
		ar[a] = min + a;
	}

	return (ar);
}
