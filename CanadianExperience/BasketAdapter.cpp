/**
 * \file BasketAdapter.cpp
 *
 * \author Grant Youngs
 */

#include "pch.h"
#include "BasketAdapter.h"
#include "TreeFactory.h"
#include "BasketActual.h"
#include "Fruit.h"

using namespace std;
using namespace Gdiplus;

/**
 * Constructor
 * \param name Name of the Drawable part
 */
CBasketAdapter::CBasketAdapter(const std::wstring& name) : CDrawable(name)
{
	CTreeFactory factory;
	mBasket = factory.CreateBasket();
	mBasket->SetBasketLocation(900, 500);
}

/**
 * Destructor
 */
CBasketAdapter::~CBasketAdapter()
{
}

/**
 * Draws the Basket Actual
 * \param graphics 
 */
void CBasketAdapter::Draw(Gdiplus::Graphics* graphics)
{
	mBasket->DrawBasket(graphics);
}

/**
 * Adds a collection of fruit to the Basket Actual
 * \param fruit Collection to add
 */
void CBasketAdapter::AddToBasket(std::vector<std::shared_ptr<CFruit>> fruit)
{
	mBasket->AddToBasket(fruit);
}

/**
 * Empties the Basket Actual
 */
void CBasketAdapter::EmptyBasket()
{
	mBasket->EmptyBasket();
}
