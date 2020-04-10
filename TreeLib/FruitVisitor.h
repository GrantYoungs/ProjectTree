/**
 * \file FruitVisitor.h
 *
 * \author Grant Youngs
 *
 * Visitor for Fruit objects. The goal is to determine that the object visited is infact a fruit
 */

#pragma once
#include "GrowableVisitor.h"

/**
 * Visitor for Fruit objects. The goal is to determine that the object visited is infact a fruit
 */
class CFruitVisitor :
	public CGrowableVisitor
{
public:
	CFruitVisitor();
	~CFruitVisitor();

	/// Copy Constructor (Disabled)
	CFruitVisitor(const CFruitVisitor&) = delete;

	/** Assignment operator disabled */
	void operator=(const CFruitVisitor&) = delete;

	/**
	* Determines if the object visited is a fruit
	* \param fruit The fruit to visit
	*/
	void VisitFruit(CFruit* fruit) override { mIsFruit = true; }

	/**
	* Returns if the the object visited is a fruit
	* \returns mIsFruit True if the object visited is a fruit
	*/
	bool IsFruit() { return mIsFruit; }

private:
	/// Boolean that determines if the object being visited is a fruit
	bool mIsFruit = false;
};

