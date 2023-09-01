#include "main.h"
#include <stdio.h>

/**
 * main - Entry point
 * @argc: The number of command-line arguments
 * @argv: An array of strings
 * Return: 0 for success, 1 for error
 */

int main(int argc, char *argv[])
{
	int first_num, second_num, output;
	if (argc != 3)
	{
		printf("Error\n");
		return (1);
	}

	first_num = _atoi(argv[1]);
	second_num = _atoi(argv[2]);

	output = first_num * second_num;

	printf("%d\n", output);
	return (0);
}
