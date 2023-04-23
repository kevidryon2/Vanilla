#include <stdbool.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>
#include <errno.h>
#include "assets.h"
#include <pwd.h>

#pragma once

#define ASSET_LOADED SIGRTMIN
#define FINISHED_LOADING (SIGRTMIN+1)
#define SWITCH_TO_CHILD (SIGRTMIN+2)

int curr_asset = 0;
char *username;

FILE *loadAssetFile() {
  struct passwd *pw = getpwuid(getuid());
  if (!pw) {
    printf("Can't get PWUID\n");
    kill(getppid(), SIGTERM);
    exit(1);
  }
  username = pw->pw_dir;
  
  //printf("%s/.local/share/pictrel/vanilla\n", username);
  return fopen(TextFormat("%s/.local/share/pictrel/vanilla/vanilla.krp", username), "r");
}

void loadAssets() {
  FILE *fp = loadAssetFile();
  
  if (!fp) {
    printf("Assets file (%s/.local/share/pictrel/vanilla/vanilla.krp) is missing", username);
    perror("");
    exit(1);
  }
	
  for (int i=0; i<NUM_ASSETS; i++) {
    loadAsset(i, fp);
	}
}
