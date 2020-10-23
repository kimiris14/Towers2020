/**
 * \file ItemVisitorPopFinder.h
 *
 * \author PaulaRed
 *
 * Visitor class to pop balloons that are within a certain radius
 */


#pragma once

#include "ItemVisitor.h"
#include <vector>

// Forward references the the balloon item type
class CItemBalloon;


/** This visitor finds balloons that are within a given distance and pops them.
 */
class CItemVisitorPopFinder : public CItemVisitor
{
public:

    CItemVisitorPopFinder(int originX, int originY, double radius, int points);

    /// destructor 
    virtual ~CItemVisitorPopFinder() {}

    virtual void VisitBalloon(CItemBalloon* balloon) override;

    /// A getter for the "has popped" boolean
    /// \returns True if the visitor has popped a balloon, false if not
    bool HasPopped() const { return mHasPopped; }

private:

    /// The origin of the circle's x component in pixels
    int mOriginX = 0;

    /// The origin of the circle's y component in pixels
    int mOriginY = 0;

    /// The number of point recieved for each balloon pop
    int mPopPoints = 1;

    /// The maximum distance from origin that a balloon can be popped by in pixels
    double mPoppingDistance = 0;

    /// This boolean is used to keep track if this visitor has popped a balloon yet
    bool mHasPopped = false;

};