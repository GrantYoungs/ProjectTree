/**
 * \file Limb.h
 *
 * \author Grant Youngs
 *
 * Implements the tree limbs in the Tree
 */

#pragma once
#include <memory>
#include "Growable.h"

class CLimb :
	public CGrowable
{
public:
	CLimb();
	~CLimb();

	/// Copy Constructor (Disabled)
	CLimb(const CLimb&) = delete;
};

