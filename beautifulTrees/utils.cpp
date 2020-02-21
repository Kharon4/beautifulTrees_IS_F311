#include "utils.h"
#include <GLFW/glfw3.h>

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
