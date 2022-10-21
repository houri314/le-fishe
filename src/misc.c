#include "misc.h"
#include <raylib.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>

static const char* gameName = "hourin fishing game";

static Config conf = {
	.ww = 640,
	.wh = 480,
	.targetFPS = 60,
	.vsync = true,
	.volume = 1
};

void updateGameTitle() {
	SetWindowTitle(
		TextFormat("%s - %d/%d (with%s vsync)",
			gameName,
			GetFPS(),
			conf.targetFPS,
			(conf.vsync)?"":"out")
		);
}

int getVolumePercent() {
	return round(conf.volume*100);
}

void setVolume(float val) {
	conf.volume += val;
	if (conf.volume > 1)
		conf.volume = 1;
	else if (conf.volume < 0)
		conf.volume = 0;
	SetMasterVolume(conf.volume);
}

Config getGameConfig() {
	return conf;
}

void initGame() {
	if (conf.vsync) SetConfigFlags(FLAG_VSYNC_HINT);
	if (conf.targetFPS>0) SetTargetFPS(conf.targetFPS);

	ChangeDirectory(GetApplicationDirectory());

	InitWindow(conf.ww, conf.wh, gameName);
	InitAudioDevice();
	SetMasterVolume(conf.volume);

	Image icon = LoadImage("res/img/icon.png");
	SetWindowIcon(icon);
	UnloadImage(icon);
}
