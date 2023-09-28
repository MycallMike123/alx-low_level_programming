#include "main.h"

/**
 * binary_to_uint - Converts a binary num to an unsigned int
 *  @b: A pointer to a string with '0' n '1' chars
 *  Return: The converted number, 0 otherwise
 */

unsigned int binary_to_uint(const char *b)
{
	unsigned int number;
	int z;

	if (b == NULL)
	{
		return (0);
	}

	number = 0;
	for (z = 0; b[z] != '\0'; z++)
	{
		if (b[z] != '1' && b[z] != '0')
		{
			return (0);
		}

		number = (number << 1) | (b[z] - '0');
	}

	return (number);
}
