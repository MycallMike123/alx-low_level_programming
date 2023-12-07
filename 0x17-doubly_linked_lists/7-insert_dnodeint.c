#include "lists.h"

/**
 * insert_dnodeint_at_index - Inserts a new node at a given position in a DLL
 * @h: Pointer to a pointer to the head of the DLL
 * @idx: Index of the new node
 * @n: The integer value to be stored in the new node
 * Return: The address of @n, NULL otherwise
 */

dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	unsigned int a;
	dlistint_t *new_n, *hd;

	new_n = NULL;
	if (idx == 0)
		new_n = add_dnodeint(h, n);
	else
	{
		a = 1;
		hd = *h;
		if (hd != NULL)
			while (hd->prev != NULL)
				hd = hd->prev;

		while (hd != NULL)
		{
			if (a == idx)
			{
				if (hd->next == NULL)
					new_n = add_dnodeint_end(h, n);
				else
				{
					new_n = malloc(sizeof(dlistint_t));
					if (new_n != NULL)
					{
						new_n->n = n;
						new_n->next = hd->next;
						new_n->prev = hd;
						hd->next->prev = new_n;
						hd->next = new_n;
					}
				}
				break;
			}
			hd = hd->next;
			a++;
		}
	}
	return (new_n);
}
