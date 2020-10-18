/**
 * \file ItemVisitorFindTower.cpp
 *
 * \author PaulaRed
 */

#include "pch.h"
#include "ItemVisitorFindTower.h"
#include "Tower.h"


 /** Visit a CTower object
 * \param tower Tower we are visiting */
void CItemVisitorFindTower::VisitTower(CTower* tower)
{
	if (tower->HitTest(mTargetX, mTargetY))
	{
		mTower = tower;
	}
}

/** Visit a CTowerDart object
* \param tower Tower we are visiting */
void CItemVisitorFindTower::VisitTowerDart(CTowerDart* tower)
{
	// we can downcast the dart tower to a tower for this
	VisitTower((CTower*)tower);
}

/** Visit a CTowerRing object
* \param tower Tower we are visiting */
void CItemVisitorFindTower::VisitTowerRing(CTowerRing* tower)
{
	// we can downcast the dart tower to a tower for this
	VisitTower((CTower*)tower);
}
