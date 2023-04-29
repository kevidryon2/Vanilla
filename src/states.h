#pragma once

typedef enum {
  STATE_INTRO,
  STATE_MAINMENU,
  STATE_EDITOR,
  STATE_SELECT_EDITOR,
  STATE_CODE_MENU,
  STATE_CODE_EDITOR,
  STATE_DATA_MENU,
  STATE_DATA_EDITOR,
  STATE_DRAW_MENU,
  STATE_DRAW_EDITOR,
  STATE_SOUND_MENU,
  STATE_SOUND_EDITOR,
  STATE_MUSIC_EDITOR,
  STATE_SHAPE_MENU,
  STATE_SHAPE_EDITOR,
  STATE_PLAY,
  STATE_MAX,
} VanillaState;

extern VanillaState state;
extern int curr_asset;
extern int main();

void switchState(VanillaState st) {
	state = st;
  printf("Switching to state %d\n", st);
  if (state>=STATE_MAX) {
    printf("Error: Tried to switch to invalid state %d! ", st);
    switch (rand()%4) {
    case 0: printf("Nope!\n"); break;
    case 1: printf("Aargh!\n"); break;
    case 2: printf("Oh spippety snappety snop!\n"); break;
    case 3: if (!rand()%16) printf("f**k this s**t i'm out\n");
            else {
              printf("89043iooo{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}\n\n\n\n\n\r\r\r\r\r\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
              for (int i=0; i<rand()%655360; i++) {
                putchar(rand());
              }
              printf("what a wonderful fantastic grand marvelous terrific tremendous wondroud howling rattling extrordinary fabulous impressive wondrous spectacular remarkable astounding interesting fascinating rain of random characters");
            }
            break;
    }
    exit(127);
  }
	switch (state) {
    case STATE_INTRO: introinit(); break;
    case STATE_MAINMENU: mainmenuinit(); break;
    case STATE_SELECT_EDITOR: selectinit(); break;
    case STATE_CODE_MENU: code(); break;
    case STATE_DATA_MENU: data(); break;
    case STATE_DRAW_MENU: draw(); break;
    case STATE_SOUND_MENU: sound(); break;
    case STATE_SHAPE_MENU: shape(); break;
    case STATE_PLAY: execgame(); break;
	}
}
