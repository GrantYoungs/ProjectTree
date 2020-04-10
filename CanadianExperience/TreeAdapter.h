/**
 * \file TreeAdapter.h
 *
 * \author Grant Youngs
 *
 * Tree Adapter class that allows The Canadian Experience to draw the TreeActual in The Canadian Experience
 */

#pragma once
#include <memory>
#include <string>
#include "Drawable.h"

class CTreeActual;
class CTimeline;
class CBasketAdapter;

/**
 * Tree Adapter class that allows The Canadian Experience to draw the TreeActual in The Canadian Experience
 */
class CTreeAdapter :
	public CDrawable
{
public:
	CTreeAdapter(const std::wstring& name);
	~CTreeAdapter();

	/// Copy Constructor (Disabled)
	CTreeAdapter(const CTreeAdapter&) = delete;

	/** Assignment operator disabled */
	void operator=(const CTreeAdapter&) = delete;

	void Draw(Gdiplus::Graphics* graphics) override;

	/**
	* Determines if this object has been hit. Returns false to make the tree immovable
	* \param pos Position to test at
	* \return false
	*/
	bool HitTest(Gdiplus::Point pos) override { return false; }

	void SetTimeline(CTimeline* timeline) override;

	/**
	* Set the start time at which the Tree should grow
	* \param startTime The start time in frames
	*/
	void SetStartTime(double startTime) { mStartTime = startTime; }

	/**
	* Returns the start time
	* \return mStartTime Time in frames
	*/
	double GetStartTime() { return mStartTime; }

	/**
	* Set the harvest time at which the Tree should harvest
	* \param harvestTime time in frames
	*/
	void SetHarvestTime(double harvestTime) { mHarvestTime = harvestTime; }

	/**
	* Returns the harvest time
	* \return Harvest time in frames
	*/
	double GetHarvestTime() { return mHarvestTime; }

	/**
	* Sets the BasketAdapter
	* \param basket The basket adapter
	*/
	void SetBasket(std::shared_ptr<CBasketAdapter> basket) { mBasket = basket; }

	void ShowDialogueBox();

	void Save(std::shared_ptr<xmlnode::CXmlNode> root);

	void Load(std::shared_ptr<xmlnode::CXmlNode> root);

	/**
	* Sets the root location of the TreeActual
	* \param x The x position
	* \param y The y position
	*/
	void SetTreeRootLocation(int x, int y);

	/**
	* Sets the tree seed of the TreeActual
	* \param seed The seed
	*/
	void SetTreeSeed(int seed);

private:
	/// The TreeActual object to be displayed
	std::shared_ptr<CTreeActual> mTree;

	/// The time at which to start the tree
	double mStartTime = 0;

	/// The time at which to harvest the Tree
	double mHarvestTime = 270;

	/// The position of this Tree
	Gdiplus::Point mPosition = Gdiplus::Point(600, 500);

	/// The timeline that this Tree adapter is a part of. Used to set the tree frame each time the draw function is called
	CTimeline* mTimeline = nullptr;

	/// The BasketAdapter we need to use to display the Basket
	std::shared_ptr<CBasketAdapter> mBasket;
};

