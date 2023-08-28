#include "main.h"

/**
 * _strchr - Locates a char in a string
 * @s: Pointer to the string to search
 * @c: The character to locate
 * Return: A pointer to char c or NULL if not found
 */

char *_strchr(char *s, char c)
{
	int a;

	for (a = 0; s[a] >= '\0'; s++)
	{
		if (s[a] == c)
			return (&s[a]);
	}

	return (0);
}
