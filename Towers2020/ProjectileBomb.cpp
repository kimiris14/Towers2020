/**
 * \file ProjectileBomb.cpp
 *
 * \author PaulaRed
 */


#include "pch.h"
#include "ProjectileBomb.h"
#include "Game.h"

using namespace Gdiplus;

/// bomb id number
const int bombID = 53; //assigned

 /**
 * Constructor
 * \param level The Level this bomb is a member of
 * \param game The Game this bomb is a member of
 * \param imageID The image id for this bomb
 */
CProjectileBomb::CProjectileBomb(CLevel* level, int imageID) : CProjectile(level, imageID)
{
}

/**
* Draw the bomb projectile
* \param graphics The GDI+ graphics context to draw on
*/
void CProjectileBomb::Draw(Gdiplus::Graphics* graphics) //may need to change to void CProjectileRing::Draw(CGame* game, Gdiplus::Graphics* graphics)
{
	//need to instantiate object of Ring type and use mItems to update/draw ring item

	//SolidBrush brush(Color(128, 0, 0));
	//graphics->FillRectangle(&brush, 0, 0, mRingRadius, mRingRadius);
	//graphics->DrawEllipse(&pen, 0, 0, mRingRadius, mRingRadius);
}

//Update Function for Bomb Explosion