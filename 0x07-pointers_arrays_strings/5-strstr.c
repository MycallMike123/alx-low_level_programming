#include "main.h"

/**
 * _strstr - Locates a substring
 * @haystack: Pointer to the string to search
 * @needle: Pointer to the substring to search for
 *  Return: A pointer to the beginning of the located substring, NULL otherwise
 */

char *_strstr(char *haystack, char *needle)
{
	char *hays;
	char *n;

	while (*haystack != '\0')
	{
		*hays = haystack;
		*n = needle;

		while (*n != '\0' && *hays == *n)
		{
			hays++;
			n++;
		}

		if (*n == '\0')
		{
			return (haystack);
		}
		haystack++;
	}
	return (0);
}
