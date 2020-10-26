/**
 * \file TowerDart.cpp
 *
 * \author PaulaRed
 */

#include "pch.h"
#include "TowerDart.h"
#include "ImageMap.h"
#include "Game.h"
#include "ProjectileDart.h"

using namespace std;
using namespace Gdiplus;

/// Dart image ID
const int dartID = 51;

/// Pi
const double Pi = 3.14159265358979323846;
/**
* Constructor
* \param level The level object that this item is a part of
* \param game The Game this item is a member of
*/
CTowerDart::CTowerDart(CLevel* level, CGame* game)
	: CTower(level, game, TowerImageID)
{
	// the image ID is not properly set in the CTower constructor because it is
	// not yet initialized. This fixes that
	SetImageID(TowerImageID);
	game->AddImage(TowerImageID, TowerImageName);

    mTimeTillFire = mTimeBetweenShots;

}

/** Handle updates for darts
* \param elapsed The time since the last update
*/
void CTowerDart::Update(double elapsed)
{

    if (!IsActive())
        return;


    if (GetLevel()->IsActive())
    {
        mTimeTillFire -= elapsed;
        if (mTimeTillFire < 0)
        {
            mTimeTillFire += mTimeBetweenShots;
            Fire();
        }
    }
}

/**
* Fire dart
*/
void CTowerDart::Fire()
{
    // Get image specifics
    shared_ptr<Bitmap> dartTowerImage = GetGame()->GetImage(TowerImageID);
    double wid = dartTowerImage->GetWidth();
    double hit = dartTowerImage->GetHeight();

    // Create 8 darts
    for (double i = 0; i < 8; i++)
    {
        shared_ptr<CItem> item = nullptr;
        auto dart = make_shared<CProjectileDart>(GetLevel(), GetGame(), dartID);

        // Set the dart's angle
        dart->SetAngle(i * (Pi / 4.0) - Pi / 4.0);
        double a = dart->GetAngle();
        double dist = dart->GetDistance();

        double sn = sin(a); // sin
        double cs = cos(a); // cos

        // Assign dart location
        double x = GetX() + cs * dart->GetDistance();
        double y = GetY() + sn * dart->GetDistance();
        dart->SetLocation(x, y);

        // Upcast and append to level's AddDeferred
        item = dart;
        GetLevel()->AddDeferred(item);

        // Set X and Y speed
        dart->SetSpeed(200 * cs, 200 * sn);
    }
}

