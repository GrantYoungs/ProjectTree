/**
 * \file Limb.cpp
 *
 * \author Grant Youngs
 */

#include "pch.h"
#include "Limb.h"
#include "Growable.h"
#include "TreeActual.h"
#include "Fruit.h"
#include "Leaf.h"
#include "FruitActual.h"
#include "GrowableVisitor.h"
#include "FruitVisitor.h"


using namespace std;
using namespace Gdiplus;

/// The Growth rate of our limb
const double GrowthRate = 1.25;

/// Constant ratio to convert radians to degrees
const double RtoD = 57.295779513;

/**
 * Constructor
 */
CLimb::CLimb()
{
	mWidth = 1;
	mLength = 2;
}

/**
 * Destructor
 */
CLimb::~CLimb()
{
}

/**
 * Goes through each of this Limb's children and add all fruit to the Tree. Then, delete the fruit from the children
 * \returns vector Empty vector of CFruitActual
 */
std::vector<std::shared_ptr<CFruitActual>> CLimb::Harvest()
{
	// Go through the children and harvest the fruit.
	// if the object is a fruit, it will return a vector consisting of itself only.
	// Everything else will recursive call down to its children
	for (auto child : mChildren)
	{
		auto fruits = child->Harvest();
		if (fruits.size() > 0)
		{
			GetTree()->AddFruit(fruits[0]);
		}
	}
	
	// Go through the children and determine if it is a fruit. If so, delete it
	for (auto child : mChildren)
	{
		CFruitVisitor visitor;
		child->Accept(&visitor);
		if (visitor.IsFruit())
		{
			auto itr = find(mChildren.begin(), mChildren.end(), child);
			if (itr != mChildren.end())
			{
				mChildren.erase(itr);
			}
		}
	}
	return vector<shared_ptr<CFruitActual>>();
}

/**
 * Draws the tree limb
 * \param graphics Context to draw on
 * \param parentAngle the angle of the parent growable
 * \param x The x location to draw at
 * \param y The y location to draw at
 */
void CLimb::Draw(Gdiplus::Graphics* graphics, double parentAngle, double x, double y)
{
	double dx = sin(parentAngle) * mLength;
	double dy = -cos(parentAngle) * mLength;

	Pen pen(Color(139, 69, 19), (REAL)mWidth);
	pen.SetEndCap(LineCapRound);
	graphics->DrawLine(&pen, (REAL)x, (REAL)y, (REAL)(x + dx), (REAL)(y + dy));

	double useAngle = parentAngle + CGrowable::GetAngle();
	FactorWindSpeed(useAngle);

	for (auto child : mChildren)
	{
		child->Draw(graphics, useAngle, (REAL)(x + dx), (REAL)(y + dy));
	}
}

/**
 * Grows the Limb
 */
void CLimb::Grow()
{
	CGrowable::SetFrame(CGrowable::GetFrame() + 1);

	double delta = 1 / double(30);
	double growRate = pow((1.0 + GrowthRate), delta);

	if (mLength < CGrowable::GetMaxHeight())
	{
		mLength *= growRate;
	}
	if (mWidth < CGrowable::GetMaxWidth())
	{
		mWidth *= growRate;
	}

	// Probably change to mChildren.size() < 2
	if (CGrowable::GetFrame() >= GetTree()->GetRandomInt(20, 36) && mChildren.size() < 2)	// Once the current frame reaches a random number between 20 and 36, and the limb has no children, add some children
	{
		Spawn();
	}

	for (auto child : mChildren)
	{
		child->Grow();
	}
}

/**
 * Determines if a leaf, limb, or fruit should be spawned on the tree, then creates it.
 */
void CLimb::Spawn()
{
	if (GetDepth() > 6 && GetTree()->GetRandomDouble(0, 1) < 0.7)
	{
		AddLeaf();
	}
	else
	{
		AddLimb();
	}
	
	if (GetDepth() > 8 && GetTree()->GetRandomDouble(0, 1) < 0.1)
	{
		AddFruit();
	}
	else
	{
		AddLimb();
	}
}

/**
 * Private function that factors wind speed into the tree
 * \param useAngle The angle that will be used to draw the children
 */
void CLimb::FactorWindSpeed(double& useAngle)
{
	if (useAngle * RtoD < 90)
	{
		useAngle += GetTree()->GetWindSpeed() * 0.002;
	}
	else if (useAngle * RtoD >= 90)
	{
		useAngle -= GetTree()->GetWindSpeed() * 0.001;
	}
}

/**
 * Creates and adds a CLimb to the Tree
 */
void CLimb::AddLimb()
{
	std::shared_ptr<CLimb> branch = make_shared<CLimb>();
	branch->SetDepth(CGrowable::GetDepth() + 1);
	double dx = sin(GetAngle()) * mLength;
	double dy = -cos(GetAngle()) * mLength;

	Gdiplus::Point position = Gdiplus::Point((INT)(GetPosition().X + dx), (INT)(GetPosition().Y + dy));
	branch->SetPosition(position);

	branch->SetMaxHeight(GetMaxHeight() * .8);
	branch->SetMaxWidth(GetMaxWidth() * .8);

	double randomAngle = GetTree()->GetRandomDouble(-1.1, 1.1);
	branch->SetAngle(randomAngle);

	branch->SetFrame(0);

	mChildren.push_back(branch);
	branch->SetParent(this);
	branch->SetTree(GetTree());
}


/**
 * Creates and adds a CLeaf to the Tree
 */
void CLimb::AddLeaf()
{
	auto child = make_shared<CLeaf>();

	child->SetImage(GetTree()->GetLeafImage());
	child->SetAngle(GetTree()->GetRandomDouble(-1.1, 1.1));	// Leaf will have different angle than fruit

	double dx = sin(GetAngle()) * mLength;
	double dy = -cos(GetAngle()) * mLength;
	Gdiplus::Point position = Gdiplus::Point((INT)(GetPosition().X + (dx)), (INT)(GetPosition().Y + dy));

	child->SetPosition(position);
	child->SetDepth(CGrowable::GetDepth() + 1);
	child->SetMaxHeight(GetMaxHeight() * .8);
	child->SetMaxWidth(GetMaxWidth() * .8);
	child->SetFrame(0);

	mChildren.push_back(child);
	child->SetParent(this);
	child->SetTree(GetTree());
}

/**
 * Creates and adds a CFruit to the Tree
 */
void CLimb::AddFruit()
{
	auto child = make_shared<CFruitActual>();

	child->SetImage(GetTree()->GetFruitImage());
	child->SetAngle(GetTree()->GetRandomDouble(-1.1, 1.1));

	double dx = sin(GetAngle()) * mLength;
	double dy = -cos(GetAngle()) * mLength;
	Gdiplus::Point position = Gdiplus::Point((INT)(GetPosition().X + (dx)), (INT)(GetPosition().Y + dy));

	child->SetPosition(position);
	child->SetDepth(CGrowable::GetDepth() + 1);
	child->SetMaxHeight(GetMaxHeight() * .8);
	child->SetMaxWidth(GetMaxWidth() * .8);
	child->SetFrame(0);

	mChildren.push_back(child);
	child->SetParent(this);
	child->SetTree(GetTree());
	child->SetSelf(child);
}

/**
 * Accept function to accept a visitor
 * \param visitor The visitor to accept
 */
void CLimb::Accept(CGrowableVisitor* visitor)
{
	for (auto child : mChildren)
	{
		child->Accept(visitor);
	}
}
