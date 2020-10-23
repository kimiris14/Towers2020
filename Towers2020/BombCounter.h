/**
 * \file BombCounter.h
 *
 * \author PaulaRed
 *
 * Bomb visitor to count bombs
 */


#pragma once

#include "ItemVisitor.h"

 // Forward references to all item types
class CTower;
class CTowerBomb;

/**
* Bomb visitor for counting bombs
*/
class CBombCounter : public CItemVisitor
{
public:

	/**Visits and counts bombs in the level
	* \param bombtower The bomb tower we are visiting
	*/
	virtual void CBombCounter::VisitTowerBomb(CTowerBomb* bombtower) { mNumBombs++; }

	/**
	* Getter for number of bombs in the level
	* \returns number of bombs in the level
	*/
	int GetNumBombs() { return mNumBombs; }

private:

	/// number of bombs in the level
	int mNumBombs = 0;
};

