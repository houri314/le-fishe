#include "splash.h"
#define SPLASH_SPEED 120
#define SECONDARY_SPEED 100

#define ww getGameConfig().ww
#define wh getGameConfig().wh

static uint8_t splashState = 1;
static Color splashBgCol = (Color){ 37, 23, 50, 255};
static Color raylibTexCol = (Color){ 220, 220, 220, 0};
static Color hourinTexCol = (Color){ 220, 220, 220, 0};

void drawSplash() {
	static int frameCounter = 0;
	BeginDrawing();
	ClearBackground(splashBgCol);

	if (splashState==STATE_RAYLIB) {
		DrawText("Made with Raylib", 
			(ww-MeasureText("Made with Raylib", 50))/2,
			wh/2,
			50,
			raylibTexCol);
		raylibTexCol.a += GetFrameTime()*SPLASH_SPEED;
		if (raylibTexCol.a >= 240)
			splashState++;
	}

	else if (splashState==STATE_WAIT1) {
		DrawText("Made with Raylib", 
			(ww-MeasureText("Made with Raylib", 50))/2,
			wh/2,
			50,
			raylibTexCol);
		raylibTexCol.a -= GetFrameTime()*SPLASH_SPEED;
		if (raylibTexCol.a <= 30) // barely visible
			splashState++;
	}

	else if (splashState==STATE_HOURIN) {
		DrawText("Game developed by Hourin",
			(ww-MeasureText("Game developed by Hourin", 40))/2,
			wh/3,
			40,
			raylibTexCol);
		DrawText("Report bugs at: ",
			(ww-MeasureText("Report bugs at:",25))/2,
			wh/2,
			25,
			raylibTexCol);
		DrawText("https://github.com/houri314/<projectname>",
			(ww-MeasureText("https://github.com/houri314/<projectname>",25))/2,
			wh/2+25,
			25,
			hourinTexCol);
		raylibTexCol.a += GetFrameTime() * SECONDARY_SPEED;
		hourinTexCol.a += GetFrameTime() * SECONDARY_SPEED;
		if (raylibTexCol.a >= 230)
			splashState++;
	}

	else if (splashState==STATE_WAIT2) {
		DrawText("Game developed by Hourin",
			(ww-MeasureText("Game developed by Hourin", 40))/2,
			wh/3,
			40,
			raylibTexCol);
		DrawText("Report bugs at: ",
			(ww-MeasureText("Report bugs at:",25))/2,
			wh/2,
			25,
			raylibTexCol);
		DrawText("https://github.com/houri314/<projectname>",
			(ww-MeasureText("https://github.com/houri314/<projectname>",25))/2,
			wh/2+25,
			25,
			hourinTexCol);
		raylibTexCol.a -= GetFrameTime() * SPLASH_SPEED;
		hourinTexCol.a -= GetFrameTime() * SECONDARY_SPEED;
		if (raylibTexCol.a <= 10) // barely visible
			splashState++;
	}
	
	EndDrawing();
}

uint8_t returnSplashState() {
	return splashState;
}

