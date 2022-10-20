#pragma once
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

struct Config {
	uint32_t wh, ww;
	float volume;
	uint32_t targetFPS;
	double timeElapsed;
	bool vsync;
};
typedef struct Config Config;

void initGame();
void updateGameTitle();
int getVolumePercent();
void setVolume(float val);
Config getGameConfig();
