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

/// ring id number
const int ringID = 52; //assigned
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
            mTimeTillFire += mTimeBetweenShots;
            Fire();
        }
    }

}

/**
* Fire ring
*/
void CTowerRing::Fire()
{
    auto ring = make_shared<CProjectileRing>(GetLevel(), GetGame(), ringID);
    int radius = ring->GetRadius();
    double rad = (double(radius));

    double secondsPerRing = 1.0 / mGrowingSpeed;
    mRingSpawnTime = mRingSpawnTime + GetLevel()->GetElapsedTime();

    if ((mRingSpawnTime >= secondsPerRing))
    {
        rad = rad + (GetLevel()->GetElapsedTime()) * (mGrowingSpeed);
        ring->SetRadius((int)rad);
 
    }
    ring->SetLocation(this->GetX(), this->GetY());

    GetLevel()->Add(ring);
    mRingSpawnTime = 0.0;
}