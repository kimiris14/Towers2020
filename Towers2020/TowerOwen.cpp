/**
 * \file TowerRing.cpp
 *
 * \author PaulaRed
 */

#include "pch.h"
#include "TowerOwen.h"
#include "ImageMap.h"
#include "ProjectileOwen.h"
#include "ItemVisitorFindNearestBalloon.h"
#include "ItemBalloon.h"
#include "Game.h"
#include <math.h>

using namespace std;

/// Constant for Pi
const double Pi = 3.14159265358979323846;

/**
* Constructor
* \param level The level object that this item is a part of
* \param game The Game this item is a member of
*/
CTowerOwen::CTowerOwen(CLevel* level, CGame* game)
    : CTower(level, game, TowerOwenImageID)
{
    // the image ID is not properly set in the CTower constructor because it is
    // not yet initialized. This fixes that
    SetImageID(TowerOwenImageID);

    game->AddImage(TowerOwenImageID, TowerOwenImageName);

    mTimeTillFire = mTimeBetweenShots;
}

/** Handle updates for owen projectiles
* \param elapsed The time since the last update
*/
void CTowerOwen::Update(double elapsed)
{
    if (GetLevel()->IsActive())
    {
        mTimeTillFire -= elapsed;
        if (mTimeTillFire <= 0 && mHasDrOwen)
        {
            // reset the timer and shoot the owen projectiles
            mTimeTillFire += mTimeBetweenShots;
            Fire();
        }

    }

}

/**
* Fire a new owen projectiles and place it into the level
*/
void CTowerOwen::Fire()
{

    // find the nearest balloon
    CItemVisitorFindNearestBalloon visitor(GetX(), GetY(), mBalloonTargetRange);
    GetLevel()->Accept(&visitor);
    CItemBalloon* balloon = visitor.GetNearestBallon();

    // if there was no nearest balloon in range, then we aren't going to fire.
    if (balloon == nullptr)
        return;

    // update the firing angle so that it's pointed at the nearest balloon
    auto dX = balloon->GetX() - GetX();
    auto dY = balloon->GetY() - GetY();

    mFiringAngle = atan(dY / dX) * (180 / Pi);

    // this is necessary because inverse tangent only gives us half of the required range
    if (dX < 0) {
        mFiringAngle = mFiringAngle + 180;
    }

    auto bit = make_shared<CProjectileOwen>(GetLevel(), GetGame(), GetX(), GetY(), mFiringAngle);
    GetLevel()->AddDeferred(bit);
}