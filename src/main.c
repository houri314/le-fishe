#include <stdlib.h>
#include <time.h>
#include <raylib.h>

#include "misc.h"
#include "splash.h"
#include "game.h"
#include "player.h"

static const uint8_t minBGM = 0;
static const uint8_t maxBGM = 1;

void loadMusic(Music* m);

int main() {
	initGame();
	Music bgm;

state_drawing_splash:
	while (!WindowShouldClose()) {
		int k;
		drawSplash();
		k = GetKeyPressed();
		if (k==KEY_Z||k==KEY_ENTER||k==KEY_SPACE)
			goto state_game;
		else if (k==KEY_ESCAPE)
			goto state_deinit;
		if (returnSplashState() >= STATE_DONE)
			goto state_game;
		
	}

state_game:
	loadMusic(&bgm);
	SetRandomSeed(time(NULL));
	initPlayer();
	initWorld();

	PlayMusicStream(bgm);
	while (!WindowShouldClose()) {
		updatePlayerCamera(&getPlayerPointer()->c);
		updateWorld();
		if (IsMusicStreamPlaying(bgm))
			updateMusic(&bgm);
		else {
			loadMusic(&bgm);
			PlayMusicStream(bgm);
		}
		updateGameTitle();

		BeginDrawing();

		if (!getWorldPointer()->isNight)
			ClearBackground(SKYBLUE);
		else
			ClearBackground(DARKBLUE);
		drawGame();

		EndDrawing();
		
	}

state_deinit:
	UnloadMusicStream(bgm);
	CloseWindow();
	CloseAudioDevice();
	return 0;
}

void loadMusic(Music* m) {
	int i = GetRandomValue(MINTRACK, MAXTRACK);
	World w = getWorld();

	// load music based on attribute and day time
	//  this way of doing the task is clunky and probably 
	//  a terrible way. i feel that it will break into wet
	//  spaghetti when i decide to expand the world.
	if (w.isNight)
		while (!getMusicAttr(i, 0))
			i = GetRandomValue(MINTRACK, MAXTRACK);
	else if (!w.isNight)
		while (!getMusicAttr(i, 1))
			i = GetRandomValue(MINTRACK, MAXTRACK);

	*m = getMusicTrack(i);
}
