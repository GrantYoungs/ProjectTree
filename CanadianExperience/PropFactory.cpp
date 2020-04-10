/**
 * \file PropFactory.cpp
 *
 * \author Grant Youngs
 */

#include "pch.h"
#include "PropFactory.h"
#include "ImageDrawable.h"

using namespace std;
using namespace Gdiplus;


/**
 * Constructor
 */
CPropFactory::CPropFactory()
{
}


/**
 * Destructor
 */
CPropFactory::~CPropFactory()
{
}


/**
 * Creates a prop actor
 * \returns prop The prop actor
 */
std::shared_ptr<CActor> CPropFactory::Create()
{
	std::shared_ptr<CActor> prop = make_shared<CActor>(L"Flagpole");

	auto flag = make_shared<CImageDrawable>(L"Shirt", L"images/msu_flag.png");
	flag->SetCenter(Point(100, 120));
	flag->SetPosition(Point(0, 0));
	prop->SetRoot(flag);

	prop->AddDrawable(flag);

	return prop;
}