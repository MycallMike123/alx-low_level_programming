#include <stdio.h>
#include "dog.h"

/**
 * print_dog - prints details of a struct dog
 * @d: pointer to @struct dog to print
 */

void print_dog(struct dog *d)
{
	if (d == NULL)
	{
		return;
	}

	printf("Name: %s\n", (d->name != NULL) ? d->name : "(nil)");
	printf("Owner: %s\n", (d->owner != NULL) ? d->owner : "(nil)");
	printf("Age: %.6f\n", d->age);
}
