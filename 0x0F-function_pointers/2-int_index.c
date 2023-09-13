#include "function_pointers.h"

/**
 * int_index - Searches for an int in array
 * @array: Pointer to the array
 * @size: Number of vars in the array
 * @cmp: Pointer to the fn to compare the values
 * Return: Index of the first matching element, -1 otherwise
 */

int int_index(int *array, int size, int (*cmp)(int))
{
	if (array != NULL && size > 0 && cmp != NULL)
	{
		int a;

		for (a = 0; a < size; a++)
		{
			if (cmp(array[a]) != 0)
			{
				return (a);
			}
		}
	}
	return (-1);
}
