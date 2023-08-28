#include "main.h"
#include <stdio.h>

/**
 * print_diagsums - Prints the sum of the diagonals
 * @a: Pointer to the matrix
 * @size: Size of the matrix
 */

void print_diagsums(int *a, int size)
{
	int sum_main = 0, sum_secondary = 0, i;

	for (i = 0; i < size; i++)
	{
		sum_main += a[i * size + i];
	}
	for (i = size - 1; i >= 0; i--)
	{
		sum_secondary += a[i * size + (size - i - 1)];
	}

	printf("%d\n", sum1);
	printf("%d\n", sum2);
}
