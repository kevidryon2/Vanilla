#include "raylib.h"

#define TAU (PI/2)
#define KILL_MAIN (SIGRTMAX)
#define average(a,b) ((a+b)/2)
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)

//State parameters
void *sp0;
void *sp1;
void *sp2;
void *sp3;
