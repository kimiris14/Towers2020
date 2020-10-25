/**
 * \file TowerRing.cpp
 *
 * \author PaulaRed
 */

#include "pch.h"
#include "TowerRing.h"
#include "ProjectileRing.h"
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
    if (GetLevel()->IsActive())
    {
        mTimeTillFire -= elapsed;
        if (mTimeTillFire <= 0)
        {
            // reset the timer and shoot the ring
            mTimeTillFire += mTimeBetweenShots;
            Fire();
        }
    }

}

/**
* Fire a new ring and place it into the level
*/
void CTowerRing::Fire()
{
    auto ring = make_shared<CProjectileRing>(GetLevel(), GetGame());

    // the ring should be centered over the tower
    ring->SetLocation(GetX(), GetY());

    // Adds the ring to the level's mItems
    GetLevel()->AddDeferred(ring);
}