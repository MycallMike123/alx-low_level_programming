#include "lists.h"

/**
 * add_nodeint - Adds a new node
 * @head: A pointer to a pointer to the head of the list
 * @n: The integer to be stored in new node
 * Return: The address of the new element, NULL otherwise
 */

listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *added_node = malloc(sizeof(listint_t));

	if (added_node == NULL)
	{
		return (NULL);
	}

	added_node->n = n;
	added_node->next = *head;

	*head = added_node;

	return (added_node);
}
