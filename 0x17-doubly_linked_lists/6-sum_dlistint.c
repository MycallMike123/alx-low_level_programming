#include "lists.h"

/**
 * sum_dlistint - Returns the sum of all the data (n) in a DLL
 * @head: Pointer to the head of the DLL
 * Return: Sum of all the data, 0 otherwise
 */

int sum_dlistint(dlistint_t *head)
{
	int sum;
	dlistint_t *current = head;

	sum = 0;
	while (current != NULL)
	{
		sum = sum + current->n;
		current = current->next;
	}

	return (sum);
}
