#pragma once
#include "misc.h"
#include <raylib.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

void drawSplash();
uint8_t returnSplashState();


enum {
	STATE_RAYLIB=1,
	STATE_WAIT1,
	STATE_HOURIN,
	STATE_WAIT2,
	STATE_DONE,
};
