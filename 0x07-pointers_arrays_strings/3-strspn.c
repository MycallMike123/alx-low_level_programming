#include "main.h"

/**
 * _strspn - Gets the length of a prefix substring
 * @s: Pointer to the string to search
 * @accept: Pointer to the string of chacters accepted
 * Return: The number of bytes in @s with bytes @accept
 */

unsigned int _strspn(char *s, char *accept)
{
	unsigned int cnt = 0;
	int accepted = 0;
	char *i;

	while (*s != '\0')
	{
		for (i = accept; *i != '\0'; i++)
		{
			if (*i == *s)
			{
				accepted = 1;
				break;
			}
		}

		if (!accepted)
		{
			break;
		}
		cnt++;
		s++;
	}
	return (cnt);
}
