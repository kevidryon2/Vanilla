#include "raylib.h"
#include "states.h"
#include <signal.h>
#include "intro.h"
#include "crash.h"

void intro();
void mainmenu();
void segfault();

VanillaState state;
int t = 0;

int main() {
	signal(SIGSEGV, segfault);
	InitWindow(640,480,"Vanilla");
	ToggleFullscreen();
	SetTargetFPS(60);
	switchState(STATE_INTRO);
	while (!WindowShouldClose()) {
		BeginDrawing();
		switch (state) {
			case STATE_INTRO: intro(); break;
		}
		t++;
		EndDrawing();
	}
}
