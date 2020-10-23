/**
 * \file TowerOwenCounter.h
 *
 * \author PaulaRed
 *
 * Bomb visitor to count bombs
 */


#pragma once

#include "ItemVisitor.h"

 // Forward references to all item types
class CTower;
class CTowerOwen;

/**
* Bomb visitor for counting bombs
*/
class CTowerOwenCounter : public CItemVisitor
{
public:

	/**Visits and counts owen towers in the level
	* \param owentower The owen tower we are visiting
	*/
	virtual void CTowerOwenCounter::VisitTowerOwen(CTowerOwen* owentower) { mNumOwens++; }

	/**
	* Getter for number of owens in the level
	* \returns number of owens in the level
	*/
	int GetNumOwens() { return mNumOwens; }

private:

	/// number of owens in the level
	int mNumOwens = 0;
};