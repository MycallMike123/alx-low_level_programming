#include "lists.h"

/**
 * add_dnodeint - Adds a new node at the beginning of the DLL
 * @head: Pointer to a pointer to the head of the DLL
 * @n: The integer value to be stored in the new node
 * Return: The address of the new element, NULL otherwise
 */

dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *new_n;

	new_n = malloc(sizeof(dlistint_t));
	if (new_n == NULL)
	{
		return (NULL);
	}

	new_n->n = n;
	new_n->prev = NULL;
	new_n->next = *head;

	if (*head != NULL)
	{
		(*head)->prev = new_n;
	}
	*head = new_n;

	return (new_n);
}
