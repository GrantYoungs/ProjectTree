/**
 * \file Limb.h
 *
 * \author Grant Youngs
 *
 * Implements tree limbs that will grow from other limbs, and have fruit and leaves growing off it
 */

#pragma once
#include "Growable.h"
#include <memory>

class CTreeActual;
class CFruit;
class CLeaf;
class CFruitActual;
class CGrowableVisitor;

/**
 * Implements tree limbs that will grow from other limbs, and have fruit and leaves growing off it
 */
class CLimb : public CGrowable
{
public:
	CLimb();

	~CLimb();

	/// Copy Constructor (Disabled)
	CLimb(const CLimb&) = delete;

	/** Assignment operator disabled */
	void operator=(const CLimb&) = delete;

	std::vector<std::shared_ptr<CFruitActual>> Harvest() override;

	void Grow() override;

	void Draw(Gdiplus::Graphics* graphics, double parentAngle, double x, double y) override;

	void Accept(CGrowableVisitor* visitor) override;

private:
	void AddLimb();
	void AddLeaf();
	void AddFruit();
	void Spawn();

	void FactorWindSpeed(double &useAngle);

	/// The children of this limb
	std::vector<std::shared_ptr<CGrowable>> mChildren;

	/// The width of the limb
	double mWidth = 0;

	/// The length of the limb
	double mLength = 0;
};

