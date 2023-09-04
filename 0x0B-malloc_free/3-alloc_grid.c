#include "main.h"
#include <stdlib.h>

/**
 * alloc_grid - Allocates a 2 dimensional grid
 * @width: The width of the grid
 * @height: The height of the grid
 * Return: A pointer to the grid, NULL otherwise
 */

int **alloc_grid(int width, int height)
{
	int a, b;
	int **grid;

	if (width <= 0 || height <= 0)
	{
		return (NULL);
	}

	grid = malloc(height * sizeof(int *));

	if (grid == NULL)
	{
		return (NULL);
	}

	for (a = 0; a < height; a++)
	{
		grid[a] = malloc(width * sizeof(int));
		if (grid[a] == NULL)
		{
			for (b = 0; b < a; b++)
			{
				free(grid[b]);
			}
			free(grid);
			return (NULL);
		}

		for (b = 0; b < width; b++)
		{
			grid[a][b] = 0;
		}

	}
	return (grid);
}
