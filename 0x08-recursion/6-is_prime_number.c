#include "main.h"

/**
 * is_prime_number - Checks if a number is prime
 * @n: The number to check
 * Return: 1 if n is prime, 0 otherwise
 */

int is_prime_number(int n)
{
	if (n <= 1)
		return (0);

	return (is_prime_fn(n, 2));
}

/**
 * is_prime_fn - Helper function for primality check
 * @n: The number to check
 * @div: The current divisor to check
 * Return: 1 if n is prime, 0 otherwise
 */
int is_prime_fn(int n, int div)
{
	if (div * div > n)
		return (1);

	if (n % div == 0)
		return (0);

	return (is_prime_fn(n, div + 1));
}
