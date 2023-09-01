#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * main - Entry point
 * @argc: The number of command-line arguments
 * @argv: An array of strings
 * Return: 0 for success, 1 error
 */

int main(int argc, char *argv[])
{
	int add = 0;
	int a, b, number;
	char on_char;

	for (a = 1; a < argc; a++)
	{
		number = 0;
		b = 0;
		on_char = argv[a][b];

		while (on_char != '\0')
		{
			if (on_char < '0' || on_char > '9')
			{
				printf("Error\n");
				return (1);
			}

			number = number * 10 + (on_char - '0');
			b++;
			on_char = argv[a][b];
		}

		if (number < 0)
		{
			printf("Error\n");
			return (1);
		}

		add += number;
	}

	printf("%d\n", add);

	return (0);
}
