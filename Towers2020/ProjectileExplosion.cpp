/**
 * \file ProjectileExplosion.cpp
 *
 * \author PaulaRed
 */


#include "pch.h"
#include "ProjectileExplosion.h"
#include "Game.h"

using namespace Gdiplus;

/// bomb id number
const int explosionID = 53; //assigned

 /**
 * Constructor
 * \param level The Level this bomb is a member of
 * \param game The Game this bomb is a member of
 * \param imageID The image id for this bomb
 */
CProjectileExplosion::CProjectileExplosion(CLevel* level, CGame* game, int imageID) : CProjectile(level, game, imageID)
{
}

/**
* Draw the bomb projectile
* \param graphics The GDI+ graphics context to draw on
*/
void CProjectileExplosion::Draw(Gdiplus::Graphics* graphics)
{
	//SolidBrush brush(Color(128, 0, 0));
	//graphics->FillEllipse(&brush, 0, 0, mRingRadius, mRingRadius);
	//graphics->DrawEllipse(&pen, 0, 0, mRingRadius, mRingRadius);
}

//Update Function for Bomb Explosion