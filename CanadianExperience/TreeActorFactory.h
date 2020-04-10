/**
 * \file TreeActorFactory.h
 *
 * \author Grant Youngs
 *
 * Factory class that creates Trees and Baskets for the Actors
 */

#pragma once
#include "ActorFactory.h"


class CActor;
class CTimeline;

/**
 * Factory class that creates Trees and Baskets for the Actors
 */
class CTreeActorFactory :
	public CActorFactory
{
public:
	CTreeActorFactory();
	~CTreeActorFactory();

	std::shared_ptr<CActor> Create();

	/**
	* Sets the timeline association
	* \param timeline The timeline
	*/
	void SetTimeline(CTimeline* timeline) { mTimeline = timeline; }

	/**
	* Returns the Timeline of this tree actor factory
	* \returns mTimeline
	*/
	CTimeline* GetTimeline() { return mTimeline; }


private:
	/// The timeline we will pass off to TreeAdaptor
	CTimeline* mTimeline;
};

