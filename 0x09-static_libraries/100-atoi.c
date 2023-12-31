#include "main.h"
#include <limits.h>

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

	while (s[z] == ' ' || (s[z] >= 9 && s[z] <= 13))
	{
		z++;
	}

	if (s[z] == '-')
	{
		num_sign *= -1;
		z++;
	}

	else if (s[z] == '+')
	{
		z++;
	}

	while (s[z] >= '0' && s[z] <= '9')
	{
		if (result > (INT_MAX - (s[z] - '0')) / 10)
		{
			return ((num_sign == 1) ? INT_MAX : INT_MIN);
		}
		result = result * 10 + (s[z] - '0');
		z++;
	}

	return (result * num_sign);
}
