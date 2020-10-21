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
    CProjectileRing(CLevel* level, CGame* game, int imageID);

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
    //Add ITERATOR

private:
    /// Radius of ring projectile
    int mRingRadius = 10;
};

