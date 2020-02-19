#pragma once

#define VIEWPORT_WIDTH 640
#define VIEWPORT_HEIGHT 480

/**
	Draws a point at (x, y) in viewport coordinates
*/
void drawPoint(int x, int y);

/**
	OpenGL uses Normalized Device Coordinates i.e the center of the viewport
	is (0,0) while the edges are from -1 to +1. We convert from a system with
	(0,0) at the bottom left to NDL
*/
float convertXToNDL(int x);

/**
	Refer to {@link #convertXToNDL}
*/
float convertYToNDL(int x);