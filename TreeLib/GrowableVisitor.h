/**
 * \file GrowableVisitor.h
 *
 * \author Grant Youngs
 *
 * Base class for the visitors for Growables
 */

#pragma once

class CFruit;
class CLimb;
class CLeaf;


/**
 * Base class for the visitors for Growables
 */
class CGrowableVisitor
{
public:
	CGrowableVisitor();
	virtual ~CGrowableVisitor();

	/// Copy Constructor (Disabled)
	CGrowableVisitor(const CGrowableVisitor&) = delete;

	/** Assignment operator disabled */
	void operator=(const CGrowableVisitor&) = delete;

	/**
	* Visits a fruit
	* \param fruit The fruit to visit
	*/
	virtual void VisitFruit(CFruit* fruit) {}

	/**
	* Visits a leaf
	* \param leaf The leaf to visit
	*/
	virtual void VisitLeaf(CLeaf* leaf) {}

	/**
	* Visits a Limb
	* \param limb The limb to visit
	*/
	virtual void VisitLimb(CLimb* limb) {}
};

