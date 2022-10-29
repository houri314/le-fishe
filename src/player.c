#include "player.h"
#include <raylib.h>

static Player p;

void initPlayer() {
	p.s = STATE_IDLE;
	p.score = 0;

	// init camera
	p.c.position = (Vector3){ 0, 2, 0 };
	p.c.up = (Vector3){ 0.0f, 1.0f, 0.0f };
	p.c.fovy = 60.0f;
	p.c.projection = CAMERA_PERSPECTIVE;
	SetCameraMode(p.c, CAMERA_CUSTOM);

}



Player* getPlayerPointer() { return &p; }
PlayerState getPlayerState() { return p.s; }
score_t getPlayerScore() { return p.score; }
Camera3D getPlayerCamera() { return p.c; }
