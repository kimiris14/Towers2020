/**
 * \file TowerRing.cpp
 *
 * \author PaulaRed
 */

#include "pch.h"
#include "TowerRing.h"
#include "ImageMap.h"
#include "Game.h"

using namespace std;

/**
* Constructor
* \param level The level object that this item is a part of
* \param game The Game this item is a member of
*/
CTowerRing::CTowerRing(CLevel* level, CGame* game)
    : CTower(level, game, TowerRingImageID)
{
    // the image ID is not properly set in the CTower constructor because it is
    // not yet initialized. This fixes that
    SetImageID(TowerRingImageID);

    game->AddImage(TowerRingImageID, TowerRingImageName);
}

/** Handle updates for rings
* \param elapsed The time since the last update
*/
void CTowerRing::Update(double elapsed)
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
void CTowerRing::Fire()
{
}