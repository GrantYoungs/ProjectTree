/**
 * \file FruitActual.h
 *
 * \author Grant Youngs
 *
 * This class implements a Fruit object that can be manipulated and drawn to the screen
 */

#pragma once
#include "Fruit.h"
#include "ImageGrowable.h"

class CGrowableVisitor;

/**
 * This class implements a Fruit object that can be manipulated and drawn to the screen
 */
class CFruitActual : public CFruit, public CImageGrowable
{
public:
	CFruitActual();
	~CFruitActual();

	CFruitActual(const CFruitActual&) = delete;

	/** Assignment operator disabled */
	void operator=(const CFruitActual&) = delete;

	/**
	* Set the position of the fruit in the basket
	*
	* This position is relative to the basket, so
	* it will be added to the basket location passed
	* to DrawInBasket when we draw it
	* \param x X position in pixels
	* \param y Y position in pixels
	*/
	void SetBasketPosition(int x, int y) override;

	/**
	* Draw the fruit in the basket
	* \param graphics The graphics object to draw on
	* \param x X location of the basket
	* \param y Y location of the basket
	*/
	void DrawInBasket(Gdiplus::Graphics* graphics, int x, int y) override;

	/**
	 * Adds this fruit to a vector of fruit actuals and returns it
	 * \returns fruits The vector of fruits
	 */
	std::vector<std::shared_ptr<CFruitActual>> Harvest() override;

	/**
	 * Sets the mSelf to itself
	 * \param self Itself
	 */
	void SetSelf(std::shared_ptr<CFruitActual> self) { mSelf = self; }

	/**
	 * Returns a shared_ptr to itself
	 * \returns mSelf.lock() returns a shared_ptr of itself
	 */
	std::shared_ptr<CFruitActual> GetSelf() { return mSelf.lock(); }

	/**
	 * Accepts a visitor
	 * \param visitor The visitor
	 */
	void Accept(CGrowableVisitor* visitor) override;

private:
	/// A pointer to itself
	std::weak_ptr<CFruitActual> mSelf;

	/// The x position of the fruit in relation to the basket
	double mRelativeBasketPosX = 0;

	/// The y position of the fruit in relation to the basket
	double mRelativeBasketPosY = 0;
};

