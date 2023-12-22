#include "hash_tables.h"
#include <string.h>

shash_table_t *shash_table_create(unsigned long int size);
int shash_table_set(shash_table_t *ht, const char *key, const char *value);
char *shash_table_get(const shash_table_t *ht, const char *key);
void shash_table_print(const shash_table_t *ht);
void shash_table_print_rev(const shash_table_t *ht);
void shash_table_delete(shash_table_t *ht);

/**
 * shash_table_create - Creates a sorted hash table
 * @size: The size of the array
 * Return: A pointer to the newly created sorted ht, NULL otherwise
 */

shash_table_t *shash_table_create(unsigned long int size)
{
	unsigned long int a;
	shash_table_t *sh_t = NULL;

	sh_t = malloc(sizeof(shash_table_t));
	if (sh_t == NULL)
	{
		return (NULL);
	}

	sh_t->size = size;
	sh_t->array = malloc(sizeof(shash_node_t *) * size);
	if (sh_t->array == NULL)
	{
		free(sh_t);
		return (NULL);
	}

	for (a = 0; a < size; a++)
	{
		sh_t->array[a] = NULL;
	}

	sh_t->shead = NULL;
	sh_t->stail = NULL;

	return (sh_t);
}

/**
 * shash_table_get - Retrieves a value associated with a key in a sorted ht
 * @ht: The sorted hash table
 * @key: The key
 * Return: The value associated with the key, or NULL if not found
 */

char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int idx;
	shash_node_t *temp;

	if (ht == NULL || key == NULL || *key == '\0')
	{
		return (NULL);
	}

	idx = key_index((const unsigned char *)key, ht->size);

	temp = ht->array[idx];
	while (temp != NULL)
	{
		if (strcmp(temp->key, key) == 0)
		{
			return (temp->value);
		}

		temp = temp->next;
	}

	return (NULL); /* If key is not found */
}

/**
 * shash_table_print_rev - Prints a sorted hash table in reverse order
 * @ht: The sorted hash table
 */

void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *temp;

	if (ht == NULL)
	{
		return;
	}

	temp = ht->stail;
	printf("{");

	while (temp != NULL)
	{
		printf("'%s': '%s'", temp->key, temp->value);
		temp = temp->sprev;
		if (temp != NULL)
			printf(", ");
	}
	printf("}\n");
}

/**
 * shash_table_set - Adds an element to the sorted hash table
 * @ht: The sorted hash table
 * @key: The key
 * @value: The value associated with the key
 * Return: 1 on success, 0 on failure
 */

int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int idx;
	shash_node_t *n_node = NULL, *temp = NULL, *prev = NULL;

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

	n_node = malloc(sizeof(shash_node_t));
	if (n_node == NULL)
		return (0);

	n_node->key = strdup(key);
	n_node->value = strdup(value);
	if (n_node->key == NULL || n_node->value == NULL)
	{
		free(n_node->key);
		free(n_node->value);
		free(n_node);
		return (0);
	}
	temp = ht->shead;
	while (temp != NULL && strcmp(temp->key, key) < 0)
	{
		prev = temp;
		temp = temp->snext;
	}
	n_node->sprev = prev;
	n_node->snext = temp;

	if (prev != NULL)
		prev->snext = n_node;
	else
		ht->shead = n_node;

	if (temp != NULL)
		temp->sprev = n_node;
	else
		ht->stail = n_node;

	n_node->next = ht->array[idx];
	ht->array[idx] = n_node;

	return (1);
}

/**
 * shash_table_print - Prints a sorted hash table
 * @ht: The sorted hash table
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *temp;

	if (ht == NULL)
		return;

	temp = ht->shead;
	printf("{");
	while (temp != NULL)
	{
		printf("'%s': '%s'", temp->key, temp->value);
		temp = temp->snext;

		if (temp != NULL)
			printf(", ");
	}
	printf("}\n");
}

/**
 * shash_table_delete - Deletes a sorted hash table
 * @ht: The sorted hash table
 */
void shash_table_delete(shash_table_t *ht)
{
	shash_node_t *temp, *curr;

	if (ht == NULL)
	{
		return;
	}

	temp = ht->shead;
	while (temp != NULL)
	{
		curr = temp;
		temp = temp->snext;
		free(curr->key);
		free(curr->value);
		free(curr);
	}

	free(ht->array);
	free(ht);
}
