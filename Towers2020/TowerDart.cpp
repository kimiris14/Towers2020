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

/// tower 8 filename
const wstring tower8ImageName = L"images/tower8.png";

/// dart id number
const int tower8Id = 61; //not yet assigned


/**
* Constructor
* \param level The level object that this item is a part of
* \param game The Game this item is a member of
* \param imageID The image id for this item
*/
CTowerDart::CTowerDart(CLevel* level, CGame* game, int imageID)
	: CTower(level, game, imageID)
{
    level->AddImage(tower8Id, tower8ImageName);
}

/**
* Draw the item from the corner
* \param graphics The graphics context to draw on
*/
void CTowerDart::Draw(Gdiplus::Graphics* graphics)
{
}

/**
* Set item location
* \param x X location
* \param y Y location
*/
void CTowerDart::SetLocation(double x, double y)
{
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
