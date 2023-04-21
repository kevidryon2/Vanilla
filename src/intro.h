#include "raylib.h"
#include "states.h"
#include <math.h>
#include <unistd.h>
#include <signal.h>
#include "loader.h"
#include "shared.h"
#include "assets.h"

#pragma once

extern VanillaState state;
extern int t;
extern int curr_asset;

#define PICTREL_LOGO_DUR 550

bool loading = true;

void loadAssets();

void nextAsset() {
	curr_asset++;
}

void lastAsset() {
	loading = false;
}

void introinit() {
  
	if (fork()) {
		signal(ASSET_LOADED, nextAsset);
		signal(FINISHED_LOADING, lastAsset);
	} else {
		loadAssets();
		kill(getpid(), SIGTERM);
	}
}

void intro() {
	ClearBackground((Color){
						(sin((float)t/300)+1)*16,
						(sin((float)t/300)+1)*16,
						(sin((float)t/300)+1)*16,
						255
					});
	if (true) {
    DrawTexture(pictrelLogo, GetRenderWidth()/2-250, GetRenderHeight()/2-75, (Color){
						255,
						255,
						255,
						/*sin((t*PI)/PICTREL_LOGO_DUR)**/255
    });
	}
	DrawText(TextFormat("%d assets loaded", curr_asset), 0, 0, 20, WHITE);
}
