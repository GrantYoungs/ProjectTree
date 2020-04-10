/**
 * \file ImageGrowable.h
 *
 * \author Grant Youngs
 *
 * Base class for the Growables on the tree that have an image
 */

#pragma once
#include "Growable.h"

class CFruit;
class CTreeActual;
class CGrowableVisitor;
class CFruitActual;

/**
 * Base class for the Growables on the tree that have an image
 */
class CImageGrowable :
	public CGrowable
{
public:
	CImageGrowable();
	~CImageGrowable();

	/// Copy Constructor (Disabled)
	CImageGrowable(const CImageGrowable&) = delete;

	/** Assignment operator disabled */
	void operator=(const CImageGrowable&) = delete;

	virtual void Draw(Gdiplus::Graphics* graphics, double parentAngle, double x, double y) override;

	/**
	* Grows the image Growable
	*/
	virtual void Grow();

	/**
	* Returns an empty collection of fruits
	* \returns std::vector<std::shared_ptr<CFruitActual>> An empty collection of fruits
	*/
	virtual std::vector<std::shared_ptr<CFruitActual>> Harvest() override;

	/**
	* Sets the image bitmap
	* \param image The image
	*/
	void SetImage(std::shared_ptr<Gdiplus::Bitmap> image) { mImage = image; }

	/**
	* Returns the image Bitmap of this ImageGrowable
	* \return mImage The image Bitmap
	*/
	std::shared_ptr<Gdiplus::Bitmap> GetImage() { return mImage; }

	/**
	* Sets the scale 
	* \param scale The scale
	*/
	void SetScale(double scale) { mScale = scale; }

	/**
	* Accepts a visitor
	* \param visitor The visitor to be accepted
	*/
	virtual void Accept(CGrowableVisitor* visitor) override {}

private:
	/// The Bitmap image of this ImageGrowable
	std::shared_ptr<Gdiplus::Bitmap> mImage;

	/// The scale at which to draw the image
	double mScale = 0.1;
};

