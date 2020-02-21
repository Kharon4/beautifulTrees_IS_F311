#include "../pch.h"
#include "../conf.h"
#include "utils.h"

float convertXToNDL(int x)
{
	return (2.0 * x / VIEWPORT_WIDTH) - 1;
}

float convertYToNDL(int y)
{
	return (2.0 * y / VIEWPORT_HEIGHT) - 1;
}