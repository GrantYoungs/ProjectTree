/**
 * \file FruitActual.cpp
 *
 * \author Grant Youngs
 */

#include "pch.h"
#include "FruitActual.h"
#include "TreeActual.h"
#include "GrowableVisitor.h"

using namespace std;
using namespace Gdiplus;

/**
 * Constructor
 */
CFruitActual::CFruitActual()
{

}

/**
 * Destructor
 */
CFruitActual::~CFruitActual()
{

}

/**
* Set the position of the fruit in the basket
*
* This position is relative to the basket, so
* it will be added to the basket location passed
* to DrawInBasket when we draw it
* \param x X position in pixels
* \param y Y position in pixels
*/
void CFruitActual::SetBasketPosition(int x, int y)
{
	double xPos = GetTree()->GetRandomDouble(x * 0.2, 0.8 * x);
	double yPos = GetTree()->GetRandomDouble(y * 0.4, y * 0.9);
	mRelativeBasketPosX = xPos;
	mRelativeBasketPosY = yPos;
}

/**
* Draw the fruit in the basket
* \param graphics The graphics object to draw on
* \param x X location of the basket
* \param y Y location of the basket
*/
void CFruitActual::DrawInBasket(Gdiplus::Graphics* graphics, int x, int y)
{
	SetScale(0.2);
	Draw(graphics, 0, x + mRelativeBasketPosX, y + mRelativeBasketPosY);
}


/**
 * Adds this fruit to a vector of fruit actuals and returns it
 * \returns fruits The vector of fruits
 */
std::vector<std::shared_ptr<CFruitActual>> CFruitActual::Harvest()
{
	std::vector<shared_ptr<CFruitActual>> fruits;
	fruits.push_back(GetSelf());
	return fruits;
}

/**
 * Accepts a visitor
 * \param visitor The visitor
 */
void CFruitActual::Accept(CGrowableVisitor* visitor)
{
	visitor->VisitFruit(this);
}




