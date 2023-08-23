#include "main.h"

/**
 * reverse_array - Reverses the content
 * @a: The array of integers
 * @n: number of elements in the array
 */

void reverse_array(int *a, int n)
{
	int temp;
	int a;
	int b;

	for (y = 0, z = n - 1; y < z; y++, z--)
	{
		temp = a[y];
		a[y] = a[z];
		a[z] = temp;
	}

}
