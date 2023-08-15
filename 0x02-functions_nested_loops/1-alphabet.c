#include "main.h"

/**
 * print_alphabet - print alphabet in lowercase
 * Return: 0 (Success)
*/

void print_alphabet(void)
{
	char alp = 'a';

	while (alp <= 'z')
	{
		_putchar(alp);
		alp++;

	}
	_putchar('\n');
}
