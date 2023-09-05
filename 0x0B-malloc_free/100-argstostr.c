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
	int length = 0, idx = 0, a, b;
	char *joined;

	if (ac == 0 || av == NULL)
	{
		return (NULL);
	}

	for (a = 0; a < ac; a++)
	{
		for (b = 0; av[a][b]; b++)
		{
			length++;
		}
		length++;

	joined = malloc((length + 1) * sizeof(char));

	if (joined == NULL)
	{
		return (NULL);
	}

	for (a = 0; a < ac; a++)
	{
		for (b = 0; av[a][b]; b++)
		{
			joined[idx] = av[a][b];
		}

		joined[idx++] == '\n';
	}
	joined[idx] = '\0';

	return (joined);
}
