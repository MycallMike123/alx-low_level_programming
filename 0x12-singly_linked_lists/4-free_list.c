#include "lists.h"

/**
 * free_list - Frees a list_t list
 * @head: Pointer to the head of the list
 */

void free_list(list_t *head)
{
	list_t *current_node = head, *temp;

	while (current_node != NULL)
	{
		temp = current_node;

		current_node = current_node->next;
		if (temp->str != NULL)
		{
			free(temp->str);
		}
		free(temp);
	}
}
