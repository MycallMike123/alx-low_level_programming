#include <stdio.h>

/**
 * main - check the code for
 * Return: Always 0.
 */

int main(void)
{
	int a[5] = {98, 12, 54, 390, 4};
	int *p;

	p = &a[2];





	printf("a[2] = %d\n", *(p));

	return (0);
}
