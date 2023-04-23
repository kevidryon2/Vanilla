#include <signal.h>
#include <unistd.h>
#include "shared.h"
#include "raylib.h"
#include "assets.h"
#include "buttons.h"

void mainMenu() {
  ClearBackground((Color){32,0,32,255});
  DrawTexture(vanillaLogo,
              GetRenderWidth()/2-(vanillaLogo.width/2),
              150,
              WHITE);
}

void mainmenuinit() {
}
