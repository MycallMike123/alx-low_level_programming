#include "main.h"
#include <stdlib.h>

/**
 * _strdup - Duplicates a string
 * @str: The string to duplicate
 * Return: pointer to the dublicated string, NULL otherwise
 */

char *_strdup(char *str)
{
	int len, a;
	char *copy = (char *)malloc((length + 1) * sizeof(char));

	if (copy == NULL)
	{
		return (NULL);
	}

	for (a = 0; a <= length; a++)
	{
		copy[a] = str[a];
	}

	return (copy);
}
