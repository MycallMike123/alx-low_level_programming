#include "hash_tables.h"
#include <string.h>

/**
 * hash_table_set - Adds an element to the hash table
 * @ht: The hash table
 * @key: The key
 * @value: The value associated with the key
 * Return: 1 on success, 0 failure
 */

int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int idx;
	hash_node_t *temp = NULL, *n_node = NULL;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	idx = key_index((const unsigned char *)key, ht->size);

	temp = ht->array[idx];
	while (temp != NULL)
	{
		if (strcmp(temp->key, key) == 0)
		{
			free(temp->value);
			temp->value = strdup(value);
			if (temp->value == NULL)
				return (0);
			return (1);
		}
		temp = temp->next;
	}

	n_node = malloc(sizeof(hash_node_t));
	if (n_node == NULL)
		return (0);

	n_node->key = strdup(key);
	n_node->value = strdup(value);
	if (n_node->key == NULL || n_node->value == NULL)
	{
		free(n_node->value);
		free(n_node->key);
		free(n_node);
		return (0);
	}
	n_node->next = ht->array[idx];
	ht->array[idx] = n_node;

	return (1);
}
