#include "lists.h"

/**
 * insert_nodeint_at_index - Inserts a new node
 * @head: A pointer to a pointer to the head of the list
 * @idx: The index where new node is added
 * @n: The integer stored in the added node
 * Return: The address of the new node, NULL otherwise
 */

listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	unsigned int nodes_count = 0;
	listint_t *added_node, *current_node, prev_node;

	if (head == NULL)
	{
		return (NULL);
	}

	added_node = malloc(sizeof(listint_t));
	if (added_node == NULL)
		return (NULL);

	added_node->n = n;
	current_node = *head;
	prev_node = NULL;

	if (idx == 0)
	{
		added_node->next = current_node;
		*head = added_node;
		return (added_node);
	}

	while (current_node != NULL && nodes_count < idx)
	{
		prev_node = current_node;
		nodes_count++;
	}

	if (nodes_count < idx)
	{
		free(added_node);
		return (NULL);
	}

	added_node->next = current_node;
	prev_node->next = added_node;

	return (added_node);
}
