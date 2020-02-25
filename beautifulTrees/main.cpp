/**
 * @file main.cpp
 * @brief The entry point of the entire assignment. Choose exercises from here.
 * @compilation g++ gfx/*.cpp pch.cpp main.cpp -lglfw -lGLU -lGL
 */

#include "pch.h"
#include "iostream"
#include "pch.h"
#include "gfx/primitives.h"
#include "gfx/treeDrawer.h"
#include <GLFW/glfw3.h>
#include "conf.h"
#include "chrono"

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

struct Circle
{
  int c_x;
  int c_y;
  int radius;
};

int exerciseChoice = -1;

struct Line line;
struct Circle circle;

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
  cin >> line.x1;
  printf("y coordinate of starting point>");
  cin >> line.y1;
  printf("x coordinate of ending point>");
  cin >> line.x2;
  printf("y coordinate of ending point>");
  cin >> line.y2;
}

void exerciseCircle()
{
  exerciseChoice = 2;
  printf("x coordinate of center of circle>");
  cin >> circle.c_x;
  printf("y coordinate of center of circle>");
  cin >> circle.c_y;
  printf("radius of circle>");
  cin >> circle.radius;
}

binTree<char> head('H');
binTree<char> c1('a');
binTree<char> c2('b');
binTree<char> c[10];
void exerciseBinTree()
{
  exerciseChoice = 3;
  head.set(&c1, &c2);
  c1.set(c, c + 1);
  c[0].set(c + 2, c + 3);
  c[1].set(c + 4, c + 5);
  c[2].set(c + 6, c + 7);

  treeDisplay::extreme<char> e1, e2;
  treeDisplay::setup<char>(&head, 0, e1, e2);
  treeDisplay::petrify<char>(&head);
}

void renderAll()
{
  glPointSize(1.0f);
  glColor3f(1.0, 0.5, 1.0);
  // glBegin(GL_POINTS);

  {
    switch (exerciseChoice)
    {
    case 1:
      glBegin(GL_POINTS);
      drawLine(line.x1, line.y1, line.x2, line.y2);
      glEnd();
      break;

    case 2:
    {
      glBegin(GL_TRIANGLES);
      drawCircle(circle.radius, circle.c_x, circle.c_y);
      glEnd();
      break;
    }

    case 3:
      treeDisplay::drawTree<char>(&head);
      break;

    default:
      cout << "Error in renderAll() - no valid exercise found\n";
      break;
    }
  }
  // glEnd();
}

void startRenders()
{
  GLFWwindow *window;

  /* Initialize the library */
  if (!glfwInit())
    return;

  /* Create a windowed mode window and its OpenGL context */
  window = glfwCreateWindow(VIEWPORT_WIDTH, VIEWPORT_HEIGHT, "Computer Graphics Assignment I", NULL, NULL);
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