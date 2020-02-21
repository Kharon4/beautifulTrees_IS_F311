#include "pch.h"
#include "utils.h"
#include "drawLine.h"
#include <GLFW/glfw3.h>

void drawPoint(int x, int y)
{
	float destX = convertXToNDL(x);
	float destY = convertYToNDL(y);

	glVertex2d(destX, destY);
}

float convertXToNDL(int x)
{
	return (float)2.0 * x / VIEWPORT_WIDTH - 1;
}

float convertYToNDL(int y)
{
	return (float)2.0 * y / VIEWPORT_HEIGHT - 1;
}

void drawLine(int x1, int y1, int x2, int y2)
{
	bool invertPoint = false;
	if ((y2 - y1) > (x2 - x1)) {
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

	int dx = x2 - x1;
	int dy = y2 - y1;
	int incrE = 2 * dy;
	int incrNE = 2 * (dy - dx);
	int x = x1;
	int y = y1;

	/* For negative gradients, we reduce the value of y*/
	int yi = dy > 0 ? 1 : -1;
	dy *= yi;

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
