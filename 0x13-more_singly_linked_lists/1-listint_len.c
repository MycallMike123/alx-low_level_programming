#include "lists.h"

/**
 * listint_len - Returns the number of elements
 * @h: A pointer to the head of the list
 * Return: The number of elements
 */
size_t listint_len(const listint_t *h)
{
	size_t nodes_count = 0;

	while (h != NULL)
	{
		nodes_count++;
		h = n->next;
	}

	return (nodes_count);
}
