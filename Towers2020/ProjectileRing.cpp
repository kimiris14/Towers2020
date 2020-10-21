/**
 * \file ProjectileRing.cpp
 *
 * \author PaulaRed
 */


#include "pch.h"
#include "ProjectileRing.h"
#include "Game.h"

using namespace Gdiplus;


 /**
 * Constructor
 * \param level The Level this ring is a member of
 * \param game The Game this ring is a member of
 */
CProjectileRing::CProjectileRing(CLevel* level, CGame* game) : CProjectile(level, game, RingImageID)
{
}

/**
* Draw the ring projectile
* \param graphics The GDI+ graphics context to draw on  
*/
void CProjectileRing::Draw(Gdiplus::Graphics* graphics)
{

	// only draw the ring if it's still active
	if (IsActive())
	{
		// calculate the upper corner of the ring to draw at
		int x = (int)GetX() - (int)mRingRadius;
		int y = (int)GetY() - (int)mRingRadius;
		Pen pen(Color(255, 0, 0), 2); // red ring

		// the radius is multiplied by two to get the total width and height of the elipse
		graphics->DrawEllipse(&pen, x, y, (int)mRingRadius * 2, (int)mRingRadius * 2);

	}
}


/// Balloon class version of the time update
/// \param elapsed The number of seconds elapsed since last draw
void CProjectileRing::Update(double elapsed) {

	// this updates the total elapsed time for the projectile
	CProjectile::Update(elapsed);

	// now, ring specific updates.
	mRingRadius = GetTotalElapsed() * mGrowingSpeed + RingInitialRadius;

	// if the radius is larger than the maximum, this ring is no longer active
	if (mRingRadius > RingEndRadius) 
	{
		SetActive(false);
	}

}