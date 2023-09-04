#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * str_concat - Concatenates two strings
 * @s1: The first string
 * @s2: The second string
 * Return: A pointer to the concatenated string, NULL otherwise
 */
char *str_concat(char *s1, char *s2)
{
	int s1_len = 0, s2_len = 0, a;
	char *joined;

	if (s1 == NULL)
	{
		s1 = "";
	}
	if (s2 == NULL)
	{
		s2 = "";
	}

	while (s1[s1_len] != '\0')
	{
		s1_len++;
	}
	while (s2[s2_len] != '\0')
	{
		s2_len++;
	}

	joined = malloc((s1_len + s2_len + 1) * sizeof(char));

	if (joined == NULL)
	{
		return (NULL);
	}

	for (a = 0; a < s1_len; a++)
	{
		joined[a] = s1[a];
	}
	for (a = 0; a < s2_len; a++)
	{
		joined[a] = s2[a];
	}

	joined[s1_len + s2_len] = '\0';

	return (joined);
}
