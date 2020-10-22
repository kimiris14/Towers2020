/**
 * \file TowerRing.cpp
 *
 * \author PaulaRed
 */

#include "pch.h"
#include "TowerOwen.h"
#include "ImageMap.h"
#include "Game.h"

using namespace std;

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
    //SetImageID(TowerOwenImageID);

    //game->AddImage(TowerOwenImageID, TowerOwenImageName);
}

/** Handle updates for owen projectiles
* \param elapsed The time since the last update
*/
void CTowerOwen::Update(double elapsed)
{
    if (GetLevel()->IsActive())
    {
        mTimeTillFire -= elapsed;
        if (mTimeTillFire <= 0)
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
}