#include "lists.h"

size_t print_listint_safe(const listint_t *head);
void print_listint_safe_recursive(const listint_t *head, size_t *nodes_count);
size_t print_listint_safe_len(const listint_t *head);

/**
 * print_listint_safe - Prints a listint_t list safely
 * @head: A pointer to the head of the list
 * Return: The number of nodes
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t nodes_count = 0;

	print_listint_safe_recursive(head, &nodes_count);

	return (nodes_count);
}

/**
 * print_listint_safe_recursive - Recursive function to print
 * @head: A pointer to the head of the list
 * @nodes_count: Pointer to the count of nodes
 */

void print_listint_safe_recursive(const listint_t *head, size_t *nodes_count)
{
	if (head == NULL)
	{
		return;
	}

	printf("[%p] %d\n", (void *)head, head->n);
	(*nodes_count)++;

	if (head->next != NULL && *nodes_count < print_listint_safe_len(head))
	{
		print_listint_safe_recursive(head->next, nodes_count);
	}

	else if (head->next != NULL)
	{
		printf("-> [%p] %d\n", (void *)head->next, head->next->n);
	}
}

/**
 * print_listint_safe_len - Counts the number of nodes in the list
 * @head: A pointer to the head of the list
 * Return: number of nodes in the list, 0 otherwise
 */

size_t print_listint_safe_len(const listint_t *head)
{
	const listint_t *fast_ptr, *slow_ptr;
	size_t nodes_count = 1;

	if (head == NULL || head->next == NULL)
	{
		return (0);
	}

	slow_ptr = head->next;
	fast_ptr = (head->next)->next;

	while (fast_ptr)
	{
		if (slow_ptr == fast_ptr)
		{
			slow_ptr = (listint_t *)head;
			while (slow_ptr != fast_ptr)
			{
				nodes_count++;
				slow_ptr = slow_ptr->next;
			}
			return (nodes_count);

		}

		slow_ptr = slow_ptr->next;
		fast_ptr = (fast_ptr->next)->next;
	}

	return (0);
}

