#include "lists.h"

/**
 * free_dlistint - Frees a dlistint_t list
 * @head: Pointer to the head of DLL
 */

void free_dlistint(dlistint_t *head)
{
	dlistint_t *current;
	dlistint_t nxt_node;

	current = head;

	while (current != NULL)
	{
		nxt_node = current->next;
		free(current);
		current = nxt_node;
	}
}
