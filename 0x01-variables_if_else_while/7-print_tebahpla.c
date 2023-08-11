#include <stdio.h>
/**
 * main - the entry point
 * Return: 0 (Success)
*/

int main(void)
{
	char alphab =  'z';

	while (alphab >= 'a')
	{
		putchar(alphab);
		alphab++;
	}

	putchar('\n');
	return (0);
}
