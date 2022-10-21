#include "game.h"
#include "player.h"
#include <raylib.h>

#include "control.h"

static const float cSpeed = PI/2;

static void updatePlayerCamera(Camera3D* c) {
	static float p;  // camera horizontal rotation
	static float py; // camera vertical rotation
	static const float upLim = 7.5f; // limit to vertical camera rotation
	static const float downLim = -2.0f;
	float delta = GetFrameTime();
	UpdateCamera(c);
	if (IsKeyDown(UP))
		if (c->target.y < upLim)
			py += delta;
	if (IsKeyDown(DOWN))
		if (c->target.y > downLim)
			py -= delta;
	if (IsKeyDown(RIGHT))
		p -= delta;
	else if (IsKeyDown(LEFT))
		p += delta;

	// camera rotation
	//  actually i don't have any particular reason to
	//  use 6. i don't know, but it works.
	c->target.x = c->position.x + 6*sin(cSpeed*p);
	c->target.z = c->position.z + 6*cos(cSpeed*p);
	c->target.y = c->position.y + 6*sin(cSpeed*py);

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