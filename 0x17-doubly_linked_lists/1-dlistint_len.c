#include "lists.h"

/**
 * dlistint_len - returns the number of elements in a linked list
 * @h: A pointer to the head  of the list
 * Return: Number of elements
 */

size_t dlistint_len(const dlistint_t *h)
{
	size_t cnt = 0;

	while (h != NULL)
	{
		h = h->next;
		cnt++;
	}

	return (cnt);
}
