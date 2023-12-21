#include "hash_tables.h"

/**
 * hash_table_print - Prints a hash table
 * @ht: The hash table
 */

void hash_table_print(const hash_table_t *ht)
{
	unsigned long int a;
	int start = 1;
	hash_node_t *temp;

	if (ht == NULL)
	{
		return;
	}

	printf("{");

	for (a = 0; a < ht->size; a++)
	{
		temp = ht->array[a];
		while (temp != NULL)
		{
			if (!start)
			{
				printf(", ");
			}
			printf("'%s': '%s'", temp->key, temp->value);
			start = 0;
			temp = temp->next;
		}
	}

	printf("}\n");
}
