#include "main.h"
#include <stdlib.h>

/**
 * _strdup - Duplicates a string
 * @str: The string to duplicate
 * Return: pointer to the dublicated string, NULL otherwise
 */

char *_strdup(char *str)
{
	int len = 0;
	int a;
	char *copy = (char *)malloc((len + 1) * sizeof(char));

	while (str[len] != '\0')
	{
		len++;
	}

	if (copy == NULL)
	{
		return (NULL);
	}

	for (a = 0; a <= len; a++)
	{
		copy[a] = str[a];
	}

	return (copy);
}
