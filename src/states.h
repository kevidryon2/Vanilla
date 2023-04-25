#pragma once

typedef enum {
  STATE_INTRO,
  STATE_MAINMENU,
  STATE_EDITOR,
  STATE_MAX,
} VanillaState;

extern VanillaState state;
extern int curr_asset;
extern int main();

void switchState(VanillaState st) {
	state = st;
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
	}
}
