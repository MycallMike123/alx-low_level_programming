#include "lists.h"

/**
 * add_node_end - Adds a new node at the end
 * @head: Pointer to the head of the list
 * @str: The string to be stored in the new node
 * Return: The address of the new element, NULL otherwise
 */

list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new_n, current_node;

	if (str == NULL)
	{
		return (NULL);
	}

	new_n = malloc(sizeof(list_t));
	if (new_n == NULL)
	{
		return (NULL);
	}

	new_n->str = strdup(str);
	if (new_n->str == NULL)
	{
		free(new_n);
		return (NULL);
	}

	new_n->len = strlen(str);
	new_n->next = NULL;

	if (*head == NULL)
	{
		*head = new_n;
	}
	else
	{
		current_node = *head;

		while (current_node->next != NULL)
			current_node = current_node->next;
		current_node->next = new_n;
	}

	return (new_n);
}
