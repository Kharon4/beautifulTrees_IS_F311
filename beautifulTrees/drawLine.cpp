#include "pch.h"
#include "utils.h"
#include "drawLine.h"
#include <GLFW/glfw3.h>

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