/**
 * \file BasketActual.cpp
 *
 * \author Grant Youngs
 */

#include "pch.h"
#include <string>
#include "BasketActual.h"
#include "Fruit.h"
#include "TreeActual.h"

using namespace std;
using namespace Gdiplus;

/// The filename for the leaf image
const std::wstring& BasketFrontFileName = L"images/basket-front.png";

/// The filename for the Basket back image
const std::wstring& BasketBackFileName = L"images/basket.png";

/**
 * Constructor
 */
CBasketActual::CBasketActual()
{
	LoadBasketBack(BasketBackFileName);
	LoadBasketFront(BasketFrontFileName);
}

/**
 * Destructor
 */
CBasketActual::~CBasketActual()
{
}


/**
* Draw the basket at the currently specified location
* \param graphics GDI+ Graphics object
*/
void CBasketActual::DrawBasket(Gdiplus::Graphics* graphics)
{
	DrawBack(graphics);
	for (auto fruit : mFruits)
	{
		fruit->DrawInBasket(graphics, mPosition.X - (mBasketBack->GetWidth()), mPosition.Y - (mBasketBack->GetHeight()));
	}
	DrawFront(graphics);
}

/**
 * Private function that draws the back of the basket
 * \param graphics Context to draw on
 */
void CBasketActual::DrawBack(Gdiplus::Graphics* graphics)
{
	auto state = graphics->Save();
	graphics->TranslateTransform((float)mPosition.X, (float)mPosition.Y);
	graphics->DrawImage(mBasketBack.get(), -(int)mBasketBack->GetWidth(), -(int)mBasketBack->GetHeight(),
		mBasketBack->GetWidth(), mBasketBack->GetHeight());
	graphics->Restore(state);
}

/**
 * Private function that draws the front of the basket
 * \param graphics Context to draw on
 */
void CBasketActual::DrawFront(Gdiplus::Graphics* graphics)
{
	auto state = graphics->Save();
	graphics->TranslateTransform((float)mPosition.X, (float)mPosition.Y);
	graphics->DrawImage(mBasketFront.get(), -(int)mBasketFront->GetWidth(), -(int)mBasketFront->GetHeight(),
		mBasketFront->GetWidth(), mBasketFront->GetHeight());
	graphics->Restore(state);
}

/**
 * Adds a collection of fruit to the basket
 * \param fruits The collection of fruits to add
 */
void CBasketActual::AddToBasket(std::vector<std::shared_ptr<CFruit>> fruits)
{
	for (auto fruit : fruits)
	{
		// This sends the upper x bounds and y bounds of the basket to the function.
		// Inside the function, the fruit will generate random numbers between 0 and these bounds
		// to get a random position relative to the basket.
		fruit->SetBasketPosition(mBasketBack->GetWidth(), mBasketBack->GetHeight());
		mFruits.push_back(fruit);
	}
}

/**
 * Empty all fruit from the basket
 */
void CBasketActual::EmptyBasket()
{
	mFruits.clear();
}

/**
 * Loads the image for the back of the basket
 * \param filename File path to the image
 */
void CBasketActual::LoadBasketBack(const std::wstring& filename)
{
	mBasketBack = make_shared<Gdiplus::Bitmap>(filename.c_str());
	if (mBasketBack->GetLastStatus() != Ok)
	{
		wstring msg(L"Failed to open ");
		msg += filename;
		AfxMessageBox(msg.c_str());
	}
}

/**
 * Loads the image for the front of the basket
 * \param filename File path to the image
 */
void CBasketActual::LoadBasketFront(const std::wstring& filename)
{
	mBasketFront = make_shared<Gdiplus::Bitmap>(filename.c_str());
	if (mBasketFront->GetLastStatus() != Ok)
	{
		wstring msg(L"Failed to open ");
		msg += filename;
		AfxMessageBox(msg.c_str());
	}
}

