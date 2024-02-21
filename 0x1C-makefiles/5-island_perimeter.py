#!/usr/bin/python3
"""A module t@ defines an island perimeter measuring function"""


def island_perimeter(grid):
    """Calculate the perimeter of the island described in grid"""

    perimeter = 0

    for a in range(len(grid)):
        for b in range(len(grid[0])):
            if grid[a][b] == 1:
                perimeter += 4

                if a > 0 and grid[a - 1][b] == 1:
                    perimeter -= 2
                if b > 0 and grid[a][b - 1] == 1:
                    perimeter -= 2

    return perimeter
