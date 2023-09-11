#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "dog.h"

/**
 * new_dog - creates a new dog_t
 * @name: name of the dog
 * @age: the dog's age
 * @owner: the dog's owner
 * Return: pointer to the newly created dog_t, NULL otherwise
 */

dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *new_dog_t;

	new_dog_t = malloc(sizeof(dog_t));

	if (new_dog_t == NULL)
		return (NULL);

	new_dog_t->name = malloc(strlen(name) + 1);
	new_dog_t->owner = malloc(strlen(owner) + 1);

	if (new_dog_t->owner == NULL || new_dog_t->name == NULL)
	{
		free(new_dog_t->name);
		free(new_dog_t->owner);
		free(new_dog_t);
		return (NULL);
	}
	strcpy(new_dog_t->name, name);
	new_dog_t->age = age;
	strcpy(new_dog_t->owner, owner);

	return (new_dog_t);
}
