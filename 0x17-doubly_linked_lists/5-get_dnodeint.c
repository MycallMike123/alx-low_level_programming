#include "lists.h"

/**
 * get_dnodeint_at_index - Returns the nth node of a DLL
 * @head: Pointer to the head of the DLL
 * @index: Index of the node
 * Return: Pointer to the nth node, NULL otherwise
 */

dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int a;
	dlistint_t *current = head;

	for (a = 0; current != NULL && a < index; a++)
	{
		current = current->next;
	}

	if (a == index && current != NULL)
	{
		return (current);
	}

	return (NULL);
}
