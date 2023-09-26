#include "lists.h"

/**
 * reverse_listint - Reverses a linked list
 * @head: A pointer to a pointer to the head of the list
 * Return: A pointer to the reversed first node
 */

listint_t *reverse_listint(listint_t **head)
{
	listint_t *prev_node = NULL, *next = NULL, *current_node = *head;

	while (current_node != NULL)
	{
		next = current_node->next;
		current_node->next = prev_node;

		prev_node = current_node;
		current_node = next;
	}

	*head = prev_node;

	return (*head);
}
