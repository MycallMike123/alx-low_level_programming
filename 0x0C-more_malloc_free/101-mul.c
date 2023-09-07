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
 * @num1: The first number
 * @num2: The second number
 * Return: The result
 */
char *multiply(const char *num1, const char *num2)
{
	int int_len1 = 0, int_len2 = 0, res_len, prod, sum, a, b;
	char *zero, *res_str;
	int *result;

	while (num1[int_len1] != '\0')
		int_len1++;
	while (num2[int_len2] != '\0')
		int_len2++;

	res_len = int_len1 + int_len2;
	result = calloc(res_len, sizeof(int));

	for (a = int_len1 - 1; a >= 0; a--)
	{
		for (b = int_len2 - 1; b >= 0; b--)
		{
			prod = (num1[a] - '0') * (num2[b] - '0');
			sum = prod + result[a + b + 1];
			result[a + b] += sum / 10;
			result[a + b + 1] = sum % 10;
		}
	}

	a = 0;
	while (a < res_len && result[a] == 0)
		a++;

	if (a == res_len)
	{
		zero = "0";
		return (zero);
	}
	res_str = malloc(res_len - a + 1);
	for (b = a; b < res_len; b++)
		res_str[b - a] = result[b] + '0';

	res_str[res_len - a] = '\0';

	free(result);
	return (res_str);
}

/**
 * main - multiplies two positive numbers
 * @argc: The number of command-line arguments
 * @argv: An array of command-line argument strings
 * Return: 0 success, 98 for error
 */

int main(int argc __attribute__((unused)), char *argv[])
{
	char *num1, *num2, *result;

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

	num1 = argv[1];
	num2 = argv[2];
	result = multiply(num1, num2);
	printf("%s\n", result);
	free(result);

	return (0);
}
