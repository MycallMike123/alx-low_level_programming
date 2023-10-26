#include "main.h"

/**
 * clear_bit - Sets the value of a bit to 0
 * @n: A pointer to the UL integer to set
 * @index: The index of the bit
 * Return: 1 if success, -1 otherwise
 */

int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int m;

	if (index >= sizeof(unsigned long int) * 8)
	{
		return (-1);
	}

	m = 1UL << index;
	*n &= ~m;

	return (1);
}
