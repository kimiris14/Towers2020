/**
 * \file ProjectileDart.h
 *
 * \author PaulaRed
 *
 * Class for a dart that shoots out of an eight tower
 */

#pragma once
#include "Projectile.h"

 /**
  * Class to represent a dart in a level
  */
class CProjectileDart :
    public CProjectile
{
public:
    CProjectileDart(CLevel* level, CGame* game, int imageID);

    /// Default constructor (disabled)
    CProjectileDart() = delete;

    /// Copy constructor (disabled)
    CProjectileDart(const CProjectileDart&) = delete;

    /// Destructor
    ~CProjectileDart() {}


    virtual void Draw(Gdiplus::Graphics* graphics) override;

    virtual void SetLocation(double x, double y) override;

    /** Accept a visitor
    * \param visitor The visitor we accept */
    virtual void Accept(CItemVisitor* visitor) override { visitor->VisitDart(this); } 
};

