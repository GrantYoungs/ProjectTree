/**
 * \file Leaf.h
 *
 * \author Grant Youngs
 *
 * Implements a leaf object to be displayed on the tree
 */

#pragma once
#include "ImageGrowable.h"

class CFruit;

/**
 * Implements a leaf object to be displayed on the tree
 */
class CLeaf :
	public CImageGrowable
{
public:
	CLeaf();
	~CLeaf();

	/// Copy Constructor (Disabled)
	CLeaf(const CLeaf&) = delete;

	/** Assignment operator disabled */
	void operator=(const CLeaf&) = delete;
};

