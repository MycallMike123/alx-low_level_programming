#include <stdlib.h>
#include <string.h>
#include "dog.h"

/**
 * init_dog - initializes a variable
 * @d: pointer to an instance of the struct dog
 * @name: name of the var to initialize
 * @age: age to initialize
 * @owner: The owner to init
 */
void init_dog(struct dog *d, char *name, float age, char *owner)
{
	if (d == NULL)
	{
		return;
	}

	d->name = malloc(1 + strlen(name));
	d->owner = malloc(1 + strlen(owner));

	if (d->owner == NULL || d->name == NULL)
	{
		exit(EXIT_FAILURE);
	}
	strcpy(d->name, name);
	d->age = age;
	strcpy(d->owner, owner);
}
