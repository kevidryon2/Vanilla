#include "raylib.h"
#include "states.h"
#include <signal.h>
#include "intro.h"
#include "crash.h"
#include "editor/editor.h"

VanillaState state;
int t = 0;

int main() {
	InitWindow(640,480,"Vanilla");
	loadAssets();
	ToggleFullscreen();
	SetTargetFPS(60);
	switchState(STATE_INTRO);
	while (!WindowShouldClose()) {
		BeginDrawing();
		switch (state) {
			case STATE_INTRO: intro(); break;
			case STATE_MAINMENU: mainMenu(); break;
			case STATE_EDITOR: editor(); break;
			case STATE_SELECT_EDITOR: selecteditor(); break;
			case STATE_CODE_MENU: code(); break;
			case STATE_DATA_MENU: data(); break;
			case STATE_DRAW_MENU: draw(); break;
			case STATE_SOUND_MENU: sound(); break;
			case STATE_SHAPE_MENU: shape(); break;
			case STATE_PLAY: execgame(); break;
		}
		t++;
		EndDrawing();
	}
}
