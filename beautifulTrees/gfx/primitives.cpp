#include "../pch.h"
#include <../include/GLFW/glfw3.h>
#include "primitives.h"
#include "utils.h"
#include <math.h>

void drawPoint(int x, int y)
{
	float destX = convertXToNDL(x);
	float destY = convertYToNDL(y);

	glVertex2f(destX, destY);
}

void drawLine(int x1, int y1, int x2, int y2)
{
	
	bool invertPoint = false;
	if ((abs(y2 - y1) > abs(x2 - x1)))
	{
		/* If the slope is greater than 1, we swap the x and y coordinates
		* to bring the slope between between 0 and 1. The algorithm then proceeds
		* as normal. However, during the final render, we need to swap the final
		* coordinates once again to render at the proper point.
		*/
		int temp = x1;
		x1 = y1;
		y1 = temp;

		temp = x2;
		x2 = y2;
		y2 = temp;

		invertPoint = true;
	}

	if (x1 > x2)
	{
		/* Swap the points around */
		int temp = x1;
		x1 = x2;
		x2 = temp;

		temp = y1;
		y1 = y2;
		y2 = temp;
	}

	int dx = x2 - x1;
	int dy = y2 - y1;

	/* For negative gradients, we reduce the value of y*/
	int yi = dy > 0 ? 1 : -1;
	dy *= yi;

	int incrE = 2 * dy;
	int incrNE = 2 * (dy - dx);
	int x = x1;
	int y = y1;

	/* Decision Variable, first pixel was NE */
	int d = incrNE;
	do
	{
		if (!invertPoint)
			drawPoint(x, y);
		else
			drawPoint(y, x);

		if (d <= 0)
		{
			d += incrE;
			x++;
		}
		else
		{
			d += incrNE;
			x++;
			y += yi;
		}
	} while (x < x2);
}

// Begin circle code.
int c_x;
int c_y;

void plotCircle(int x, int y)
{
	drawPoint(c_x - x, c_y - y);
	drawPoint(c_x - x, c_y + y);
	drawPoint(c_x + x, c_y - y);
	drawPoint(c_x + x, c_y + y);
	drawPoint(c_x + y, c_y + x);
	drawPoint(c_x - y, c_y + x);
	drawPoint(c_x + y, c_y - x);
	drawPoint(c_x - y, c_y - x);
}

void drawCircle(int radius, int center_x, int center_y)
{
	c_x = center_x;
	c_y = center_y;
	int x = 0;
	int y = radius;
	int d = 1 - radius;
	int deltaE = 3;
	int deltaSE = -2 * radius + 5;
	plotCircle(x, y);
	while (y > x)
	{
		if (d < 0)
		{
			d += deltaE;
			deltaE += 2;
			deltaSE += 2;
		}
		else
		{
			d += deltaSE;
			deltaE += 2;
			deltaSE += 4;
			y--;
		}
		x++;
		plotCircle(x, y);
	}
}
// End circle code.