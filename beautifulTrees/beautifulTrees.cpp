#include "pch.h"
#include "drawLine.h"
#include "beautifulTrees.h"
#include "utils.h"
#include <GLFW/glfw3.h>

/**
 * Point of entry for execution
 */
int main(void)
{
	GLFWwindow* window;

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

void renderAll(void)
{
	glPointSize(1.0f);
	glBegin(GL_POINTS);
	{
		drawLine(0, 0, VIEWPORT_WIDTH, VIEWPORT_HEIGHT / 2);
		drawLine(0, 0, VIEWPORT_WIDTH / 2, VIEWPORT_HEIGHT);
	}
	glEnd();
}