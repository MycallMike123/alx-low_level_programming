#include "lists.h"

/**
 * add_dnodeint_end - Adds a new node at the end of a list
 * @head: Pointer to a pointer to the head of the DLL
 * @n: The integer value to be stored in the new node
 *  Return: The address of @n, NULL otherwise
 */

dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *temp, *new_n;

	new_n = malloc(sizeof(dlistint_t));
	if (new_n == NULL)
	{
		return (NULL);
	}

	new_n->n = n;
	new_n->next = NULL;

	if (*head == NULL)
	{
		new_n->prev = NULL;
		*head = new_n;
		return (new_n);
	}

	temp = *head;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}

	new_n->prev = temp;
	temp->next = new_n;

	return (new_n);
}
