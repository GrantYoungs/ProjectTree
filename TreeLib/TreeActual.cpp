
/**
 * \file TreeActual.cpp
 *
 * \author Grant Youngs
 */

#include "pch.h"
#include "TreeActual.h"
#include "Limb.h"
#include "FruitActual.h"

using namespace std;
using namespace Gdiplus;

/// The filename for the leaf image
const std::wstring& LeafFileName = L"images/leaf3.png";

/// The filename for the fruit image
const std::wstring& FruitFileName = L"images/orange.png";

/**
 * Constructor
 */
CTreeActual::CTreeActual()
{
	Reset();
	LoadLeafImage(LeafFileName);
	LoadFruitImage(FruitFileName);
}

/**
 * Destructor
 */
CTreeActual::~CTreeActual()
{
}

/**
 * Resets the tree's current frame back to 0, and deletes all the children with the exception of the root
 */
void CTreeActual::Reset()
{
	mCurrentFrame = 0;
	InitializeRoot();
	mRandom.Reset();
}

/**
 * Private function that initializes the root of this tree.
 * TODO: Change the max height and width to a pseudorandom number once the Pseudorandom class is done
 */
void CTreeActual::InitializeRoot()
{
	mRoot = new CLimb();
	mRoot->SetTree(this);
	mRoot->SetDepth(1);
	Gdiplus::Point location = Gdiplus::Point(mRootLocationX, mRootLocationY);
	mRoot->SetPosition(location);
	mRoot->SetMaxHeight(115);
	mRoot->SetMaxWidth(25);
	mRoot->SetAngle(0);
	mRoot->SetFrame(mCurrentFrame);
}


/**
 * Loads the leaf image
 * \param filename The path to the leaf image
 */
void CTreeActual::LoadLeafImage(const std::wstring& filename)
{
	mLeafImage = make_shared<Gdiplus::Bitmap>(filename.c_str());
	if (mLeafImage->GetLastStatus() != Ok)
	{
		wstring msg(L"Failed to open ");
		msg += filename;
		AfxMessageBox(msg.c_str());
	}
}

/**
 * Loads the fruit image
 * \param filename The path to the leaf image
 */
void CTreeActual::LoadFruitImage(const std::wstring& filename)
{
	mFruitImage = make_shared<Gdiplus::Bitmap>(filename.c_str());
	if (mFruitImage->GetLastStatus() != Ok)
	{
		wstring msg(L"Failed to open ");
		msg += filename;
		AfxMessageBox(msg.c_str());
	}
}


/**
 * Draws the tree
 * \param graphics context on which to draw
 */
void CTreeActual::DrawTree(Gdiplus::Graphics* graphics)
{
	mRoot->Draw(graphics, mWindSpeed * 0.002, mRootLocationX, mRootLocationY);
}

/**
 * Sets the Tree frame. Allows for the tree to "grow backwards" when the timeline slider is moved backwards
 * \param frame Frame number
 */
void CTreeActual::SetTreeFrame(int frame)
{
	if (frame < mCurrentFrame)
	{
		Reset();
	}
	while (mCurrentFrame < frame) {
		mCurrentFrame++;
		mRoot->Grow();
	}
}

/**
 * Harvests all the fruit in the tree and 
 * \returns mFruits The vector of fruits
 */
std::vector<std::shared_ptr<CFruit>> CTreeActual::Harvest()
{
	mFruits.clear();
	std::vector<std::shared_ptr<CFruitActual>> _fruits = mRoot->Harvest();
	return mFruits;
}

/**
 * Sets the seed of the Random Number Generator
 * \param seed Seed to set
 */
void CTreeActual::SetSeed(int seed)
{
	mSeed = seed;
	mRandom.Seed(mSeed);
}
