#pragma once

#include <raylib.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#define MAXTRACK 6
#define MINTRACK 0

typedef uint8_t music_t; 

enum {
	MUS_ATTR_NIGHT,
	MUS_ATTR_DAY,

	MUS_ATTR_LAST // unused, to signal end of enum
};


bool getMusicAttr(music_t index, uint8_t attr);
Music getMusicTrack(music_t index);
