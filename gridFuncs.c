#include "header.h"

SDL_Point **drawGridIso(SDL_Window *win, SDL_Renderer *rend, int *arr, int gridC, int gridR)
{
  int winH, winW;
  SDL_GetWindowSize(win, &winW, &winH);
  int boxsizeV = winH / gridR;
  int boxsizeH = boxsizeV;
  int i, j;
  printf("winH = %d winV = %d bH = %d bV = %d\n", winH, winW, boxsizeH, boxsizeV);
  SDL_Point **grid;
  grid = malloc(sizeof(SDL_Point *) * gridR + 1);
  for (i = 0; i < gridC; i++) {
    grid[i] = malloc(sizeof(SDL_Point) * gridC + 1);
  }

  makeGrid(grid, gridC, gridR, boxsizeV, boxsizeH);

  return(grid);
}

void makeGrid(SDL_Point **grid, int gridC, int gridR, int boxsizeV, int boxsizeH)
{
  int i, j, distH = 400, distV = -80;
  for (i = 0; i < gridR; i++) {
    for (j = 0; j < gridC; j++) {
      grid[i][j].x = distH;
      grid[i][j].y = distV;
      distH += boxsizeH;
    }
    distH = 400;
    distV += boxsizeV;
  }
}

void drawGrid(SDL_Renderer *rend, SDL_Point **grid, int gridC, int gridR)
{
int i, j;
SDL_SetRenderDrawColor(rend, 225, 225, 225, SDL_ALPHA_OPAQUE);
for (i = 0; i < gridR; i++) {
  for (j = 0; j < gridC - 1; j++) {
    SDL_RenderDrawLine(rend, grid[i][j].x, grid[i][j].y, grid[i][j + 1].x, grid[i][j + 1].y);
  }
}
for (i = 0; i < gridC; i++) {
  for (j = 0; j < gridR - 1; j++) {
    SDL_RenderDrawLine(rend, grid[j][i].x, grid[j][i].y, grid[j + 1][i].x, grid[j + 1][i].y);
  }
}
debugGrid(grid, gridC, gridR);
SDL_RenderPresent(rend);
}

void applyAlt(SDL_Point **grid, int gridC, int gridR, int *arr)
{
  int k = 0, i, j;
  int y;
  for (i = 0; i < gridR; i++) {
    for (j = 0; j < gridC; j++) {
      y = grid[i][j].y - arr[k] * 0.6;
      grid[i][j].y = y;
      k++;
    }
  }
}

void isoGrid(SDL_Point **grid, float inc, int gridC, int gridR)
{
 int i, j;
 int x, y;
 for (i = 0; i < gridR; i++) {
   for (j = 0; j < gridC; j++) {
     x = grid[i][j].x * inc - inc * grid[i][j].y;
     y = (1 - inc) * grid[i][j].x + (1 - inc) * grid[i][j].y;
     grid[i][j].x = x;
     grid[i][j].y = y;
   }
 }
}

void rotateGrid(SDL_Point **grid, int gridC, int gridR, float a, int centerX, int centerY)
{
 int i, j;
 int x, y;
 for (i = 0; i < gridR; i++) {
   for (j = 0; j < gridC; j++) {
     x = (grid[i][j].x - centerX) * cos(a) - (grid[i][j].y - centerY) * sin(a) + centerX;
     y = (grid[i][j].x - centerX) * sin(a) + (grid[i][j].y - centerY) * cos(a) + centerY;
     grid[i][j].x = x;
     grid[i][j].y = y;
   }
 }
}
