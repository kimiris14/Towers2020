/**
 * \file ItemVisitorFindRoad.cpp
 *
 * \author PaulaRed
 */

#include "pch.h"
#include "ItemVisitorFindRoad.h"
#include "ItemTileRoad.h"


/** Visit a CItemTileRoad object
* \param road Road we are visiting */
void CItemVisitorFindRoad::VisitRoad(CItemTileRoad* road)
{
	if (road->GetGridX() == mTargetX && road->GetGridY() == mTargetY)
	{
		mRoad = road;
	}
}
