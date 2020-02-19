/**
 * @file beautifulTrees.h header file for the main beautiful trees program.
 */

#pragma once

#define VIEWPORT_WIDTH 640
#define VIEWPORT_HEIGHT 480

/**
 *  Draw a point, with (0,0) corresponding to bottom left of window,
 * i.e. in viewport coordinates.
 *
 * @param x x coodrinate of the point
 * @param y y coordinate of the point
 */
void drawPoint(int x, int y);

/**
 *OpenGL uses Normalized Device Coordinates i.e the center of the viewport
 *is (0,0) while the edges are from -1 to +1. We convert from a system with
 *(0,0) at the bottom left to NDL
 */
float convertXToNDL(int x);

/**
	Refer to { @link #convertXToNDL }
*/
float convertYToNDL(int x);

/**
 * All renders are grouped here.
 */
void renderAll(void);

/**
 * Uses the midpoint line drawing algorithm to draw a line from (x1, y1) to
 * (x2, y2).
 *
 * @param x1 the on-screen x coordinate to start drawing from
 * @param y1 the on-screen y coordinate to start drawing from
 * @param x2 the on-screen x coordinate to draw upto
 * @param y2 the on-screen y coordinate to draw upto
 */
void drawLine(int x1, int y1, int x2, int y2);
