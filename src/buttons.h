#include <raylib.h>
#include <math.h>
#include "shared.h"
#include "assets.h"

#pragma once
#define cblend(a,b) (Color){average(a.r,b.r),average(a.g,b.g),average(a.b,b.b),255}
#define lighten(c,a) (Color){min(c.r+a,255),min(c.g+a,255),min(c.b+a,255),255}
#define darken(c,a) lighten(c,-a)

extern int t;

typedef struct {
  Rectangle rec;
  bool rounded;
  char *text;
  Color color;
  Color bordercolor;
  int bordersize;
  void (*callback)();
} Button;
                                                         
bool buttonHovered(Button b) {
  return (GetMouseX()>b.rec.x && GetMouseX()<(b.rec.x+b.rec.width) &&
          GetMouseY()>b.rec.y && GetMouseY()<(b.rec.y+b.rec.height));
}

bool buttonPressed(Button b, MouseButton button) {
  return buttonHovered(b) && IsMouseButtonPressed(button);
}

bool buttonPressedCallback(Button b, MouseButton button) {
  if (buttonPressed(b,button)) {
    if (b.callback) b.callback();
    else {
      printf("Function not implemented.\n");
    }
  }
  return buttonPressed(b,button);
}
          
void drawButton(Button b) {
  if (b.rounded) {
    DrawRectangleRoundedLines(b.rec, 0.3, 100, b.bordersize, b.bordercolor);
    DrawRectangleRounded(b.rec, 0.3, 100, buttonHovered(b)?
                         lighten(b.color, ((sin((float)t/20)+2)*24)):
                         b.color);
  } else {
    DrawRectangleLinesEx(b.rec, b.bordersize, b.bordercolor);
    DrawRectangleRec(b.rec, buttonHovered(b)?
                         lighten(b.color, ((sin((float)t/20)+2)*24)):
                         b.color);
    
  }
  DrawTextEx(normal_regular, b.text, (Vector2){
    b.rec.x+(b.rec.width/2)-MeasureTextEx(normal_regular, b.text, 48, 0).x/2,
    b.rec.y+(b.rec.height/2)-24},
  48, 0, ((b.color.r+b.color.g+b.color.b)/3<128)?WHITE:BLACK);
}

//drawButton + buttonPressedCallback
bool drawButtonCallback(Button b, MouseButton button) {
  drawButton(b);
  return buttonPressedCallback(b, button);
}

