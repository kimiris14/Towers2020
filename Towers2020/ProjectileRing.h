/**
 * \file ProjectileRing.h
 *
 * \author PaulaRed
 *
 * Class for a ring that shoots out of a ring tower
 */


#pragma once
#include "Projectile.h"

/**
 * Class to represent a Ring projectile in a level
 */
class CProjectileRing :
    public CProjectile
{
public:
    CProjectileRing(CLevel* level, CGame* game);

    /// Default constructor (disabled)
    CProjectileRing() = delete;

    /// Copy constructor (disabled)
    CProjectileRing(const CProjectileRing&) = delete;

    /// Destructor
    ~CProjectileRing() {}

    virtual void CProjectileRing::Draw(Gdiplus::Graphics* graphics);

    /** Accept a visitor
    * \param visitor The visitor we accept */
    virtual void Accept(CItemVisitor* visitor) override { visitor->VisitRing(this); } 

    ///Getter for the ring's radius
    /// <returns> the ring radius in pixels </returns>
    int GetRadius() { return mRingRadius; }

    /// Set the ring's radius
    /// <param name="rad"> radius to set </param>
    void SetRadius(int rad) { mRingRadius = rad; }

    virtual void Update(double elapsed);

    double GetGrowingSpeed() { return mGrowingSpeed; }

private:

    /// the initial radius of the ring in pixels
    const double RingInitialRadius = 10;

    /// the max radius of the ring in pixels
    const double RingEndRadius = 100;

    /// the current radius of the ring in pixels
    double mRingRadius = 0;

    /// This image ID is arbitrary, since the ring is not drawn by an image.
    const int RingImageID = 0;

    /// Ring radius growing speed in pixels per second
    double mGrowingSpeed = 200;
};

