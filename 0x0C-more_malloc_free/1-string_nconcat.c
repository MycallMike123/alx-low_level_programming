#include "main.h"

/**
 * string_nconcat - Concatenates two strings
 * @s1: The first string
 * @s2: The second string
 * @n: The maximum number of bytes to concatenate from @s2
 * Return: A pointer to the concatenated string, NULL otherwise
 */

char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	unsigned int str_length1 = 0, str_length2 = 0;
	unsigned int a, b;
	char *joined;

	if (s1 == NULL)
	{
		s1 = "";
	}
	if (s2 == NULL)
	{
		s2 = "";
	}

	while (s1[str_length1])
		str_length1++;

	while (s2[str_length2])
		str_length2++;

	if (n >= str_length2)
		n = str_length2;

	joined = malloc(str_length1 + n + 1);

	if (joined == NULL)
		return (NULL);

	for (a = 0; a < str_length1; a++)
		joined[a] = s1[a];

	for (b = 0; b < n; b++)
		joined[a + b] = s2[b];

	joined[a + b] = '\0';

	return (joined);
}
