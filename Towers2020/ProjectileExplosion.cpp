/**
 * \file ProjectileExplosion.cpp
 *
 * \author PaulaRed
 */


#include "pch.h"
#include "ProjectileExplosion.h"
#include "ItemVisitorPopFinder.h"
#include "Game.h"

using namespace Gdiplus;

/// explosion id number
const int ExplosionID = 53; //assigned

/// The length of the explosion in seconds
const double ExplosionLength = 0.25;

 /**
 * Constructor
 * \param level The Level this bomb is a member of
 * \param game The Game this bomb is a member of
 */
CProjectileExplosion::CProjectileExplosion(CLevel* level, CGame* game) : CProjectile(level, game, ExplosionID)
{
}

/**
* Draw the explosion projectile
* \param graphics The GDI+ graphics context to draw on
*/
void CProjectileExplosion::Draw(Gdiplus::Graphics* graphics)
{
	if (IsActive())
	{
		auto x = (int)this->GetX() - (int)mExplosionRadius;
		auto y = (int)this->GetY() - (int)mExplosionRadius;
		SolidBrush brush(Color(128, 0, 0));
		graphics->FillEllipse(&brush, x, y, int(mExplosionRadius * 2), int(mExplosionRadius * 2));
		
	}
}

/**
* Update the explosion projectile animation
* \param elapsed The elapsed time in seconds
*/
void CProjectileExplosion::Update(double elapsed)
{
	CProjectile::Update(elapsed);
	if (GetTotalElapsed() > ExplosionLength)
	{
		SetActive(false); //deactivate projectile
	}

	if (IsActive())
	{
		//pop balloons
		CItemVisitorPopFinder popper((int)GetX(), (int)GetY(), mExplosionRadius, PointsPerPop);
		GetLevel()->Accept(&popper);
	}
}
