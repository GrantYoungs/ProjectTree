/**
 * \file Growable.h
 *
 * \author Grant Youngs
 *
 * Base class for the tree Growables, the objects that can grow on the tree.
 */

#pragma once
#include <memory>
#include <vector>


class CFruit;
class CTreeActual;
class CGrowableVisitor;
class CFruitActual;

/**
* Base class for the tree Growables, the objects that can grow on the tree.
*/
class CGrowable
{
public:
	CGrowable();
	virtual ~CGrowable();

	/// Copy Constructor (Disabled)
	CGrowable(const CGrowable&) = delete;

	/** Assignment operator disabled */
	void operator=(const CGrowable&) = delete;

	/**
	* Draws the Growable to the screen
	* \param graphics The context to draw on
	* \param parentAngle The angle of the parent growable
	* \param x The x position to draw at
	* \param y The y position to draw at
	*/
	virtual void Draw(Gdiplus::Graphics* graphics, double parentAngle, double x, double y) {}

	/**
	* Harvests the fruit
	* \returns std::vector<std::shared_ptr<CFruitActual>> vector of fruit actuals
	*/
	virtual std::vector<std::shared_ptr<CFruitActual>> Harvest() = 0;

	/**
	* Grows the Growable object
	*/
	virtual void Grow() = 0;

	/**
	* Sets the dept of the Growable
	* \param depth The depth
	*/
	virtual void SetDepth(int depth) { mDepth = depth; }

	/**
	* Returns the depth of the Growable
	* \returns mDepth The depth of the Growable
	*/
	virtual int GetDepth() { return mDepth; }

	/**
	* Sets the position of the Growable
	* \param position The position of the Growable
	*/
	virtual void SetPosition(Gdiplus::Point position) { mPosition = position; }

	/**
	* Returns the position of the Growable
	* \returns mPosition The position of the Growable
	*/
	virtual Gdiplus::Point GetPosition() { return mPosition; }

	/**
	* Sets the angle of the Growable object
	* \param angle The angle of the Growable
	*/
	virtual void SetAngle(double angle) { mAngle = angle; }

	/**
	* Returns the angle of the Growable
	* \returns mAngle The angle of the Growable
	*/
	virtual double GetAngle() { return mAngle; }

	/**
	* Sets the maximum width of the Growable
	* \param width The maximum width of the Growable
	*/
	virtual void SetMaxWidth(double width) { mMaxWidth = width; }

	/**
	* Returns the max width of the Growable
	* \returns mMaxWidth The max width of the Growable
	*/
	virtual double GetMaxWidth() { return mMaxWidth; }

	/**
	* Sets the max height of the Growable
	* \param height The max height of the Growable
	*/
	virtual void SetMaxHeight(double height) { mMaxHeight = height; }

	/**
	* Returns the max height of the Growable
	* \returns mMaxHeight The max height of the Growable
	*/
	virtual double GetMaxHeight() { return mMaxHeight; }

	/**
	* Sets the current frame of the Growable
	* \param frame The current frame of the Growable
	*/
	virtual void SetFrame(int frame) { mCurrentFrame = frame; }

	/**
	* Returns the current frame of the Growable
	* \returns mCurrentFrame the current frame
	*/
	virtual int GetFrame() { return mCurrentFrame; }

	/**
	* Sets the parent of the Growable
	* \param parent The parent of the Growable
	*/
	virtual void SetParent(CGrowable* parent) { mParent = parent; }

	/**
	* Sets the tree that this Growable is a part of
	* \param tree The tree that this growable is a part of
	*/
	void SetTree(CTreeActual* tree) { mTree = tree; }

	/**
	* Returns the tree of this Growable
	* \returns mTree The tree
	*/
	CTreeActual* GetTree() { return mTree; }

	/**
	* Accepts a visitor
	* \param visitor The visitor
	*/
	virtual void Accept(CGrowableVisitor* visitor) = 0;

private:
	/// Depth of the Growable
	int mDepth = 0;

	/// Position of the Growable
	Gdiplus::Point mPosition = Gdiplus::Point(0, 0);

	/// The angle of the Growable
	double mAngle = 0;

	/// The max Width
	double mMaxWidth = 0;

	/// The max Height
	double mMaxHeight = 0;

	/// The currentFrame of the Growable
	int mCurrentFrame = 0;

	/// The parent of this Growable
	CGrowable* mParent = nullptr;

	/// The tree
	CTreeActual* mTree = nullptr;
};
