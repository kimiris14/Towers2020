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

    CItemVisitorRingPopFinder(int originX, int originY, double radius, double range);

    /// destructor 
    virtual ~CItemVisitorRingPopFinder() {}

    /** Visit a CItemBalloon object
     * \param balloon Balloon we are visiting */
    virtual void VisitBalloon(CItemBalloon* balloon) override;

private:

    /// The origin of the circle's x component in pixels
    int mOriginX = 0;
    
    /// The origin of the circle's y component in pixels
    int mOriginY = 0;

    /// The radius of the circle in pixels
    double mRadius = 0;

    /// The range between the ring's edge and a balloon's center in pixels.
    /// All balloons within this range will be added to the popped list
    double mRange = 0;

    /// A vector of the balloons that were determined to be popped
    std::vector<CItemBalloon*> mBalloonsToPop;

};