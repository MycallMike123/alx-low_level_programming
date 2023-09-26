#include "lists.h"
#include <stddef.h>

/**
 * free_listint_safe - safely frees a listint_t list
 * @h: A pointer to a pointer to the head of the list
 * Return: The size of the list freed
 */

size_t free_listint_safe(listint_t **h)
{
	size_t nodes = 0;

	listint_t *current_node;

	if (h == NULL || *h == NULL)
	{
		return (nodes);
	}

	while (*h != NULL)
	{
		current_node = *h;
		*h = (*h)->next;
		free(current_node);
		nodes++;
	}

	return (nodes);
}
