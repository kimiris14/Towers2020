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

    /** Set X and Y speed of dart
    * \param x X pos
    * \param y Y pos
    */
    void SetSpeed(double x, double y) { mSpeedX = x; mSpeedY = y; }
    
    /** Accept a visitor
    * \param visitor The visitor we accept */
    virtual void Accept(CItemVisitor* visitor) override { visitor->VisitDart(this); } 

    virtual void Update(double elapsed) override;

    double GetAngle();

    /** Return initial distance of dart from tower
    * \return mInitialDistance
    */
    double GetDistance() { return mInitialDistance; }

    void SetAngle(double angle);

private:

    /// The maximum distance that a balloon can be from a dart and still be popped (in pixels)
    const double PoppingDistance = 24;

    /// The number of points to award if a dart hits a balloon
    const int PointsPerPop = 10;

    /// Dart image's angle
    double mAngle = 0;
    
    /// Dart's distance from Tower
    double mDistanceFromTower = 0;

    /// Current speed of dart at X
    double mSpeedX = 0;

    /// Current speed of dart at Y
    double mSpeedY = 0;

    /// Dart's growing speed in pixels per second
    double mGrowingSpeed = 200;

    /// Dart's initial distance from tower
    double mInitialDistance = 10;

    /// Dart's final distance from tower
    double mFinalDistance = 100;
};

