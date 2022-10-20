#include "game.h"
#include "player.h"
#include <raylib.h>

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

}
