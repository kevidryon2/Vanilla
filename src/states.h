#pragma once

typedef enum {
  STATE_INTRO,
  STATE_MAINMENU
} VanillaState;

extern VanillaState state;
extern int curr_asset;

void switchState(VanillaState st) {
	state = st;
	switch (state) {
    case STATE_INTRO: introinit(); break;
    case STATE_MAINMENU: mainmenuinit(); break;
	}
}
