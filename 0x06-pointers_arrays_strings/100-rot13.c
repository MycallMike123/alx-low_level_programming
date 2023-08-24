#include "main.h"
#include <string.h>

/**
 * rot13 - Encodes a string using ROT13
 * @str: The input string
 * Return: A pointer to the encoded string
 */

char *rot13(char *str)
{
	char *alp = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char *rot13_alp = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	int a;

	for (a = 0; str[a] != '\0'; a++)
	{
		char *found = strchr(alp, str[a]);

		if (found)
		{
			str[a] = rot13_alp[found - alp];
		}
	}
	return (str);
}
