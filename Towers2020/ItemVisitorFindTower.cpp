/**
 * \file ItemVisitorFindTower.cpp
 *
 * \author PaulaRed
 */

#include "pch.h"
#include "ItemVisitorFindTower.h"
#include "Tower.h"
#include "TowerOwen.h"


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
	// we can upcast the dart tower to a tower for this
	VisitTower((CTower*)tower);
}

/** Visit a CTowerRing object
* \param tower Tower we are visiting */
void CItemVisitorFindTower::VisitTowerRing(CTowerRing* tower)
{
	// we can upcast the ring tower to a tower for this
	VisitTower((CTower*)tower);
}

/** Visit a CTowerBomb object
* \param tower Tower we are visiting */
void CItemVisitorFindTower::VisitTowerBomb(CTowerBomb* tower)
{
	// we can upcast the bomb tower to a tower for this
	VisitTower((CTower*)tower);
}


/** Visit a CTowerOwen object
 * \param tower Dr Owen Tower we are visiting 
 */
void CItemVisitorFindTower::VisitTowerOwen(CTowerOwen* tower)
{
	// we can upcast the dart tower to a tower for this
	VisitTower((CTower*)tower);

	if (tower->HitTest(mTargetX, mTargetY))
	{
		mOwenTower = tower;
	}

	if (mClearOwens)
	{
		tower->SetDrOwen(false);
	}
}
