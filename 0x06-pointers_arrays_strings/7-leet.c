#include "main.h"

/**
 * leet - Encodes a string into 1337
 * @str: The input string
 * Return: A pointer to the modified string
 */

char *leet(char *str)
{
	char *lcr = "aAeEoOtTlL";
	char *lce = "4433007711";
	int i;
	int k;

	for (i = 0; str[i] != '\0'; i++)
	{
		for (k = 0; lcr[k] != '\0'; k++)
		{
			if (str[i] == lcr[k])
			{
				str[i] = lce[k];
				break;
			}
		}
	}
	return (str);
}
