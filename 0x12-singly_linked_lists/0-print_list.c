#include "lists.h"

/**
 * print_list - Print all elements of a list_t list
 * @h: Pointer to head of the list
 * Return: The number of nodes in the list
 */

size_t print_list(const list_t *h)
{
	size_t nodes_count = 0;

	while (h != NULL)
	{
		if (h->str == NULL)
		{
			printf("[0] (nil)\n");
		}

		else
		{
			printf("[%u] %s\n", h->len, h->str);
		}

		h = h->next;
		nodes_count++;
	}

	return (nodes_count);
}
