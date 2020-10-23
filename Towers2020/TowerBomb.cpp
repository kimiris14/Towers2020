/**
 * \file TowerBomb.cpp
 *
 * \author PaulaRed
 * 
 * Class for a bomb tower
 */


#include "pch.h"
#include "TowerBomb.h"
#include "BombCounter.h"
#include "ProjectileExplosion.h"
#include "ImageMap.h"
#include "Game.h"

using namespace std;

/**
* Constructor
* \param level The level object that this item is a part of
* \param game The Game this item is a member of
*/
CTowerBomb::CTowerBomb(CLevel* level, CGame* game)
    : CTower(level, game, TowerBombImageID), mLevel(level)
{
    // the image ID is not properly set in the CTower constructor because it is
    // not yet initialized. This fixes that
    SetImageID(TowerBombImageID);
    game->AddImage(TowerBombImageID, TowerBombImageName);

    //Projectile has not exploded at level start
    mHasExploded = false;
}

/** Handle updates for explosion
* \param elapsed The time since the last update
*/
void CTowerBomb::Update(double elapsed)
{
 
    if (GetLevel()->IsActive())
    {
        
        mTimeTillFire -= elapsed;
        if (mTimeTillFire <= 0)
        {
            mTimeTillFire += mTimeBetweenShots;
            Fire();

            //projectile exploded
            mHasExploded = true;
        }

    }
}

/**
* Fire the explosion projectile, add and destroy it
*/
void CTowerBomb::Fire()
{
    auto explosion = make_shared<CProjectileExplosion>(GetLevel(), GetGame());

    //Set location of explosion
    explosion->SetLocation(GetX(), GetY());

    //Add explosion projectile to level
    GetLevel()->Add(explosion);

    //If level elapsed time > 0.25, deactivate projectile
    if (GetLevel()->GetElapsedTime() > mDisplayTime && mHasExploded == true)
    {
        explosion->SetActive(false);
    }
}

/**
* Draw the bomb tower only if the projectile has not exploded
* \param graphics The graphics context to draw on
*/
void CTowerBomb::Draw(Gdiplus::Graphics* graphics)
{
    if (!mHasExploded)
    {
        CItem::Draw(graphics);
    }
}

/**
* Keeps track of the number of times a bomb was successfully placed and 
* updates the time until fire accordingly
* \return true if the bomb was placed successfully, false otherwise
*/
bool CTowerBomb::Place()
{
    // upcall
    bool successful = CTower::Place();

    // count number of bombs placed using a visitor
    if (successful)
    {
        // only declare time til fire if this is the first placement
        if (mFirstPlacement)
        {
            // only visit if it was placed successfully
            CBombCounter visitor;
            mLevel->Accept(&visitor);
            int numBombsPlaced = visitor.GetNumBombs();
            mTimeTillFire = mTimeTillFire * numBombsPlaced;
            mFirstPlacement = false;
            
        }
        return true;
    }

    else
    {
        return false;
    }
}