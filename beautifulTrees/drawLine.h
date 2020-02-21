/**
 * @file drawLine.h
 * @brief Exports a function that can be used to draw a line between two points.
 */

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
