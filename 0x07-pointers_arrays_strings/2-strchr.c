#include "main.h"
#include <stddef.h>

/**
 * _strchr - Locates a char in a string
 * @s: Pointer to the string to search
 * @c: The character to locate
 * Return: A pointer to char c or NULL if not found
 */

char *_strchr(char *s, char c)
{
	while (*s != '\0')
	{
		if (*s == c)
		{
			return (s);
		}
		s++;
	}

	return (NULL);
}
