#include "raylib.h"

#define NUM_ELEMENT_TYPES 7

typedef enum {
  EMPTY_ELEMENT,
  CODE_ELEMENT,
  DATA_ELEMENT,
  GRAPHICS_ELEMENT,
  SOUND_ELEMENT,
  SHAPE_ELEMENT,
} ElementType;

const Color element_colors[NUM_ELEMENT_TYPES] = {
  BLANK,  //No element
  GOLD,   //Code
  ORANGE, //Data
  RED,    //Graphics
  VIOLET, //Sound
  BLUE,   //Shape
  GREEN   //Play
};
