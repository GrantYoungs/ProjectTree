/**
 * \file BasketActual.h
 *
 * \author Grant Youngs
 *
 * Implements a basket to be drawn with the tree
 */

#pragma once
#include "Basket.h"
#include <string>

class CFruit;

/**
 * Implements a basket to be drawn with the tree
 */
class CBasketActual : public CBasket
{
public:
	/**
	 * Constructor
	 */
	CBasketActual();

	/**
	 * Destructor
	 */
	~CBasketActual();

	/// Copy Constructor (Disabled)
	CBasketActual(const CBasketActual&) = delete;

	/// Assignment operator/disabled
	void operator=(const CBasketActual&) = delete;

	/**
	* Set the position for the basket.
	* \param x X location (pixels)
	* \param y Y location (pixels)
	*/
	void SetBasketLocation(int x, int y) override { mPosition = Gdiplus::Point(x, y); }

	/**
	* Draw the basket at the currently specified location
	* \param graphics GDI+ Graphics object
	*/
	void DrawBasket(Gdiplus::Graphics* graphics) override;

	/**
	 * Adds a collection of fruit to the basket
	 * \param fruits The collection of fruits to add
	 */
	void AddToBasket(std::vector < std::shared_ptr<CFruit>> fruits) override;

	/**
	 * Empty all fruit from the basket
	 */
	void EmptyBasket() override;

private:
	/**
	 * Loads the image for the back of the basket
	 * \param filename File path to the image
	 */
	void LoadBasketBack(const std::wstring& filename);

	/**
	 * Loads the image for the front of the basket
	 * \param filename File path to the image
	 */
	void LoadBasketFront(const std::wstring& filename);

	/**
	 * Private function that draws the back of the basket
	 * \param graphics Context to draw on
	 */
	void DrawBack(Gdiplus::Graphics* graphics);

	/**
	 * Private function that draws the front of the basket
	 * \param graphics Context to draw on
	 */
	void DrawFront(Gdiplus::Graphics* graphics);

	/// The leaf image to be used for the back of the basket
	std::shared_ptr<Gdiplus::Bitmap> mBasketBack;

	/// The leaf image to be used for the front of the basket
	std::shared_ptr<Gdiplus::Bitmap> mBasketFront;

	/// The position of this basket
	Gdiplus::Point mPosition = Gdiplus::Point(0, 0);

	/// Vector of Fruits
	std::vector<std::shared_ptr<CFruit>> mFruits;
};

