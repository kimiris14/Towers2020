/**
 * \file ItemVisitorFindNearestBalloon.h
 *
 * \author PaulaRed
 *
 * Visitor class to find and return a pointer to the nearest balloon.
 */


#pragma once

#include "ItemVisitor.h"
#include <vector>

 // Forward references the the balloon item type
class CItemBalloon;


/** This visitor finds the nearest unpopped balloon
 */
class CItemVisitorFindNearestBalloon : public CItemVisitor
{
public:

    CItemVisitorFindNearestBalloon(int x, int y, double range);

    /// destructor 
    virtual ~CItemVisitorFindNearestBalloon() {}

    virtual void VisitBalloon(CItemBalloon* balloon) override;
    virtual void VisitBalloonGhost(CItemBalloonGhost* balloon) override;


    /// Getter for the nearest balloon after it's been found
    /// \returns a pointer to the nearest balloon
    CItemBalloon* GetNearestBallon() const { return mNearestBalloon; }

private:

    /// The point to find the nearest balloon to (pixels)
    int mX = 0;

    /// The point to find the nearest balloon to (pixels)
    int mY = 0;

    /// This will hold the closest balloon's distance to mX and mY in pixels
    double mBalloonDistance = 0;

    /// This is the range to look within (in pixels)
    double mRange = 1000;

    /// This will hold the nearest balloon if there is one found
    CItemBalloon* mNearestBalloon = nullptr;

};