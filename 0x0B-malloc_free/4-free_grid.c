#include "main.h"
#include <stdlib.h>

/**
 * free_grid - Frees the memory to be allocated to the grid
 * @grid: Pointer to the 2D grid to be freed
 * @height: The height of the grid
 */
void free_grid(int **grid, int height)
{
	int a;

	if (grid == NULL || height <= 0)
	{
		return;
	}

	for (a = 0; a < height; a++)
	{
		free(grid[a]);
	}

	free(grid);
}
