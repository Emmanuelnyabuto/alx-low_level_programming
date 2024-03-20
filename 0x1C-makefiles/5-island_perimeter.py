#!/usr/bin/python3
"""
Function that returns the perimeter of an island described in a grid.

Args:
    grid: list of list of integers where 0 represents water and 1 represents land.

Returns:
    int: the perimeter of the island.

Raises:
    ValueError: if the grid is not rectangular or if it's not completely surrounded by water.

"""
def island_perimeter(grid):
    # Check if the grid is rectangular and completely surrounded by water
    if not all(len(row) == len(grid[0]) for row in grid) or grid[0][0] != 0 or grid[-1][-1] != 0:
        raise ValueError("The grid is not rectangular or not completely surrounded by water.")

    perimeter = 0
    for i, row in enumerate(grid):
        for j, cell in enumerate(row):
            if cell == 1:  # land cell
                perimeter += 4
                if i > 0 and grid[i-1][j] == 1:
                    perimeter -= 2
                if j > 0 and grid[i][j-1] == 1:
                    perimeter -= 2
    return perimeter
