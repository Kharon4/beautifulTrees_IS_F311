#pragma once
#include "../conf.h"

/**
 *  Draw a point, with (0,0) corresponding to bottom left of window,
 * i.e. in viewport coordinates.
 *
 * @param x x coodrinate of the point
 * @param y y coordinate of the point
 */
float convertXToNDL(int x);

/**
 *OpenGL uses Normalized Device Coordinates i.e the center of the viewport
 *is (0,0) while the edges are from -1 to +1. We convert from a system with
 *(0,0) at the bottom left to NDL
 */
float convertYToNDL(int y);
