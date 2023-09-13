#include "function_pointers.h"

/**
 * array_iterator - executes a function
 * @array: Pointer to the array
 * @size: Size of the array
 * @action: Pointer to the function
 */

void array_iterator(int *array, size_t size, void (*action)(int))
{
	unsigned int a;

	if (action != NULL && array != NULL)
	{
		for (a = 0; a < size; a++)
			action(array[i]);
	}
}
