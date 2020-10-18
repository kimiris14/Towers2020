/**
 * \file ItemVisitorFindTile.cpp
 *
 * \author PaulaRed
 */

#include "pch.h"
#include "ItemVisitorFindTile.h"
#include "ItemTileRoad.h"


 /** Visit a CItemTileRoad object
 * \param road Road we are visiting */
void CItemVisitorFindTile::VisitRoad(CItemTileRoad* road)
{
	if (road->GetGridX() == mTargetX && road->GetGridY() == mTargetY)
	{
		mTile = road;
	}
}

/** Visit a CItemTileRoad object
* \param tile Tile we are visiting */
void CItemVisitorFindTile::VisitTile(CItemTile* tile)
{
	if (tile->GetGridX() == mTargetX && tile->GetGridY() == mTargetY)
	{
		mTile = tile;
	}
}
