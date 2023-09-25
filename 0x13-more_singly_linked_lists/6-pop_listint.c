#include "lists.h"

/**
 *  pop_listint - Deletes the head node
 *  @head: A pointer to a pointer to the head of the list
 *  Return: The data (n) of the deleted head node
 */

int pop_listint(listint_t **head)
{
	int data_returned;

	listint_t *temp_node;

	if (head == NULL || *head == NULL)
	{
		return (0);
	}

	temp_node = *head;
	data_returned = temp_node->n;

	*head = temp_node->next;
	free(temp_node);

	return (data_returned);
}
