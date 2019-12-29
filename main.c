#include "header.h"

int main(int argc, char const *argv[])
{

  //Initializing SDL
  if(SDL_Init(SDL_INIT_VIDEO) < 0)
  {
    printf("Failed to intialize SDL %s\n", SDL_GetError());
    return(1);
  }
  //Creating a window.
  SDL_Window *win = SDL_CreateWindow("Isometric", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 0);
  if (!win)
  {
    printf("Failed to create window %s\n", SDL_GetError());
    SDL_Quit();
    return(1);
  }

  //Creating a renderer.
  Uint32 render_flags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;
  SDL_Renderer *rend= SDL_CreateRenderer(win, -1, render_flags);
  if (!rend) {
    printf("Failed to create renderer %s\n", SDL_GetError());
    SDL_DestroyWindow(win);
    SDL_Quit();
    return(1);
  }
  SDL_SetRenderDrawColor(rend, 225, 225, 225, SDL_ALPHA_OPAQUE);

  int *rand;
  rand = fileHandle(argv[1]);
  int gridC = 8;
  int gridR = 8;
  float inc = 0.7;
  int angle;
  float a;
  SDL_Point **grid;
  grid = drawGridIso(win, rend, rand, gridC, gridR);
  isoGrid(grid, inc, gridC, gridR);
  applyAlt(grid, gridC, gridR, rand);
  int centerX = (grid[gridR - 1][gridC - 1].x + grid[0][0].x) / 2;
  int centerY = (grid[gridR - 1][gridC - 1].y + grid[0][0].y) / 2;
  drawGrid(rend, grid, gridC, gridR);
  printf("(%d,%d)\n", centerX, centerY);
  SDL_Event e;

  while (1) {
    if (SDL_PollEvent(&e) != 0) {
      if (e.type == SDL_QUIT) {
        break;
      }
      if (e.key.keysym.sym == SDLK_RIGHT) {
        angle += 1;
        a = angle * M_PI / 180;
        SDL_SetRenderDrawColor(rend, 0, 0, 0, SDL_ALPHA_OPAQUE);
        SDL_RenderClear(rend);
        rotateGrid(grid, gridC, gridR, angle, centerX, centerY);
        drawGrid(rend, grid, gridC, gridR);
      }
      else if (e.key.keysym.sym == SDLK_LEFT)
      {
        angle -= 1;
        a = angle * M_PI / 180;
        SDL_SetRenderDrawColor(rend, 0, 0, 0, SDL_ALPHA_OPAQUE);
        SDL_RenderClear(rend);
        rotateGrid(grid, gridC, gridR, angle, centerX, centerY);
        drawGrid(rend, grid, gridC, gridR);
      }
    }
    SDL_Delay(1000/60);
  }

  SDL_DestroyRenderer(rend);
  SDL_DestroyWindow(win);
  SDL_Quit();
}
