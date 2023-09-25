#include "lists.h"
#include <stddef.h>

/**
 * print_listint - Prints all the elements of a listint_t list
 * @h: A pointer to head of the list
 * Return: The number of nodes
 */

size_t print_listint(const listint_t *h)
{
	size_t nodes_count = 0;

	while (h != NULL)
	{
		printf("%d\n", h->n);
		h = h->next;
		nodes_count++;
	}

	return (nodes_count);
}
