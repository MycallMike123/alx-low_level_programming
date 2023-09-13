#include <stdio.h>
#include <stdlib.h>

/**
 * main - Prints the opcodes of its own main function
 * @argc: The number of arguments
 * @argv: An array of string arguments
 * Return: 0 Success
 */

int main(int argc, char *argv[])
{
	int bytes_count, a;
	char *opcodes;

	if (argc != 2)
	{
		printf("Error\n");
		exit(1);
	}

	bytes_count = atoi(argv[1]);

	if (bytes_count < 0)
	{
		printf("Error\n");
		exit(2);
	}

	opcodes = (char *)main;

	for (a = 0; a < bytes_count; a++)
	{
		printf("%02hhx", opcodes[a]);

		if (a < bytes_count - 1)
		{
			printf(" ");
		}
	}
	printf("\n");

	return (0);
}
