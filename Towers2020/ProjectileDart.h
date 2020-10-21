/**
 * \file ProjectileDart.h
 *
 * \author PaulaRed
 *
 * Class for a dart that shoots out of an eight tower
 */

#pragma once
#include "Projectile.h"
#include "ImageMap.h"

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

    //virtual void Update(double elapsed) override; <-- will fix

    double GetAngle();

    void SetAngle(double angle);

private:
    /// Dart image's angle
    double mAngle = 0;

    /// Dart's number counter
    int mAngleCounter = 0;

    /// Dart's x position
    double mXPos = 0;
    
    /// Dart's y position
    double mYPos = 0;

    /// Dart speed X
    double mSpeedX = 0;
    
    /// Dart speed Y
    double mSpeedY = 0;
    
    /// Dart's distance from Tower
    double mDistanceFromTower = 10;
};

