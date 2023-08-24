#include "main.h"
#include <stdio.h>
#include <string.h>
/**
 * infinite_add - Adds two positive numbers
 * @n1: The first number
 * @n2: The second number
 * @r: buffer to store the result
 * @size_r: The size of the result buffer
 * Return: A pointer to the result
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int length_n1 = strlen(n1);
	int length_n2 = strlen(n2);
	int c = 0;
	int k, l, m;
	int first_digit, second_digit, sum;

	if (length_n1 + 1 > size_r || length_n2 + 1 > size_r)
		return (0);
	r[size_r - 1] = '\0';
	k = length_n1 - 1;
	l = length_n2 - 1;
	m = size_r - 2;

	while (k >= 0 || l >= 0 || c)
	{
		first_digit = k >= 0 ? n1[k] - '0' : 0;
		second_digit = l >= 0 ? n2[l] - '0' : 0;

		sum = first_digit + second_digit + c;
		c = sum / 10;
		r[m] = (sum % 10) + '0';

		k--;
		l--;
		m--;
	}
	if (m >= 0)
		return (r + m + 1);
	else
		return (0);
}
