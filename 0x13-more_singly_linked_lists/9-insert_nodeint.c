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
	unsigned int a;
	listint_t *added_node, *current_node;

	if (head == NULL)
	{
		return (NULL);
	}

	added_node = malloc(sizeof(listint_t));
	if (added_node == NULL)
	{
		return (NULL);
	}

	added_node->n = n;

	if (idx == 0 || *head == NULL)
	{
		added_node->next = *head;
		*head = added_node;
		return (added_node);
	}

	current_node = *head;
	for (a = 0; a < idx - 1 && current_node->next != NULL; a++)
	{
		current_node = current_node->next;
	}

	if (current_node == NULL)
	{
		free(added_node);
		return (NULL);
	}

	added_node->next = current_node->next;
	current_node->next = added_node;

	return (added_node);
}
