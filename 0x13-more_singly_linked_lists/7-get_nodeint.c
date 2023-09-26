#include "lists.h"

/**
 * get_nodeint_at_index - Returns the nth node
 * @head: A pointer to the head of the list
 * @index: The index of the node
 * Return: A pointer to the nth node, NULL otherwise
 */

listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int nodes_count;

	nodes_count = 0;
	while (head != NULL)
	{
		if (nodes_count == 0)
		{
			return (head);
		}

		head = head->next;
		nodes_count++;
	}

	return (NULL);
}
