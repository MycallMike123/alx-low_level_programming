#include "hash_tables.h"

/**
 * hash_table_delete - Deletes a hash table
 * @ht: The hash table
 */

void hash_table_delete(hash_table_t *ht)
{
	unsigned long int a;
	hash_node_t *temp, *curr;

	if (ht == NULL)
	{
		return;
	}

	for (a = 0; a < ht->size; a++)
	{
		temp = ht->array[a];

		while (temp != NULL)
		{
			curr = temp;
			temp = temp->next;
			free(curr->key);
			free(curr->value);
			free(curr);
		}
	}

	free(ht->array);
	free(ht);
}
