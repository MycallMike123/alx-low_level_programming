#include "main.h"
#include <stdio.h>

/**
 * main - prints the number of arguments passed into it
 * @argc: number of command-line arguments
 * @argv: An array of strings
 * Return: 0 Success
 */

int main(int argc, char *argv[])
{
	printf("%d\n", argc - 1);

	return (0);
}
