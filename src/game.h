#pragma once

#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <raymath.h>

typedef uint32_t worldtime_t;

typedef struct {
	worldtime_t time; // world time (measured in second)
} World;

World* getWorldPointer();
worldtime_t getWorldTime();

void drawGame();
void updateGame();
