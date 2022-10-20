#include <stdlib.h>
#include <raylib.h>

#include "misc.h"
#include "splash.h"
#include "game.h"
#include "player.h"

int main() {
	initGame();

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

state_game: {
	while (!WindowShouldClose()) {
		
	}
}

state_deinit:
	CloseWindow();
	CloseAudioDevice();
	return 0;
}
