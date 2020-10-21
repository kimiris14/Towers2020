/**
 * \file TowerBomb.cpp
 *
 * \author PaulaRed
 * 
 * Class for a bomb tower
 */


#include "pch.h"
#include "TowerBomb.h"
#include "ImageMap.h"
#include "Game.h"

using namespace std;

/**
* Constructor
* \param level The level object that this item is a part of
* \param game The Game this item is a member of
*/
CTowerBomb::CTowerBomb(CLevel* level, CGame* game)
    : CTower(level, game, TowerBombImageID)
{
    // the image ID is not properly set in the CTower constructor because it is
    // not yet initialized. This fixes that
    SetImageID(TowerBombImageID);

    game->AddImage(TowerBombImageID, TowerBombImageName);
}

/** Handle updates for rings
* \param elapsed The time since the last update
*/
void CTowerBomb::Update(double elapsed)
{
    mTimeTillFire -= elapsed;
    if (mTimeTillFire <= 0)
    {
        mTimeTillFire += mTimeBetweenShots;
        Fire();
    }
}

/**
* Fire ring
*/
void CTowerBomb::Fire()
{
}