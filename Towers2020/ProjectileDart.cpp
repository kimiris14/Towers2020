/**
 * \file ProjectileDart.cpp
 *
 * \author PaulaRed
 */

#include "pch.h"
#include "ProjectileDart.h"
#include "ImageMap.h"
#include "Game.h"

using namespace std;
using namespace Gdiplus;

/// dart balloon filename
const wstring dartImageName = L"images/dart.png";

/// dart id number
const int dartID = 51; //assigned

/// Constant to covert radians to degrees.
const double RtoD = 57.2957795;

/// Pi
const double Pi = 3.14159265358979323846;

 /**
 * Constructor
 * \param level The Level this item is a member of
 * \param game The Game this item is a member of
 * \param imageID The image id for this item
 */
CProjectileDart::CProjectileDart(CLevel* level, CGame* game, int imageID) : CProjectile(level, game, imageID)
{
    SetImageID(dartID);
 	game->AddImage(dartID, dartImageName);
    
}

/**
 * Draw the rotated dart. Rotation is determined by the member
 * variable mAngle, which is the rotation in radians.
 *
 * @param graphics The graphics context to draw on.
 */
void CProjectileDart::Draw(Gdiplus::Graphics* graphics)
{
    // Check to make sure projectile is still active
    if (IsActive())
    {
        shared_ptr<Bitmap> dartImage = GetGame()->GetImage(dartID);
        if (dartImage != nullptr)
        {
            // Find image specifics
            int wid = dartImage->GetWidth();
            int hit = dartImage->GetHeight();
            // Draw
            auto save = graphics->Save();
            graphics->TranslateTransform((REAL)(GetX()),
                (REAL)(GetY()));
            graphics->RotateTransform((REAL)(mAngle * RtoD));
            graphics->DrawImage(dartImage.get(), 0,
                0, wid, hit);
            graphics->Restore(save);
        }
    }
}

/**
 * Update function
 * \param elapsed Time elapsed
 */
void CProjectileDart::Update(double elapsed)
{
    // This updates the total elapsed time for the projectile
    CProjectile::Update(elapsed);

    // Dart's specifics for draw
    double newX = GetX() + mSpeedX * elapsed;
    double newY = GetY() + mSpeedY * elapsed; 
    
    // Set the new location
    SetLocation(newX, newY);

    // Dart's distance from tower
    mDistanceFromTower = GetTotalElapsed() * mGrowingSpeed + mInitialDistance;
    
    // If the dart's distance is larger than 100 pixels, this dart is no longer active
    if (mDistanceFromTower > mFinalDistance)
    {
        SetActive(false);
    }
}

/**
 * Get dart's current angle
 * \return mAngle
 */
double CProjectileDart::GetAngle()
{
    return mAngle;
}

/** 
 * Set mAngle
 * \param angle Angle to be set
 */
void CProjectileDart::SetAngle(double angle)
{
    mAngle = angle;
}
