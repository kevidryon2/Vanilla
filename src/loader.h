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

int curr_asset = 0;
char *username;

void loadAssets() {
  struct passwd *pw = getpwuid(getuid());
  if (!pw) {
    printf("Can't get PWUID\n");
    kill(getppid(), SIGTERM);
    exit(1);
  }
       
  username = pw->pw_dir;
  printf("%s/.local/share/pictrel/vanilla\n", username);
  
  FILE *fp = fopen(TextFormat("%s/.local/share/pictrel/vanilla/vanilla.krp", username), "r");
  
  if (!fp) {
    printf("Assets file (%s/.local/share/pictrel/vanilla/vanilla.krp) is missing", username);
    perror("");
    kill(getppid(), SIGTERM);
    exit(1);
  }
	
  for (int i=0; i<NUM_ASSETS; i++) {
    loadAsset(i, fp);
    printf("Sending signal to main process\n");
		kill(getppid(), SIGRTMIN);
    printf("Sent signal to main process\n");
	}
	kill(getppid(), SIGRTMIN+1);
}
