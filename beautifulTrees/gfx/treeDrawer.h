/**
 * @file treeDrwer.h
 * @brief implements functions that can be used to draw a binary tree.
 */

#pragma once
#include "binTree.cpp"
#include "primitives.h"
#include "../conf.h"
#include <GLFW/glfw3.h>

namespace treeDisplay
{

#define minSep 50
#define rad 10

template <typename T>
class extreme
{
public:
	binTree<T> *addr = nullptr;
	long int off = 0, lev = 0;
};


/**
  * Calculates the relative position of nodes , before calculation the absolute value.
  *
  * @param t address of the root node of the sub tree
  * @param level level of root node of the sub tree
  * @param rMost right extreme descendant
  * @param lMost left extreme descendant
  */
template <typename T>
void setup(binTree<T> *t, int level, extreme<T> &rMost, extreme<T> &lMost)
{
	//variable declaration
	binTree<T> *L, *R;
	extreme<T> LR, LL, RR, RL;

	long int curSep, rootSep, lOffSum, rOffSum;

	if (t == nullptr)
	{
		lMost.lev = -1;
		rMost.lev = -1;
	}
	else
	{
		t->yCoord = level;
		L = t->left;
		R = t->right;
		setup(L, level + 1, LR, LL);
		setup(R, level + 1, RR, RL);
		if (R == nullptr && L == nullptr)
		{ //leaf
			rMost.addr = t;
			lMost.addr = t;
			rMost.lev = level;
			lMost.lev = level;
			rMost.off = 0;
			lMost.off = 0;
			t->offset = 0;
		}
		else
		{ //not a leaf
			curSep = minSep;
			rootSep = minSep;
			lOffSum = 0;
			rOffSum = 0;

			while (L != nullptr && R != nullptr)
			{
				if (curSep < minSep)
				{
					rootSep = rootSep + minSep - curSep;
					curSep = minSep;
				}

				//update L
				if (L->right != nullptr)
				{
					lOffSum += L->offset;
					curSep -= L->offset;
					L = L->right;
				}
				else
				{
					lOffSum -= L->offset;
					curSep += L->offset;
					L = L->left;
				}

				//update R
				if (R->left != nullptr)
				{
					rOffSum -= R->offset;
					curSep -= R->offset;
					R = R->left;
				}
				else
				{
					rOffSum += R->offset;
					curSep += R->offset;
					R = R->right;
				}
			}

			t->offset = (rootSep + 1) / 2;
			lOffSum -= t->offset;
			rOffSum += t->offset;

			if ((RL.lev > LL.lev) || (t->left == nullptr))
			{
				lMost = RL;
				lMost.off += t->offset;
			}
			else
			{
				lMost = LL;
				lMost.off -= t->offset;
			}

			if ((LR.lev > RR.lev) || (t->right == nullptr))
			{
				rMost = LR;
				rMost.off -= t->offset;
			}
			else
			{
				rMost = RR;
				rMost.off += t->offset;
			}

			if (L != nullptr && L != t->left)
			{
				RR.addr->thread = true;
				RR.addr->offset = abs((RR.off + t->offset) - lOffSum);
				if ((lOffSum - t->offset) <= RR.off)
				{
					RR.addr->left = L;
				}
				else
				{
					RR.addr->right = L;
				}
			}
			else if (R != nullptr && R != t->right)
			{
				LL.addr->thread = true;
				LL.addr->offset = abs((LL.off - t->offset) - rOffSum);
				if (rOffSum + t->offset >= LL.off)
				{
					LL.addr->right = R;
				}
				else
				{
					LL.addr->left = R;
				}
			}
		}
	}
}


/**
  * Sums the relative position of nodes to calculation the absolute value.
  *
  * @param t address of the root node of the sub tree
  * @param xPos x coordinate of the root node
  */
template <typename T>
void petrify(binTree<T> *t, long int xPos = VIEWPORT_WIDTH / 2)
{
	if (t != nullptr)
	{
		t->xCoord = xPos;
		if (t->thread)
		{
			t->thread = false;
			t->right = nullptr;
			t->left = nullptr;
		}
		petrify(t->left, xPos - t->offset);
		petrify(t->right, xPos + t->offset);
	}
}

/**
  *Converts the integral coordinates obtained by petrify function to viewport coordinates
  *
  * @param in the parameter to be converted
 */
int convert(int in)
{
	return VIEWPORT_HEIGHT - 30 * in - 20;
}

/**
  *Draws the nodes at their respective positions , and connects parent/chld nodes using lines
  *
  * @param t address of the root of the tree to be drawn 
 */
template <typename T>
void drawTree(binTree<T> *t)
{
	glBegin(GL_TRIANGLES);
	drawCircle(rad, t->xCoord, convert(t->yCoord));
	glEnd();

	if (t->left != nullptr)
	{
		glBegin(GL_POINTS);
		drawLine(t->left->xCoord, convert(t->left->yCoord), t->xCoord, convert(t->yCoord));
		glEnd();

		drawTree(t->left);
	}
	if (t->right != nullptr)
	{
		glBegin(GL_POINTS);
		drawLine(t->right->xCoord, convert(t->right->yCoord), t->xCoord, convert(t->yCoord));
		glEnd();

		drawTree(t->right);
	}
}

} // namespace treeDisplay