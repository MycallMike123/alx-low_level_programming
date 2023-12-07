#include "lists.h"

/**
 * insert_dnodeint_at_index - Inserts a new node at a given position in a DLL
 * @h: Pointer to a pointer to the head of the DLL
 * @idx: Index where the new node should be added
 * @n: The integer to be stored in the new node
 * Return: The address @n, NULL otherwise
 */

dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *temp = *h, *new_n;

	if (idx == 0)
	{
		return (add_dnodeint(h, n));
	}

	while (idx-- > 1 && temp != NULL)
	{
		temp = temp->next;
	}

	if (temp == NULL)
	{
		return (NULL);
	}

	new_n = add_dnodeint_end(&temp, n);

	return (new_n);
}
