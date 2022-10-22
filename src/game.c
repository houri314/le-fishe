#include "game.h"
#include "player.h"
#include <raylib.h>

#include "control.h"

#define WORLDDAY 240

static World w = {
	.sky = (Color){ 0, 0, 0, 255},
	.time = 0,
	.isNight = 0
};

static const float cSpeed = PI/2;

void updatePlayerCamera(Camera3D* c) {
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
	Player* p = getPlayerPointer();
	BeginMode3D(getPlayerCamera());
		// i copied these lines from raylib example to
		// test the camera first
                DrawCube((Vector3){ -16.0f, 2.5f, 0.0f }, 1.0f, 5.0f, 32.0f, BLUE);     // Draw a blue wall
                DrawCube((Vector3){ 16.0f, 2.5f, 0.0f }, 1.0f, 5.0f, 32.0f, LIME);      // Draw a green wall
                DrawCube((Vector3){ 0.0f, 2.5f, 16.0f }, 32.0f, 5.0f, 1.0f, GOLD);      // Draw a yellow wall
	EndMode3D();

//	DrawText(TextFormat("%d", w.time), 0, 0, 20, BLACK);
}

void initWorld() {
	w.time = 0;
	w.isNight = 0;
}

void updateWorld() {
	static float t = 0;
	static Color d;
	t += GetFrameTime();
	if (t >= 1) {
		w.time++;
		t = 0;
	}
	if (w.time >= WORLDDAY) {
		w.time = 0;
		w.isNight = !w.isNight;
	}

	if (!w.isNight) d = SKYBLUE;
	if (!w.isNight && w.time >= 3*WORLDDAY/4) d = ORANGE;
	else if (w.isNight) d= DARKBLUE;

	w.sky.r += GetFrameTime()*100 * (w.sky.r!=d.r) * (-(w.sky.r>d.r) + (w.sky.r<d.r));
	w.sky.g += GetFrameTime()*100 * (w.sky.g!=d.g) * (-(w.sky.g>d.g) + (w.sky.g<d.g));
	w.sky.b += GetFrameTime()*100 * (w.sky.b!=d.b) * (-(w.sky.b>d.b) + (w.sky.b<d.b));

}

World* getWorldPointer() { return &w; }
World getWorld() { return w; }
Color getSkyColor() { return w.sky; }
worldtime_t getWorldTime() { return w.time; }
