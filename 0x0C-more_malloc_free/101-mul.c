#include <stdio.h>
#include <stdlib.h>

/**
 * is_digit - Checks if a string has digits
 * @str: The string to check
 * Return: 1 if it has digits and 0 otherwise
 */

int is_digit(char *str)
{
	while (*str)
	{
		if (*str > '9' || *str < '0')
		{
			return (0);
		}
		str++;
	}

	return (1);
}

/**
 * multiply - Multiplies two positive numbers
 * @n1: The first number
 * @n2: The second number
 * Return: The result
 */

int multiply(char *n1, char *n2)
{
	return (atoi(n2) * atoi(n1));
}

/**
 * main - multiplies two positive numbers
 * @argc: The number of command-line arguments
 * @argv: An array of command-line argument strings
 * Return: 0 success, 98 for error
 */

int main(int argc, char *argv[])
{
	int res;

	if (argc != 3)
	{
		printf("Error\n");
		return (98);
	}

	if (!is_digit(argv[1]) || !is_digit(argv[2]))
	{
		printf("Error\n");
		return (98);
	}

	res = multiply(argv[1], argv[2]);
	printf("%d\n", res);

	return (0);
}
