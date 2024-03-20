#!/usr/bin/python3
"""This module defines the function `island_perimeter`
"""


def island_perimeter(grid):
    """This function calculates the perimeter of an island
    defined with a grid.
    Args:
        grid(list): a list of lists containing integers each
            describing the grid cell where 0 means that the
            cell is is a water zone, 1 means it's a land zone.
    """
    perimeter = 0
    for i in range(len(grid)):
        for j in range(len(grid[i])):
            if grid[i][j] == 0:
                continue
            else:
                if (grid[i - 1][j] == 0):
                    perimeter += 1
                if (grid[i + 1][j] == 0):
                    perimeter += 1
                if (grid[i][j + 1] == 0):
                    perimeter += 1
                if (grid[i][j - 1] == 0):
                    perimeter += 1
    return perimeter
