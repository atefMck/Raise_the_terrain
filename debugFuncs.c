#include "header.h"

void debugGrid(SDL_Point **grid, int gridC, int gridR)
{
  int i, j;
  for (i = 0; i < gridR; i++) {
    for (j = 0; j < gridC; j++) {
      printf("(%d,%d) ", grid[i][j].x, grid[i][j].y);
    }
    printf("\n");
  }
}
