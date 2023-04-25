#include <signal.h>
#include <unistd.h>
#include "shared.h"
#include "raylib.h"
#include "assets.h"
#include "buttons.h"
#include "states.h"

#pragma once

void openeditor() {
  switchState(STATE_EDITOR);
}

void mainMenu() {
  ClearBackground((Color){32,0,32,255});
  DrawTexture(vanillaLogo,
              GetRenderWidth()/2-(vanillaLogo.width/2),
              150,
              WHITE);
  drawButtonCallback((Button){
                        (Rectangle){
                          GetRenderWidth()/2-(vanillaLogo.width/2),
                          GetRenderHeight()/2-72,
                          256,
                          72
                        },
                        "Editor",
                        LIGHTGRAY,
                        openeditor
                      }, MOUSE_BUTTON_LEFT);
  drawButtonCallback((Button){
                        (Rectangle){
                          GetRenderWidth()/2+40,
                          GetRenderHeight()/2-72,
                          256,
                          72
                        },
                        "Quit",
                        LIGHTGRAY,
                        exit
                      }, MOUSE_BUTTON_LEFT);
}

void mainmenuinit() {
}
