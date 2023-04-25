#include "raylib.h"
#include "states.h"
#include <math.h>
#include <unistd.h>
#include <signal.h>
#include "loader.h"
#include "shared.h"
#include "assets.h"
#include "mainmenu.h"

#pragma once
#define PICTREL_LOGO_DUR 300

extern VanillaState state;
extern int t;
extern int curr_asset;

void introinit() {
}

void intro() {
	ClearBackground((Color){
						(sin((float)t/(PICTREL_LOGO_DUR))+1)*16,
						(sin((float)t/(PICTREL_LOGO_DUR))+1)*16,
						(sin((float)t/(PICTREL_LOGO_DUR))+1)*16,
						255
					});
	if (t<PICTREL_LOGO_DUR) {
    DrawTexture(pictrelLogo, GetRenderWidth()/2-500, GetRenderHeight()/2-150, (Color){
						255,
						255,
						255,
						sin((t*PI)/PICTREL_LOGO_DUR)*255
    });
	}
               
#ifdef linux
  if (IsKeyPressed(KEY_Q)) t = PICTREL_LOGO_DUR;
#endif
               
  if (t == PICTREL_LOGO_DUR) {
    switchState(STATE_MAINMENU);
  }
}
