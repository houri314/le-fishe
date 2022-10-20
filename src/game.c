#include "game.h"
#include "player.h"
#include <raylib.h>

#include "control.h"

static const float cSpeed = 4.0f;

static void updatePlayerCamera(Camera3D* c) {
	static float p;
	float delta = GetFrameTime();
	UpdateCamera(c);
	if (IsKeyDown(UP))
		c->target.y += cSpeed * delta;
	else if (IsKeyDown(DOWN))
		c->target.y -= cSpeed * delta;
	if (IsKeyDown(RIGHT))
		p -= delta;
	else if (IsKeyDown(LEFT))
		p += delta;

	c->target.x = c->position.x + 6*sin(PI/2*p);
	c->target.z = c->position.z + 6*cos(PI/2*p);


}

void drawGame() {
	BeginDrawing();
	ClearBackground(WHITE);
	Player* p = getPlayerPointer();

	BeginMode3D(getPlayerCamera());
		// i copied these lines from raylib example to
		// test the camera first
                DrawCube((Vector3){ -16.0f, 2.5f, 0.0f }, 1.0f, 5.0f, 32.0f, BLUE);     // Draw a blue wall
                DrawCube((Vector3){ 16.0f, 2.5f, 0.0f }, 1.0f, 5.0f, 32.0f, LIME);      // Draw a green wall
                DrawCube((Vector3){ 0.0f, 2.5f, 16.0f }, 32.0f, 5.0f, 1.0f, GOLD);      // Draw a yellow wall
	EndMode3D();

	EndDrawing();
}

void updateGame() {
	updatePlayerCamera(&getPlayerPointer()->c);
}
