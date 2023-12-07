#include "lists.h"

/**
 * delete_dnodeint_at_index - Deletes the node at a given position
 * @head: Pointer to a pointer to the head of the DLL
 * @index: Index of the node that should be deleted
 * Return: 1 Sucess, -1 otherwise
 */

int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	unsigned int a;
	dlistint_t *curr, *temp;

	if (*head == NULL)
		return (-1);

	curr = *head;

	if (index == 0)
	{
		*head = curr->next;
		if (*head != NULL)
			(*head)->prev = NULL;
		free(curr);
		return (1);
	}
	for (a = 0; a < index && curr != NULL; a++)
		curr = curr->next;

	if (curr == NULL)
		return (-1);

	temp = curr->prev;
	temp->next = curr->next;

	if (curr->next != NULL)
		curr->next->prev = temp;

	free(curr);

	return (1);
}
