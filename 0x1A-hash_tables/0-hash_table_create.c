#include "hash_tables.h"

/**
 * hash_table_create - Creates a hash table
 * @size: The size of the array
 * Return: A pointer to the newly created hash table, Null otherwise
 */

hash_table_t *hash_table_create(unsigned long int size)
{
	unsigned long int a;
	hash_table_t *hash_t = NULL;

	if (size < 1)
	{
		return (NULL);
	}

	hash_t = malloc(sizeof(hash_table_t));

	if (hash_t == NULL)
	{
		return (NULL);
	}

	hash_t->array = malloc(sizeof(hash_node_t *) * size);

	if (hash_t->array == NULL)
	{
		free(hash_t);
		return (NULL);
	}

	hash_t->size = size;

	for (a = 0; a < size; a++) /* Initialize each pointer in array to NULL */
	{
		hash_t->array[a] = NULL;
	}

	return (hash_t);
}
