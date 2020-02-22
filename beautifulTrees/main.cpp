/**
 * @file main.cpp
 * @brief The entry point of the entire assignment. Choose exercises from here.
 * @compilation g++ gfx/*.cpp pch.cpp main.cpp -lglfw -lGLU -lGL
 */

#include "iostream"
#include "gfx/primitives.h"
#include "pch.h"
#include <GLFW/glfw3.h>
#include "conf.h"
using namespace std;

void exerciseLine();
void exerciseCircle();
void exerciseBinTree();
void startRenders();
void renderAll();

struct Line
{
  int x1;
  int y1;
  int x2;
  int y2;
};

int exerciseChoice = -1;

struct Line line;

int main(int argc, char const *argv[])
{
  int choice = -1;
  cout << "Welcome! Choose an exercise for a demonstration:\n";
  cout << "Available Options:\n1 - Draw a line\n2 - Draw a circle\n3 - Draw an aesthetic rooted binary tree\nYour option >";
  cin >> choice;
  switch (choice)
  {
  case 1:
  {
    cout << "You chose Draw a line\n";
    exerciseLine();
    break;
  }
  case 2:
  {
    cout << "You chose Draw a circle\n";
    exerciseCircle();
    break;
  }
  case 3:
  {
    cout << "You chose Draw an aesthetic rooted binary tree\n";
    exerciseBinTree();
    break;
  }
  default:
  {
    cout << "Invalid option. Exiting.\n";
    return -1;
    break;
  }
  }
  startRenders();
  return 0;
}

void exerciseLine()
{
  exerciseChoice = 1;
  printf("x coordinate of starting point>");
  scanf("%d", &line.x1);
  printf("y coordinate of starting point>");
  scanf("%d", &line.y1);
  printf("x coordinate of ending point>");
  scanf("%d", &line.x2);
  printf("y coordinate of ending point>");
  scanf("%d", &line.y2);
}

void exerciseCircle()
{
}

void exerciseBinTree()
{
}

void renderAll()
{
  glPointSize(1.0f);
  glBegin(GL_POINTS);
  {
    switch (exerciseChoice)
    {
    case 1:
      printf("Drawing line %d %d %d %d\n", line.x1, line.y1, line.x2, line.y2);
      drawLine(line.x1, line.y1, line.x2, line.y2);
      break;

    default:
      cout << "Error in renderAll() - no valid exercise found\n";
      break;
    }
  }
  glEnd();
}

void startRenders()
{
  GLFWwindow *window;

  /* Initialize the library */
  if (!glfwInit())
    return;

  /* Create a windowed mode window and its OpenGL context */
  window = glfwCreateWindow(VIEWPORT_WIDTH, VIEWPORT_HEIGHT, "Test Window", NULL, NULL);
  if (!window)
  {
    glfwTerminate();
    return;
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
  return;
}