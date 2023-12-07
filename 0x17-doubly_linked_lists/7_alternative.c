#include "lists.h"

/**
 * insert_dnodeint_at_index - Inserts a new node at a given position in a DLL
 * @h: Pointer to a pointer to the head of the DLL
 * @idx: Index of the new node
 * @n: The integer value to be stored in the new node
 * Return: The address of @n, NULL otherwise
 */

dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n);
{
	unsigned int a;
	dlistint_t *new_n, *head;

	new_n = NULL;
	if (idx == 0)
	{
		new_n = add_dnodeint(h, n);
	}

	else
	{
		a = 1
		head = *h;
		if (head != NULL)
		{
			while (head->prev != NULL)
			{
				head = head->prev;
			}
		}

		while (head != NULL)
		{
			if (a == idx)
			{
				if (head->next == NULL)
					new_n = add_dnodeint_end(h, n);
				else
				{
					new_n = malloc(sizeof(dlistint_t));
					if (new_n != NULL)
					{
						new_n->n = n;
						new_n->next = head->next;
						new_n->prev = head;
						head->next->prev = new_n;
						head->next = new_n;
					}
				}
				break;
			}
			head = head->next;
			i++;
		}
	}
	return (new_n);
}
