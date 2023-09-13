#include "3-calc.h"

/**
 * get_op_func - selects the correct fn to perform operations
 * @s: Operator passed as an argument
 * Return: Pointer to the function, NULL otherwise
 */

int (*get_op_func(char *s))(int, int)
{
	op_t ops[] = {
		{"+", op_add},
		{"-", op_sub},
		{"*", op_mul},
		{"/", op_div},
		{"%", op_mod},
		{NULL, NULL}
	};

	int a = 0;

	while (ops[a].op)
	{
		if (s[1] == '\0' && ops[a].op[0] == s[0])
		{
			return (ops[a].f);
		}
		a++;
	}

	return (NULL);
}
