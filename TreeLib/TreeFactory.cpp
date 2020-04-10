/**
 * \file TreeFactory.cpp
 *
 * \author Charles Owen
 *
 * You are allowed to change this file.
 */

#include "pch.h"
#include <memory>
#include "TreeFactory.h"
#include "Tree.h"
#include "Basket.h"
#include "TreeActual.h"
#include "BasketActual.h"

using namespace std;

/**
 * Constructor
 */
CTreeFactory::CTreeFactory()
{
}


/**
 * Destructor
 */
CTreeFactory::~CTreeFactory()
{
}


/**
 * Create a Tree object
 * \returns Object of type CTree
 */
std::shared_ptr<CTreeActual> CTreeFactory::CreateTree()
{
    return make_shared<CTreeActual>();
}


/**
 * Create a Basket object
 * \returns Object of type CBasket
 */
std::shared_ptr<CBasketActual> CTreeFactory::CreateBasket()
{
    return make_shared<CBasketActual>();
}



