/**
 * \file PropFactory.h
 *
 * \author Grant Youngs
 *
 * Factory that creates a prop
 */

#pragma once
#include "ActorFactory.h"

/**
 * Factory that creates a prop
 */
class CPropFactory :
	public CActorFactory
{
public:
	CPropFactory();
	virtual ~CPropFactory();

	/// Copy Constructor (Disabled)
	CPropFactory(const CPropFactory&) = delete;

	/** Assignment operator disabled */
	void operator=(const CPropFactory&) = delete;

	std::shared_ptr<CActor> Create();
};

