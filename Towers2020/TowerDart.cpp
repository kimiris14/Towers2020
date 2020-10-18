/**
 * \file TowerDart.cpp
 *
 * \author PaulaRed
 */


#include "pch.h"
#include "TowerDart.h"
#include "ImageMap.h"
#include "Game.h"

using namespace std;

/// dart balloon filename
const wstring dartImageName = L"images/tower8.png";

/// dart id number
///const int tower8 = ; //not yet assigned


/**
* Constructor
* \param level The level object that this item is a part of
* \param game The Game this item is a member of
* \param imageID The image id for this item
*/
CTowerDart::CTowerDart(CLevel* level, CGame* game)
	: CTower(level, game, TowerImageID)
{
	// the image ID is not properly set in the CTower constructor because it is
	// not yet initialized. This fixes that
	SetImageID(TowerImageID);

	level->AddImage(TowerImageID, TowerImageName);
}

/** Handle updates for darts
* \param elapsed The time since the last update
*/
void CTowerDart::Update(double elapsed)
{
    mTimeTillFire -= elapsed;
    if (mTimeTillFire <= 0)
    {
        mTimeTillFire += mTimeBetweenShots;
        Fire();
    }
}

/**
* Fire dart
*/
void CTowerDart::Fire()
{
}
