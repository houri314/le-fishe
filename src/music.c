#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include "music.h"

// flags for loading music depending on day-night time
//  first element corresponds to res/snd/bgm00.ogg
//  so on so on
//
//  however i wonder if i should use [track][attr] or keep
//  [attr][track] ?
static const bool musicAttr[][MAXTRACK+1] = {
	{ 0, 1, 1, 1, 1, 1, 0 },  // is music played during night ?
	{ 1, 1, 0, 0, 1, 0, 1 }   // is music played during day ?
};

// shouldn't play music at full volume
static const float trackVol = 0.45f;

// for fading
static float volDelta = 0.02;
static float currentMVol = 0;
static bool fadeOut = false;

bool getMusicAttr(music_t index, uint8_t attr) {
	if (index>MAXTRACK)
		TraceLog(LOG_WARNING,
			TextFormat("%d>MAXTRACK(%d)\n", index, MAXTRACK));
	if (attr>MUS_ATTR_LAST) {
		TraceLog(LOG_WARNING,
			TextFormat("%d>MUS_ATTR_LAST(%d)\n", index, MUS_ATTR_LAST));
		return 0;
	}
	return musicAttr[attr][index];
}

Music getMusicTrack(music_t index) {
	if (index>MAXTRACK)
		TraceLog(LOG_FATAL,
			TextFormat("%d>MAXTRACK(%d)\n", index, MAXTRACK));
	Music tmp = LoadMusicStream(
			TextFormat("res/snd/bgm%02d.ogg", index)
			);
	SetMusicVolume(tmp, 0);
	tmp.looping = false;
	currentMVol = 0; // reset volume on loading new music
	fadeOut = false; // reset fading
#if defined(DEBUG_ENABLED)
	TraceLog(LOG_INFO, "Loaded track %02d", index);
#endif
	return tmp;

}

void updateMusic(Music* m) {
	if (currentMVol < trackVol && !fadeOut) {
		currentMVol += volDelta * GetFrameTime();
		SetMusicVolume(*m, currentMVol);
	}
	if (GetMusicTimePlayed(*m)/GetMusicTimeLength(*m)>=0.9 && !fadeOut)
		fadeOut = true;
	if (fadeOut && currentMVol>=0) {
		currentMVol -= volDelta * GetFrameTime() * 2;
		SetMusicVolume(*m, currentMVol);
	}
	UpdateMusicStream(*m);
}
