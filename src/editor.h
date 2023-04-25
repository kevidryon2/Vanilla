#include "raylib.h"
#include "states.h"
#include "elements.h"
#include "assets.h"
#include "shared.h"

#define TILESIZE 64
#define TILEWIDTH (GetRenderWidth()/TILESIZE)

int grid[256*256];

float zoom = 1;
int sx = 0;
int sy = 0;

void editor() {
  ClearBackground(BLACK);
  printf("%d\n", (int)((float)TILEWIDTH/zoom)+sx+1);
  for (int x=max(sx,0); x<min(((int)((float)TILEWIDTH/zoom)+sx+1),256); x++) {
    for (int y=max(sy,0); y<min(((int)((float)TILEWIDTH/zoom)+sy+1),256); y++) {
      DrawRectangleLinesEx((Rectangle){x*TILESIZE*zoom, y*TILESIZE*zoom, TILESIZE*zoom+1, TILESIZE*zoom+1}, 1, DARKGRAY);
      DrawRectangle(x*TILESIZE*zoom, y*TILESIZE*zoom, TILESIZE*zoom, TILESIZE*zoom, grid[x+y*256]<6?element_colors[grid[x+y*256]]:PINK);
    }
  }
                
  DrawTextEx(mono_medium, TextFormat("Zoom: %f\nSX: %d\nSY: %d\n", zoom, sx, sy), (Vector2){0,0}, 48, 0, WHITE);              
  
  if (zoom<0.01) zoom += 0.1;
  if (IsKeyPressed(KEY_KP_ADD)) zoom += 0.1;
  if (IsKeyPressed(KEY_KP_SUBTRACT)) zoom -= 0.1;
}
