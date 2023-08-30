#include "main.h"

/**
 * _sqrt_recursion - Calculates the natural square root
 * @n: The number to calculate the square root
 * Return: The natural square root of n or -1
 */
int _sqrt_recursion(int n)
{
	if (n == 0 || n == 1)
	{
		return (n);
	}

	if (n < 0)
	{
		return (-1);
	}

	return (_sqrt_recursion_search(n, 0));
}

/**
 * _sqrt_recursion_search - Recursive binary search for square root calculation
 * @n: The original number
 * @best_1: the iterator
 * Return: The natural square root
 */

int _sqrt_recursion_search(int n, int best_1)
{
	if (best_1 * best_1 > n)
	{
		return (-1);
	}
	if (best_1 * best_1 == n)
	{
		return (best_1);
	}

	return (_sqrt_recursion_search(n, best_1 + 1));
}
