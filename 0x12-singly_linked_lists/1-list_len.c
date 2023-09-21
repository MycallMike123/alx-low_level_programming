#include "lists.h"

/**
 * list_len - Returns the number of elements
 * @h: Pointer to the head of the list
 * Return: The number of nodes in the list
 */

size_t list_len(const list_t *h)
{
	size_t nodes_count = 0;

	while (h != NULL)
	{
		h = h->next;
		nodes_count++;
	}

	return (nodes_count);
}
