#include "lists.h"

size_t print_listint_safe(const listint_t *head);
size_t print_listint_safe_len(const listint_t *head);

/**
 * print_listint_safe - Prints a listint_t list safely
 * @head: A pointer to the head of the list
 * Return: The number of nodes
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t nodes_count = 0;
	size_t idx = 0;

	nodes_count = print_listint_safe_len(head);
	if (nodes_count == 0)
	{
		for (; head != NULL; nodes_count++)
		{
			printf("[%p] %d\n", (void *)head, head->n);
			head = head->next;
		}
	}
	else
	{
		for (idx = 0; idx < nodes_count; idx++)
		{
			printf("[%p] %d\n", (void *)head, head->n);
			head = head->next;
		}

		printf("-> [%p] %d\n", (void *)head, head->n);
	}

	return (nodes_count);
}

/**
 * print_listint_safe_len - Counts the number of nodes in the list
 * @head: A pointer to the head of the list
 * Return: number of nodes in the list, 0 otherwise
 */

size_t print_listint_safe_len(const listint_t *head)
{
	const listint_t *fast_ptr;
	const listint_t *slow_ptr;
	size_t nodes_count = 1;

	if (head->next == NULL || head == NULL)
	{
		return (0);
	}

	slow_ptr = head->next;
	fast_ptr = (head->next)->next;

	while (fast_ptr)
	{
		if (slow_ptr == fast_ptr)
		{
			slow_ptr = head;
			while (slow_ptr != fast_ptr)
			{
				nodes_count++;
				slow_ptr = slow_ptr->next;
				fast_ptr = fast_ptr->next;
			}
			slow_ptr = slow_ptr->next;

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

