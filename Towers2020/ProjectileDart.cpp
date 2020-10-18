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
const double pi = 3.14159265358979323846;

 /**
 * Constructor
 * \param level The Level this item is a member of
 * \param game The Game this item is a member of
 * \param imageID The image id for this item
 */
CProjectileDart::CProjectileDart(CLevel* level, CGame* game, int imageID) : CProjectile(level, game, imageID)
{
	level->AddImage(dartID, dartImageName);
}

/**
 * Draw the rotated dart. Rotation is determined by the member
 * variable mAngle, which is the rotation in radians.
 *
 * @param graphics The graphics context to draw on.
 * @param offsetX An X offset added to the position of the dart.
 * @param offsetY A Y offset added to the position of the dart.
 */
void CProjectileDart::Draw(Gdiplus::Graphics* graphics, int offsetX, int offsetY)
{
    /*int wid = mImage->GetWidth();
    int hit = mImage->GetHeight();
    auto save = graphics->Save();
    graphics->TranslateTransform((REAL)(GetX() + offsetX),
        (REAL)(GetY() + offsetY));
    graphics->RotateTransform((REAL)(mAngle * RtoD));
    graphics->DrawImage(mImage.get(), 0, 0, wid, hit);
    graphics->Restore(save);*/
}

/**
* Set item location
* \param x X location
* \param y Y location
*/
void CProjectileDart::SetLocation(double x, double y)
{
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
 */
void CProjectileDart::SetAngle()
{
    if (mAngle == 0)
    {
        mAngle = pi / 4;
    }
    else if (mAngle == (pi / 4))
    {
        mAngle = pi / 2;
    }
    else if (mAngle == (pi / 2))
    {
        mAngle = (3 * pi) / 4;
    }
    else if (mAngle == ((3 * pi) / 4))
    {
        mAngle = pi;
    }
    else if (mAngle == pi)
    {
        mAngle = (5 * pi) / 4;
    }
    else if (mAngle == ((5 * pi) / 4))
    {
        mAngle = (3 * pi) / 2;
    }
    else if (mAngle == ((3 * pi) / 2))
    {
        mAngle = (7 * pi) / 4;
    }
    else if (mAngle == ((7 * pi) / 4))
    {
        mAngle = 0;
    }
}
