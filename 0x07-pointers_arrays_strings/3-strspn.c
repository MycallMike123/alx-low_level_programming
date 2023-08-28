#include "main.h"

/**
 * _strspn - Gets the length of a prefix substring
 * @s: Pointer to the string to search
 * @accept: Pointer to the string of chacters accepted
 * Return: The number of bytes in @s with bytes @accept
 */

unsigned int _strspn(char *s, char *accept)
{
	unsigned int count = 0;
	int a;

	while (*s != '\0')
	{
		for (a = 0; accept[a]; a++)
		{
			if (*a == accept[a])
			{
				count++;
				break;
			}
			else if (accept[a + 1])
			{
				return (count);
			}
		}
		s++;
	}
	return (count);
}
