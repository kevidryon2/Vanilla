#include "raylib.h"
#include "../shared.h"
#include "../assets.h"
#include "../buttons.h"
//TODO write this and data and every unwritten state

struct {
  bool used;
  char filename[16];
  char data[65536];
} codefiles[256];

int ox, oy;

void code() {
  ClearBackground((Color){32,32,32,255});
  DrawTextEx(normal_regular, "Code Editor", (Vector2){5, 0}, 72, 0, WHITE);
  oy = (int)(*(Vector2*)sp0).y/TILESIZE;
  ox = (int)(*(Vector2*)sp0).x/TILESIZE;

  drawButtonCallback((Button){
    (Rectangle){300,5,320,64}
  }, MouseButton button)
  
}
