#include "pch.h"
#include "utils.h"
#include <GLFW/glfw3.h>

#define convertXToNDL(x) ((2.0 * x / VIEWPORT_WIDTH) - 1)
#define convertYToNDL(x) ((2.0 * x / VIEWPORT_HEIGHT) - 1)

void drawPoint(int x, int y)
{
  float destX = convertXToNDL(x);
  float destY = convertYToNDL(y);

  glVertex2f(destX, destY);
}