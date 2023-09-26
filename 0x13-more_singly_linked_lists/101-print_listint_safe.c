#include "lists.h"

/**
 * print_listint_safe - Prints a listint_t linked list safely
 * @head: pointer to the head of the list
 * Return: The number of nodes
 */

size_t print_listint_safe(const listint_t *head)
{
	const listint_t *slow_pointer = head, *fast_pointr = head;
	size_t nodes_count = 0;

	while (fast_pointr != NULL && slow_pointer != NULL)
	{
		printf("[%p] %d\n", (void *)slow_pointer, slow_pointer->n);
		nodes_count++;

		slow_pointer = slow_pointer->next;
		fast_pointr = (fast_pointr->next != NULL) ? fast_pointr->next->next : NULL;
		if (slow_pointer == fast_pointr)
		{
			if (nodes_count == 1)
			{
				printf("[%p] %d\n", (void *)slow_pointer, slow_pointer->n);
				return (nodes_count);
			}

			slow_pointer = head;
			while (slow_pointer != fast_pointr)
			{
				printf("[%p] %d\n", (void *)slow_pointer, slow_pointer->n);
				nodes_count++;
				slow_pointer = slow_pointer->next;
				fast_pointr = fast_pointr->next;
			}
			printf("-> [%p] %d\n", (void *)slow_pointer, slow_pointer->n);
			break;
		}

	}
	return (nodes_count);
}
