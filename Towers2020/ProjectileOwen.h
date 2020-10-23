#pragma once
#include "Projectile.h"

class CLevel;
class CGame;

class CProjectileOwen :
    public CProjectile
{

public:
    
    CProjectileOwen(CLevel* level, CGame* game, int originX, int originY, double angle);

    /// Default constructor (disabled)
    CProjectileOwen() = delete;

    /// Copy constructor (disabled)
    CProjectileOwen(const CProjectileExplosion&) = delete;

    /// Destructor
    ~CProjectileOwen() {}

    virtual void Update(double elapsed);

    virtual void Draw(Gdiplus::Graphics* graphics);

private:

    /// the origin of the projectile in pixels (the center of the tower)
    int mOriginX = 0;

    /// the origin of the projectile in pixels (the center of the tower)
    int mOriginY = 0;

    /// The angle that this projectile was launched at in degrees
    double mAngle = 0;

    /// The speed of this projectile in pixels per second
    double mSpeed = 250;

    /// the current distance of the projectile from the origin in pixels
    double mDistance = 0;

    /// The max distance of this projectile in pixels
    const int MaxDistance = 200;

    /// How far the projectile should start from the origin in pixels
    const int StartingDistance = 10;

    /// the font size in pixels (used for centering the bit, as well)
    const int FontSize = 10;

    /// The maximum distance that a balloon can be from a dart and still be popped (in pixels)
    const double PoppingDistance = 15;

    /// The number of points to award if a dart hits a balloon
    const int PointsPerPop = 2;

    /// This is the value to display as the projectile, which is set in the constructor
    int mBitValue = 0;
};

