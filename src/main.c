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
	SetRandomSeed(time(NULL));
	initPlayer();
	initWorld();

	float mTime = GetRandomValue(5,25);
	while (!WindowShouldClose()) {
		updatePlayerCamera(&getPlayerPointer()->c);
		updateWorld();
		if (IsMusicStreamPlaying(bgm))
			updateMusic(&bgm);
		else {
			if (mTime <= 0) {
				loadMusic(&bgm);
				PlayMusicStream(bgm);
				mTime = GetRandomValue(20, 120);
			}
			else
				mTime -= GetFrameTime();
		}
		updateGameTitle();

		BeginDrawing();

		ClearBackground(getSkyColor());
		drawGame();

#if defined(DEBUG_ENABLED)
#define mTimeMsg TextFormat("%g", mTime)
		DrawText(mTimeMsg,
			getGameConfig().ww-MeasureText(mTimeMsg,30),
			getGameConfig().wh-30,
			30,RED);
#endif

		EndDrawing();
	}

state_deinit:
	// unload bgm if it has been loaded
	if (bgm.frameCount != 0)
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
