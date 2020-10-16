/**
 * \file ProjectileBomb.h
 *
 * \author PaulaRed
 *
 * Class for a bomb that explodes out of a bomb tower
 */


#pragma once
#include "Projectile.h"

/**
 * Class to represent a bomb projectile in a level
 */
class CProjectileBomb :
    public CProjectile
{
public:
    CProjectileBomb(CLevel* level, CGame* game, int imageID);

    /// Default constructor (disabled)
    CProjectileBomb() = delete;

    /// Copy constructor (disabled)
    CProjectileBomb(const CProjectileBomb&) = delete;

    /// Destructor
    ~CProjectileBomb() {}

    /// Draw the bomb projectile
    /// \param graphics The GDI+ graphics context to draw on

    //previously : void CProjectileRing::Draw(CGame* game, Gdiplus::Graphics* graphics)
    virtual void CProjectileBomb::Draw(Gdiplus::Graphics* graphics);

    /** Accept a visitor
    * \param visitor The visitor we accept */
    //virtual void Accept(CItemVisitor* visitor) override { visitor->VisitBomb(this); } 

private:
    /// Dedicated bomb timer for each bomb placed
    int mTimer = 0;

};

