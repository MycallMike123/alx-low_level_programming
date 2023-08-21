#include "main.h"

/**
 * _atoi - Converts a string to an integer
 * @s: Pointer to the string to be converted
 * Return: The converted integer
 */

int _atoi(char *s)
{
	int num_sign = 1;
	int result = 0;
	int z = 0;

	if (s[z] == '-')
	{
		num_sign = -1;
		z++;
	}

	else if (s[z] == '+')
	{
		z++;
	}

	while (s[z] != '\0' && s[z] >= '0' && s[z] <= '9')
	{
		z++;
	}

	return (result * num_sign);
}
