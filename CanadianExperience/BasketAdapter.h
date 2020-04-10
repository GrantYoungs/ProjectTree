/**
 * \file BasketAdapter.h
 *
 * \author Grant Youngs
 *
 * Basket Adapter class that allows The Canadian Experience to draw the BasketActual in The Canadian Experience
 */

#pragma once
#include <memory>
#include <string>
#include "Drawable.h"

class CBasketActual;
class CTimeline;
class CTreeAdapter;
class CFruit;

/**
 * Basket Adapter class that allows The Canadian Experience to draw the BasketActual in The Canadian Experience
 */
class CBasketAdapter :
	public CDrawable
{
public:
	/**
	 * Constructor
	 * \param name Name of the Drawable part
	 */
	CBasketAdapter(const std::wstring& name);

	/**
	 * Destructor
	 */
	~CBasketAdapter();

	/// Copy Constructor (Disabled)
	CBasketAdapter(const CBasketAdapter&) = delete;

	/** Assignment operator disabled */
	void operator=(const CBasketAdapter&) = delete;

	/**
	 * Draws the Basket Actual
	 * \param graphics
	 */
	void Draw(Gdiplus::Graphics* graphics) override;

	/**
	 * Does a hit test on the basket aactual
	 * \param pos The position to test
	 * \returns bool false
	 */
	bool HitTest(Gdiplus::Point pos) override { return false; }

	/**
	 * Sets the timeline association
	 * \param timeline The timeline object
	 */
	void SetTimeline(CTimeline* timeline) override { CDrawable::SetTimeline(timeline); mTimeline = timeline; }

	/**
	 * Sets the tree association
	 * \param tree The tree object
	 */
	void SetTree(std::shared_ptr<CTreeAdapter> tree) { mTree = tree; }

	/**
	 * Adds a collection of fruit to the Basket Actual
	 * \param fruit Collection to add
	 */
	void AddToBasket(std::vector<std::shared_ptr<CFruit>> fruit);

	/**
	 * Empties the Basket Actual
	 */
	void EmptyBasket();

private:
	/// The timeline that this BasketAdapter is a part of
	CTimeline* mTimeline = nullptr;

	/// The actual basket to be displayed
	std::shared_ptr<CBasketActual> mBasket;

	/// The Tree Adapter that this class is linked with to utilize the harvest function
	std::shared_ptr<CTreeAdapter> mTree;
};

