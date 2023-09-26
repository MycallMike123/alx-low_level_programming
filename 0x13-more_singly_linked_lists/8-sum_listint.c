#include "lists.h"

/**
 * sum_listint - Returns the sum of all the data (n)
 * @head: A pointer to the head of the list
 * Return: The sum of all the data, 0 if empty
 */

int sum_listint(listint_t *head)
{
	int added;

	added = 0;
	while (head != NULL)
	{
		added += head->n;
		head = head->next;
	}

	return (added);
}
