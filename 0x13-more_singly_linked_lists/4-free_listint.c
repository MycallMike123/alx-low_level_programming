#include "lists.h"

/**
 * free_listint - Frees a listint_t list
 * @head: A pointer to the head of the list
 */

void free_listint(listint_t *head)
{
	listint_t *current_node, *temp_holder;

	current_node = head;

	while (current_node != NULL)
	{
		temp_holder = current_node;
		current_node = current_node->next;
		free(temp_holder);
	}
}
