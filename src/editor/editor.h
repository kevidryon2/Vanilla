#include "raylib.h"
#include "../states.h"
#include "../elements.h"
#include "../assets.h"
#include "../shared.h"
#include "../buttons.h"
#include "code.h"
#include "data.h"
#include "draw.h"
#include "sound.h"
#include "shape.h"
#include "play/play.h"

#define TILESIZE 64
#define TILEWIDTH (GetRenderWidth()/TILESIZE)

#define TILEMOUSEX ((int)(GetMouseX()/(TILESIZE*zoom)))
#define TILEMOUSEY ((int)(GetMouseY()/(TILESIZE*zoom)))

#define HOVEREDTILE (grid[TILEMOUSEX+TILEMOUSEY*256])

extern int t;

int grid[256*256];

Vector2 mousepos;

float zoom = 1;
int sx = 0;
int sy = 0;


void editor() {
  ClearBackground(BLACK);
  printf("%d\n", (int)((float)TILEWIDTH/zoom)+sx+1);
  
  //Draw grid
  for (int x=max(sx,0); x<min(((int)((float)TILEWIDTH/zoom)+sx+1),256); x++) {
    for (int y=max(sy,0); y<min(((int)((float)TILEWIDTH/zoom)+sy+1),256); y++) {
      DrawRectangleLinesEx((Rectangle){x*TILESIZE*zoom, y*TILESIZE*zoom,
                                        TILESIZE*zoom+1, TILESIZE*zoom+1}, 1, DARKGRAY);
      DrawRectangle(x*TILESIZE*zoom, y*TILESIZE*zoom, TILESIZE*zoom, TILESIZE*zoom,
                    grid[x+y*256]<6?elementconstants[grid[x+y*256]].color:PINK);
    }
  }
  
  //Draw hovered cell
  DrawRectangle(
    TILEMOUSEX * (TILESIZE*zoom),
    TILEMOUSEY * (TILESIZE*zoom),
    TILESIZE*zoom, TILESIZE*zoom,
    (Color){255,255,255,64+(sin((float)t/30)+1)*32}
  );
                
  DrawTextEx(mono_medium, TextFormat("Zoom: %f\nSX: %d\nSY: %d\n", zoom, sx, sy), (Vector2){0,0}, 48, 0, WHITE);              
  
  if (zoom<0.01) zoom += 0.1;
  if (IsKeyPressed(KEY_KP_ADD)) zoom += 0.1;
  if (IsKeyPressed(KEY_KP_SUBTRACT)) zoom -= 0.1;
  if (zoom<0.01) zoom += 0.1;
  
  if (IsMouseButtonPressed(MOUSE_RIGHT_BUTTON)) {
    if (HOVEREDTILE == EMPTY_ELEMENT) switchState(STATE_SELECT_EDITOR);
  }
}

void selecteditor() {
  DrawRectangleV(mousepos, (Vector2){424,150}, LIGHTGRAY);
  
  
  
  for (int i=1; i<NUM_ELEMENT_TYPES; i++) {
    drawButtonCallback((Button){
                       (Rectangle){
                          mousepos.x-44+i*64,
                          mousepos.y+20,
                          64, 64
                       },
                       false,
                       "a",
                       elementconstants[i].color,
                       BLACK,
                       0,
                       elementconstants[i].openfunction
    }, MOUSE_BUTTON_LEFT);
  }
  
  if ((GetMouseX()<mousepos.x || GetMouseX()>mousepos.x+500 ||
      GetMouseY()<mousepos.y || GetMouseY()>mousepos.y+150) &&
      IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) switchState(STATE_EDITOR);
}

void selectinit() {
  mousepos = GetMousePosition();
}
