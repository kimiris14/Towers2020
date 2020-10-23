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

/// dart image filename
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
    if (IsActive())
    {
        shared_ptr<Bitmap> dartImage = GetGame()->GetImage(dartID);
        if (dartImage != nullptr)
        {
            int wid = dartImage->GetWidth();
            int hit = dartImage->GetHeight();
            auto offsetX = wid / 2;
            auto offsetY = hit / 2;
            auto save = graphics->Save();
            graphics->TranslateTransform((REAL)(mXPos),
                (REAL)(mYPos));
            graphics->RotateTransform((REAL)(mAngle * RtoD));
            graphics->DrawImage(dartImage.get(), mDistanceFromTower,
                mDistanceFromTower, wid, hit);
            graphics->Restore(save);
        }
    }
}

/**
* Set item location
* \param x X location
* \param y Y location
*/
void CProjectileDart::SetLocation(double x, double y)
{
    mXPos = x;
    mYPos = y;
}

/**
 * Update function
 * \param elapsed Time elapsed
 */
void CProjectileDart::Update(double elapsed)
{
    CProjectile::Update(elapsed);

    mDistanceFromTower = GetTotalElapsed() * mSpeed;

    /*if (mDistanceFromTower > 90)
    {
        SetActive(false);
    }*/
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
