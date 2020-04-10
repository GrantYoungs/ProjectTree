/**
 * \file TreeActorFactory.cpp
 *
 * \author Grant Youngs
 */

#include "pch.h"
#include <memory>
#include "TreeActorFactory.h"
#include "Actor.h"
#include "TreeAdapter.h"
#include "BasketAdapter.h"
#include "Timeline.h"

using namespace std;
using namespace Gdiplus;

/**
 * Constructor
 */
CTreeActorFactory::CTreeActorFactory()
{
}

/**
 * Destructor
 */
CTreeActorFactory::~CTreeActorFactory()
{
}

/**
 * This is a concrete factory method that returns our Tree actor
 * \returns actor Pointer to an actor object
 */
std::shared_ptr<CActor> CTreeActorFactory::Create()
{
	shared_ptr<CActor> actor = make_shared<CActor>(L"Tree");

	// Create the first tree
	auto tree = make_shared<CTreeAdapter>(L"Tree");
	tree->SetTreeRootLocation(1400, 600);
	tree->SetPosition(Point(600, 500));
	tree->SetTreeSeed(0);
	tree->SetTimeline(mTimeline);
	mTimeline->SetTree(tree.get());

	// Create the second tree
	auto secondTree = make_shared<CTreeAdapter>(L"SecondTree");
	secondTree->SetTreeRootLocation(1000, 500);
	secondTree->SetPosition(Point(600, 500));
	secondTree->SetTreeSeed(42);
	secondTree->SetTimeline(mTimeline);
	mTimeline->SetSecondTree(secondTree.get());

	// Create the basket
	auto basket = make_shared<CBasketAdapter>(L"Basket");
	basket->SetPosition(Point(0, 0));
	basket->SetTimeline(mTimeline);

	// Set the association
	tree->SetBasket(basket);
	secondTree->SetBasket(basket);

	actor->AddDrawable(basket);
	actor->AddDrawable(secondTree);
	actor->AddDrawable(tree);

	return actor;
}

