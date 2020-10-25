/**
 * \file BombCounter.cpp
 *
 * \author Dave Yonkers
 */

#include "pch.h"
#include "BombCounter.h"
#include "TowerBomb.h"

/**Visits and counts bombs in the level
* \param bombtower The bomb tower we are visiting
*/
void CBombCounter::VisitTowerBomb(CTowerBomb* bombtower)
{
	if (bombtower->IsActive())
		mNumBombs++;
}
