/**
 * \file ProjectileOwen.cpp
 *
 * \author PaulaRed
 */

#include "pch.h"
#include "ProjectileOwen.h"
#include "Level.h"
#include "ItemVisitorPopFinder.h"

using namespace std;
using namespace Gdiplus;

/// Constant to covert radians to degrees.
const double RtoD = 57.2957795;

/// the pixel offset to draw the bits the x direction
const int FontOffsetX = -10;

/// the pixel offset to draw the bits in the y direction
const int FontOffsetY = -12;



/**
 * Constructor for the own projectile
 * \param level The current level that this projectile belongs to
 * \param game The current game that this projectile belongs to
 * \param originX The origin of this projectie in pixels
 * \param originY The origin of this projectile in pixels
 * \param angle The angle at which this projectile was launched relative to the tower
 */
CProjectileOwen::CProjectileOwen(CLevel* level, CGame* game, int originX, int originY, double angle) 
	: CProjectile(level, game, 000), mOriginX(originX), mOriginY(originY), mAngle(angle)
{
	// either a one or a zero
	if (((double)rand() / RAND_MAX) < 0.5)
		mBitValue = 0;
	else
		mBitValue = 1;

}

/**
 * Update this projectile's position and pops balloons if need be
 * \param elapsed the elapsed time since last update in seconds
 */
void CProjectileOwen::Update(double elapsed)
{
	// this updates the total elapsed time for the projectile
	CProjectile::Update(elapsed);

	mDistance = GetTotalElapsed() * mSpeed + StartingDistance;

	if (mDistance > MaxDistance)
		SetActive(false);

	// attempt to pop balloons if we're active
	if (IsActive())
	{
		CItemVisitorPopFinder popper((int)GetX(), (int)GetY(), PoppingDistance, PointsPerPop);
		GetLevel()->Accept(&popper);

		// If there was a balloon popped, consider this projectile as "spent"
		if (popper.HasPopped())
			SetActive(false);
	}

}



/**
 * Draw the projectile
 * \param graphics The graphics context to draw on
 */
void CProjectileOwen::Draw(Gdiplus::Graphics* graphics)
{

	// do nothing if the projectile is no longer active
	if (!IsActive())
		return;

	double x = mOriginX + mDistance * cos(mAngle / RtoD);
	double y = mOriginY + mDistance * sin(mAngle / RtoD);

	// set the location (this is not so important for the drawing here, but it's important for the
	// GetX() and GetY() getters, which are used in the visitor initialization
	SetLocation(x, y);

	// this is to offset the fint size, so that the bit appears to be centered over it's position
	x += FontOffsetX;
	y += FontOffsetY;

	FontFamily fontFamily(L"Arial");
	Gdiplus::Font font(&fontFamily, (REAL)FontSize);


	SolidBrush white(Color(255, 255, 255));
	wstring bit = to_wstring(mBitValue);
	graphics->DrawString(bit.c_str(),
		-1,  // string length
		&font,      
		PointF((REAL)x, (REAL)y),
		&white);

}
