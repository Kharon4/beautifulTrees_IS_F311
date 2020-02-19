#include "pch.h"
#include "beautifulTrees.h"
#include <GLFW/glfw3.h>

int main(void)
{
	GLFWwindow *window;

	/* Initialize the library */
	if (!glfwInit())
		return -1;

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(VIEWPORT_WIDTH, VIEWPORT_HEIGHT, "Test Window 2", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);

		renderAll();

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}

void drawPoint(int x, int y)
{
	float destX = convertXToNDL(x);
	float destY = convertYToNDL(y);

	glVertex2f(destX, destY);
}

float convertXToNDL(int x)
{
	return 2.0 * x / VIEWPORT_WIDTH - 1;
}

float convertYToNDL(int y)
{
	return 2.0 * y / VIEWPORT_HEIGHT - 1;
}

void drawLine(int x1, int y1, int x2, int y2)
{
	int dx = x2 - x1;
	int dy = y2 - y1;
	int d = 2 * dy - dx;
	int incrE = 2 * dy;
	int incrNE = 2 * (dy - dx);
	int x = x1;
	int y = y1;

	drawPoint(x, y);
	while (x < x2)
	{
		if (d <= 0)
		{
			d += incrE;
			x++;
		}
		else
		{
			d += incrNE;
			x++;
			y++;
		}
		drawPoint(x, y);
	}
}

void renderAll(void)
{
	glPointSize(1.0f);
	glBegin(GL_POINTS);
	{
		drawLine(0, 0, 500, 500);
	}
	glEnd();
}