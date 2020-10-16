/**
 * \file ProjectileExplosion.h
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
class CProjectileExplosion :
    public CProjectile
{
public:
    CProjectileExplosion(CLevel* level, CGame* game, int imageID);

    /// Default constructor (disabled)
    CProjectileExplosion() = delete;

    /// Copy constructor (disabled)
    CProjectileExplosion(const CProjectileExplosion&) = delete;

    /// Destructor
    ~CProjectileExplosion() {}

    /// Draw the bomb projectile
    /// \param graphics The GDI+ graphics context to draw on
    virtual void CProjectileExplosion::Draw(Gdiplus::Graphics* graphics);

    /** Accept a visitor
    * \param visitor The visitor we accept */
    virtual void Accept(CItemVisitor* visitor) override { visitor->VisitExplosion(this); } 

};

