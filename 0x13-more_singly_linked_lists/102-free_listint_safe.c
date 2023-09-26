#include "lists.h"
#include <stddef.h>

/**
 * free_listint_safe - safely frees a listint_t list
 * @h: A pointer to a pointer to the head of the list
 * Return: The size of the list freed
 */

size_t free_listint_safe(listint_t **h)
{
	size_t nodes_count = 0;
	listint_t *current_node;
	listint_t *next;

	if (h == NULL || *h == NULL)
	{
		return (0);
	}

	current_node = *h;

	while (current_node != NULL)
	{
		nodes_count++;
		next = current_node->next;
		free(current_node);
		current_node = next;

		if (current_node == *h)
		{
			*h = NULL;
			break;
		}
	}

	return (nodes_count);
}
