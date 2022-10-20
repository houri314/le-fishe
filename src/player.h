#pragma once
#include <raylib.h>

typedef uint32_t score_t;

typedef enum PlayerState {
	STATE_IDLE,
	STATE_FISHING,
	STATE_REELING
} PlayerState;

typedef struct {
	Camera3D c;
	PlayerState s;
	score_t score;
} Player;

void initPlayer();

Player* getPlayerPointer();
PlayerState getPlayerState();
score_t getPlayerScore();
Camera3D getPlayerCamera();
// functions above are just generally safer ways to
// get a specific property of Player

void destroyPlayer();
