#include "main.h"

/**
 * binary_to_uint - Converts a binary number to unsigned int
 * @b: A pointer to a string with binary xters 0 and 1
 * Return: The converted number, 0 otherwise
 */

unsigned int binary_to_uint(const char *b)
{
	int w;
	unsigned int res;

	if (b == NULL)
	{
		return (0);
	}
	res = 0;

	for (w = 0; b[w] != '\0'; w++)
	{
		if (b[w] != '0' && b[w] != '1')
		{
			return (0);
		}
	res = (res << 1) | (b[w] - '0');
	}

	return (res);
}
