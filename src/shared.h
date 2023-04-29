#include "raylib.h"

#define TAU (PI/2)
#define KILL_MAIN (SIGRTMAX)
#define average(a,b) ((a+b)/2)
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define TILESIZE 64
#define TILEWIDTH (GetRenderWidth()/TILESIZE)
#define TILEMOUSEX ((int)(GetMouseX()/(TILESIZE*zoom)))
#define TILEMOUSEY ((int)(GetMouseY()/(TILESIZE*zoom)))
#define HOVEREDTILE (grid[TILEMOUSEX+TILEMOUSEY*256])

//State parameters
void *sp0;
void *sp1;
void *sp2;
void *sp3;
