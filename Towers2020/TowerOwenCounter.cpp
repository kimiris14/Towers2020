/**
 * \file TowerOwenCounter.cpp
 *
 * \author Dave Yonkers
 */

#include "pch.h"
#include "TowerOwenCounter.h"
#include "TowerOwen.h"

/**Visits and counts owen towers in the level
* \param owentower The owen tower we are visiting
*/
void CTowerOwenCounter::VisitTowerOwen(CTowerOwen* owentower)
{
	if (owentower->IsActive())
		mNumOwens++;
}