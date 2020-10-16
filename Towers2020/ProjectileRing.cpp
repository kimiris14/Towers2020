/**
 * \file ProjectileRing.cpp
 *
 * \author PaulaRed
 */


#include "pch.h"
#include "ProjectileRing.h"
#include "Game.h"

using namespace Gdiplus;

 /// ring id number
const int ringID = 52; //assigned

 /**
 * Constructor
 * \param level The Level this ring is a member of
 * \param game The Game this ring is a member of
 * \param imageID The image id for this ring
 */
CProjectileRing::CProjectileRing(CLevel* level, int imageID) : CProjectile(level, imageID)
{
}

/**
* Draw the ring projectile
* \param graphics The GDI+ graphics context to draw on  
*/

//may need to change to void CProjectileRing::Draw(CGame* game, Gdiplus::Graphics* graphics)
void CProjectileRing::Draw(Gdiplus::Graphics* graphics)
{
	//need to instantiate object of Ring type and use mItems to update/draw ring item

	//Pen pen(Color(255, 0, 0));
	//graphics->DrawEllipse(&pen, 0, 0, mRingRadius, mRingRadius);
}

//Update Function for Ring Animation