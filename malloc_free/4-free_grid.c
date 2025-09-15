#include <stdlib.h>
#include "main.h"
/**
 * free_grid - frees a 2D grid previously created by alloc_grid
 * @grid: pointer to the grid (array of int *)
 * @height: number of rows in the grid
 *
 * Return: void
 */
void free_grid(int **grid, int height)
{
int i;
if (grid == NULL || height <= 0)
return;
for (i = 0; i < height; i++)
{
if (grid[i] != NULL)
free(grid[i]);
}
free(grid);
}
