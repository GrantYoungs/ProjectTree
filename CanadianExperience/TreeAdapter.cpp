/**
 * \file TreeAdapter.cpp
 *
 * \author Grant Youngs
 */

#include "pch.h"
#include "TreeAdapter.h"
#include "TreeActual.h"
#include "TreeFactory.h"
#include "Timeline.h"
#include "BasketAdapter.h"
#include "Fruit.h"
#include "Timeline.h"
#include "TreeSeedDlg.h"

using namespace std;
using namespace Gdiplus;
using namespace xmlnode;

/**
 * Constructor
 * \param name Name of the drawable
 */
CTreeAdapter::CTreeAdapter(const std::wstring& name) : CDrawable(name)
{
	CTreeFactory factory;
	mTree = factory.CreateTree();
}

/**
 * Destructor
 */
CTreeAdapter::~CTreeAdapter()
{
}

/**
 * Draws the TreeActual to the screen
 * \param graphics Context to draw on
 */
void CTreeAdapter::Draw(Gdiplus::Graphics* graphics)
{
		double scale = 0.5;

		auto save = graphics->Save();
		graphics->ScaleTransform((float)scale, (float)scale);

		if (mTimeline->GetCurrentFrame() - mStartTime < 270)	// Limits the tree to growing to just 270 frames
		{
			mTree->SetTreeFrame(mTimeline->GetCurrentFrame() - (int)mStartTime);
		}
		if (mTimeline->GetCurrentFrame() >= mHarvestTime)
		{
			std::vector<std::shared_ptr<CFruit>> harvest = mTree->Harvest();
			mBasket->AddToBasket(harvest);
		}
		else
		{
			mBasket->EmptyBasket();
		}

		mTree->DrawTree(graphics);
		graphics->Restore(save);
}

/**
 * Sets the timeline and tree adapter association
 * \param timeline This tree adapter belongs to
 */
void CTreeAdapter::SetTimeline(CTimeline* timeline)
{
	CDrawable::SetTimeline(timeline); 
	mTimeline = timeline;
	//timeline->SetTree(this);
}

/**
 * Shows the dialogue box that allows the user to change the seed of the tree
 */
void CTreeAdapter::ShowDialogueBox()
{
	CTreeSeedDlg dlg(mTree);
	if (dlg.DoModal() == IDOK)
	{
		
	}
}

/**
 * Saves the attributes of the TreeActual object to an XML file
 * \param root XML file to save to
 */
void CTreeAdapter::Save(std::shared_ptr<xmlnode::CXmlNode> root)
{
	root->SetAttribute(L"seed", mTree->GetSeed());
	root->SetAttribute(L"startTime", mStartTime);
	root->SetAttribute(L"harvestTime", mHarvestTime);
}

/**
 * Loads the attributes of the TreeActual object from an XML file
 * \param root XML file to load from
 */
void CTreeAdapter::Load(std::shared_ptr<xmlnode::CXmlNode> root)
{
	mTree->SetSeed(root->GetAttributeIntValue(L"seed", 0));
	mStartTime = root->GetAttributeIntValue(L"startTime", 0);
	mHarvestTime = root->GetAttributeIntValue(L"harvestTime", 0);
}

/**
* Sets the root location of the TreeActual
* \param x The x position
* \param y The y position
*/
void CTreeAdapter::SetTreeRootLocation(int x, int y)
{
	mTree->SetRootLocation(x, y);
}

/**
* Sets the tree seed of the TreeActual
* \param seed The seed
*/
void CTreeAdapter::SetTreeSeed(int seed)
{
	mTree->SetSeed(seed);
}
