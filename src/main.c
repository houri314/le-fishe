#include <stdlib.h>
#include <raylib.h>

#include "misc.h"
#include "splash.h"
#include "game.h"
#include "player.h"

static const uint8_t minBGM = 0;
static const uint8_t maxBGM = 1;

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
	bgm = LoadMusicStream("res/snd/bgm00.ogg");
	initPlayer();

	while (!WindowShouldClose()) {
		if (!IsMusicStreamPlaying(bgm))
			PlayMusicStream(bgm);
		updateGame();
		UpdateMusicStream(bgm);
		drawGame();
		updateGameTitle();
		
	}

state_deinit:
	UnloadMusicStream(bgm);
	CloseWindow();
	CloseAudioDevice();
	return 0;
}
