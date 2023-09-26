#include "lists.h"

/**
 * delete_nodeint_at_index - Deletes the node at index
 * @head: A pointer to a pointer to the head of the list
 * @index: The index of the node to delete
 * Return: 1 success, -1 fail
 */

int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	unsigned int nodes_count = 0;
	listint_t *current_node, *prev_node, *temp_node;

	if (head == NULL || *head == NULL)
	{
		return (-1);
	}

	if (index == 0)
	{
		temp_node = *head;
		*head = (*head)->next;
		free(temp_node);
		return (1);
	}

	current_node = *head;
	prev_node = NULL;
	nodes_count = 0;

	while (current_node != NULL)
	{
		if (nodes_count == index)
		{
			prev_node->next = current_node->next;
			free(current_node);
			return (1);
		}

		prev_node = current_node;
		current_node = current_node->next;
		nodes_count++;
	}
	return (-1);
}
