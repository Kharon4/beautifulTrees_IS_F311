/**
 * @file drawLine.h
 * @brief Exports a function that can be used to draw a line between two points.
 */
#pragma once

 /**
  *  Draw a point, with (0,0) corresponding to bottom left of window,
  * i.e. in viewport coordinates.
  *
  * @param x x coodrinate of the point
  * @param y y coordinate of the point
  */
void drawPoint(int x, int y);

 /**
 * Uses the midpoint line drawing algorithm to draw a line from (x1, y1) to
 * (x2, y2) for any real valued slope.
 *
 * @param x1 the on-screen x coordinate to start drawing from
 * @param y1 the on-screen y coordinate to start drawing from
 * @param x2 the on-screen x coordinate to draw upto
 * @param y2 the on-screen y coordinate to draw upto
 */
void drawLine(int x1, int y1, int x2, int y2);

/**
 * Draws a cricle for a given center and radius.
 * @param radius radius of the circle
 * @param center_x x coordinate of the center
 * @param center_y y coordinate of the center
 */
void drawCircle(int radius, int center_x, int center_y);


