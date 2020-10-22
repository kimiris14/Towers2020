/**
 * \file ItemVisitorRingPopFinder.h
 *
 * \author PaulaRed
 *
 * Visitor class to find all of the balloons that should be popped by a ring
 */


#pragma once

#include "ItemVisitor.h"
#include <vector>

 // Forward references the the balloon item type
class CItemBalloon;


/** This visitor finds balloons that are within a given radius and range, then returns
 *  pointers those balloons in a set. 
 */
class CItemVisitorRingPopFinder : public CItemVisitor
{
public:

    CItemVisitorRingPopFinder(int originX, int originY, double radius, double range, int points);

    /// destructor 
    virtual ~CItemVisitorRingPopFinder() {}

    virtual void VisitBalloon(CItemBalloon* balloon) override;

private:

    /// The origin of the circle's x component in pixels
    int mOriginX = 0;
    
    /// The origin of the circle's y component in pixels
    int mOriginY = 0;

    /// The number of point recieved for each balloon pop
    int mPopPoints = 1;

    /// The minimum distance from origin in pixels
    double mMinPoppingDistance = 0;

    /// The maximum distance from the origin in pixels
    double mMaxPoppingDistance = 0;

};