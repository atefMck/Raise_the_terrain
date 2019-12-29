#ifndef _HEADER_
#define _HEADER_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_image.h>
#include <math.h>

#define POINTS_COUNT 5

int *fileHandle(char *path);

void drawGrid(SDL_Renderer *rend, SDL_Point **grid, int gridC, int gridR);
void makeGrid(SDL_Point **grid, int gridC, int gridR, int boxsizeV, int boxsizeH);
void rotateGrid(SDL_Point **grid, int gridC, int gridR, float a, int centerX, int centerY);
void isoGrid(SDL_Point **grid, float inc, int gridC, int gridR);
SDL_Point **drawGridIso(SDL_Window *win, SDL_Renderer *rend, int *arr, int gridC, int gridR);
void applyAlt(SDL_Point **grid, int gridC, int gridR, int *arr);

void debugGrid(SDL_Point **grid, int gridC, int gridR);

#endif
