/**
 * \file TreeActual.h
 *
 * \author Grant Youngs
 *
 * This class represents a tree that we can manipulate
 */

#pragma once
#include <memory>
#include <string>
#include "Tree.h"
#include "PseudoRandom.h"
#include "Limb.h"


class CFruit;
class CFruitActual;

/**
 * This class represents a tree that we can use instead of the default CTree class.
 */
class CTreeActual :
	public CTree
{
public:
	CTreeActual();
	~CTreeActual();

	/// Copy constructor (disabled)
	CTreeActual(const CTreeActual&) = delete;

	/** Assignment operator disabled */
	void operator=(const CTreeActual&) = delete;

	/**
	* Sets location at which to draw this tree
	* \param x X position
	* \param y Y position
	*/
	void SetRootLocation(int x, int y) override { mRootLocationX = x; mRootLocationY = y; }

	void DrawTree(Gdiplus::Graphics* graphics) override;

	void SetTreeFrame(int frame) override;

	/**
	* Sets the wind speed affecting the tree
	* \param speed The windspeed to set
	*/
	void SetWindSpeed(double speed) override { mWindSpeed = speed; }

	/**
	* Returns the wind speed
	* \return mWindSpeed The windspeed
	*/
	double GetWindSpeed() { return mWindSpeed; }

	virtual std::vector<std::shared_ptr<CFruit>> Harvest() override;

	/**
	* Returns the seed of the tree
	* \return mSeed The seed of the tree
	*/
	int GetSeed() override { return mSeed; }

	void SetSeed(int seed) override;

	void Reset();

	/**
	* Returns a pseudo random integer between two values
	* \param fm The lower value range
	* \param to The higher value range
	* \return num The pseudo random integer
	*/
	int GetRandomInt(int fm, int to) { int num = mRandom.Random(fm, to); return num; }

	/**
	* Returns a pseudo random double between two values
	* \param fm The lower value range
	* \param to The higher value range
	* \return num The pseudo random double
	*/
	double GetRandomDouble(double fm, double to) { double num = mRandom.Random(fm, to); return num; }	// Assigning this to a variable as opposed to just returning the value of the function to make Doxygen happy

	/**
	* Returns the bitmap image for the leaf
	* \return mLeafImage the bitmap image for the leaf
	*/
	std::shared_ptr<Gdiplus::Bitmap> GetLeafImage() { return mLeafImage; }

	/**
	* Returns the bitmap image for the fruit
	* \return mFruitImage the bitmap image for the fruit
	*/
	std::shared_ptr<Gdiplus::Bitmap> GetFruitImage() { return mFruitImage; }

	/**
	* Adds a fruit to the vector of fruits
	* \param fruit The fruit to add
	*/
	void AddFruit(std::shared_ptr<CFruit> fruit) { mFruits.push_back(fruit); }

private:

	void InitializeRoot();

	void LoadLeafImage(const std::wstring& filename);

	void LoadFruitImage(const std::wstring& filename);

	/// The current frame we're on
	int mCurrentFrame = 0;

	/// The frame rate
	double mFrameRate = 0;

	/// The wind speed affecting the tree
	double mWindSpeed = 0;

	/// The seed that tells us how to draw the tree
	int mSeed = 0;

	/// The x location of our root
	int mRootLocationX = 0;

	/// The y location of our root
	int mRootLocationY = 0;

	/// The root of our tree
	CLimb* mRoot = nullptr;

	/// Our PseudoRandom object that randomly generates numbers we'll need
	CPseudoRandom mRandom;

	/// The leaf image to be used for all leaf objects
	std::shared_ptr<Gdiplus::Bitmap> mLeafImage;

	/// The fruit image to be used for all fruit objects
	std::shared_ptr<Gdiplus::Bitmap> mFruitImage;

	/// A collection of fruits
	std::vector<std::shared_ptr<CFruit>> mFruits;
};

