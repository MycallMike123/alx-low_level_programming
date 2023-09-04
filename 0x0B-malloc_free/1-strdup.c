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
	int a = 0;
	char *copy = (char *)malloc(sizeof(char) * (len + 1));

	if (str == NULL)
	{
		return (NULL);
	}

	while (str[len] != '\0')
	{
		len++;
	}

	if (copy == NULL)
	{
		return (NULL);
	}

	for (a = 0; str[a]; a++)
	{
		copy[a] = str[a];
	}

	return (copy);
}
