#include "main.h"
#include <stdlib.h>

/**
 * argstostr - Concatenates all program arguments
 * @ac: The argument count
 * @av: Array of strings in the argument
 * Return: A pointer to the concatenated string, NULL otherwise
 */
char *argstostr(int ac, char **av)
{
	int len = 0, idx = 0, a;
	char *argument;
	char *joined;

	if (ac == 0 || av == NULL)
	{
		return (NULL);
	}

	for (a = 0; a < ac; a++)
	{
		argument = av[a];
		while (*argument)
		{
			len++;
			argument++;
		}
		len++;
	}

	joined = malloc((len + 1) * sizeof(char));

	if (joined == NULL)
	{
		return (NULL);
	}

	for (a = 0; a < ac; a++)
	{
		argument = av[a];
		while (*argument)
		{
			joined[idx++] = *argument++;
		}
		joined[idx++] = '\0';
	}
	joined[idx] = '\0';

	return (joined);
}
