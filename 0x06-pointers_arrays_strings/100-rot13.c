#include "main.h"

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
		char *pointer = alp;
		char *rot13_pointer = rot13_alp;
		char found = 0;

		while (*pointer != '\0')
		{
			if (*pointer == str[a])
			{
				str[a] = *rot13_pointer;
				found = 1;
				break;
			}

			pointer++;
			rot13_pointer++;
		}

		if (!found)
		{
			str[a] = str[a];
		}
	}
	return (str);
}
