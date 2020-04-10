/**
 * \file ImageGrowable.cpp
 *
 * \author Grant Youngs
 */

#include "pch.h"
#include "ImageGrowable.h"
#include "TreeActual.h"
#include "FruitActual.h"

using namespace std;
using namespace Gdiplus;

/// Constant ratio to convert radians to degrees
const double RtoD = 57.295779513;


/**
 * Constructor
 */
CImageGrowable::CImageGrowable()
{
}

/**
 * Destructor
 */
CImageGrowable::~CImageGrowable()
{
}

/**
 * Draws the ImageGrowable to the screen
 * \param graphics 
 * \param parentAngle 
 * \param x 
 * \param y 
 */
void CImageGrowable::Draw(Gdiplus::Graphics* graphics, double parentAngle, double x, double y)
{
	auto state = graphics->Save();
	graphics->TranslateTransform((float)x, (float)y);
	graphics->RotateTransform((float)(parentAngle * RtoD));
	graphics->ScaleTransform((float)mScale, (float)mScale);
	graphics->DrawImage(mImage.get(), -(int)mImage->GetWidth() / 2,
		-(int)mImage->GetHeight(),
		mImage->GetWidth(), mImage->GetHeight());
	graphics->Restore(state);
}

/**
 * Grows the image Growable
 */
void CImageGrowable::Grow()
{
	CGrowable::SetFrame(CGrowable::GetFrame() + 1);
	mScale += .003;
}

/**
 * Returns an empty collection of fruits
 * \returns std::vector<std::shared_ptr<CFruitActual>> An empty collection of fruits
 */
std::vector<std::shared_ptr<CFruitActual>> CImageGrowable::Harvest()
{
	return std::vector<std::shared_ptr<CFruitActual>>();
}



