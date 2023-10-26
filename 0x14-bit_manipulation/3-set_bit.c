#include "main.h"

/**
 * set_bit - Sets the value of a bit to 1
 * @n: A pointer to the UL integer to set
 * @index: The index of the bit tu set
 * Return: 1 if success, -1 otherwise
 */

int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int m;

	if (index >= sizeof(unsigned long int) * 8)
	{
		return (-1);
	}

	m = 1UL << index;
	*n |= m;

	return (1);
}
