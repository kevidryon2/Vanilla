#include "raylib.h"
#include <stdlib.h>
#include "shared.h"

#define NUM_ELEMENT_TYPES 7

typedef enum {
  EMPTY_ELEMENT,
  CODE_ELEMENT,
  DATA_ELEMENT,
  GRAPHICS_ELEMENT,
  SOUND_ELEMENT,
  SHAPE_ELEMENT,
} ElementType;

extern Vector2 mousepos;

void opencodeeditor()   {sp0=&mousepos;switchState(STATE_CODE_MENU);}
void opendataeditor()   {sp0=&mousepos;switchState(STATE_DATA_MENU);}
void opendraweditor()   {sp0=&mousepos;switchState(STATE_DRAW_MENU);}
void opensoundeditor()  {sp0=&mousepos;switchState(STATE_SOUND_MENU);}
void openshapeeditor()  {sp0=&mousepos;switchState(STATE_SHAPE_MENU);}
void execgame()         {switchState(STATE_PLAY);}

const struct {
  Color color;
  void (*openfunction)();
} elementconstants[NUM_ELEMENT_TYPES] = {
  {BLANK,   NULL          },    //No element
  {GOLD,    opencodeeditor},    //Code
  {ORANGE,  opendataeditor},    //Data
  {RED,     opendraweditor},    //Graphics
  {VIOLET,  opensoundeditor},   //Sound
  {BLUE,    openshapeeditor},   //Shape
  {GREEN,   execgame}           //Play
};

