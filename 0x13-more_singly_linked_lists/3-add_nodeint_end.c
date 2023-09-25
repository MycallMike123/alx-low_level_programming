#include "lists.h"

/**
 * add_nodeint_end - adds a new node at the end of a listint_t list
 * @head: A pointer to a pointer to the head of the list
 * @n: An int to be stored in the added node
 * Return: The address of the new element, NULL otherwise
 */

listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *added_node, *current_node;

	added_node = malloc(sizeof(listint_t));
	if (added_node == NULL)
	{
		return (NULL);
	}
	added_node->n = n;
	added_node->next = NULL;

	if (*head == NULL)
	{
		*head = added_node;
		return (added_node);
	}

	current_node = *head;
	while (current_node->next != NULL)
	{
		current_node = current_node->next;
	}

	current_node->next = added_node;

	return (added_node);
}
